#include "qbasicformfadewidget.h"
#include <QDebug>

QBasicFormFadeWidget::QBasicFormFadeWidget(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    show_animation_ = new QPropertyAnimation(this,"opacity");
}

void QBasicFormFadeWidget::setopacity(qreal param_opacity)
{
    opacity_ = param_opacity;
    this->setWindowOpacity(param_opacity);
    qDebug()<<"param_opacity:"<<param_opacity;
    update();
    emit opacityChanged(param_opacity);
}

qreal QBasicFormFadeWidget::getopacity()
{
    return opacity_;
}


void QBasicFormFadeWidget::beginFadeShow(quint32 param_seconds)
{
    show();
    show_animation_->setDuration(param_seconds * 1000);
    show_animation_->setStartValue(0);
    show_animation_->setEndValue(0.8);
    show_animation_->start();
}
