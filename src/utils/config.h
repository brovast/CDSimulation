#pragma once
#include <QObject>
#include <QSettings>
#include <QStringList>

class Config : public QObject
{
    Q_OBJECT
public:
    static Config& getInstance();
    bool initialize(const QString& configPath);

    // 软件配置相关
    QStringList getSoftwareList() const;
    QString getSoftwarePath(const QString& name) const;
    QString getSoftwareParams(const QString& name) const;
    void setSoftwarePath(const QString& name, const QString& path);
    void setSoftwareParams(const QString& name, const QString& params);
    void removeSoftware(const QString& name);

    // 数据路径配置
    QString getBasicDataPath() const;
    QString getCDDataPath() const;
    void setBasicDataPath(const QString& path);
    void setCDDataPath(const QString& path);

    // 其他通用配置
    QVariant getValue(const QString& key, const QVariant& defaultValue = QVariant()) const;
    void setValue(const QString& key, const QVariant& value);

private:
    Config(QObject* parent = nullptr);
    ~Config();
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

    void initDefaultConfig();

    QSettings* m_settings;
}; 