#ifndef WIDGET1_H
#define WIDGET1_H

#include <QVariant>
#include <QWidget>
#include <QLabel>
#include <QStackedWidget>
#include "qbaseuikit_global.h"
/*!
 * \brief The QBasicRotatingStackedWidget class
 *  堆栈页基础动画组件
 */
class QBASEUIKITSHARED_EXPORT QBasicRotatingStackedWidget : public QStackedWidget
{
    Q_OBJECT
    Q_PROPERTY( float rotateVal READ rotateVal WRITE setRotateVal)

public:
    explicit QBasicRotatingStackedWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void rotate(int);
    float rotateVal();
    void setRotateVal(float);

private slots:
    void valChanged(QVariant);
    void animDone();

private:
    float iRotateVal;
    bool isAnimating;
    int nextIndex;
};

#endif // WIDGET1_H
