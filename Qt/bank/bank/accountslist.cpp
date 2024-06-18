#include "accountslist.h"
#include "ui_accountslist.h"

AccountsList::AccountsList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AccountsList)
{
    ui->setupUi(this);

    // run refresh method
    AccountsList::refresh_list();


}

AccountsList::~AccountsList()
{
    delete ui;
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
    ui->lst_accountsList->addItem("João da silva");
    ui->lst_accountsList->addItem("Paulo Jorge da Silva");
    ui->lst_accountsList->addItem("Luiz de Souza");
    ui->lst_accountsList->addItem("Pedro da Silva");
    ui->lst_accountsList->addItem("Amongos sus");

}

