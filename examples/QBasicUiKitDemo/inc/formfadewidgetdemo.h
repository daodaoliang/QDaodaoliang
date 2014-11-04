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

private:
    Ui::FormFadeWidgetDemo *ui;
    QEncryptionKit m_encryption_instance;
};

#endif // FORMFADEWIDGETDEMO_H
