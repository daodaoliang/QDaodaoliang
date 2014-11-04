#include "qcomputerinfo.h"
#include "getdiskinfo.h"

QComputerInfo::QComputerInfo(QObject *parent):
    QObject(parent)
{
}

QString QComputerInfo::getMAC(bool &param_bool)
{
    foreach (QNetworkInterface temp_mac_info, QNetworkInterface::allInterfaces()) {
        if(!temp_mac_info.hardwareAddress().isEmpty()){
            param_bool = true;
            return temp_mac_info.hardwareAddress();
        }
    }
    param_bool = false;
    return QString("00:00:00:00:00:00");
}

QString QComputerInfo::getVolumeSerialNumber(bool &param_bool)
{
    QString lpRootPathName = "C:\\";
    LPTSTR lpVolumeNameBuffer = new TCHAR[12];
    DWORD nVolumeNameSize=12;
    DWORD VolumeSerialNumber;
    DWORD MaximumComponentLength;
    LPTSTR lpFileSystemNameBuffer = new TCHAR[10];
    DWORD nFileSystemNameSize=10;
    DWORD FileSystemFlags;
    GetVolumeInformation((LPTSTR)lpRootPathName.utf16(),
                         lpVolumeNameBuffer, nVolumeNameSize,
                         &VolumeSerialNumber, &MaximumComponentLength,
                         &FileSystemFlags,
                         lpFileSystemNameBuffer, nFileSystemNameSize);
    param_bool = true;
    return QString::number(VolumeSerialNumber,16);
}

QString QComputerInfo::getHardDiskSerialNumber(bool &param_bool)
{
    QLibrary tempLib("./getdiskinfo.dll");
    typedef diskInfo (*getDiskInfo)();
    getDiskInfo myFunction = (getDiskInfo) tempLib.resolve("getDiskInfo");
    if(myFunction){
        param_bool = true;
        return QString(myFunction().serialNumber).trimmed();
    }
    param_bool = false;
    return "";
}

QString QComputerInfo::getCPUCount(bool &param_bool)
{
    //备用(2014年11月3日--daodaoliang)
    //systemInfo.dwActiveProcessorMask ---处理器掩码
    //systemInfo.dwNumberOfProcessors ---处理器个数
    //systemInfo.dwPageSize ---处理器分页大小
    //systemInfo.dwProcessorType ---处理器类型
    //systemInfo.lpMaximumApplicationAddress ---最大寻址单元
    //systemInfo.lpMinimumApplicationAddress ---最小寻址单元
    //systemInfo.wProcessorLevel ---处理器等级
    //systemInfo.wProcessorRevision ---处理器版本

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    param_bool = true;
    return QString::number(systemInfo.dwNumberOfProcessors);
}

QString QComputerInfo::getSysVersion(bool &param_bool)
{
    return QString::number((int)QSysInfo::windowsVersion(),16);
}

bool QComputerInfo::getDiskSize(int &param_total, int &param_available)
{
    long long freeBytesAvail=0,totalBytes=0,freeBytes=0;
    bool result_flag;
    result_flag=GetDiskFreeSpaceEx((LPCWSTR)QString("C:").utf16(),(PULARGE_INTEGER)&freeBytesAvail,
                                   (PULARGE_INTEGER)&totalBytes,(PULARGE_INTEGER)&freeBytes);
    if(result_flag)
    {
        param_total = totalBytes/(1024*1024);
        param_available = freeBytesAvail/(1024*1024);
        return true;
    } else {
        param_total = -1;
        param_available = -1;
        return false;
    }
}
