#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Window_triggered()
{
//    MyDialog dialog;
//    dialog.setModal(true);
//    dialog.exec();

//      MyDialog dialog;
////      dialog.setModal(false);
////      dialog.exec();
//      dialog.show();

//    MyDialog *dialog = new MyDialog(this);
//    dialog->show();

//    现在在类中加入私有成员
    dialog = new MyDialog(this);
    dialog->show();

}
