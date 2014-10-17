#include "qbasicformminiconwidget.h"
#include <QPainter>

QBasicFormMinIconWidget::QBasicFormMinIconWidget(QWidget *parent) :
    QBasicFormMoveableWidget(parent)
{
    setWindowFlags( Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool );
    setAttribute(Qt::WA_TranslucentBackground, true);
    setFocusPolicy(Qt::NoFocus);
}

QBasicFormMinIconWidget::~QBasicFormMinIconWidget()
{
}

void QBasicFormMinIconWidget::setPixmap(const QPixmap &pixmap)
{
    m_Pixmap = pixmap;
    update();
}

void QBasicFormMinIconWidget::enterEvent(QEvent *event)
{
    setCursor(Qt::PointingHandCursor);
    QBasicFormMoveableWidget::enterEvent(event);
}

void QBasicFormMinIconWidget::leaveEvent(QEvent *event)
{
    setCursor(Qt::ArrowCursor);
    QBasicFormMoveableWidget::leaveEvent(event);
}

void QBasicFormMinIconWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_Pixmap);
    QBasicFormMoveableWidget::paintEvent(event);
}

void QBasicFormMinIconWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit signalMiniIconClicked();
    QBasicFormMoveableWidget::mouseDoubleClickEvent(event);
}
