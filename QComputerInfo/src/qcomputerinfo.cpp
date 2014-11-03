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
    LPTSTR lpVolumeNameBuffer=new TCHAR[12];
    DWORD nVolumeNameSize=12;
    DWORD VolumeSerialNumber;
    DWORD MaximumComponentLength;
    LPTSTR lpFileSystemNameBuffer=new TCHAR[10];
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
