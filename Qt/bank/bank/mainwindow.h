#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"account.hpp"
#include"client.hpp"
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_accountsList_clicked();

    void on_btn_operations_clicked();

    void on_btn_logs_clicked();

    void on_btn_registerNewAccount_clicked();

private:
    Ui::MainWindow *ui;

    // [                         ] accounts vector here
    std::vector<std::string>logs_list;
    std::vector<Client>clients_list;
    std::vector<ContaCorrente*>accounts_list; //ContaEspecial inherits from ContaCorrente


};
#endif // MAINWINDOW_H
