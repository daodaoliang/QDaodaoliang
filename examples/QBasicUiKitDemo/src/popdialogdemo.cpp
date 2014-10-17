#include "popdialogdemo.h"
#include "ui_popdialogdemo.h"

PopDialogDemo::PopDialogDemo(QWidget *parent) :
    PopDialog(parent),
    ui(new Ui::PopDialogDemo)
{
    ui->setupUi(this);
}

PopDialogDemo::~PopDialogDemo()
{
    delete ui;
}

void PopDialogDemo::on_pushButton_clicked()
{
    pausePopDialog();
}
