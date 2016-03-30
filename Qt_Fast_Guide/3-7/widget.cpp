#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <iostream>
//颜色对话框
#include <QColorDialog>
//文件对话框
#include <QFileDialog>
//字体对话框
#include <QFontDialog>
//输入对话框
#include <QInputDialog>
//消息对话框
#include <QMessageBox>
//进度对话框
#include <QProgressDialog>
//错误信息对话框
#include <QErrorMessage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/*--------------------------颜色对话框--------------------------------------*/

void Widget::on_pushButton_clicked()
{
    /* 以下第一种方法：使用静态函数，不创建对象 */


    //ShowAlpahChannel: 显示对透明度的设置
//    QColor color = QColorDialog::getColor(Qt::white,this,
//                                          QObject::tr("颜色对话框"),
//                                          QColorDialog::ShowAlphaChannel);
//    QColor color = QColorDialog::getColor(Qt::white,this,
//                                          QObject::tr("颜色对话框"));

/*********************************************************************************/

    /* 以下第二种方法：首先创建对象 */
    /*
    QColorDialog *dialog = new QColorDialog(Qt::white,this);
    //显示alpha 透明度设置选项
    dialog->setOption(QColorDialog::ShowAlphaChannel);
    //以模态方式运行，如果没有以下面这句，colordialog弹出后瞬间消失
    dialog->exec();
    //获取当前颜色
    QColor color = dialog->currentColor();
    */

/*********************************************************************************/
    /* 以下也使用第二种方法，创建对象，但不使用new创建 */
    QColorDialog dialog(Qt::white,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    //以模态方式运行，如果没有以下面这句，colordialog弹出后瞬间消失
    dialog.exec();
//    QColor color = dialog.currentColor();
    //一下对上一句换一种方式，使用getColor()
    QColor color = dialog.getColor();

    qDebug() << color;

    /****************************
     * 输出结果：
     * QColor(ARGB 1, 1, 1, 1)
     * 4个数值分别代表： 透明度，红色，绿色，蓝色
     *
     * *************************/
}

/*--------------------------文件对话框----------------------------------------------*/

void Widget::on_pushButton_2_clicked()
{

//    QString fileName = QFileDialog::getOpenFileName(this,QObject::tr("文件对话框"),
//                                                    QObject::tr("/Users/Haoyang/Downloads/"),
//                                                    tr("图片文件(*.jpg *.png *.gif)"));

     //设置不同的过滤器，用;;隔开
//    QString fileName = QFileDialog::
//            getOpenFileName(this,
//                            tr("文件对话框"),
//                            "/Users/Haoyang/Downloads/",
//                            "图片文件(*.jpg *.png);;文本文件(*.txt)");

/*********************************************************************************/
    //以下可以一次选择多个文件,注意使用 QStringList 接收
    QStringList fileName = QFileDialog::
            getOpenFileNames(this,
                             tr("多文件对话框"),
                             "/Users/Haoyang/Downloads/"
                             "图片文件(*.jpg *.png);;文本文件(*.txt *.doc)");
/*********************************************************************************/
    qDebug() << fileName;
//    std::cout << fileName.toStdString() << std::endl;
}

/*----------------------------字体对话框------------------------------------------*/

void Widget::on_pushButton_3_clicked()
{
    //以下使用静态函数，不创建对象
    bool ok; // 用于标记是否点击确定
    QFont font = QFontDialog::getFont(&ok,this);
    //如果点击了OK，则让字体对话框上相识的文字显示选定字体
    //如果点击cancel，则取消，并输出提示
    if(ok)
        ui->pushButton_3->setFont(font);
    else
        qDebug() << tr("没有选择！");

/****************************************************************************/
    //以下创建对象实现,但第一次选择后没反应，
//    bool ok;
//    QFontDialog *dialog = new QFontDialog(this);
//    QFont font = dialog->currentFont();

////    QFont font = dialog->getFont(&ok,this);
//    dialog->exec();
//    ui->pushButton_3->setFont(font);

}

/*-------------------------输入对话框-----------------------------------------*/

void Widget::on_pushButton_4_clicked()  //输入对话框
{
    //用于获取是否点击确定按钮
    bool ok;

    //获取字符串,这里使用new创建了对象
    QInputDialog *dialogText = new QInputDialog(this);
    QString string = dialogText->getText(this,QObject::tr("字符串对话框"),
                                     QObject::tr("请输入用户名"),
                                     QLineEdit::Normal,
                                     QObject::tr("Haoyang"),
                                     &ok);
    if(ok)
        qDebug() << "string: " << string;
    else
        qDebug() << "什么都不输入，干毛啊！";

    /************************************************************************/

    //获取整数,这里穿件对象，但不使用new
    QInputDialog dialogInt(this);
    int value1 = dialogInt.getInt(this,QObject::tr("整数对话框"),
                                  QObject::tr("输入-100到100之间的数值："),
                                  0,-100,100,5,&ok);
    if(ok)
        qDebug() << "输入的整数是: " << value1;
    else
        qDebug() << "什么都不输入，干毛啊！";

    /************************************************************************/

    //获取浮点型，这里直接创建对象
    double value2 = QInputDialog::getDouble(this,QObject::tr("浮点型对话框"),
                                            QObject::tr("输入-100到100之间的实数："),
                                            1.5,-100,100,2,&ok);
    if(ok)
        qDebug() << "输入的实数是： " << value2;
    else
        qDebug() << "什么都不输入，干毛啊！";

    /************************************************************************/

    //获取条目，这里使用new创建直接创建对象
    QInputDialog *dialogItem = new QInputDialog(this);
    //创建条目，使用 QStringList 类型
    QStringList items;
    //向items中添加内容
    items << "去死吧" << "你来啊" << "打不死你";
    //获取条目,注意获取到的每个条目的类型是 QString
    QString item = dialogItem->getItem(this,QObject::tr("条目对话框"),
                                       QObject::tr("选择一个条目"),
                                       items,
                                       1,   //默认第几个条目，0为第一个
                                       true,    //条目是否可编辑，true为可编辑
                                       &ok);
    if(ok)
        qDebug() << "选择的条目是： " << item;
    else
        qDebug() << "什么都不输入，干毛啊！";

}

/*-----------------------------消息对话框----------------------------------------*/

void Widget::on_pushButton_5_clicked()
{
    //问题对话框，使用new创建对象
    QMessageBox *dialogQuestion = new QMessageBox(this);
    int retQuestion = dialogQuestion->question(this,QObject::tr("问题对话框"),
                                               QObject::tr("不会Qt，滚蛋！"),
                                               QMessageBox::Yes,
                                               QMessageBox::No);
    if(retQuestion == QMessageBox::Yes)
        qDebug() << tr("会Qt，可以留下");
    else
        qDebug() << "没看到吗？ 滚蛋";

    /************************************************************************/

    //提示对话框，不使用 new 创建对象
    QMessageBox dialogInfo(this);
    int retInfo = dialogInfo.information(this,tr("提示对话框"),
                                         tr("不会就滚蛋！"),
                                         QMessageBox::Yes,
                                         QMessageBox::No);
    if(retInfo == QMessageBox::Yes)
        qDebug() << "我会啊";
    else
        qDebug() << "我不会";

    /************************************************************************/
    //警告对话框,不再直接创建对象
    int retWarning = QMessageBox::warning(this,tr("警告对话框"),
                                           tr("快点滚蛋！"),
                                           QMessageBox::Yes,
                                           QMessageBox::No);
    if(retWarning == QMessageBox::Yes)
        qDebug() << "好的";
    else
        qDebug() << "你说滚就滚，你算老几";

    /************************************************************************/
    //关于对话框，不创建对象
    //对话框中内容太多，建立个字符串先
    QString content = "这是个关于你是否滚蛋的测试！";
    //about() 没有返回值
    QMessageBox::about(this,"关于滚蛋",content);

    //最后，显示一下现在用的Qt的版本吧
    QMessageBox::aboutQt(this,tr("我就不写这是版本"));

}

/*-----------------------------进度对话框----------------------------------------*/

void Widget::on_pushButton_6_clicked()
{
    //尝试以创建对象的方式进行
    QProgressDialog *dialogProgress = new QProgressDialog(tr("文件复制进度"),
                                                          tr("取消"),
                                                          0,100,this);
    dialogProgress->setWindowTitle(tr("进度对话框"));
//    dialogProgress->exec();
    dialogProgress->show();
    for(float i = 0; i<100; i += 0.001) {
        dialogProgress->setValue(i);    //设置进度条当前值
        QCoreApplication::processEvents();  //避免界面冻结
        if(dialogProgress->wasCanceled()) {
            qDebug() << tr("还没复制完，你个二货!");
            exit(1);
//            break;
        }

    }
    dialogProgress->setValue(100);  //这样才能显示100%，因为for循环中不到100
    qDebug() << "复制完了，走吧";

}

/*-----------------------------错误信息对话框----------------------------------------*/

void Widget::on_pushButton_7_clicked()
{
    //创建对象
    QErrorMessage dialogError(this);

    dialogError.setWindowTitle("错误信息对话框");
    dialogError.showMessage("出错了，你个二货");
    //对于这种方法，下面这句必须，否则瞬间消失
    dialogError.exec();

    /**************************************************************/
    //不创建对象，报错
//    QString error = QErrorMessage::showMessage("出错了，你个大二货!");
//    qDebug() << error;
    /**************************************************************/
    //用new创建对象
    QErrorMessage * dialogErrorNew = new QErrorMessage(this);
    dialogErrorNew->setWindowTitle("再次出错");
    dialogErrorNew->showMessage("出错了，你个二货");

}

/*-----------------------------向导对话框----------------------------------------*/
//先定义头文件中对应的三个函数
QWizardPage* Widget::createPage1() {
    QWizardPage *page = new QWizardPage;
    page->setTitle("这就是个介绍，有版权哦");

    return page;
}
QWizardPage* Widget::createPage2() {
    QWizardPage *page = new QWizardPage(this);
    page->setTitle("该你选了");
    return page;

}

QWizardPage* Widget::createpage3(){
    QWizardPage *page = new QWizardPage();
    page->setTitle("结束了");
    return page;
}

void Widget::on_pushButton_8_clicked()
{
    //创建对象，new
    QWizard *dialog = new QWizard(this);
    dialog->setWindowTitle("向导");
    dialog->addPage(createPage1());
    dialog->addPage(createPage2());
    dialog->addPage(createpage3());
    dialog->exec();
//    dialog->setWindowModality(Qt::WindowModal);
}
