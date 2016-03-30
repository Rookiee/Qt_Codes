#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    for (int i=1; i !=11; ++i) {
        list.append(i);
    }

//    foreach (int mNumber, list) {         // OK
//        qDebug() << mNumber;
//    }

//    // Remove
//    list.removeOne(7);

    // Remove
    list.removeAt(4);
    typedef QList<int>::const_iterator lIter;
    for (lIter it = list.begin(); it != list.end(); ++it) {
//        std::cout << *it << std::endl;    // OK
        qDebug() << *it ;                   // OK
    }

    // Remove
    list.removeOne(7);

    return a.exec();
}

