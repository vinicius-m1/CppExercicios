#ifndef LOGS_H
#define LOGS_H

#include <QDialog>

namespace Ui {
class logs;
}

class logs : public QDialog
{
    Q_OBJECT

public:
    explicit logs(QWidget *parent = nullptr);

    //logs(std::vector<QString> * t_logs_list){
        //logs_list = t_logs_list;
    //}

    ~logs();

    void SetLogs(std::vector<std::string> *t_logs_list);

private slots:
    void on_btn_refreshList_clicked();

private:
    Ui::logs *ui;
    void RefreshList();
    std::vector<std::string> * logs_list;
};

#endif // LOGS_H
