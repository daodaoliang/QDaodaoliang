#ifndef QBASICFORMMINICONWIDGET_H
#define QBASICFORMMINICONWIDGET_H
#include "qbaseuikit_global.h"
#include <QWidget>
#include "qbasicformmoveablewidget.h"

/*!
 * \brief The QBasicFormMinIconWidget class
 *  程序悬浮mini窗体
 */
class QBASEUIKITSHARED_EXPORT QBasicFormMinIconWidget : public QBasicFormMoveableWidget
{
    Q_OBJECT
    
signals:
    void signalMiniIconClicked();

public:
    explicit QBasicFormMinIconWidget(QWidget *parent = 0);
    ~QBasicFormMinIconWidget();

public:
    /*!
     * \brief setPixmap
     *  设置窗体背景,并实时刷新
     * \param pixmap
     *  背景图片资源
     */
    void setPixmap(const QPixmap &pixmap);

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    QPixmap m_Pixmap;
};

#endif // QBASICFORMMINICONWIDGET_H
