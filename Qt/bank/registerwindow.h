#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <vector>
#include "account.hpp"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT


public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

    void addVector(std::vector<ContaCorrente*> *t_accounts_list);
    std::vector<std::string> *logs_list;
    void SetLogs(std::vector<std::string> *t_logs_list);
private slots:

    void on_checkspecialAcc_stateChanged(int arg1);

    void on_buttonBox_accepted();

private:
    std::vector<ContaCorrente*> *accounts_list;

    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
