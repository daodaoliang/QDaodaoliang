#include "qbasicformsnowlabel.h"

QBasicFormSnowLabel::QBasicFormSnowLabel(QWidget *parent) :
    QLabel(parent)
{
}

void QBasicFormSnowLabel::paintEvent(QPaintEvent *event)
{
    QPainter tempPainter(this);
    tempPainter.setPen(Qt::red);
    tempPainter.setBrush(Qt::red);
    tempPainter.setFont(QFont("微软雅黑", 12, QFont::Bold));
    if(alignment() == (Qt::AlignHCenter|Qt::AlignVCenter)){
        tempPainter.drawText((width() - fontMetrics().width(text()))/2-10,this->contentsRect().height()/2-8,8,8,Qt::AlignCenter,"*");
    } else if(alignment() == (Qt::AlignRight|Qt::AlignVCenter)){
        tempPainter.drawText((width() - fontMetrics().width(text()))-10,this->contentsRect().height()/2-8,8,8,Qt::AlignCenter,"*");
    }
    QLabel::paintEvent(event);
}
