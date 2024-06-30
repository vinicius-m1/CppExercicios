/********************************************************************************
** Form generated from reading UI file 'logs.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_logs
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *lb_systemLogsTitle;
    QListWidget *lst_logs;
    QToolButton *btn_refreshList;

    void setupUi(QDialog *logs)
    {
        if (logs->objectName().isEmpty())
            logs->setObjectName("logs");
        logs->resize(400, 310);
        logs->setMinimumSize(QSize(400, 310));
        logs->setMaximumSize(QSize(400, 310));
        verticalLayout_2 = new QVBoxLayout(logs);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(logs);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 51, 56);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        lb_systemLogsTitle = new QLabel(frame);
        lb_systemLogsTitle->setObjectName("lb_systemLogsTitle");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        lb_systemLogsTitle->setFont(font);
        lb_systemLogsTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(lb_systemLogsTitle);

        lst_logs = new QListWidget(frame);
        lst_logs->setObjectName("lst_logs");
        lst_logs->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(lst_logs);

        btn_refreshList = new QToolButton(frame);
        btn_refreshList->setObjectName("btn_refreshList");
        btn_refreshList->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("media-playlist-repeat")));
        btn_refreshList->setIcon(icon);

        verticalLayout->addWidget(btn_refreshList, 0, Qt::AlignRight);


        verticalLayout_2->addWidget(frame);


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
