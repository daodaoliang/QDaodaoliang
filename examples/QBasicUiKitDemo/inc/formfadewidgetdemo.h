#ifndef FORMFADEWIDGETDEMO_H
#define FORMFADEWIDGETDEMO_H

#include <QWidget>
#include "qbasicformfadewidget.h"
#include "qencryptionkit.h"

namespace Ui {
class FormFadeWidgetDemo;
}

class FormFadeWidgetDemo : public QBasicFormFadeWidget
{
    Q_OBJECT
    
public:
    explicit FormFadeWidgetDemo(QBasicFormFadeWidget *parent = 0);
    ~FormFadeWidgetDemo();
    
private slots:
    void on_pushButton_clicked();

protected:
    void paintEvent(QPaintEvent *e);
    void showEvent(QShowEvent *e);

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
    Ui::FormFadeWidgetDemo *ui;
    QEncryptionKit m_encryption_instance;
    QPixmap m_shadow;
};

#endif // FORMFADEWIDGETDEMO_H
