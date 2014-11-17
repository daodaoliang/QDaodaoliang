#include "formfadewidgetdemo.h"
#include "ui_formfadewidgetdemo.h"
#include <QPainter>

FormFadeWidgetDemo::FormFadeWidgetDemo(QBasicFormFadeWidget *parent) :
    QBasicFormFadeWidget(parent),m_shadow(":/image/window_shadow.png"),
    ui(new Ui::FormFadeWidgetDemo)
{
    ui->setupUi(this);
    ui->label_4->setText(m_encryption_instance.getMD5Harsh(ui->label_2->text()));
    setAttribute(Qt::WA_TranslucentBackground);
}

FormFadeWidgetDemo::~FormFadeWidgetDemo()
{
    delete ui;
}

void FormFadeWidgetDemo::on_pushButton_clicked()
{
    close();
}

void FormFadeWidgetDemo::paintEvent(QPaintEvent *e)
{
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
}

void FormFadeWidgetDemo::showEvent(QShowEvent *e)
{
    repaint();
}
