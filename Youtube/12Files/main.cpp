#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


void Write(QString fileName) {
    QFile mFile(fileName);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "could not open file for writing";
        return;
    }

    QTextStream out(&mFile);
    out << "Hello world";

    mFile.flush();

    mFile.close();
}

void Read(QString fileName) {
    QFile mFile(fileName);
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "could not open file for reading";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();
    qDebug() << mText;



    mFile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QString mFilename = "/Users/Haoyang/Downloads/text.txt";
//    Write(mFilename);
//    Read(mFilename);

    // 读资源库中的文件，路径前加冒号
    Read(":/MyFiles/12Files.pro");
    return a.exec();
}

