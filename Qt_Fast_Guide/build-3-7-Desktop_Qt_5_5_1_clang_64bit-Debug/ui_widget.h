/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 361, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton->setText(QApplication::translate("Widget", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206", 0));
        pushButton_2->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", 0));
        pushButton_3->setText(QApplication::translate("Widget", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206", 0));
        pushButton_4->setText(QApplication::translate("Widget", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206", 0));
        pushButton_5->setText(QApplication::translate("Widget", "\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206", 0));
        pushButton_6->setText(QApplication::translate("Widget", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206", 0));
        pushButton_7->setText(QApplication::translate("Widget", "\351\224\231\350\257\257\344\277\241\346\201\257\345\257\271\350\257\235\346\241\206", 0));
        pushButton_8->setText(QApplication::translate("Widget", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
