#include "miniiconwidgetdemo.h"
#include "ui_miniiconwidgetdemo.h"
#include <QTimer>

MiniIconWidgetDemo::MiniIconWidgetDemo(QWidget *parent) :
    QWidget(parent),m_shadow(":/image/window_shadow.png"),
    ui(new Ui::MiniIconWidgetDemo)
{
    ui->setupUi(this);
    mMinIconWidget = new QBasicFormMinIconWidget;
    mMinIconWidget->setPixmap(QPixmap(":/image/icon_sun.png"));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
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

void MiniIconWidgetDemo::paintEvent(QPaintEvent *e)
{
    //drawShadowPlanA();
    drawShadowPlanB();
    QWidget::paintEvent(e);
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

void MiniIconWidgetDemo::drawShadowPlanA()
{
    //画阴影边框方案[A]
    QPainter painter(this);
    //source
    QRect bottom(5, 136, 200, 7);
    QRect top(5, 0, 200, 3);
    QRect left(0, 3, 5, 133);
    QRect right(205, 3, 5, 133);
    QRect topRight(205, 0, 5, 3);
    QRect topLeft(0, 0, 5, 3);
    QRect bottomLeft(0, 136, 5, 7);
    QRect bottomRight(205, 136, 5, 7);
    //target
    QRect tBottom(5, this->height() - 7, this->width() - 10, 7);
    QRect tTop(5, 0, this->width() - 10, 3);
    QRect tLeft(0, 3, 5, this->height() - 10);
    QRect tRight(this->width() - 5, 3, 5, this->height() - 10);
    QRect tTopLeft(0, 0, 5, 3);
    QRect tTopRight(this->width() - 5, 0, 5, 3);
    QRect tBottomLeft(0, this->height() - 7, 5, 7);
    QRect tBottomRight(this->width() - 5, this->height() - 7, 5, 7);

    painter.drawPixmap(tBottom, m_shadow, bottom);
    painter.drawPixmap(tTop, m_shadow, top);
    painter.drawPixmap(tLeft, m_shadow, left);
    painter.drawPixmap(tRight, m_shadow, right);
    painter.drawPixmap(tTopRight, m_shadow, topRight);
    painter.drawPixmap(tTopLeft, m_shadow, topLeft);
    painter.drawPixmap(tBottomLeft, m_shadow, bottomLeft);
    painter.drawPixmap(tBottomRight, m_shadow, bottomRight);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRoundedRect(QRect(18,18,this->width() - 36,this->height() - 36),2.0f,2.0f);
}

void MiniIconWidgetDemo::drawShadowPlanB()
{
    //画阴影边框方案[B]
    QPainter painter(this);
    QList<QPixmap> pixmaps;
    pixmaps.append(QPixmap(":/image/shadow_left.png"));
    pixmaps.append(QPixmap(":/image/shadow_right.png"));
    pixmaps.append(QPixmap(":/image/shadow_top.png"));
    pixmaps.append(QPixmap(":/image/shadow_bottom.png"));
    pixmaps.append(QPixmap(":/image/shadow_corner1.png"));
    pixmaps.append(QPixmap(":/image/shadow_corner2.png"));
    pixmaps.append(QPixmap(":/image/shadow_corner3.png"));
    pixmaps.append(QPixmap(":/image/shadow_corner4.png"));
    painter.drawPixmap(0,0,20,20,pixmaps[4]);
    painter.drawPixmap(this->width() - 20,0,20,20,pixmaps[5]);
    painter.drawPixmap(0,this->height() - 20,20,20,pixmaps[6]);
    painter.drawPixmap(this->width() - 20,this->height() - 20,20,20,pixmaps[7]);
    painter.drawPixmap(0,20,20,this->height() - 40,pixmaps[0].scaled(20,this->height() - 40));
    painter.drawPixmap(this->width() - 20,20,20,this->height() - 40,pixmaps[1].scaled(20,this->height() - 40));
    painter.drawPixmap(20,0,this->width() - 40,20,pixmaps[2].scaled(this->width() - 40,20));
    painter.drawPixmap(20,this->height() - 20,this->width() - 40,20,pixmaps[3].scaled(this->width() - 40,20));
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRoundedRect(QRect(18,18,this->width() - 36,this->height() - 36),2.0f,2.0f);
}
