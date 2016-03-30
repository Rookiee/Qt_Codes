#include <QApplication>
#include <QWidget>
#include <iostream>
#include <QDebug>
using namespace std; // in order to use cout and endl;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //创建一个widget
//    QWidget * widget = new QWidget();
    QWidget * widget = new QWidget;
    cout << widget->pos().x() << '\t'<< widget->pos().y() << endl;
    cout << widget->geometry().x() << '\t' << widget->geometry().y()<< endl;

    cout << widget->size().width() << '\t' << widget->size().height()<< endl;
    cout << widget->width() << '\t' << widget->height() << endl;
    cout << widget->geometry().width() << '\t' << widget->geometry().height()<<endl;

    cout << widget->frameGeometry().width() << '\t' << widget->frameGeometry().height()<< endl;

    //geometry() 和 frameGeometry() 返回的数据类型是QRect
    qDebug() << widget->geometry() << endl;
    qDebug() << widget->frameGeometry();
    int ret = a.exec();

    delete widget;
    return ret;
}
