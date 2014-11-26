#ifndef QBASICFORMMOVEABLEWIDGET_H
#define QBASICFORMMOVEABLEWIDGET_H

#include "qbaseuikit_global.h"
#include <QWidget>
#include <QPoint>
#include <QCursor>
#include <QRect>

/*接受边框处理的宽度*/
#define PADDING 2

/*!
 * \brief The QBasicFormMoveableWidget class
 *  可以拖动大小、可移动的窗体
 */

/*!
 * \brief The Direction enum
 *  鼠标方向
 */
enum Direction{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    LEFTTOP,
    LEFTBOTTOM,
    RIGHTBOTTOM,
    RIGHTTOP,
    NONE
};

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
    void region(const QPoint &cursorGlobalPoint);

private:
    bool isLeftPressDown;
    QPoint dragPosition;
    Direction dir;
};

#endif // QBASICFORMMOVEABLEWIDGET_H
