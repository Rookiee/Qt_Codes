#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_RadioButton_clicked();



    void on_ComboButton_clicked();

    void on_ListButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
