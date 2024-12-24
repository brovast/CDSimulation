#include "config.h"
#include <QDir>
#include <QDebug>
#include <QApplication>

Config::Config(QObject* parent) : QObject(parent), m_settings(nullptr)
{
}

Config::~Config()
{
    delete m_settings;
}

Config& Config::getInstance()
{
    static Config instance;
    return instance;
}

bool Config::initialize(const QString& configPath)
{
    QDir dir(QFileInfo(configPath).path());
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    
    m_settings = new QSettings(configPath, QSettings::IniFormat);
    if (!m_settings->isWritable()) {
        qCritical() << "配置文件不可写:" << configPath;
        return false;
    }

    // 设置默认配置
    initDefaultConfig();
    
    return true;
}

void Config::initDefaultConfig()
{
    // 如果是首次运行，设置默认配置
    if (m_settings->value("FirstRun", true).toBool()) {
        // 设置默认的数据路径
        QString appPath = QApplication::applicationDirPath();
        QString defaultBasicDataPath = QDir(appPath).filePath("database/basicdata");
        QString defaultCDDataPath = QDir(appPath).filePath("database/cddata");

        // 确保数据目录存在
        QDir(defaultBasicDataPath).mkpath(".");
        QDir(defaultCDDataPath).mkpath(".");

        setBasicDataPath(defaultBasicDataPath);
        setCDDataPath(defaultCDDataPath);

        // 标记已经初始化
        m_settings->setValue("FirstRun", false);
    }
}

// 软件配置相关方法
QStringList Config::getSoftwareList() const
{
    m_settings->beginGroup("Software");
    QStringList softwareList = m_settings->childGroups();
    m_settings->endGroup();
    return softwareList;
}

QString Config::getSoftwarePath(const QString& name) const
{
    return m_settings->value(QString("Software/%1/Path").arg(name)).toString();
}

QString Config::getSoftwareParams(const QString& name) const
{
    return m_settings->value(QString("Software/%1/Params").arg(name)).toString();
}

void Config::setSoftwarePath(const QString& name, const QString& path)
{
    m_settings->setValue(QString("Software/%1/Path").arg(name), path);
    m_settings->sync();
}

void Config::setSoftwareParams(const QString& name, const QString& params)
{
    m_settings->setValue(QString("Software/%1/Params").arg(name), params);
    m_settings->sync();
}

void Config::removeSoftware(const QString& name)
{
    m_settings->beginGroup("Software");
    m_settings->remove(name);
    m_settings->endGroup();
    m_settings->sync();
}

// 数据路径配置方法
QString Config::getBasicDataPath() const
{
    return m_settings->value("DataPath/BasicData").toString();
}

QString Config::getCDDataPath() const
{
    return m_settings->value("DataPath/CDData").toString();
}

void Config::setBasicDataPath(const QString& path)
{
    m_settings->setValue("DataPath/BasicData", path);
    m_settings->sync();
}

void Config::setCDDataPath(const QString& path)
{
    m_settings->setValue("DataPath/CDData", path);
    m_settings->sync();
}

// 通用配置方法
QVariant Config::getValue(const QString& key, const QVariant& defaultValue) const
{
    return m_settings->value(key, defaultValue);
}

void Config::setValue(const QString& key, const QVariant& value)
{
    m_settings->setValue(key, value);
    m_settings->sync();
} 