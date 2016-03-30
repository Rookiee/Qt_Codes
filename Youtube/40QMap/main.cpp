#include <QCoreApplication>
#include <QDebug>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<int,QString> employee;

    // Key  不能重复
    employee.insert(1, "Bob");
    employee.insert(2, "Chad");
    employee.insert(3, "Mary");


    foreach(int i, employee.keys()) {
        qDebug() << employee[i];
    }

    QMapIterator<int,QString> Iter(employee);
    while(Iter.hasNext()){
//        qDebug() << Iter.next();  // error
        Iter.next();
        qDebug() << Iter.key() << " " << Iter.value();
    }

    return a.exec();
}

