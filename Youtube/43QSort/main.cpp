#include <QCoreApplication>
#include <QList>
#include <QtAlgorithms>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;

    list << 2 << 3 << 1 << 0;
    qDebug() << "The original order: ";
    foreach(int i, list) {
        qDebug() << i;
    }

    qDebug() << "The new order: ";
    // 大写S
//    qSort(list);
    qSort(list.begin()+1,list.end()-1);

    foreach(int i, list) {
        qDebug() << i;
    }

    return a.exec();
}

