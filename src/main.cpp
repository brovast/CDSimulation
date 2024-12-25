#include <QApplication>
#include <QDir>
#include "core/database.h"
#include "utils/config.h"
#include "views/login.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 获取应用程序所在目录
    QString appDir = QCoreApplication::applicationDirPath();
    
    // 构建配置文件和数据库文件的绝对路径
    // 配置文件放在exe同级目录下的config文件夹中
    QString configPath = QDir(appDir).filePath("config/software_config.ini");
    QString dbPath = QDir(appDir).filePath("database/database.db");

    // 确保配置目录存在
    QDir configDir(QDir(appDir).filePath("config"));
    if (!configDir.exists()) {
        configDir.mkpath(".");
    }

    // 确保数据库目录存在
    QDir dbDir(QDir(appDir).filePath("database"));
    if (!dbDir.exists()) {
        dbDir.mkpath(".");
    }

    // 初始化配置
    if (!Config::getInstance().initialize(configPath)) {
        qCritical() << "配置初始化失败";
        return -1;
    }

    // 初始化数据库
    if (!Database::getInstance().initialize(dbPath)) {
        qCritical() << "数据库初始化失败";
        return -1;
    }
    
    // 修复管理员权限
    Database::getInstance().fixAdminPermissions();

    // 显示登录界面
    Login login;
    login.show();

    return app.exec();
} 