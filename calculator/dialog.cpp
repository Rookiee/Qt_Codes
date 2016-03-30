#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->CalButton,SIGNAL(clicked()),
                     this,SLOT(calSlot()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::calSlot()
{

    int result;
    if (ui->comboBox->currentText() == "+") {
        int first = ui->firstNumLineEdit->text().toInt();
        int second = ui->secondNumLineEdit->text().toInt();
        result = first + second;
        ui->resultLabel->setText(QString::number(result));

    }


    if (ui->comboBox->currentText() == "-") {
        int first = ui->firstNumLineEdit->text().toInt();
        int second = ui->secondNumLineEdit->text().toInt();
        result = first-second;
        ui->resultLabel->setText(QString::number(result));
    }
    if (ui->comboBox->currentText() == "*") {
        int first = ui->firstNumLineEdit->text().toInt();
        int second = ui->secondNumLineEdit->text().toInt();
        result = first * second;
        ui->resultLabel->setText(QString::number(result));
    }
    if (ui->comboBox->currentText() == "/"){
        int first = ui->firstNumLineEdit->text().toInt();
        int second = ui->secondNumLineEdit->text().toInt();
        if (second==0){
            QMessageBox::warning(this,"Warning","The second number can not be zero");

        }
        else {
            result = first/second;
            ui->resultLabel->setText(QString::number(result));
        }



    }


//    qDebug() << result;




}
