#ifndef POPDIALOG_H
#define POPDIALOG_H

#include "qbaseuikit_global.h"
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QPoint>
#include <QTimer>
#include "qbasicformmoveablewidget.h"

namespace Ui {
class PopDialog;
}

/*!
 * \brief The PopDialog class
 *  该类为弹出窗口,可以在右下角的桌面以弹出的效果显示
 *  显示过后停留一定的时间在消失掉,这是一个基类
 */
class QBASEUIKITSHARED_EXPORT PopDialog : public QBasicFormMoveableWidget
{
    Q_OBJECT
    
public:
    explicit PopDialog(QWidget *parent = 0);
    ~PopDialog();

public slots:
    /*!
     * \brief showPopDialog
     *  以弹出效果显示本窗口
     * \param paramRemainTime
     *  停留时间和显示时间
     */
    void showPopDialog(quint32 paramRemainTime = 6);

    /*!
     * \brief closePopDialog
     *  关闭弹出窗口
     */
    void closePopDialog();

    /*!
     * \brief pausePopDialog
     *  动画效果暂停
     */
    void pausePopDialog();

    /*!
     * \brief startPopDialog
     *  启用动画效果
     */
    void startPopDialog();

private slots:
    /*!
     * \brief closeAnimation
     *  弹出窗消失时的动画效果
     */
    void closeAnimation();

    /*!
     * \brief clearAll
     *  清除弹出框消失时的动画并关闭窗体
     */
    void clearAll();

    /*!
     * \brief showAnimation
     *  弹出框显示时的动画效果
     */
    void showAnimation();

    /*!
     * \brief animationValueChanged
     *  属性值发生改变时的槽函数
     * \param param_value
     *  属性值
     */
    void animationValueChanged(QVariant param_value);
private:
    /*!
     * \brief desktop
     *  窗体桌面信息
     */
    QDesktopWidget desktop;

    /*!
     * \brief animation
     *  当前动画指针
     */
    QPropertyAnimation* animation;

    /*!
     * \brief remainTimer
     *  出场动画和落场动画之间的时间间隔定时器
     *  即窗体停留时间间隔
     */
    QTimer *remainTimer;

    /*!
     * \brief mremainTime
     *  动画效果持续的时间
     */
    quint32 mremainTime;

    /*!
     * \brief mIsPause
        动画效果是否处于暂停
     */
    bool mIsPause;
};
#endif // POPDIALOG_H
