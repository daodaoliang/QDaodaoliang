#include "qbasicrotatingstackedwidget.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QPainter>
#include <QTransform>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QDebug>

QBasicRotatingStackedWidget::QBasicRotatingStackedWidget(QWidget *parent) :
    QStackedWidget(parent)
{
    iRotateVal=0;
    isAnimating=false;
}

void QBasicRotatingStackedWidget::paintEvent(QPaintEvent * event)
{
    if(isAnimating)
    {
        if(iRotateVal > 90)
        {
            QPixmap pixmap(widget(nextIndex)->size());
            widget(nextIndex)->render(&pixmap);
            QPainter painter(this);

            QTransform transform;
            transform.translate(width()/2, 0);
            transform.rotate(iRotateVal+180,Qt::YAxis);
            painter.setTransform(transform);
            painter.drawPixmap(-1*width()/2,0,pixmap);
        } else {
            QPixmap pixmap(currentWidget()->size());
            currentWidget()->render(&pixmap);
            QPainter painter(this);

            QTransform transform;
            transform.translate(width()/2, 0);
            transform.rotate(iRotateVal,Qt::YAxis);
            painter.setTransform(transform);
            painter.drawPixmap(-1*width()/2,0,pixmap);
        }
    } else {
        QWidget::paintEvent(event);
    }
}

void QBasicRotatingStackedWidget::rotate(int index)
{
    if(isAnimating)
        return;
    nextIndex = index;
    int offsetx=frameRect().width();
    int offsety=frameRect().height();
    widget(index)->setGeometry ( 0,  0, offsetx, offsety );
    QPropertyAnimation *animnow = new QPropertyAnimation(this,"rotateVal");
    animnow->setDuration(500);
    animnow->setEasingCurve(QEasingCurve::Linear);
    animnow->setStartValue(0);
    animnow->setEndValue(180);
    connect(animnow,SIGNAL(valueChanged(QVariant)),this,SLOT(valChanged(QVariant)));
    connect(animnow,SIGNAL(finished()),this,SLOT(animDone()));
    currentWidget()->hide();
    isAnimating = true;
    animnow->start();;
}

float QBasicRotatingStackedWidget::rotateVal()
{
    return iRotateVal;
}

void QBasicRotatingStackedWidget::setRotateVal(float fl)
{
    iRotateVal = fl;
}

void QBasicRotatingStackedWidget::valChanged(QVariant)
{
    repaint();
}

void QBasicRotatingStackedWidget::animDone()
{
    iRotateVal=0;
    isAnimating=false;
    widget(nextIndex)->show();
    widget(nextIndex)->raise();;
    setCurrentWidget(widget(nextIndex));
    repaint();
}
