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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_AccountsList
{
public:
    QFrame *frm_ListAccounts;
    QLabel *label;
    QToolButton *btn_refreshList;
    QPushButton *btn_close;
    QListWidget *lst_accountsList;

    void setupUi(QDialog *AccountsList)
    {
        if (AccountsList->objectName().isEmpty())
            AccountsList->setObjectName("AccountsList");
        AccountsList->resize(400, 300);
        frm_ListAccounts = new QFrame(AccountsList);
        frm_ListAccounts->setObjectName("frm_ListAccounts");
        frm_ListAccounts->setGeometry(QRect(-10, -10, 411, 311));
        frm_ListAccounts->setFrameShape(QFrame::StyledPanel);
        frm_ListAccounts->setFrameShadow(QFrame::Raised);
        label = new QLabel(frm_ListAccounts);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 131, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        btn_refreshList = new QToolButton(frm_ListAccounts);
        btn_refreshList->setObjectName("btn_refreshList");
        btn_refreshList->setGeometry(QRect(270, 280, 24, 22));
        btn_refreshList->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-playlist-repeat")));
        btn_refreshList->setIcon(icon);
        btn_close = new QPushButton(frm_ListAccounts);
        btn_close->setObjectName("btn_close");
        btn_close->setGeometry(QRect(320, 280, 80, 23));
        btn_close->setCursor(QCursor(Qt::PointingHandCursor));
        lst_accountsList = new QListWidget(frm_ListAccounts);
        lst_accountsList->setObjectName("lst_accountsList");
        lst_accountsList->setGeometry(QRect(20, 50, 381, 221));

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
