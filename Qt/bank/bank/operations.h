#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QDialog>
#include "account.hpp"

namespace Ui {
class Operations;
}

class Operations : public QDialog
{
    Q_OBJECT

public:
    explicit Operations(QWidget *parent = nullptr);
    ~Operations();

    void SetAccounts(std::vector<ContaCorrente*> *t_accounts_list);
    void SetLogs(std::vector<std::string> *t_logs_list);

    std::vector<ContaCorrente*> *accounts_list;
    std::vector<std::string> *logs_list;


private slots:
    void on_btn_completeOperation_clicked();

    void on_rb_transfer_toggled(bool checked);


private:
    Ui::Operations *ui;
};

#endif // OPERATIONS_H
