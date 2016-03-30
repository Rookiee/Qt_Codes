#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    ui->horizontalSlider->setMinimum(1);
    ui->horizontalSlider->setMaximum(100);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar,SLOT(setValue(int)));

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->label,SLOT(setNum(int)));


//    ui->horizontalSlider->setValue(0);
//    ui->progressBar->setValue(0);

    // 这个好！！！！
    ui->progressBar->setValue(ui->horizontalSlider->value());
    ui->label->setNum(ui->horizontalSlider->value());
}

Dialog::~Dialog()
{
    delete ui;
}
