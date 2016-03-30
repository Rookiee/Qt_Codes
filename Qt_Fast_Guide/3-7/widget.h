#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//向导对话框
#include <QWizard>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Widget *ui;
    //以下为向导对话框所需内容
private:
    //所要建立的向导总共有三个页面，所以设置了3个函数，分别对应三个页面
    QWizardPage *createPage1();
    QWizardPage *createPage2();
    QWizardPage *createpage3();
};

#endif // WIDGET_H
