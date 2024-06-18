#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QDialog>

namespace Ui {
class Operations;
}

class Operations : public QDialog
{
    Q_OBJECT

public:
    explicit Operations(QWidget *parent = nullptr);
    ~Operations();

private slots:
    void on_btn_completeOperation_clicked();

    void on_rb_transfer_toggled(bool checked);

private:
    Ui::Operations *ui;
};

#endif // OPERATIONS_H
