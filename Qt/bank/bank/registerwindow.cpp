#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <iostream>
RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::addVector(std::vector<ContaCorrente*> *t_accounts_list){
    accounts_list = t_accounts_list;
}

void RegisterWindow::SetLogs(std::vector<std::string> *t_logs_list)
{
    logs_list = t_logs_list;
}

void RegisterWindow::on_checkspecialAcc_stateChanged(int arg1)
{
        ui->LimitSpinF->setEnabled(arg1==2);
}


void RegisterWindow::on_buttonBox_accepted()
{
    if(ui->checkspecialAcc->checkState()==2){
        std::cout<<"registered special acc"<<std::endl;
        logs_list->push_back(std::string("Special Account Registered. - " + ui->FullName->text().toStdString()));
        accounts_list->push_back(new ContaEspecial(new Client(ui->FullName->text().toStdString(),ui->Address->text().toStdString(),ui->Job->text().toStdString(),ui->Income->value()),0,ui->LimitSpinF->value()));
    }else{
        std::cout<<"registered niormal acc"<<std::endl;
        logs_list->push_back(std::string("Normal Account Registered. - "+ ui->FullName->text().toStdString()));
        accounts_list->push_back(new ContaCorrente(new Client(ui->FullName->text().toStdString(),ui->Address->text().toStdString(),ui->Job->text().toStdString(),ui->Income->value()),0));
    }

}

