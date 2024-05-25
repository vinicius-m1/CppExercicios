#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::janela)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMORE_clicked()
{
    ui->progBar->setValue(ui->progBar->value() + 10) ;
    //ui->centralwidget->resize(100, 100);      works kinda
    //ui->centralwidget->setGeometry(200, 100); nope
    //ui->setFixedSize(500,600);                nope
    //ui->resize(100, 100);                     nope
}


void MainWindow::on_progBar_valueChanged(int value)
{
    int progress = ui->progBar->value();

    if (progress > int(ui->progBar->maximum()/2)){
        ui->progBar->setMaximum(progress*3);

    };
}

