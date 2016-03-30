#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList list;

    QString line = "a,b,c,d,e,f,g";

    // 分割line
    list = line.split(",");

    foreach(QString i, list) {
        qDebug() << i;
    }

    QString after = list.join("");
    QString after2 = list.join(":");
    qDebug() << after;
    qDebug() << after2;
    return a.exec();
}

