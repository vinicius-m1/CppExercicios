#include "operations.h"
#include "ui_operations.h"
#include <QDebug>
#include <QMessageBox>
Operations::Operations(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Operations)
{
    ui->setupUi(this);

    ui->pb_progressBar->hide();
    ui->cb_transferAccount->hide();
    ui->lb_accountSelec_2->hide();

}


void Operations::SetAccounts(std::vector<ContaCorrente*> *t_accounts_list)
{
    ui->cb_accountSelector->clear();
    ui->cb_transferAccount->clear();

    accounts_list = t_accounts_list;

    qDebug() << "Loading accounts on combo boxes.";


    if (accounts_list->empty())
        return;

    for (size_t i=0; i < accounts_list->size(); i++){
        ui->cb_accountSelector->addItem(QString::fromStdString(accounts_list->at(i)->GetClientName()));
        ui->cb_transferAccount->addItem(QString::fromStdString(accounts_list->at(i)->GetClientName()));
    }

}

void Operations::SetLogs(std::vector<std::string> *t_logs_list)
{
    logs_list = t_logs_list;
}


Operations::~Operations()
{
    delete ui;
}

void Operations::on_btn_completeOperation_clicked()
{
    if (accounts_list->empty())
        return;

    if (ui->sb_amount->value() <= 0){
        QMessageBox::information(nullptr, "Invalid Operation", "Reason: No Value Informed.");
        return;
    }

    std::string str = "Operation: None Selected";
    bool status = true;
    // code to select operation

    if (ui->rb_deposit->isChecked()){
        // DEPOSIT
        status = accounts_list->at(ui->cb_accountSelector->currentIndex())->Deposit(ui->sb_amount->value());
        if (!status){
            QMessageBox::information(nullptr, "Invalid Operation", "Reason: Internal Error.");
            logs_list->push_back(std::string("Error raised in Deposit Operation.")); //logging event
            return;
        }

        qDebug() << "tried to: deposit, new value:"<< accounts_list->at(ui->cb_accountSelector->currentIndex())->m_balance;
        str = "Operation Occured: Deposit to "+ accounts_list->at(ui->cb_accountSelector->currentIndex())->GetClientName();

    } else if (ui->rb_withdrawn->isChecked()){
        // WITHDRAWN
        qDebug() << "tried to: withdraw";
        status = accounts_list->at(ui->cb_accountSelector->currentIndex())->Withdraw(ui->sb_amount->value());
        if (!status){
            QMessageBox::information(nullptr, "Invalid Operation", "Reason: Insuficient Balance.");
            logs_list->push_back(std::string("Error raised in Withdrawn Operation.")); //logging event
            return;
        }
        str = "Operation Occured: Withdrawn from "+ accounts_list->at(ui->cb_accountSelector->currentIndex())->GetClientName();
    } else if (ui->rb_transfer->isChecked()){
        // TRANSFER

        //accounts_list->at(ui->cb_accountSelector->currentIndex())->Transfer(accounts_list->at(ui->cb_transferAccount->currentIndex()), ui->sb_amount->value());

        ContaCorrente& selectedAccount = *accounts_list->at(ui->cb_accountSelector->currentIndex());
        status = selectedAccount.Transfer(*accounts_list->at(ui->cb_transferAccount->currentIndex()), ui->sb_amount->value());
        qDebug() << "tried to: transfer";
        if (!status){
            QMessageBox::information(nullptr, "Invalid Operation", "Reason: Insuficient Balance.");
            logs_list->push_back(std::string("Error raised in Transfer Operation.")); //logging event
            return;
        }
        str = "Operation Occured: Transfer " + accounts_list->at(ui->cb_accountSelector->currentIndex())->GetClientName() + " to " + accounts_list->at(ui->cb_transferAccount->currentIndex())->GetClientName();
    } else {
        QMessageBox::information(nullptr, "Invalid Operation", "Reason: No Option Selected.");
        return;
    }

    logs_list->push_back(str); //logging event
    ui->sb_amount->setValue(0);


    // ----

    ui->pb_progressBar->setEnabled(true);
    ui->pb_progressBar->show();

    while(ui->pb_progressBar->value() < 100)
        ui->pb_progressBar->setValue(ui->pb_progressBar->value()+1);

    ui->pb_progressBar->hide();
    ui->pb_progressBar->setValue(0);

    close();
}


void Operations::on_rb_transfer_toggled(bool checked)
{
    if (checked == true){
        ui->cb_transferAccount->show();
        ui->lb_accountSelec_2->show();
    } else
    {
        ui->lb_accountSelec_2->hide();
        ui->cb_transferAccount->hide();
    }

    ui->cb_transferAccount->setEnabled(checked);

}
