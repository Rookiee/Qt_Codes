#ifndef WIDGET_H
#define WIDGET_H
#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include "mylineedit.h"
namespace Ui {
class Widget;
}
class MyLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    MyLineEdit *lineEdit;
};

#endif // WIDGET_H
