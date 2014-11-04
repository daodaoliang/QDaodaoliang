#include "qencryptionkit.h"


QEncryptionKit::QEncryptionKit(QObject *parent):
    QObject(parent)
{
}

QString QEncryptionKit::getMD5Harsh(const QString &param_data)
{
    return QString(QCryptographicHash::hash(param_data.toLocal8Bit(),QCryptographicHash::Md5).toHex());
}

QString QEncryptionKit::getSHA1Harsh(const QString &param_data)
{
    return QString(QCryptographicHash::hash(param_data.toLocal8Bit(),QCryptographicHash::Sha1).toHex());
}

bool QEncryptionKit::stringByKaiser(QString &param_data, quint8 param_key)
{
    if(param_data.isEmpty()){
        return false;
    }
    for(int temp_index = 0; temp_index != param_data.size();++temp_index){
        char tempChar = param_data.at(temp_index).toAscii();
        if(tempChar >= 0x30 && tempChar <= 0x39){
            tempChar = (tempChar - '0' + param_key) % 10 + '0';
        } else if (tempChar >= 0x41 && tempChar <= 0x5a) {
            tempChar = (tempChar - 'A' + param_key) % 26 + 'A';
        } else if (tempChar >= 0x61 && tempChar <= 0x7a) {
            tempChar = (tempChar - 'a' + param_key) % 10 + 'a';
        }
        param_data[temp_index] = QChar(tempChar);
    }
    return true;
}
