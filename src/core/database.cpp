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
        query.prepare("INSERT OR IGNORE INTO roles (id, name, permissions) VALUES (1, '管理员', 'all')");
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
        
        qInfo() << "成功创建默认管理员账户";
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
        qCritical() << "获取用户列表失败:" << query.lastError().text();
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
        qCritical() << "删除用户失败:" << query.lastError().text();
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