#ifndef MINIICONWIDGETDEMO_H
#define MINIICONWIDGETDEMO_H

#include <QWidget>
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

public slots:
    void showMiniDemoWindow();
    void hideMiniDemoWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MiniIconWidgetDemo *ui;
    QBasicFormMinIconWidget *mMinIconWidget;
};

#endif // MINIICONWIDGETDEMO_H
