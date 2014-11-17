#ifndef POPDIALOGDEMO_H
#define POPDIALOGDEMO_H

#include <QDialog>
#include <QPixmap>
#include <QPainter>
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

protected:
    void paintEvent(QPaintEvent *e);
    void showEvent(QShowEvent *e);

private:
    Ui::PopDialogDemo *ui;
    QPixmap m_shadow;
};

#endif // POPDIALOGDEMO_H
