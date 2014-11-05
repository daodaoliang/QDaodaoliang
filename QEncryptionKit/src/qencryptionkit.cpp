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

bool QEncryptionKit::stringByKaiser(QString &param_data, qint8 param_key)
{
    if(param_data.isEmpty()){
        return false;
    }
    for(int temp_index = 0; temp_index != param_data.size();++temp_index){
        char tempChar = param_data.at(temp_index).toAscii();
        int tempValue = 0;
        if(tempChar >= 0x30 && tempChar <= 0x39){
            tempValue = (tempChar - '0' + param_key);
            tempChar = (tempValue >= 0) ? (tempValue % 10 + '0') : (tempValue % 10 + 0x3a);
        } else if (tempChar >= 0x41 && tempChar <= 0x5a) {
            tempValue = (tempChar - 'A' + param_key);
            tempChar = (tempValue >= 0) ? (tempValue % 26 + 'A') : (tempValue % 26 + 0x5b);
        } else if (tempChar >= 0x61 && tempChar <= 0x7a) {
            tempValue = (tempChar - 'a' + param_key);
            tempChar = (tempValue >= 0) ? (tempValue % 26 + 'a') : (tempValue % 26 + 0x7b);
        }
        param_data[temp_index] = QChar(tempChar);
    }
    return true;
}

QString QEncryptionKit::stringDESEncode(const QString &param_data, const QString &param_key)
{
    return EncodeMain(param_data,param_key);
}

QString QEncryptionKit::stringDESDecode(const QString &param_data, const QString &param_key)
{
    return DecodeMain(param_data,param_key);
}
