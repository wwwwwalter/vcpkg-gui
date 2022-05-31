/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_12;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_8;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(995, 516);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(MainWindow);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(MainWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout);

        listWidget = new QListWidget(MainWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 22));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_9 = new QPushButton(MainWindow);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_4 = new QPushButton(MainWindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(MainWindow);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(MainWindow);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(MainWindow);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);


        verticalLayout_4->addLayout(verticalLayout);

        pushButton_3 = new QPushButton(MainWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_4->addWidget(pushButton_3);

        pushButton_12 = new QPushButton(MainWindow);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout_4->addWidget(pushButton_12);

        pushButton_10 = new QPushButton(MainWindow);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout_4->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(MainWindow);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout_4->addWidget(pushButton_11);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEdit_2 = new QTextEdit(MainWindow);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_2 = new QLineEdit(MainWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        pushButton_8 = new QPushButton(MainWindow);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "install", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "port:0", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "installed", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "git pull", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "update", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "upgrade", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "clean", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "vcpkg", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "clone", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "bootstrap", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "integrate", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
