#pragma once
#include <QString>

class User 
{
public:
    enum class Status {
        Pending = 0,
        Approved = 1,
        Rejected = 2
    };

    User();
    
    int id() const { return m_id; }
    QString username() const { return m_username; }
    int roleId() const { return m_roleId; }
    Status status() const { return m_status; }

private:
    int m_id;
    QString m_username;
    QString m_password;
    int m_roleId;
    Status m_status;
}; 