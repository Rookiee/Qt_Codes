#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QTreeWidget>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

public:
    void AddRoot(QString name, QString Destription);

    void AddChild(QTreeWidgetItem *parent, QString name, QString Destription);

};

#endif // DIALOG_H
