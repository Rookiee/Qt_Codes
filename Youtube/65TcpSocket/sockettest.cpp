#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::connect()
{

    socket = new QTcpSocket(this);

    socket->connectToHost("voidrealms.com",80);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected!";
        // send
        socket->write("Hello server\r\n ");

        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();
        qDebug() << socket->readAll();
        socket->close();
    }
    else {
        qDebug() << "Not Connected!";
    }
    // connected

    // sent data

    // get data

    // closed
}

