#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list << 1 << 5 << 15 << 23;

    // Both OK
//    QList<int>::const_iterator Iter = qFind(list.begin(),list.end(),17);
    QList<int>::const_iterator Iter = qFind(list,15);


    if(Iter != list.end()){
        qDebug() << "Found: " << *Iter;

    }
    else {
        qDebug() << "Not Found";
    }
    return a.exec();
}

