/********************************************************************************
** Form generated from reading UI file 'operations.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATIONS_H
#define UI_OPERATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Operations
{
public:
    QFrame *frm_operations;
    QComboBox *cb_accountSelector;
    QRadioButton *rb_deposit;
    QRadioButton *rb_withdrawn;
    QRadioButton *rb_transfer;
    QPushButton *btn_completeOperation;
    QComboBox *cb_transferAccount;
    QLabel *lb_accountSelec;
    QLabel *lb_accountSelec_2;
    QProgressBar *pb_progressBar;
    QLabel *label;

    void setupUi(QDialog *Operations)
    {
        if (Operations->objectName().isEmpty())
            Operations->setObjectName("Operations");
        Operations->resize(421, 300);
        Operations->setMinimumSize(QSize(421, 300));
        Operations->setMaximumSize(QSize(421, 300));
        frm_operations = new QFrame(Operations);
        frm_operations->setObjectName("frm_operations");
        frm_operations->setGeometry(QRect(0, -10, 421, 311));
        frm_operations->setMinimumSize(QSize(421, 311));
        frm_operations->setMaximumSize(QSize(421, 311));
        frm_operations->setSizeIncrement(QSize(421, 311));
        frm_operations->setFrameShape(QFrame::StyledPanel);
        frm_operations->setFrameShadow(QFrame::Raised);
        cb_accountSelector = new QComboBox(frm_operations);
        cb_accountSelector->setObjectName("cb_accountSelector");
        cb_accountSelector->setGeometry(QRect(30, 70, 111, 23));
        rb_deposit = new QRadioButton(frm_operations);
        rb_deposit->setObjectName("rb_deposit");
        rb_deposit->setGeometry(QRect(30, 130, 100, 21));
        rb_withdrawn = new QRadioButton(frm_operations);
        rb_withdrawn->setObjectName("rb_withdrawn");
        rb_withdrawn->setGeometry(QRect(30, 150, 100, 21));
        rb_transfer = new QRadioButton(frm_operations);
        rb_transfer->setObjectName("rb_transfer");
        rb_transfer->setGeometry(QRect(30, 170, 100, 21));
        btn_completeOperation = new QPushButton(frm_operations);
        btn_completeOperation->setObjectName("btn_completeOperation");
        btn_completeOperation->setGeometry(QRect(30, 220, 131, 23));
        btn_completeOperation->setCursor(QCursor(Qt::PointingHandCursor));
        cb_transferAccount = new QComboBox(frm_operations);
        cb_transferAccount->setObjectName("cb_transferAccount");
        cb_transferAccount->setEnabled(true);
        cb_transferAccount->setGeometry(QRect(250, 70, 111, 23));
        lb_accountSelec = new QLabel(frm_operations);
        lb_accountSelec->setObjectName("lb_accountSelec");
        lb_accountSelec->setGeometry(QRect(30, 50, 58, 15));
        lb_accountSelec_2 = new QLabel(frm_operations);
        lb_accountSelec_2->setObjectName("lb_accountSelec_2");
        lb_accountSelec_2->setEnabled(true);
        lb_accountSelec_2->setGeometry(QRect(250, 50, 111, 16));
        pb_progressBar = new QProgressBar(frm_operations);
        pb_progressBar->setObjectName("pb_progressBar");
        pb_progressBar->setEnabled(false);
        pb_progressBar->setGeometry(QRect(220, 220, 118, 23));
        pb_progressBar->setValue(0);
        label = new QLabel(frm_operations);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 171, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        retranslateUi(Operations);

        QMetaObject::connectSlotsByName(Operations);
    } // setupUi

    void retranslateUi(QDialog *Operations)
    {
        Operations->setWindowTitle(QCoreApplication::translate("Operations", "Account Operations Menu", nullptr));
        rb_deposit->setText(QCoreApplication::translate("Operations", "Deposit", nullptr));
        rb_withdrawn->setText(QCoreApplication::translate("Operations", "Withdraw", nullptr));
        rb_transfer->setText(QCoreApplication::translate("Operations", "Transfer", nullptr));
        btn_completeOperation->setText(QCoreApplication::translate("Operations", "Complete Operation", nullptr));
        lb_accountSelec->setText(QCoreApplication::translate("Operations", "<html><head/><body><p>Account</p></body></html>", nullptr));
        lb_accountSelec_2->setText(QCoreApplication::translate("Operations", "<html><head/><body><p>Receiver Account</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Operations", "<html><head/><body><p><span style=\" color:#ffffff;\">Account Operations</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Operations: public Ui_Operations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONS_H
