#pragma once
#include <QObject>
#include <QSqlDatabase>
#include <QDateTime>

class Database : public QObject 
{
    Q_OBJECT
public:
    static Database& getInstance();
    bool initialize(const QString& dbPath);
    bool createTables();
    bool validateUser(const QString& username, const QString& password, int& roleId, int& status, int& userId);
    bool addUser(const QString& username, const QString& password, int roleId);
    
    struct UserInfo {
        int id;
        QString username;
        int roleId;
        QString roleName;
        int status;
        QDateTime createTime;
    };

    struct RoleInfo {
        int id;
        QString name;
        QString permissions;
    };

    struct ApprovalInfo {
        int id;
        int userId;
        QString username;
        int approverId;
        QString approverName;
        int status;
        QDateTime createTime;
        QDateTime approveTime;
    };

    struct TaskInfo {
        int id;
        QString name;
        QString description;
        QString workDir;
        QString modelPath;
        QString modelType;
        int assignedTo;
        QString assignedUsername;
        QString assignDescription;
        int status;
        int createdBy;
        QDateTime createTime;
        QDateTime updateTime;
    };

    struct TaskAnalysisType {
        int taskId;
        QString analysisType;
        QString parameters;
    };

    QList<UserInfo> getUserList(int statusFilter = -1);
    bool updateUserStatus(int userId, int status, int approverId);
    bool deleteUser(int userId);
    bool updateUserRole(int userId, int roleId);
    bool updateUserPassword(int userId, const QString& newPassword);
    bool getUserInfo(int userId, QString& username, int& roleId);

    QList<RoleInfo> getRoleList();
    bool addRole(const QString& name, const QString& permissions);
    bool updateRole(int roleId, const QString& name, const QString& permissions);
    bool deleteRole(int roleId);

    QList<ApprovalInfo> getApprovalList(int statusFilter = -1);
    
    bool fixAdminPermissions();

    QList<TaskInfo> getTaskList(int statusFilter = -1, int assignedTo = -1);
    bool addTask(const TaskInfo& task, const QList<TaskAnalysisType>& analysisTypes);
    bool updateTaskStatus(int taskId, int status);
    bool deleteTask(int taskId);
    bool getTaskInfo(int taskId, TaskInfo& taskInfo);
    QList<TaskAnalysisType> getTaskAnalysisTypes(int taskId);

    QList<TaskInfo> getTaskList(int statusFilter = -1, const QString& typeFilter = QString());
    QList<TaskInfo> getTaskListByUser(int statusFilter = -1, int assignedTo = -1);

private:
    bool initDefaultAdmin();
    Database(QObject* parent = nullptr);
    ~Database();
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    QSqlDatabase m_db;
}; 