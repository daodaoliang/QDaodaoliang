#ifndef POPDIALOGDEMO_H
#define POPDIALOGDEMO_H

#include <QDialog>
#include "qbasicformpopdialog.h"
#include "qbasicformmoveablewidget.h"

namespace Ui {
class PopDialogDemo;
}

class PopDialogDemo : public PopDialog
{
    Q_OBJECT
    
public:
    explicit PopDialogDemo(QWidget *parent = 0);
    ~PopDialogDemo();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::PopDialogDemo *ui;
};

#endif // POPDIALOGDEMO_H
