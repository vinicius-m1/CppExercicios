#ifndef ACCOUNTSLIST_H
#define ACCOUNTSLIST_H

#include <QDialog>
#include "account.hpp"

namespace Ui {
class AccountsList;
}

class AccountsList : public QDialog
{
    Q_OBJECT

public:
    explicit AccountsList(QWidget *parent = nullptr);
    ~AccountsList();

    void SetAccounts(std::vector<ContaCorrente*> *t_accounts_list);
    void SetLogs(std::vector<std::string> *t_logs_list);

    std::vector<ContaCorrente*> *accounts_list;
    std::vector<std::string> *logs_list;

private slots:
    void on_btn_close_clicked();

    void on_btn_refreshList_clicked();

private:
    Ui::AccountsList *ui;
    void refresh_list();
};

#endif // ACCOUNTSLIST_H
