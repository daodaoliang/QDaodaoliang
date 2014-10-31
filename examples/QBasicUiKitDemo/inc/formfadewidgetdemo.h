#ifndef FORMFADEWIDGETDEMO_H
#define FORMFADEWIDGETDEMO_H

#include <QWidget>
#include "qbasicformfadewidget.h"

namespace Ui {
class FormFadeWidgetDemo;
}

class FormFadeWidgetDemo : public QBasicFormFadeWidget
{
    Q_OBJECT
    
public:
    explicit FormFadeWidgetDemo(QBasicFormFadeWidget *parent = 0);
    ~FormFadeWidgetDemo();
    
private:
    Ui::FormFadeWidgetDemo *ui;
};

#endif // FORMFADEWIDGETDEMO_H
