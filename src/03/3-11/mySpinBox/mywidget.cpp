#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 设置时间为现在的系统时间
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    // 设置时间的显示格式
    ui->dateTimeEdit->setDisplayFormat(tr("yyyy年MM月dd日ddd HH时mm分ss秒"));

    qDebug() << ui->dateTimeEdit->text();
    qDebug() << ui->dateTimeEdit->dateTime();
    qDebug() << ui->doubleSpinBox->value();
    qDebug() << ui->spinBox->value();
}

MyWidget::~MyWidget()
{
    delete ui;
}

