#include <QCoreApplication>
#include <QVector>
#include <QStringList>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList list;
    list << "abc" << "def" << "opq";
    // 4: vec中的元素数量
    QVector<QString> Vec(4);

//    qCopy(list.begin(),list.end(),Vec.begin());
//    qCopy(list.begin()+1,list.end(),Vec.begin());
    qCopy(list.begin(),list.end(),Vec.begin()+1);
    foreach(QString itm, Vec) {
        qDebug() << itm;
    }

    return a.exec();
}

