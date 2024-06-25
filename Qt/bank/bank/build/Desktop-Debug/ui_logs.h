/********************************************************************************
** Form generated from reading UI file 'logs.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGS_H
#define UI_LOGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_logs
{
public:
    QFrame *frame;
    QLabel *lb_systemLogsTitle;
    QListWidget *lst_logs;
    QToolButton *btn_refreshList;

    void setupUi(QDialog *logs)
    {
        if (logs->objectName().isEmpty())
            logs->setObjectName("logs");
        logs->resize(421, 300);
        logs->setMinimumSize(QSize(421, 300));
        logs->setMaximumSize(QSize(421, 300));
        frame = new QFrame(logs);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -10, 411, 311));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lb_systemLogsTitle = new QLabel(frame);
        lb_systemLogsTitle->setObjectName("lb_systemLogsTitle");
        lb_systemLogsTitle->setGeometry(QRect(20, 20, 131, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        lb_systemLogsTitle->setFont(font);
        lst_logs = new QListWidget(frame);
        lst_logs->setObjectName("lst_logs");
        lst_logs->setGeometry(QRect(30, 50, 361, 231));
        btn_refreshList = new QToolButton(frame);
        btn_refreshList->setObjectName("btn_refreshList");
        btn_refreshList->setGeometry(QRect(350, 286, 24, 22));
        btn_refreshList->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-playlist-repeat")));
        btn_refreshList->setIcon(icon);

        retranslateUi(logs);

        QMetaObject::connectSlotsByName(logs);
    } // setupUi

    void retranslateUi(QDialog *logs)
    {
        logs->setWindowTitle(QCoreApplication::translate("logs", "Dialog", nullptr));
        lb_systemLogsTitle->setText(QCoreApplication::translate("logs", "<html><head/><body><p>\360\237\247\276\357\270\217 System Logs</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        btn_refreshList->setToolTip(QCoreApplication::translate("logs", "Refresh", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_refreshList->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class logs: public Ui_logs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGS_H
