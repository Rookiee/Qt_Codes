#include <QCoreApplication>
#include <QVector>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<QString> vect(5);

//    qFill(vect,"Hello World");
    qFill(vect.begin()+1, vect.end()-2,"lol");

    vect.append("BBB");
    foreach(QString itm, vect){
        qDebug() << itm;
    }

    qDebug() << vect.length();
    return a.exec();
}

