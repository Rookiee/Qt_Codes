#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置打开是的title
    this->setWindowTitle("Untitled ---Notepad");
/*------------------------------File---------------------------------*/
    QObject::connect(ui->actionNew,SIGNAL(triggered(bool)),
                     this,SLOT(newFileSlot()));

    QObject::connect(ui->actionOpen,SIGNAL(triggered(bool)),
                      this,SLOT(openFileSlot()));

    QObject::connect(ui->actionSave_As,SIGNAL(triggered(bool)),
                     this,SLOT(saveAsFileSlot()));

    QObject::connect(ui->actionSave,SIGNAL(triggered(bool)),
                     this,SLOT(saveFileSlot()));

    QObject::connect(ui->actionClose,SIGNAL(triggered(bool)),
                     this,SLOT(closeFileSlot()));

/*------------------------------Edit---------------------------------*/
    QObject::connect(ui->actionUndo,SIGNAL(triggered(bool)),
                     this,SLOT(undoEditSlot()));

    QObject::connect(ui->actionRedo,SIGNAL(triggered(bool)),
                     this,SLOT(redoEditSlot()));
    QObject::connect(ui->actionCut,SIGNAL(triggered(bool)),
                     this,SLOT(cutEditSlot()));
    QObject::connect(ui->actionCopy,SIGNAL(triggered(bool)),
                     this,SLOT(copyEditSlot()));
    QObject::connect(ui->actionPaste,SIGNAL(triggered(bool)),
                     this,SLOT(pasteEditSlot()));
    QObject::connect(ui->actionSelectAll,SIGNAL(triggered(bool)),
                     this,SLOT(selectALlEditSlot()));
    QObject::connect(ui->actionColor,SIGNAL(triggered(bool)),
                     this,SLOT(colorEditSlot()));
    QObject::connect(ui->actionFont,SIGNAL(triggered(bool)),
                     this,SLOT(fontEditSlot()));
    QObject::connect(ui->actionDateTime,SIGNAL(triggered(bool)),
                     this,SLOT(dateTimeEditSlot()));

/*------------------------------Edit---------------------------------*/
    QObject::connect(ui->actionAboutQt,SIGNAL(triggered(bool)),
                     this,SLOT(aboutQtHelpSlot()));
//    QObject::connect(ui->actionAboutOurSite,SIGNAL(triggered(bool)),
//                     this,SLOT(aboutOurSiteHelpSlot()));
    QObject::connect(ui->actionAboutOurSite,SIGNAL(triggered(bool)),
                     this,SLOT(aboutSoftwareHelpSlot()));
}

/*--------------------------析构函数---------------------------*/
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox msgBox;
        // 一下代码是在帮助文档中直接抄的
        // 显示的文本
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        // 添加按钮
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();    // Dialog exec
        switch (ret) {
          case QMessageBox::Save:
              // Save was clicked
              this->saveFileSlot();
              break;
          case QMessageBox::Discard:
              // Don't Save was clicked
              event->accept();
              break;
          case QMessageBox::Cancel:
              // Cancel was clicked
            event->ignore();
              break;
          default:
              // should never be reached
              break;
        }
    }
    else
    {
        event->ignore();
    }
}

/*--------------------------各种槽函数---------------------------*/
void MainWindow::newFileSlot()
// 新建文档前，如果已经有内容，会提示保存
{
    // 如果当前文档内容已经改变
    if(ui->textEdit->document()->isModified())
    {
        qDebug() << "current file modified";
        // 写save的时候，再写
        this->saveAsFileSlot();
        ui->textEdit->clear();
        this->setWindowTitle("Untitled.txt -----DHU");
    }
    else
    {
        qDebug() << " not modified";
        ui->textEdit->clear();
        this->setWindowTitle("Untitled.txt -----DHU");
    }
}
/*-----------------------------------------------------------------------*/
void MainWindow::openFileSlot()
{
    // get the file name
    /*
     *QString saveFileName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                "/home",
                                                tr("Images (*.png *.xpm *.jpg)"));
     */
     saveFileName = QFileDialog::getOpenFileName(this,tr("Open File"),
                                                    QDir::currentPath()/*,
                                                    tr("文本 (*.txt)")*/);
    // 测试上面获得的文件路径 (显示绝对路径)
//    qDebug() << "saveFileName is " << saveFileName;
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(NULL/*this*/,"Error Message","Please Select a Text File");
        return;
    }
    QFile *file = new QFile;
    file->setFileName(saveFileName);    // set file name
    bool ok = file->open(QIODevice::ReadOnly);

    // open fils as read only mode

    if(ok)
    {
        this->setWindowTitle(saveFileName);
        // 文件与文本流相关联
        QTextStream in(file);
        ui->textEdit->setText(in.readAll());    // read all context from the file
        file->close();
        delete file;        // 析构中的delete ui; 只能释放图形模块，对core模块，要手动释放
    }
    else
    {
        QMessageBox::information(this,"Error Message","File Open Error"+file->errorString());
        return;
    }

}
/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
void MainWindow::saveFileSlot()
{
//    QString saveFileName = QFileDialog::getSaveFileName(this,"Save File",QDir::currentPath());

    if(saveFileName.isEmpty())
    {
        this->saveAsFileSlot();
    }
    QFile *file = new QFile;
    file->setFileName(saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if (ok)
    {
        QTextStream out(file);
        out << ui->textEdit->toPlainText(); // 这里是取出textEdit当中的纯文本
        file->close();
        delete file;

    }
}
/*-----------------------------------------------------------------------*/
void MainWindow::saveAsFileSlot()
{
    // getSaveFileName() 与上面不同
    saveFileName = QFileDialog::getSaveFileName(this,"Save File",QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"Error Message","Please select a file");
        return;
    }
    QFile *file = new QFile;
    file->setFileName(saveFileName);
    bool ok = file->open(QIODevice::WriteOnly);
    if (ok)
    {
        QTextStream out(file);
        out << ui->textEdit->toPlainText(); // 这里是取出textEdit当中的纯文本
        file->close();
        delete file;

    }
    else
    {
        QMessageBox::information(this,"Error Message", "Save File Error!");
    }
}
/*-----------------------------------------------------------------------*/
void MainWindow::closeFileSlot()
{
    if (ui->textEdit->document()->isModified())
    {
        this->saveAsFileSlot();
        this->close();

    }
    this->close();
}
/*-----------------------------------------------------------------------*/
void MainWindow::undoEditSlot()
{
    ui->textEdit->undo();
}

void MainWindow::redoEditSlot()
{
    ui->textEdit->redo();
}

void MainWindow::cutEditSlot()
{
    ui->textEdit->cut();
}

void MainWindow::copyEditSlot()
{
    ui->textEdit->copy();
}

void MainWindow::pasteEditSlot()
{
    ui->textEdit->paste();
}

void MainWindow::selectALlEditSlot()
{
    ui->textEdit->selectAll();
}

void MainWindow::colorEditSlot()
{
    /*
    void Dialog::setColor()
    {
        const QColorDialog::ColorDialogOptions options = QFlag(colorDialogOptionsWidget->value());
        const QColor color = QColorDialog::getColor(Qt::green, this, "Select Color", options);

        if (color.isValid()) {
            colorLabel->setText(color.name());
            colorLabel->setPalette(QPalette(color));
            colorLabel->setAutoFillBackground(true);
        }
    }
    */
    QColor color = QColorDialog::getColor(Qt::green,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
        QMessageBox::information(this,"Error Message","Set Color Failed.");
        return;
    }
}

void MainWindow::fontEditSlot()
{
    // get user select font
    // 下面注释为帮助文档内容
    /*
     *bool ok;
        QFont font = QFontDialog::getFont(&ok, this);
            if (ok) {
    // font is set to the font the user selected
        } else {
    // the user canceled the dialog; font is set to the default
    // application font, QApplication::font()
        }
     */
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else
    {
        QMessageBox::information(this,"Erro Message", "Error Set Font");
    }
}

void MainWindow::dateTimeEditSlot()
{
    QDateTime current = QDateTime::currentDateTime();
    QString time = current.toString("yyyy年M月dd日");
    ui->textEdit->append(time);
}

void MainWindow::aboutQtHelpSlot()
{
    qApp->aboutQt();
}

void MainWindow::aboutOurSiteHelpSlot()
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}

void MainWindow::aboutSoftwareHelpSlot()
{
    about *aboutDialog = new about;
    aboutDialog->show();

}

