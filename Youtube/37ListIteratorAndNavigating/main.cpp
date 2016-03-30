#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    for(int i=0; i<10; ++i) {
        list.append(i);
    }

    // Qt List 新方法
    QListIterator<int> Iter(list);

    Iter.toBack();
    while(Iter.hasPrevious()){
        qDebug() << Iter.previous();
        if(Iter.hasPrevious()) {
            qDebug() << "Next... " << Iter.peekPrevious();
        }
    }

//    while(Iter.hasNext()){
//        qDebug() << Iter.next();
//    }

    return a.exec();
}

