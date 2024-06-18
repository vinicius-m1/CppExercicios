#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_cifrador.CreateTable(5);
    ui->key->setValue(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnencriptar_clicked()
{
    QString input = ui->txt_input->toPlainText();
    string inputstr = input.toStdString();

    string outputstr = m_cifrador.Encrypt(inputstr);
    QString output = outputstr.c_str();
    ui->txt_output->setText(output);
}


void MainWindow::on_btndecriptar_clicked()
{
    QString input = ui->txt_output->toPlainText();
    string inputstr = input.toStdString();

    string outputstr = m_cifrador.Decrypt(inputstr);
    QString output = outputstr.c_str();
    ui->txt_input->setText(output);
}


void MainWindow::on_key_valueChanged(int arg1)
{
    size_t novoValor = ui->key->value();
    m_cifrador.CreateTable(novoValor);


}

