#ifndef QBASICFORMMOVEABLEWIDGET_H
#define QBASICFORMMOVEABLEWIDGET_H

#include "qbaseuikit_global.h"
#include <QWidget>

/*!
 * \brief The QBasicFormMoveableWidget class
 *  可以移动的窗体
 */
class QBASEUIKITSHARED_EXPORT QBasicFormMoveableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QBasicFormMoveableWidget(QWidget *parent = 0);
    
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    bool _pressed;
};

#endif // QBASICFORMMOVEABLEWIDGET_H
