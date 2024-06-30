#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "accountslist.h"
#include "operations.h"
#include "logs.h"
#include "account.hpp"
#include "registerwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_accountsList_clicked()
{
    //Client client("Antonio Carlos", "Rua X", "Professor", 200000);
    //ContaCorrente c1(&client);
    //accounts_list.push_back(c1);

    AccountsList accountsList;
    accountsList.SetAccounts(&accounts_list); //pass accounts
    accountsList.SetLogs(&logs_list); // pass log

    accountsList.setModal(true);
    //accountsList.setAttribute(Qt::WA_DeleteOnClose);
    accountsList.exec();


}


void MainWindow::on_btn_operations_clicked()
{
    //Client client("Joao pedras", "Rua Xaa", "Estudante", 0);
    //ContaCorrente c8(&client);
    //accounts_list.push_back(c8);

    //qDebug() << c8.GetClientName();
    // show operations form
    Operations operations; //pass logs and accounts
    operations.SetAccounts(&accounts_list);
    operations.SetLogs(&logs_list);



    operations.setModal(true);
    operations.exec();

}


void MainWindow::on_btn_logs_clicked()
{
    // show operations form
    logs logs_window;
    logs_window.SetLogs(&logs_list); //pass logs
    logs_window.setModal(true);
    logs_window.exec();

}


void MainWindow::on_btn_registerNewAccount_clicked()
{
    RegisterWindow register_window;
    register_window.addVector(&accounts_list);
    register_window.SetLogs(&logs_list);

    register_window.setModal(true);
    register_window.exec();
}

