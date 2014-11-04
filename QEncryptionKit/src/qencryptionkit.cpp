#include "qencryptionkit.h"


QEncryptionKit::QEncryptionKit(QObject *parent):
    QObject(parent)
{
}

QString QEncryptionKit::getMD5Harsh(const QString &param_data)
{
    return QCryptographicHash::hash(param_data.toLocal8Bit(),QCryptographicHash::Md5);
}

QString QEncryptionKit::getSHA1Harsh(const QString &param_data)
{
    return QCryptographicHash::hash(param_data.toLocal8Bit(),QCryptographicHash::Sha1);
}
