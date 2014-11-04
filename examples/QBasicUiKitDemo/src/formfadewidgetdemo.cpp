#include "formfadewidgetdemo.h"
#include "ui_formfadewidgetdemo.h"

FormFadeWidgetDemo::FormFadeWidgetDemo(QBasicFormFadeWidget *parent) :
    QBasicFormFadeWidget(parent),
    ui(new Ui::FormFadeWidgetDemo)
{
    ui->setupUi(this);
    ui->label_4->setText(m_encryption_instance.getMD5Harsh(ui->label_2->text()));
}

FormFadeWidgetDemo::~FormFadeWidgetDemo()
{
    delete ui;
}

void FormFadeWidgetDemo::on_pushButton_clicked()
{
    close();
}
