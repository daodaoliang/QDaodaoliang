#include "formfadewidgetdemo.h"
#include "ui_formfadewidgetdemo.h"

FormFadeWidgetDemo::FormFadeWidgetDemo(QBasicFormFadeWidget *parent) :
    QBasicFormFadeWidget(parent),
    ui(new Ui::FormFadeWidgetDemo)
{
    ui->setupUi(this);
}

FormFadeWidgetDemo::~FormFadeWidgetDemo()
{
    delete ui;
}
