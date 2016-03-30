#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QDir mDir("/Users/Haoyang/Downloads/Pics/");
//    qDebug() << mDir.exists();

    QDir mDir;
//    foreach (QFileInfo mItm, mDir.drives()) {
//        qDebug() << mItm.absoluteFilePath();
//    }

    QString mPath = "/Users/Haoyang/Downloads/Pics/";

//    if(!mDir.exists(mPath)){
//        mDir.mkpath(mPath);
//        qDebug() << "Created";
//    }
//    else {
//        qDebug() << "Already exists";
//    }
    QDir sDir(mPath);
    foreach (QFileInfo mitm, sDir.entryInfoList()){
        if(mitm.isFile())
            qDebug() << "File: " << mitm.absoluteFilePath();
        if(mitm.isDir())
            qDebug() << "Dir: " << mitm.absoluteDir();
    }


    return a.exec();
}

