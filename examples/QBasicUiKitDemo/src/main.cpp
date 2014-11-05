#include "popdialogdemo.h"
#include <QApplication>
#include <QDebug>
#include <QDir>
#include "qtsingleapplication.h"
#include "mini_dump.h"
#include "BreakpadHandler.h"
#include "miniiconwidgetdemo.h"
#include "formfadewidgetdemo.h"

int main(int argc, char *argv[])
{
    //crashDump 方案[1]
    //    QApplication app(argc, argv);
    //    BreakpadQt::GlobalHandler *handler = BreakpadQt::GlobalHandler::instance();
    //    handler->setDumpPath(qApp->applicationDirPath());
    //    qDebug()<<QDir::tempPath();
    //MiniDump 方案[2]
    QtSingleApplication app("daodaoliang",argc, argv);
    MiniDumper::Instance().Install();
    if(app.sendMessage("Hi I am daodaoliang~")){
        qDebug()<<"daodaoliang";
        return 0;
    }
    //PopDemo
    PopDialogDemo demoPopDialog;
    demoPopDialog.showPopDialog(5);
    //miniWidgetDemo
    MiniIconWidgetDemo demoMiniWidget;
    demoMiniWidget.setGeometry(0,30,400,300);
    demoMiniWidget.show();
    //fadewidgetDemo
    FormFadeWidgetDemo demoFadeWidget;
    demoFadeWidget.setGeometry(400,30,400,300);
    demoFadeWidget.beginFadeShow(3);
    //QEncryptionKit
    QEncryptionKit demoEncryptionKit;
    QString tempStr("IMISSYOU");
    qDebug()<<"string:"<<tempStr;
    demoEncryptionKit.stringByKaiser(tempStr,-2);
    qDebug()<<"Kaiser encode:"<<tempStr;
    demoEncryptionKit.stringByKaiser(tempStr,2);
    qDebug()<<"Kaiser dncode:"<<tempStr;
    tempStr = demoEncryptionKit.stringDESEncode(tempStr,"12345678");
    qDebug()<<"DES encode:"<<tempStr;
    tempStr = demoEncryptionKit.stringDESDecode(tempStr,"12345678");
    qDebug()<<"DES dncode:"<<tempStr;
    //MiniDump 方案[2]
    app.setActivationWindow(&demoPopDialog);
    //崩溃测试
    //    int *tempTest = NULL;
    //    qMemCopy(tempTest,0,100);
    return app.exec();
}
