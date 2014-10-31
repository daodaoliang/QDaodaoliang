#ifndef QBASICFORMFADEWIDGET_H
#define QBASICFORMFADEWIDGET_H

#include <QWidget>
#include "qbaseuikit_global.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "qbasicformmoveablewidget.h"

/*!
 * \brief The QBasicFormFadeWidget class
 *  淡入淡出的widget基类
 */

class QBASEUIKITSHARED_EXPORT QBasicFormFadeWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ getopacity WRITE setopacity NOTIFY opacityChanged)

public:
    explicit QBasicFormFadeWidget(QWidget *parent = 0);

signals:
    void opacityChanged(qreal param_opacity);

public:
    /*!
     * \brief beginFadeShow
     *  开始渐入效果
     */
    void beginFadeShow(quint32 param_seconds);

    /*!
     * \brief setopacity
     *  设置透明度
     * \param param_opacity
     *  透明度值
     */
    void setopacity(qreal param_opacity);

    /*!
     * \brief getopacity
     *  获取透明度
     * \return
     *  透明度值
     */
    qreal getopacity();

private:
    qreal opacity_;
    QPropertyAnimation *show_animation_;
};

#endif // QBASICFORMFADEWIDGET_H
