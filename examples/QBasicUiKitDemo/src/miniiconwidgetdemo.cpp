#include "miniiconwidgetdemo.h"
#include "ui_miniiconwidgetdemo.h"
#include <QTimer>

MiniIconWidgetDemo::MiniIconWidgetDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniIconWidgetDemo)
{
    ui->setupUi(this);
    mMinIconWidget = new QBasicFormMinIconWidget;
    mMinIconWidget->setPixmap(QPixmap(":/image/icon_sun.png"));
    setWindowFlags(Qt::WindowStaysOnTopHint);
    connect(mMinIconWidget,SIGNAL(signalMiniIconClicked()),this,SLOT(showMiniDemoWindow()));
    ui->widget->setCircleInfo(":/image/icon_sun.png",5);
}

MiniIconWidgetDemo::~MiniIconWidgetDemo()
{
    delete ui;
}

void MiniIconWidgetDemo::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange){
        if(windowState() & Qt::WindowMinimized){
            QTimer::singleShot(0,this,SLOT(hideMiniDemoWindow()));
        } else if (windowState() & Qt::WindowNoState) {
            QTimer::singleShot(0,this,SLOT(showMiniDemoWindow()));
        }
    }
    QWidget::changeEvent(event);
}

void MiniIconWidgetDemo::showMiniDemoWindow()
{
    mMinIconWidget->hide();
    move(mMinIconWidget->pos());
    show();
    setWindowState(Qt::WindowNoState);
}

void MiniIconWidgetDemo::hideMiniDemoWindow()
{
    hide();
    mMinIconWidget->move(pos());
    mMinIconWidget->show();
    setWindowState(Qt::WindowMinimized);
}

void MiniIconWidgetDemo::on_pushButton_2_clicked()
{
    ui->stackedWidget->rotate(1);
    ui->widget->stopAnimation();
    ui->widget->startAnimation();
}

void MiniIconWidgetDemo::on_pushButton_clicked()
{
    ui->stackedWidget->rotate(0);
    ui->widget->stopAnimation();
    ui->widget->startAnimation();
}
