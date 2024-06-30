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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Operations
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frm_operations;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *lb_accountSelec;
    QLabel *lb_accountSelec_2;
    QComboBox *cb_accountSelector;
    QComboBox *cb_transferAccount;
    QLabel *lb_amount;
    QRadioButton *rb_deposit;
    QDoubleSpinBox *sb_amount;
    QRadioButton *rb_withdrawn;
    QRadioButton *rb_transfer;
    QPushButton *btn_completeOperation;
    QProgressBar *pb_progressBar;

    void setupUi(QDialog *Operations)
    {
        if (Operations->objectName().isEmpty())
            Operations->setObjectName("Operations");
        Operations->resize(420, 315);
        Operations->setMinimumSize(QSize(420, 315));
        verticalLayout = new QVBoxLayout(Operations);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frm_operations = new QFrame(Operations);
        frm_operations->setObjectName("frm_operations");
        frm_operations->setMinimumSize(QSize(421, 311));
        frm_operations->setMaximumSize(QSize(421, 311));
        frm_operations->setSizeIncrement(QSize(421, 311));
        frm_operations->setFrameShape(QFrame::StyledPanel);
        frm_operations->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frm_operations);
        formLayout->setObjectName("formLayout");
        label = new QLabel(frm_operations);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0)"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lb_accountSelec = new QLabel(frm_operations);
        lb_accountSelec->setObjectName("lb_accountSelec");

        formLayout->setWidget(1, QFormLayout::LabelRole, lb_accountSelec);

        lb_accountSelec_2 = new QLabel(frm_operations);
        lb_accountSelec_2->setObjectName("lb_accountSelec_2");
        lb_accountSelec_2->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lb_accountSelec_2);

        cb_accountSelector = new QComboBox(frm_operations);
        cb_accountSelector->setObjectName("cb_accountSelector");

        formLayout->setWidget(2, QFormLayout::LabelRole, cb_accountSelector);

        cb_transferAccount = new QComboBox(frm_operations);
        cb_transferAccount->setObjectName("cb_transferAccount");
        cb_transferAccount->setEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, cb_transferAccount);

        lb_amount = new QLabel(frm_operations);
        lb_amount->setObjectName("lb_amount");
        lb_amount->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, lb_amount);

        rb_deposit = new QRadioButton(frm_operations);
        rb_deposit->setObjectName("rb_deposit");

        formLayout->setWidget(4, QFormLayout::LabelRole, rb_deposit);

        sb_amount = new QDoubleSpinBox(frm_operations);
        sb_amount->setObjectName("sb_amount");

        formLayout->setWidget(4, QFormLayout::FieldRole, sb_amount);

        rb_withdrawn = new QRadioButton(frm_operations);
        rb_withdrawn->setObjectName("rb_withdrawn");

        formLayout->setWidget(5, QFormLayout::LabelRole, rb_withdrawn);

        rb_transfer = new QRadioButton(frm_operations);
        rb_transfer->setObjectName("rb_transfer");

        formLayout->setWidget(6, QFormLayout::LabelRole, rb_transfer);

        btn_completeOperation = new QPushButton(frm_operations);
        btn_completeOperation->setObjectName("btn_completeOperation");
        btn_completeOperation->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout->setWidget(7, QFormLayout::LabelRole, btn_completeOperation);

        pb_progressBar = new QProgressBar(frm_operations);
        pb_progressBar->setObjectName("pb_progressBar");
        pb_progressBar->setEnabled(false);
        pb_progressBar->setValue(0);

        formLayout->setWidget(7, QFormLayout::FieldRole, pb_progressBar);


        verticalLayout->addWidget(frm_operations);


        retranslateUi(Operations);

        QMetaObject::connectSlotsByName(Operations);
    } // setupUi

    void retranslateUi(QDialog *Operations)
    {
        Operations->setWindowTitle(QCoreApplication::translate("Operations", "Account Operations Menu", nullptr));
        label->setText(QCoreApplication::translate("Operations", "<html><head/><body><p><span>Account Operations</span></p></body></html>", nullptr));
        lb_accountSelec->setText(QCoreApplication::translate("Operations", "<html><head/><body><p>Account</p></body></html>", nullptr));
        lb_accountSelec_2->setText(QCoreApplication::translate("Operations", "<html><head/><body><p>Receiver Account</p></body></html>", nullptr));
        lb_amount->setText(QCoreApplication::translate("Operations", "<html><head/><body><p>Amount</p></body></html>", nullptr));
        rb_deposit->setText(QCoreApplication::translate("Operations", "Deposit", nullptr));
        rb_withdrawn->setText(QCoreApplication::translate("Operations", "Withdraw", nullptr));
        rb_transfer->setText(QCoreApplication::translate("Operations", "Transfer", nullptr));
        btn_completeOperation->setText(QCoreApplication::translate("Operations", "Complete Operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Operations: public Ui_Operations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONS_H
