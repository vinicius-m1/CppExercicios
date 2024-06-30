/********************************************************************************
** Form generated from reading UI file 'accountslist.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTSLIST_H
#define UI_ACCOUNTSLIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AccountsList
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frm_ListAccounts;
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *lst_accountsList;
    QToolButton *btn_refreshList;
    QPushButton *btn_close;

    void setupUi(QDialog *AccountsList)
    {
        if (AccountsList->objectName().isEmpty())
            AccountsList->setObjectName("AccountsList");
        AccountsList->resize(492, 373);
        verticalLayout = new QVBoxLayout(AccountsList);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frm_ListAccounts = new QFrame(AccountsList);
        frm_ListAccounts->setObjectName("frm_ListAccounts");
        frm_ListAccounts->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 51, 56);"));
        frm_ListAccounts->setFrameShape(QFrame::StyledPanel);
        frm_ListAccounts->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frm_ListAccounts);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(frm_ListAccounts);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lst_accountsList = new QListWidget(frm_ListAccounts);
        lst_accountsList->setObjectName("lst_accountsList");
        lst_accountsList->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lst_accountsList, 1, 0, 1, 3);

        btn_refreshList = new QToolButton(frm_ListAccounts);
        btn_refreshList->setObjectName("btn_refreshList");
        btn_refreshList->setCursor(QCursor(Qt::PointingHandCursor));
        btn_refreshList->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-playlist-repeat")));
        btn_refreshList->setIcon(icon);

        gridLayout->addWidget(btn_refreshList, 2, 1, 1, 1);

        btn_close = new QPushButton(frm_ListAccounts);
        btn_close->setObjectName("btn_close");
        btn_close->setCursor(QCursor(Qt::PointingHandCursor));
        btn_close->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btn_close, 2, 2, 1, 1);


        verticalLayout->addWidget(frm_ListAccounts);


        retranslateUi(AccountsList);

        QMetaObject::connectSlotsByName(AccountsList);
    } // setupUi

    void retranslateUi(QDialog *AccountsList)
    {
        AccountsList->setWindowTitle(QCoreApplication::translate("AccountsList", "Accounts List", nullptr));
        label->setText(QCoreApplication::translate("AccountsList", "<html><head/><body><p>\360\237\247\276\357\270\217 Accounts List</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        btn_refreshList->setToolTip(QCoreApplication::translate("AccountsList", "Refresh", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_refreshList->setText(QString());
        btn_close->setText(QCoreApplication::translate("AccountsList", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountsList: public Ui_AccountsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTSLIST_H
