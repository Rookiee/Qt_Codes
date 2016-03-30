#include <QApplication>
#include <QWidget>
#include "hellodialog.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    HelloDialog w;
    w.show();
    return app.exec();
}
