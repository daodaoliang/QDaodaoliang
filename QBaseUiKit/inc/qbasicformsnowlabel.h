#ifndef QBASICFORMSNOWLABEL_H
#define QBASICFORMSNOWLABEL_H

#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include "qbaseuikit_global.h"

/*!
 * \brief The QBasicFormSnowLabel class
 *  在QLabel里面的文字内容前方重绘出一个红色的星号
 */

class QBASEUIKITSHARED_EXPORT QBasicFormSnowLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QBasicFormSnowLabel(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // QBASICFORMSNOWLABEL_H
