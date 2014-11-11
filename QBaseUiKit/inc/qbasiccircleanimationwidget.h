#ifndef CIRCLEANIMATIONWIDGET_H
#define CIRCLEANIMATIONWIDGET_H

#include <QWidget>
#include "qbaseuikit_global.h"
#define PI  3.1415

class QPropertyAnimation;

class QBASEUIKITSHARED_EXPORT QBasicCircleAnimationWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal percent READ percent WRITE setPercent)

public:
    explicit QBasicCircleAnimationWidget(QWidget *parent = 0);
    explicit QBasicCircleAnimationWidget(const QString &icon,const qreal &radius, QWidget *parent = 0);
    void setCircleInfo(const QString &icon, const qreal &radius);
    void startAnimation();
    void stopAnimation();
    void setPercent(const qreal &per);
    const qreal &percent(){return m_percent;}

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void updatePos();

private:
    QPoint mathPoint();
    QPoint mathPoint(const QPoint &centerPos, const qreal &percent, const qreal &radius);
    void initAnimation();

private:
    qreal m_percent;
    qreal m_radius;
    QPoint m_centerPos;

    QPropertyAnimation *m_percentAnimation;
    QPixmap m_pix;
    QPoint m_point;
    QPoint m_originPoint;
};


#endif // CIRCLEANIMATIONWIDGET_H
