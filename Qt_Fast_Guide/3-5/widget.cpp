#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QObject::connect(ui->showChildButton,SIGNAL(clicked()),
//            this,SLOT(showChildDialog()));
}

Widget::~Widget()
{
    delete ui;
}

//以这种命名方式----自动关联 （ on_发射信号的部件对象名_信号名)
//必须使用qt部件已经提供的信号
void Widget::on_showChildButton_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}
