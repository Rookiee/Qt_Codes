#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->showChildButton,SIGNAL(clicked()),
            this,SLOT(showChildDialog()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}
