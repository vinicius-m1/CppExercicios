#include "operations.h"
#include "ui_operations.h"

Operations::Operations(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Operations)
{
    ui->setupUi(this);

    ui->pb_progressBar->hide();
    ui->cb_transferAccount->hide();
    ui->lb_accountSelec_2->hide();


    // code to add info to combo boxes


    //


}

Operations::~Operations()
{
    delete ui;
}

void Operations::on_btn_completeOperation_clicked()
{

    ui->pb_progressBar->setEnabled(true);
    ui->pb_progressBar->show();

    // code to select operation



    // ----

    while(ui->pb_progressBar->value() < 100)
        ui->pb_progressBar->setValue(ui->pb_progressBar->value()+1);

    ui->pb_progressBar->hide();
    ui->pb_progressBar->setValue(0);
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

