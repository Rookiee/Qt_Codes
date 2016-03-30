#include "mywidget.h"
#include "ui_mywidget.h"

// 用来在Label中显示图片
#include <QPixmap>
// 用来在lable中显示gif动态图
#include <QMovie>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    // 以上两个函数可以使用setFrameSytle(QFrame::Box | QFrame::Sunken) 代替
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    /*------------------------在lable中显示图片和动态图片-------------------*/
    ui->label->setPixmap(QPixmap("/Users/Haoyang/Downloads/Pics/boldt.jpg"));
//    ui->label->setText("Hello World");  // 显示文字可以，上面的显示图片怎么不行，不能显示全部，lable太小。
    QMovie * movie = new QMovie("/Users/Haoyang/Downloads/Pics/testG.gif");
    ui->label->setMovie(movie);
    movie->start();


    /*-----------------------QLCDNumber 液晶数字效果----------------------*/
//    在Designer中完成



}

MyWidget::~MyWidget()
{
    delete ui;
}
