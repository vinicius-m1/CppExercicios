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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *wid_mainMenuWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frm_mainMenuFrame;
    QLabel *label;
    QFrame *frm_accountsList;
    QPushButton *btn_accountsList;
    QFrame *frm_registerNewAccount;
    QPushButton *btn_registerNewAccount;
    QFrame *frm_registerNewUser;
    QPushButton *btn_registerNewUser;
    QFrame *frm_operations;
    QPushButton *btn_operations;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(520, 600);
        MainWindow->setMinimumSize(QSize(520, 600));
        MainWindow->setMaximumSize(QSize(520, 600));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        wid_mainMenuWidget = new QWidget(MainWindow);
        wid_mainMenuWidget->setObjectName("wid_mainMenuWidget");
        verticalLayoutWidget = new QWidget(wid_mainMenuWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 511, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frm_mainMenuFrame = new QFrame(verticalLayoutWidget);
        frm_mainMenuFrame->setObjectName("frm_mainMenuFrame");
        frm_mainMenuFrame->setAutoFillBackground(true);
        frm_mainMenuFrame->setStyleSheet(QString::fromUtf8(""));
        frm_mainMenuFrame->setFrameShape(QFrame::Panel);
        frm_mainMenuFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frm_mainMenuFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 30, 241, 81));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setWordWrap(true);
        frm_accountsList = new QFrame(frm_mainMenuFrame);
        frm_accountsList->setObjectName("frm_accountsList");
        frm_accountsList->setEnabled(true);
        frm_accountsList->setGeometry(QRect(160, 200, 171, 41));
        frm_accountsList->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        frm_accountsList->setFrameShape(QFrame::StyledPanel);
        frm_accountsList->setFrameShadow(QFrame::Raised);
        btn_accountsList = new QPushButton(frm_accountsList);
        btn_accountsList->setObjectName("btn_accountsList");
        btn_accountsList->setGeometry(QRect(0, 0, 171, 41));
        btn_accountsList->setCursor(QCursor(Qt::PointingHandCursor));
        btn_accountsList->setAutoFillBackground(false);
        btn_accountsList->setStyleSheet(QString::fromUtf8("background-color: grey\n"
""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("contact-new")));
        btn_accountsList->setIcon(icon);
        btn_accountsList->setIconSize(QSize(26, 26));
        btn_accountsList->setFlat(true);
        frm_registerNewAccount = new QFrame(frm_mainMenuFrame);
        frm_registerNewAccount->setObjectName("frm_registerNewAccount");
        frm_registerNewAccount->setEnabled(true);
        frm_registerNewAccount->setGeometry(QRect(160, 260, 171, 41));
        frm_registerNewAccount->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        frm_registerNewAccount->setFrameShape(QFrame::StyledPanel);
        frm_registerNewAccount->setFrameShadow(QFrame::Raised);
        btn_registerNewAccount = new QPushButton(frm_registerNewAccount);
        btn_registerNewAccount->setObjectName("btn_registerNewAccount");
        btn_registerNewAccount->setGeometry(QRect(0, 0, 171, 41));
        btn_registerNewAccount->setCursor(QCursor(Qt::PointingHandCursor));
        btn_registerNewAccount->setAutoFillBackground(false);
        btn_registerNewAccount->setStyleSheet(QString::fromUtf8("background-color: grey\n"
""));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("list-add")));
        btn_registerNewAccount->setIcon(icon1);
        btn_registerNewAccount->setIconSize(QSize(26, 26));
        btn_registerNewAccount->setFlat(true);
        frm_registerNewUser = new QFrame(frm_mainMenuFrame);
        frm_registerNewUser->setObjectName("frm_registerNewUser");
        frm_registerNewUser->setEnabled(true);
        frm_registerNewUser->setGeometry(QRect(160, 320, 171, 41));
        frm_registerNewUser->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        frm_registerNewUser->setFrameShape(QFrame::StyledPanel);
        frm_registerNewUser->setFrameShadow(QFrame::Raised);
        btn_registerNewUser = new QPushButton(frm_registerNewUser);
        btn_registerNewUser->setObjectName("btn_registerNewUser");
        btn_registerNewUser->setGeometry(QRect(0, 0, 171, 41));
        btn_registerNewUser->setCursor(QCursor(Qt::PointingHandCursor));
        btn_registerNewUser->setAutoFillBackground(false);
        btn_registerNewUser->setStyleSheet(QString::fromUtf8("background-color: grey\n"
""));
        btn_registerNewUser->setIcon(icon1);
        btn_registerNewUser->setIconSize(QSize(26, 26));
        btn_registerNewUser->setFlat(true);
        frm_operations = new QFrame(frm_mainMenuFrame);
        frm_operations->setObjectName("frm_operations");
        frm_operations->setEnabled(true);
        frm_operations->setGeometry(QRect(160, 380, 171, 41));
        frm_operations->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        frm_operations->setFrameShape(QFrame::StyledPanel);
        frm_operations->setFrameShadow(QFrame::Raised);
        btn_operations = new QPushButton(frm_operations);
        btn_operations->setObjectName("btn_operations");
        btn_operations->setGeometry(QRect(0, 0, 171, 41));
        btn_operations->setCursor(QCursor(Qt::PointingHandCursor));
        btn_operations->setAutoFillBackground(false);
        btn_operations->setStyleSheet(QString::fromUtf8("background-color: grey\n"
""));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("applications-other")));
        btn_operations->setIcon(icon2);
        btn_operations->setIconSize(QSize(26, 26));
        btn_operations->setFlat(true);
        frm_accountsList->raise();
        label->raise();
        frm_registerNewAccount->raise();
        frm_registerNewUser->raise();
        frm_operations->raise();

        verticalLayout->addWidget(frm_mainMenuFrame);

        MainWindow->setCentralWidget(wid_mainMenuWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 520, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btn_accountsList->setDefault(false);
        btn_registerNewAccount->setDefault(false);
        btn_registerNewUser->setDefault(false);
        btn_operations->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bank Admin Panel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Main Menu   Bank Admin", nullptr));
        btn_accountsList->setText(QCoreApplication::translate("MainWindow", "Accounts List", nullptr));
        btn_registerNewAccount->setText(QCoreApplication::translate("MainWindow", "Register New Account", nullptr));
        btn_registerNewUser->setText(QCoreApplication::translate("MainWindow", "Register New User", nullptr));
        btn_operations->setText(QCoreApplication::translate("MainWindow", "Operations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
