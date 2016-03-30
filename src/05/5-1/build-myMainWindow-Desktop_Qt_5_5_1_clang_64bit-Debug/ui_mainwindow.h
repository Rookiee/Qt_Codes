/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Dock;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QFontComboBox *fontComboBox;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        action_New->setCheckable(false);
        action_New->setChecked(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/myImage/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_New->setIconVisibleInMenu(true);
        action_Dock = new QAction(MainWindow);
        action_Dock->setObjectName(QStringLiteral("action_Dock"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(true);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        fontComboBox = new QFontComboBox(dockWidgetContents);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(10, 80, 61, 22));
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 30, 75, 23));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menu_F->menuAction());
        menu_F->addAction(action_New);
        menu_F->addAction(action_Dock);
        mainToolBar->addAction(action_New);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_New->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", 0));
#ifndef QT_NO_TOOLTIP
        action_New->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        action_New->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        action_Dock->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272Dock", 0));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
