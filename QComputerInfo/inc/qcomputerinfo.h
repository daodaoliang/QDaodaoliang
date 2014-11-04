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
#include <QSysInfo>

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
     *  获取C磁盘序列号
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

    /*!
     * \brief getCPUCount
     *  获取CPU个数
     * \param
     *  是否获取成功
     * \return
     *  CPU个数
     */
    QString getCPUCount(bool &param_bool);

    /*!
     * \brief getSysVersion
     *  获取系统版本
     * \param param_bool
     *  是否获取成功
     * \return
     *  系统版本
     */
    QString getSysVersion(bool &param_bool);

    /*!
     * \brief getDiskSize
     *  获取系统硬盘容量
     * \param param_total
     *  总容量
     * \param param_available
     *  可用容量
     * \return
     *  是否获取成功
     */
    bool getDiskSize(int &param_total,int &param_available);
};

#endif // QCOMPUTERINFO_H
