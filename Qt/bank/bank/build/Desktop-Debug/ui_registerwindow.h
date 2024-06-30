/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *FullName;
    QLabel *label_3;
    QLineEdit *Address;
    QLabel *label_2;
    QLineEdit *Job;
    QLabel *label;
    QDoubleSpinBox *Income;
    QLabel *label_5;
    QDoubleSpinBox *LimitSpinF;
    QCheckBox *checkspecialAcc;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 300);
        RegisterWindow->setMinimumSize(QSize(400, 300));
        RegisterWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 51, 56);"));
        verticalLayout = new QVBoxLayout(RegisterWindow);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_4 = new QLabel(RegisterWindow);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        FullName = new QLineEdit(RegisterWindow);
        FullName->setObjectName("FullName");
        FullName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, FullName);

        label_3 = new QLabel(RegisterWindow);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        Address = new QLineEdit(RegisterWindow);
        Address->setObjectName("Address");
        Address->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Address);

        label_2 = new QLabel(RegisterWindow);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        Job = new QLineEdit(RegisterWindow);
        Job->setObjectName("Job");
        Job->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Job);

        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        Income = new QDoubleSpinBox(RegisterWindow);
        Income->setObjectName("Income");
        Income->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Income->setMaximum(9999.989999999999782);

        formLayout->setWidget(3, QFormLayout::FieldRole, Income);

        label_5 = new QLabel(RegisterWindow);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        LimitSpinF = new QDoubleSpinBox(RegisterWindow);
        LimitSpinF->setObjectName("LimitSpinF");
        LimitSpinF->setEnabled(false);
        LimitSpinF->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        LimitSpinF->setMaximum(99999.990000000005239);

        formLayout->setWidget(5, QFormLayout::FieldRole, LimitSpinF);

        checkspecialAcc = new QCheckBox(RegisterWindow);
        checkspecialAcc->setObjectName("checkspecialAcc");
        checkspecialAcc->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, checkspecialAcc);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(RegisterWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RegisterWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RegisterWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RegisterWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "RegisterWindow", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", " Full Name", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "Adress", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "job position", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "Income", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterWindow", "Limit", nullptr));
        checkspecialAcc->setText(QCoreApplication::translate("RegisterWindow", "Special Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
