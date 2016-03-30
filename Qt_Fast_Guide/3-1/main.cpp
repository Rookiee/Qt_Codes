#include <QApplication>
//For widget
#include <QWidget>

//For label
#include <QLabel>


int main(int argc, char *argv[]) {
    QApplication a(argc,argv);

//    QWidget *widget = new QWidget(0,Qt::WindowStaysOnTopHint);
    QWidget *widget = new QWidget(0);

    widget->setWindowTitle(QObject::tr("我是窗口"));
    widget->resize(200,20);

    QLabel *label = new QLabel(widget);
    label->setWindowTitle(QObject::tr("我是label"));
    label->setText(QObject::tr("我是LABEL TEXT"));

    widget->show();

    //create another lable to test the Qt::WindowsFlat
    QLabel *labelTest = new QLabel(0,Qt::Dialog | Qt::FramelessWindowHint);
    labelTest->setWindowState(Qt::WindowFullScreen);
    labelTest->resize(200,30);
    labelTest->setWindowTitle(QObject::tr("我是测试Label窗口"));
    labelTest->setText(QObject::tr("THIS IS A TEEST!"));
    labelTest->show();



//     以下联系3-3测试模态与非模态
//     将 int ret。。。一下注释掉
//    QWidget test;
//    test.setWindowTitle(QObject::tr("这是模态和非模态测试"));
//    test.show();

//    QWidget *test1 = new QWidget();
//    test1->setWindowTitle(QObject::tr("这是模态和非模态测试"));
//    test1->show();


    int ret = a.exec();

    delete widget;
    return ret;

}
