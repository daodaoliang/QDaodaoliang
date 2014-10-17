#include "qbasicformmoveablewidget.h"
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>

QBasicFormMoveableWidget::QBasicFormMoveableWidget(QWidget *parent) :
    QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
}

void QBasicFormMoveableWidget::mousePressEvent(QMouseEvent *event)
{
    _pressed = true;
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void QBasicFormMoveableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!this->hasFocus()){
        this->setFocus();
        return;
    }
    if (_pressed == true)
    {
        QPoint p = event->globalPos() - this->dPos;
        this->move(p);
    }
    else
    {
        event->ignore();
    }
}

void QBasicFormMoveableWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    _pressed = false;
}

void QBasicFormMoveableWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
