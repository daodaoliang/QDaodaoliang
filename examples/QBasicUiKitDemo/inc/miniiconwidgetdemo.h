#ifndef MINIICONWIDGETDEMO_H
#define MINIICONWIDGETDEMO_H

#include <QWidget>
#include <QPainter>
#include "qbasicformminiconwidget.h"

namespace Ui {
class MiniIconWidgetDemo;
}

/*!
 * \brief The MiniIconWidgetDemo class
 *  迷你Widget程序小样
 */
class MiniIconWidgetDemo : public QWidget
{
    Q_OBJECT
    
public:
    explicit MiniIconWidgetDemo(QWidget *parent = 0);
    ~MiniIconWidgetDemo();
    
protected:
    void changeEvent(QEvent *event);
    void paintEvent(QPaintEvent *e);

public slots:
    void showMiniDemoWindow();
    void hideMiniDemoWindow();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    /*!
     * \brief drawShadowPlanA
     *  画边框阴影方案A
     */
    void drawShadowPlanA();

    /*!
     * \brief drawShadowPlanA
     *  画边框阴影方案B
     */
    void drawShadowPlanB();

private:
    Ui::MiniIconWidgetDemo *ui;
    QBasicFormMinIconWidget *mMinIconWidget;
    QPixmap m_shadow;
};

#endif // MINIICONWIDGETDEMO_H
