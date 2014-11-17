#ifndef QCOMMONKIT_H
#define QCOMMONKIT_H

#include "qcommonkit_global.h"
#include <QObject>

/*!
 * \brief The QCommonKit class
 *  公共函数库
 */
class QCOMMONKITSHARED_EXPORT QCommonKit:public QObject
{

public:
    explicit QCommonKit(QObject *parent = NULL);

public:
    /*!
     * \brief GetFirstLetter
     *  获取字符串(包含汉字)的首字母
     * \param strName
     *  字符串内容
     * \param result
     *  字符串首字母或者汉字拼音首字母
     */
    void GetFirstLetter(const QByteArray &strName, QString &result);
};

#endif // QCOMMONKIT_H
