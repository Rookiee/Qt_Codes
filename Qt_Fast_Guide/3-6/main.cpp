#include "widget.h"
#include "mydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    MyDialog dialog;
    if(dialog.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    }

    return 0;
}
