#ifndef QENCRYPTIONKIT_H
#define QENCRYPTIONKIT_H

#include "qencryptionkit_global.h"
#include <QObject>
#include <QCryptographicHash>
#include "qdesencode.h"

/*!
 * \brief The QEncryptionKit class
 *  加解密、数据摘要、数据校验等统一接口
 */

class QENCRYPTIONKITSHARED_EXPORT QEncryptionKit: public QObject
{
    
public:
    explicit QEncryptionKit(QObject *parent = NULL);

public:
    /*!
     * \brief getMD5Harsh
     *  获取字符串的MD5散列值
     * \param param_data
     *  待转换的数据
     * \return
     *  散列值
     */
    QString getMD5Harsh(const QString &param_data);

    /*!
     * \brief getSHA1Harsh
     *  获取字符串的SHA1散列值
     * \param param_data
     *  待转换的数据
     * \return
     *  散列值
     */
    QString getSHA1Harsh(const QString &param_data);

    /*!
     * \brief stringByKaiser
     *  采用凯撒加解密方式加密字符串
     * \param param_data
     *  原始数据
     * \param param_key
     *  加密密钥
     * \return
     */
    bool stringByKaiser(QString &param_data,qint8 param_key);

    /*!
     * \brief stringDES
     *  采用DES加密方式加密字符串(长度为8)
     * \param param_data
     *  原始数据
     * \param param_key
     *  密钥
     * \return
     *  密文
     */
    QString stringDESEncode(const QString &param_data,const QString &param_key);

    /*!
     * \brief stringDESDecode
     *  采用DES加密方式解密字符串(长度为8)
     * \param param_data
     *  加密字符串
     * \param param_key
     *  密钥
     * \return
     *  明文
     */
    QString stringDESDecode(const QString &param_data,const QString &param_key);
};

#endif // QENCRYPTIONKIT_H
