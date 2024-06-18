#ifndef ACCOUNTSLIST_H
#define ACCOUNTSLIST_H

#include <QDialog>

namespace Ui {
class AccountsList;
}

class AccountsList : public QDialog
{
    Q_OBJECT

public:
    explicit AccountsList(QWidget *parent = nullptr);
    ~AccountsList();

private slots:
    void on_btn_close_clicked();

    void on_btn_refreshList_clicked();

private:
    Ui::AccountsList *ui;
    void refresh_list();
};

#endif // ACCOUNTSLIST_H
