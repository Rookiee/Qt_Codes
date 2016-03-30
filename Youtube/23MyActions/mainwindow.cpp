#include "mainwindow.h"
#include "ui_mainwindow.h"
////#include <QWidget>
//#include <QtGui>
//#include <QtCore>

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox::information(this,"Title","Open This");
}
