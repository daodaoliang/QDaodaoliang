#ifndef QENCRYPTIONKIT_H
#define QENCRYPTIONKIT_H

#include "qencryptionkit_global.h"
#include <QObject>
#include <QCryptographicHash>

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

};

#endif // QENCRYPTIONKIT_H
