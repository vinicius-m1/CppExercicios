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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
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

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 300);
        RegisterWindow->setMinimumSize(QSize(400, 300));
        RegisterWindow->setMaximumSize(QSize(400, 300));
        buttonBox = new QDialogButtonBox(RegisterWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(RegisterWindow);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 20, 381, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        FullName = new QLineEdit(formLayoutWidget);
        FullName->setObjectName("FullName");

        formLayout->setWidget(0, QFormLayout::FieldRole, FullName);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        Address = new QLineEdit(formLayoutWidget);
        Address->setObjectName("Address");

        formLayout->setWidget(1, QFormLayout::FieldRole, Address);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        Job = new QLineEdit(formLayoutWidget);
        Job->setObjectName("Job");

        formLayout->setWidget(2, QFormLayout::FieldRole, Job);

        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        Income = new QDoubleSpinBox(formLayoutWidget);
        Income->setObjectName("Income");
        Income->setMaximum(9999.989999999999782);

        formLayout->setWidget(3, QFormLayout::FieldRole, Income);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        LimitSpinF = new QDoubleSpinBox(formLayoutWidget);
        LimitSpinF->setObjectName("LimitSpinF");
        LimitSpinF->setEnabled(false);
        LimitSpinF->setMaximum(99999.990000000005239);

        formLayout->setWidget(5, QFormLayout::FieldRole, LimitSpinF);

        checkspecialAcc = new QCheckBox(formLayoutWidget);
        checkspecialAcc->setObjectName("checkspecialAcc");

        formLayout->setWidget(4, QFormLayout::LabelRole, checkspecialAcc);


        retranslateUi(RegisterWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RegisterWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RegisterWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "RegisterWindow", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", " Nome Completo", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "Endere\303\247o", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "ocupa\303\247\303\243o", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "Renda", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterWindow", "Limite", nullptr));
        checkspecialAcc->setText(QCoreApplication::translate("RegisterWindow", "Conta Especial?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
