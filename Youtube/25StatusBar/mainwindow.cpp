#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    stateLabel = new QLabel(ui->statusBar);
//    stateBar = new QProgressBar(ui->statusBar);

    // 这个方法好，先在窗口创建，加到窗口，再把他们添加到statusbar，添加顺序从右向左
    stateLabel = new QLabel(this);
    stateBar = new QProgressBar(this);
    ui->statusBar->addPermanentWidget(stateLabel);
    ui->statusBar->addPermanentWidget(stateBar);
    stateLabel->setNum(stateBar->value());

    connect(stateBar,SIGNAL(valueChanged(int)),
            stateLabel,SLOT(setNum(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDo_Sth_triggered()
{
    stateBar->setValue(45);
}
