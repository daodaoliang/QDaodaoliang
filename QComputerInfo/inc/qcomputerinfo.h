#ifndef QCOMPUTERINFO_H
#define QCOMPUTERINFO_H

#include "qcomputerinfo_global.h"
#include <QObject>
#include <Windows.h>
#include <WinIoCtl.h>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QLibrary>

/*!
 * \brief The QComputerInfo class
 *  获取系统软硬件信息
 */

class QCOMPUTERINFOSHARED_EXPORT QComputerInfo: public QObject
{
    Q_OBJECT

public:
    explicit QComputerInfo(QObject *parent = NULL);

public:
    /*!
     * \brief getMAC
     *  获取电脑的MAC地址
     *  (默认获取第一个不为空的MAC)
     * \param
     *  是否获取成功(输出参数)
     * \return
     *  MAC地址串
     */
    QString getMAC(bool &param_bool);

    /*!
     * \brief getVolumeSerialNumber
     *  获取磁盘序列号
     * \param param_bool
     *  是否获取成功
     * \return
     *  磁盘序列号
     */
    QString getVolumeSerialNumber(bool &param_bool);

    /*!
     * \brief getHardDiskSerialNumber
     *  获取硬盘序列号
     * \param param_bool
     *  是否获取成功
     * \return
     *  硬盘序列号
     */
    QString getHardDiskSerialNumber(bool &param_bool);
};

#endif // QCOMPUTERINFO_H
