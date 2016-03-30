#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->movie = new QMovie("/Users/Haoyang/Documents/test/NotePad/yao.gif");
//    this->movie = new QMovie("yao.gif");
//    this->movie = new QMovie(QDir::currentPath())
    ui->moiveLabel->setMovie(this->movie);
    qDebug() << "Current moive has " << this->movie->frameCount();
    this->movie->start();

    QObject::connect(ui->startButton,SIGNAL(clicked(bool)),
                     this,SLOT(startMovieSlot()));
    QObject::connect(ui->stopButton,SIGNAL(clicked(bool)),
                     this,SLOT(stopMovieSlot()));
}

about::~about()
{
    delete ui;
}

void about::startMovieSlot()
{
    this->movie->start();   // 开始播放
}

void about::stopMovieSlot()
{
    this->movie->stop();    // 停止播放
}
