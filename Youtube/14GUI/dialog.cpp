#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText("<b>Hello</b> Everyone");
    ui->checkBox->setChecked(true);

    for(int i = 1; i != 10; ++i) {
        ui->comboBox->addItem(QString::number(i) + " item");
    }

    for (int i=1; i!=10; ++i) {
        ui->listWidget->addItem(QString::number(i) + " item");
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QMessageBox::information(this, "Titel Here", "Hello World");
}

void Dialog::on_pushButton_2_clicked()
{
   ui->lineEdit->setText("Hell World");
    // ui->lineEdit->text() 获取输入的内容，很有用吧
    QMessageBox::information(this,"Title",ui->lineEdit->text());

}

void Dialog::on_pushButton_3_clicked()
{
   if(ui->checkBox->isChecked()) {
       QMessageBox::information(this,"Cat","you like cats");
   }
   else {
       QMessageBox::information(this,"Cat","you do not like cats");
   }

}

void Dialog::on_RadioButton_clicked()
{
    if(ui->radioButton1->isChecked()) {
        QMessageBox::information(this,"Title", ui->radioButton1->text());
    }
    if(ui->radioButton2->isChecked()) {
        QMessageBox::information(this,"Title",ui->radioButton2->text());
    }
}




void Dialog::on_ComboButton_clicked()
{
    QMessageBox::information(this,"Combo","You choosed " + ui->comboBox->currentText());
}

// 这个比较特别，试了试不能用上面的QMessageBox显示的方法
// QListWidget 的item又自己的类型，QListWidgetItem, 下面创建了该类型的对象，并对其进行操作
// 也许只能这样
void Dialog::on_ListButton_clicked()
{
  QListWidgetItem *itm = ui->listWidget->currentItem();
  itm->setText("Fuck");
  itm->setTextColor(Qt::red);

}
