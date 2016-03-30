#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
    AddRoot("Hello", "World");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::AddRoot(QString name, QString Destription)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,name);
    itm->setText(1,Destription);
//    ui->treeWidget->addTopLevelItem(itm);
    AddChild(itm,"one","two");

}

void Dialog::AddChild(QTreeWidgetItem *parent, QString name, QString Destription)
{
//    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Destription);
    parent->addChild(itm);

}
