#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "accountslist.h"
#include "operations.h"

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
    AccountsList accountsList;
    accountsList.setModal(true);
    //accountsList.setAttribute(Qt::WA_DeleteOnClose);
    accountsList.exec();


}


void MainWindow::on_btn_operations_clicked()
{
    // show operations form
    Operations operations;
    operations.setModal(true);
    operations.exec();

}

