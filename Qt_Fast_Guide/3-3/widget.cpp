#include "widget.h"
#include "ui_widget.h"

//for QDialog
#include <QDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //一下不会消失
//    QDialog dialog(this);
//    dialog.show();

    //以下也会消失
    QDialog *dialog = new QDialog(this);
    dialog->show();

}

Widget::~Widget()
{
    delete ui;
}
