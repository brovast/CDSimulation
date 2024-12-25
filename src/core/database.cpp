#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Database::Database(QObject* parent) : QObject(parent)
{
}

Database::~Database()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

Database& Database::getInstance()
{
    static Database instance;
    return instance;
}

bool Database::initialize(const QString& dbPath)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);
    
    if (!m_db.open()) {
        qCritical() << "数据库连接失败:" << m_db.lastError().text();
        return false;
    }
    
    // 创建表结构
    if (!createTables()) {
        return false;
    }

    // 初始化默认管理员账户
    if (!initDefaultAdmin()) {
        return false;
    }
    
    return true;
}

bool Database::initDefaultAdmin()
{
    // 检查是否已存在管理员账户
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE username = 'admin'");
    
    if (!query.exec() || !query.next()) {
        qCritical() << "检查管理员账户失败:" << query.lastError().text();
        return false;
    }
    
    if (query.value(0).toInt() == 0) {
        // 创建角色表中的管理员角色（如果不存在）
        QString adminPermissions = "登录权限/系统管理登录,登录权限/工作台登录";
        
        // 使用 INSERT OR REPLACE 而不是 INSERT OR IGNORE，确保权限被更新
        query.prepare("INSERT OR REPLACE INTO roles (id, name, permissions) VALUES (1, '管理员', ?)");
        query.addBindValue(adminPermissions);
        if (!query.exec()) {
            qCritical() << "创建管理员角色失败:" << query.lastError().text();
            return false;
        }

        // 创建默认管理员账户
        query.prepare("INSERT INTO users (username, password, role_id, status) VALUES ('admin', 'admin', 1, 1)");
        if (!query.exec()) {
            qCritical() << "创建管理员账户失败:" << query.lastError().text();
            return false;
        }
        
        // 创建工程师角色
        QString engineerPermissions = "登录权限/工作台登录";
        query.prepare("INSERT OR IGNORE INTO roles (id, name, permissions) VALUES (2, '工程师', ?)");
        query.addBindValue(engineerPermissions);
        if (!query.exec()) {
            qCritical() << "创建工程师角色失败:" << query.lastError().text();
            return false;
        }
        
        qInfo() << "成功创建默认管理员账户和角色";
    }
    
    return true;
}

bool Database::createTables()
{
    QSqlQuery query;
    
    // 创建角色表
    if (!query.exec("CREATE TABLE IF NOT EXISTS roles ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "name TEXT NOT NULL,"
                   "permissions TEXT)")) {
        qCritical() << "创建角色表失败:" << query.lastError().text();
        return false;
    }
    
    // 创建用户表
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "username TEXT NOT NULL UNIQUE,"
                   "password TEXT NOT NULL,"
                   "role_id INTEGER,"
                   "status INTEGER DEFAULT 0,"  // 0:待审批 1:已审批 2:拒绝
                   "FOREIGN KEY(role_id) REFERENCES roles(id))")) {
        qCritical() << "创建用户表失败:" << query.lastError().text();
        return false;
    }
    
    // 创建审批表
    if (!query.exec("CREATE TABLE IF NOT EXISTS approvals ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "user_id INTEGER,"
                   "approver_id INTEGER,"
                   "status INTEGER,"
                   "create_time DATETIME,"
                   "approve_time DATETIME,"
                   "FOREIGN KEY(user_id) REFERENCES users(id),"
                   "FOREIGN KEY(approver_id) REFERENCES users(id))")) {
        qCritical() << "创建审批表失败:" << query.lastError().text();
        return false;
    }
    
    // 创建任务表
    if (!query.exec("CREATE TABLE IF NOT EXISTS tasks ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "name TEXT NOT NULL,"                    // 任务名称
                   "description TEXT,"                      // 任务描述
                   "work_dir TEXT,"                        // 工作目录
                   "model_path TEXT,"                      // 模型路径
                   "model_type TEXT,"                      // 型号
                   "assigned_to INTEGER,"                  // 指派人员
                   "assign_description TEXT,"              // 指派说明
                   "status INTEGER DEFAULT 0,"             // 状态(0:待处理 1:进行中 2:已完成 3:已取消)
                   "created_by INTEGER,"                   // 创建人
                   "create_time DATETIME,"                 // 创建时间
                   "update_time DATETIME,"                 // 更新时间
                   "FOREIGN KEY(assigned_to) REFERENCES users(id),"
                   "FOREIGN KEY(created_by) REFERENCES users(id))")) {
        qCritical() << "创建任务表失败:" << query.lastError().text();
        return false;
    }
    
    // 创建任务分析类型关联表
    if (!query.exec("CREATE TABLE IF NOT EXISTS task_analysis_types ("
                   "task_id INTEGER,"
                   "analysis_type TEXT,"                   // 分析类型
                   "parameters TEXT,"                      // 分析参数(JSON格式)
                   "PRIMARY KEY (task_id, analysis_type),"
                   "FOREIGN KEY(task_id) REFERENCES tasks(id))")) {
        qCritical() << "创建任务分析类型表失败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

bool Database::validateUser(const QString& username, const QString& password, int& roleId, int& status, int& userId)
{
    QSqlQuery query;
    query.prepare("SELECT id, role_id, status FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);
    
    if (query.exec() && query.next()) {
        userId = query.value(0).toInt();
        roleId = query.value(1).toInt();
        status = query.value(2).toInt();
        return true;
    }
    return false;
}

bool Database::addUser(const QString& username, const QString& password, int roleId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, role_id, status) VALUES (?, ?, ?, 0)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(roleId);
    
    return query.exec();
}

QList<Database::UserInfo> Database::getUserList(int statusFilter)
{
    QList<UserInfo> users;
    QSqlQuery query;
    
    QString sql = "SELECT u.id, u.username, u.role_id, r.name as role_name, u.status "
                 "FROM users u LEFT JOIN roles r ON u.role_id = r.id";
    
    if (statusFilter >= 0) {
        sql += QString(" WHERE u.status = %1").arg(statusFilter);
    }
    
    if (query.exec(sql)) {
        while (query.next()) {
            UserInfo user;
            user.id = query.value("id").toInt();
            user.username = query.value("username").toString();
            user.roleId = query.value("role_id").toInt();
            user.roleName = query.value("role_name").toString();
            user.status = query.value("status").toInt();
            users.append(user);
        }
    } else {
        qCritical() << "获取用户列表���败:" << query.lastError().text();
    }
    
    return users;
}

bool Database::updateUserStatus(int userId, int status, int approverId)
{
    QSqlQuery query;
    
    // 开始事务
    m_db.transaction();
    
    // 更新用户状态
    query.prepare("UPDATE users SET status = ? WHERE id = ?");
    query.addBindValue(status);
    query.addBindValue(userId);
    
    if (!query.exec()) {
        m_db.rollback();
        qCritical() << "更新用户状态失败:" << query.lastError().text();
        return false;
    }
    
    // 添加审批记录
    query.prepare("INSERT INTO approvals (user_id, approver_id, status, create_time, approve_time) "
                 "VALUES (?, ?, ?, CURRENT_TIMESTAMP, CURRENT_TIMESTAMP)");
    query.addBindValue(userId);
    query.addBindValue(approverId);
    query.addBindValue(status);
    
    if (!query.exec()) {
        m_db.rollback();
        qCritical() << "添加审批记录失败:" << query.lastError().text();
        return false;
    }
    
    // 提交事务
    return m_db.commit();
}

bool Database::deleteUser(int userId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE id = ? AND id != 1"); // 防止删除超级管理员
    query.addBindValue(userId);
    
    if (!query.exec()) {
        qCritical() << "删除用户��败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

bool Database::updateUserRole(int userId, int roleId)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET role_id = ? WHERE id = ?");
    query.addBindValue(roleId);
    query.addBindValue(userId);
    
    if (!query.exec()) {
        qCritical() << "更新用户角色失败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

QList<Database::RoleInfo> Database::getRoleList()
{
    QList<RoleInfo> roles;
    QSqlQuery query("SELECT id, name, permissions FROM roles ORDER BY id");
    
    if (query.exec()) {
        while (query.next()) {
            RoleInfo role;
            role.id = query.value("id").toInt();
            role.name = query.value("name").toString();
            role.permissions = query.value("permissions").toString();
            roles.append(role);
        }
    } else {
        qCritical() << "获取角色列表失败:" << query.lastError().text();
    }
    
    return roles;
}

bool Database::updateUserPassword(int userId, const QString& newPassword)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET password = ? WHERE id = ?");
    query.addBindValue(newPassword);
    query.addBindValue(userId);
    
    if (!query.exec()) {
        qCritical() << "更新用户密码失败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

bool Database::getUserInfo(int userId, QString& username, int& roleId)
{
    QSqlQuery query;
    query.prepare("SELECT username, role_id FROM users WHERE id = ?");
    query.addBindValue(userId);
    
    if (query.exec() && query.next()) {
        username = query.value("username").toString();
        roleId = query.value("role_id").toInt();
        return true;
    }
    
    return false;
}

bool Database::addRole(const QString& name, const QString& permissions)
{
    QSqlQuery query;
    query.prepare("INSERT INTO roles (name, permissions) VALUES (?, ?)");
    query.addBindValue(name);
    query.addBindValue(permissions);
    
    if (!query.exec()) {
        qCritical() << "添加角色失败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

bool Database::updateRole(int roleId, const QString& name, const QString& permissions)
{
    QSqlQuery query;
    query.prepare("UPDATE roles SET name = ?, permissions = ? WHERE id = ?");
    query.addBindValue(name);
    query.addBindValue(permissions);
    query.addBindValue(roleId);
    
    if (!query.exec()) {
        qCritical() << "更新角色失败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

bool Database::deleteRole(int roleId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM roles WHERE id = ? AND id != 1"); // 防止删除超级管理员角色
    query.addBindValue(roleId);
    
    if (!query.exec()) {
        qCritical() << "删除角色失败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

QList<Database::ApprovalInfo> Database::getApprovalList(int statusFilter)
{
    QList<ApprovalInfo> approvals;
    QSqlQuery query;
    
    QString sql = "SELECT a.id, a.user_id, u1.username as username, "
                 "a.approver_id, u2.username as approver_name, "
                 "a.status, a.create_time, a.approve_time "
                 "FROM approvals a "
                 "LEFT JOIN users u1 ON a.user_id = u1.id "
                 "LEFT JOIN users u2 ON a.approver_id = u2.id";
    
    if (statusFilter >= 0) {
        sql += QString(" WHERE a.status = %1").arg(statusFilter);
    }
    sql += " ORDER BY a.create_time DESC";
    
    if (query.exec(sql)) {
        while (query.next()) {
            ApprovalInfo approval;
            approval.id = query.value("id").toInt();
            approval.userId = query.value("user_id").toInt();
            approval.username = query.value("username").toString();
            approval.approverId = query.value("approver_id").toInt();
            approval.approverName = query.value("approver_name").toString();
            approval.status = query.value("status").toInt();
            approval.createTime = query.value("create_time").toDateTime();
            approval.approveTime = query.value("approve_time").toDateTime();
            approvals.append(approval);
        }
    } else {
        qCritical() << "获取审批列表失败:" << query.lastError().text();
    }
    
    return approvals;
}

bool Database::fixAdminPermissions()
{
    QSqlQuery query;
    QString adminPermissions = "登录权限/系统管理登录,登录权限/工作台登录";
    
    query.prepare("UPDATE roles SET permissions = ? WHERE id = 1");
    query.addBindValue(adminPermissions);
    
    if (!query.exec()) {
        qCritical() << "修复管理员权限失败:" << query.lastError().text();
        return false;
    }
    
    return true;
}

QList<Database::TaskInfo> Database::getTaskList(int statusFilter, const QString& typeFilter)
{
    QList<TaskInfo> tasks;
    QSqlQuery query;
    
    QString sql = "SELECT DISTINCT t.* FROM tasks t";
    if (!typeFilter.isEmpty()) {
        sql += " LEFT JOIN task_analysis_types at ON t.id = at.task_id";
    }
    sql += " WHERE 1=1";
    
    if (statusFilter >= 0) {
        sql += " AND t.status = " + QString::number(statusFilter);
    }
    if (!typeFilter.isEmpty()) {
        sql += " AND at.analysis_type = '" + typeFilter + "'";
    }
    sql += " ORDER BY t.create_time DESC";
    
    if (query.exec(sql)) {
        while (query.next()) {
            TaskInfo task;
            task.id = query.value("id").toInt();
            task.name = query.value("name").toString();
            task.description = query.value("description").toString();
            task.workDir = query.value("work_dir").toString();
            task.modelPath = query.value("model_path").toString();
            task.modelType = query.value("model_type").toString();
            task.assignedTo = query.value("assigned_to").toInt();
            task.assignDescription = query.value("assign_description").toString();
            task.status = query.value("status").toInt();
            task.createdBy = query.value("created_by").toInt();
            task.createTime = query.value("create_time").toDateTime();
            task.updateTime = query.value("update_time").toDateTime();
            tasks.append(task);
        }
    } else {
        qCritical() << "获取任务列表失败:" << query.lastError().text();
    }
    
    return tasks;
}

QList<Database::TaskAnalysisType> Database::getTaskAnalysisTypes(int taskId)
{
    QList<TaskAnalysisType> types;
    QSqlQuery query;
    
    query.prepare("SELECT * FROM task_analysis_types WHERE task_id = ?");
    query.addBindValue(taskId);
    
    if (query.exec()) {
        while (query.next()) {
            TaskAnalysisType type;
            type.taskId = query.value("task_id").toInt();
            type.analysisType = query.value("analysis_type").toString();
            type.parameters = query.value("parameters").toString();
            types.append(type);
        }
    } else {
        qCritical() << "获取任务分析类型失败:" << query.lastError().text();
    }
    
    return types;
}

bool Database::addTask(const TaskInfo& task, const QList<TaskAnalysisType>& analysisTypes)
{
    m_db.transaction();
    
    QSqlQuery query;
    query.prepare("INSERT INTO tasks (name, description, work_dir, model_path, model_type, "
                 "assigned_to, assign_description, status, created_by, create_time, update_time) "
                 "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(task.name);
    query.addBindValue(task.description);
    query.addBindValue(task.workDir);
    query.addBindValue(task.modelPath);
    query.addBindValue(task.modelType);
    query.addBindValue(task.assignedTo);
    query.addBindValue(task.assignDescription);
    query.addBindValue(task.status);
    query.addBindValue(task.createdBy);
    query.addBindValue(task.createTime);
    query.addBindValue(task.updateTime);
    
    if (!query.exec()) {
        qCritical() << "添加任务失败:" << query.lastError().text();
        m_db.rollback();
        return false;
    }
    
    int taskId = query.lastInsertId().toInt();
    
    // 添加分析类型
    for (const auto& type : analysisTypes) {
        query.prepare("INSERT INTO task_analysis_types (task_id, analysis_type, parameters) "
                     "VALUES (?, ?, ?)");
        query.addBindValue(taskId);
        query.addBindValue(type.analysisType);
        query.addBindValue(type.parameters);
        
        if (!query.exec()) {
            qCritical() << "添加任务分析类型失败:" << query.lastError().text();
            m_db.rollback();
            return false;
        }
    }
    
    m_db.commit();
    return true;
}

bool Database::getTaskInfo(int taskId, TaskInfo& taskInfo)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM tasks WHERE id = ?");
    query.addBindValue(taskId);
    
    if (query.exec() && query.next()) {
        taskInfo.id = query.value("id").toInt();
        taskInfo.name = query.value("name").toString();
        taskInfo.description = query.value("description").toString();
        taskInfo.workDir = query.value("work_dir").toString();
        taskInfo.modelPath = query.value("model_path").toString();
        taskInfo.modelType = query.value("model_type").toString();
        taskInfo.assignedTo = query.value("assigned_to").toInt();
        taskInfo.assignDescription = query.value("assign_description").toString();
        taskInfo.status = query.value("status").toInt();
        taskInfo.createdBy = query.value("created_by").toInt();
        taskInfo.createTime = query.value("create_time").toDateTime();
        taskInfo.updateTime = query.value("update_time").toDateTime();
        return true;
    }
    
    qCritical() << "获取任务信息失败:" << query.lastError().text();
    return false;
}

bool Database::deleteTask(int taskId)
{
    m_db.transaction();
    
    QSqlQuery query;
    
    // 删除任务分析类型
    query.prepare("DELETE FROM task_analysis_types WHERE task_id = ?");
    query.addBindValue(taskId);
    if (!query.exec()) {
        qCritical() << "删除任务分析类型失败:" << query.lastError().text();
        m_db.rollback();
        return false;
    }
    
    // 删除任务
    query.prepare("DELETE FROM tasks WHERE id = ?");
    query.addBindValue(taskId);
    if (!query.exec()) {
        qCritical() << "删除任务失败:" << query.lastError().text();
        m_db.rollback();
        return false;
    }
    
    m_db.commit();
    return true;
}

bool Database::updateTaskStatus(int taskId, int status)
{
    QSqlQuery query;
    query.prepare("UPDATE tasks SET status = ?, update_time = ? WHERE id = ?");
    query.addBindValue(status);
    query.addBindValue(QDateTime::currentDateTime());
    query.addBindValue(taskId);
    
    if (!query.exec()) {
        qCritical() << "更新任务状态失败:" << query.lastError().text();
        return false;
    }
    
    return true;
} 