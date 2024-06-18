/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *txt_input;
    QTextEdit *txt_output;
    QPushButton *btnencriptar;
    QPushButton *btndecriptar;
    QSpinBox *key;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(486, 398);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        txt_input = new QTextEdit(centralwidget);
        txt_input->setObjectName("txt_input");
        txt_input->setGeometry(QRect(10, 20, 181, 271));
        txt_output = new QTextEdit(centralwidget);
        txt_output->setObjectName("txt_output");
        txt_output->setGeometry(QRect(290, 10, 181, 271));
        btnencriptar = new QPushButton(centralwidget);
        btnencriptar->setObjectName("btnencriptar");
        btnencriptar->setGeometry(QRect(200, 120, 80, 23));
        btndecriptar = new QPushButton(centralwidget);
        btndecriptar->setObjectName("btndecriptar");
        btndecriptar->setGeometry(QRect(200, 150, 80, 23));
        key = new QSpinBox(centralwidget);
        key->setObjectName("key");
        key->setGeometry(QRect(230, 40, 51, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 50, 49, 15));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 486, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UFSC Cifrador", nullptr));
        btnencriptar->setText(QCoreApplication::translate("MainWindow", "Encriptar", nullptr));
        btndecriptar->setText(QCoreApplication::translate("MainWindow", "Decriptar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
