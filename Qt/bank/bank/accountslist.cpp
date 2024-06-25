#include "accountslist.h"
#include "ui_accountslist.h"
#include <iostream>
AccountsList::AccountsList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AccountsList)
{
    ui->setupUi(this);

    // run refresh method
    //AccountsList::refresh_list(); //crashes the program


}

AccountsList::~AccountsList()
{
    delete ui;

}

void AccountsList::SetAccounts(std::vector<ContaCorrente*> *t_accounts_list)
{
    accounts_list = t_accounts_list;
}

void AccountsList::SetLogs(std::vector<std::string> *t_logs_list)
{
    logs_list = t_logs_list;
}

void AccountsList::on_btn_close_clicked()
{
    close();

}


void AccountsList::on_btn_refreshList_clicked()
{
    ui->lst_accountsList->clear(); // clear old data
    refresh_list();
}

void AccountsList::refresh_list()
{
    // function to refresh list with values from vector

    std::string std = ("Accounts list refreshed.");
    logs_list->push_back(std);

    if (accounts_list->empty())
            return;

    for (size_t i=0; i < accounts_list->size(); i++){
        ui->lst_accountsList->addItem(QString::fromStdString(accounts_list->at(i)->GetClientName()));
        qDebug() << accounts_list->at(i)->GetClientName();
    }

}

