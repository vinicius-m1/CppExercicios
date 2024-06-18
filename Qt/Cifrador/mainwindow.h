#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cifrador.hpp"

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
    void on_btnencriptar_clicked();

    void on_btndecriptar_clicked();

    void on_key_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Cifrador m_cifrador;
};
#endif // MAINWINDOW_H
