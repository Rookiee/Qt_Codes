#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QLineEdit>

// 这个例子重点在pro文件，创建的时候是empty项目
int main(int argc, char *argv[])  {
    QApplication app(argc, argv);

//    QLabel *label = new QLabel("<b>Hello</b> <i>World</i>");

//    8
    QWidget *window = new QWidget;
    window->setWindowTitle("My App");


//  添加三个按钮
//    QPushButton *button1 = new QPushButton("One");
//    QPushButton *button2 = new QPushButton("Two");
//    QPushButton *button3 = new QPushButton("Three");


/********************HBoxLayout和VBoxLayout ******************/
    /*
//    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vlayout = new QVBoxLayout;

    vlayout->addWidget(button1);
    vlayout->addWidget(button2);
    vlayout->addWidget(button3);

    window->setLayout(vlayout);
    */
/***************************************************************/

    QGridLayout *layout = new QGridLayout;
    QLabel *label1 = new QLabel("Name:");
    //QLineEdit 要加头文件
    QLineEdit *txtName1 = new QLineEdit;

    QLabel *label2 = new QLabel("Age:");
    //QLineEdit 要加头文件
    QLineEdit *txtName2 = new QLineEdit;

    layout->addWidget(label1, 0,0);
    layout->addWidget(txtName1, 0,1);

    layout->addWidget(label2, 1,0);
    layout->addWidget(txtName2, 1,1);

    QPushButton *button = new QPushButton("OK");
    layout->addWidget(button, 2,0,1,2);

    window->setLayout(layout);

    window->show();

//    label->show();

    return app.exec();
}
