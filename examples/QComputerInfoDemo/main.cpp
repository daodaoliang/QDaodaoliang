#include <QCoreApplication>
#include "qcomputerinfo.h"

#pragma comment(lib,"./../../daodaoliang/bin/QComputerInfo.lib")

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QComputerInfo temp_computer_info;
    bool flag = false;
    qDebug()<<"MAC:"<<temp_computer_info.getMAC(flag);
    qDebug()<<"MAC get result:"<<flag;
    qDebug()<<"VolumeSerialNumber:"<<temp_computer_info.getVolumeSerialNumber(flag);
    qDebug()<<"VolumeSerialNumber get result:"<<flag;
    qDebug()<<"HardDiskSerialNumber:"<<temp_computer_info.getHardDiskSerialNumber(flag);
    qDebug()<<"HardDiskSerialNumber get result:"<<flag;
    qDebug()<<"NumberOfProcessors:"<<temp_computer_info.getCPUCount(flag);
    qDebug()<<"NumberOfProcessors get result:"<<flag;
    qDebug()<<"SysVersion :"<<temp_computer_info.getSysVersion(flag);
    qDebug()<<"SysVersion get result:"<<flag;
    int m_total_size , m_available = 0;
    qDebug()<<"Disksize get result:"<<temp_computer_info.getDiskSize(m_total_size,m_available);
    qDebug()<<"Disksize  :"<<"m_total_size:"<<m_total_size<<" m_available:"<<m_available;
    return a.exec();
}
