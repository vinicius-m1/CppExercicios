#include "logs.h"
#include "ui_logs.h"
#include <QDebug>
logs::logs(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::logs)
{
    ui->setupUi(this);
    // run refresh method
    //RefreshList(); //crashes the program
}

logs::~logs()
{
    delete ui;
}

void logs::SetLogs(std::vector<std::string> *t_logs_list)
{
    logs_list = t_logs_list;
}


void logs::on_btn_refreshList_clicked()
{
    // run refresh method
    ui->lst_logs->clear();
    RefreshList();

}

void logs::RefreshList()
{
    std::string std;
    std = "Logs were checked.";
    logs_list->push_back(std);

    if (logs_list->empty())
        return;

    qDebug() << logs_list->size();

    for (size_t i=0; i < logs_list->size(); i++){
        ui->lst_logs->addItem(QString::fromStdString(logs_list->at(i)));
    }

}

