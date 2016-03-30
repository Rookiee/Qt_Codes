#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QDebug>

#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>

#include <QColor>
#include <QColorDialog>
#include <QFont>
#include <QFontDialog>

#include <QDateTime>

#include <QUrl>
#include <QDesktopServices>     //用于访问桌面服务

#include "about.h"

#include <QCloseEvent>  // 当程序需要关闭的时候，所处理的内容，所有的事件都是受保护的成员函数 protected
                        // QWidget

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString saveFileName;

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void newFileSlot();
    // 打开一个已经存在的文本文件
    void openFileSlot();
    // 另存为文件到磁盘
    void saveAsFileSlot();
    // 保存文件
    void saveFileSlot();
    // 关闭文件
    void closeFileSlot();
/******************************/
    // Undo
    void undoEditSlot();
    // Redo
    void redoEditSlot();
    // Cut
    void cutEditSlot();
    // Copy
    void copyEditSlot();
    // Paste
    void pasteEditSlot();
    // Select All
    void selectALlEditSlot();
    // Color
    void colorEditSlot();
    // Font
    void fontEditSlot();
    // DateTime
    void dateTimeEditSlot();

/*********** Help ************/
    void aboutQtHelpSlot();
    void aboutOurSiteHelpSlot();
    void aboutSoftwareHelpSlot();




};

#endif // MAINWINDOW_H
