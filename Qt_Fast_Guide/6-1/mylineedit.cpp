#include "mylineedit.h"
#include <QDebug>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "MyLineEdit中的键盘按下事件";
    QLineEdit::keyPressEvent(event);
}

