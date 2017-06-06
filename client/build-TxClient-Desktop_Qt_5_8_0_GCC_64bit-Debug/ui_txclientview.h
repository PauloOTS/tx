/********************************************************************************
** Form generated from reading UI file 'txclientview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TXCLIENTVIEW_H
#define UI_TXCLIENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TxClientView
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableWidget *tableAccounts;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelDeposit;
    QLineEdit *lineDeposit;
    QPushButton *btnDeposit;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelWithdraw;
    QLineEdit *lineWithdraw;
    QPushButton *btnWithdraw;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnTransaction;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineTransaction;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelReceiver;
    QLabel *labelTransaction;
    QLineEdit *lineReceiver;

    void setupUi(QMainWindow *TxClientView)
    {
        if (TxClientView->objectName().isEmpty())
            TxClientView->setObjectName(QStringLiteral("TxClientView"));
        TxClientView->resize(612, 419);
        centralWidget = new QWidget(TxClientView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableAccounts = new QTableWidget(groupBox);
        tableAccounts->setObjectName(QStringLiteral("tableAccounts"));

        gridLayout->addWidget(tableAccounts, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelDeposit = new QLabel(groupBox_2);
        labelDeposit->setObjectName(QStringLiteral("labelDeposit"));

        horizontalLayout->addWidget(labelDeposit);

        lineDeposit = new QLineEdit(groupBox_2);
        lineDeposit->setObjectName(QStringLiteral("lineDeposit"));

        horizontalLayout->addWidget(lineDeposit);

        btnDeposit = new QPushButton(groupBox_2);
        btnDeposit->setObjectName(QStringLiteral("btnDeposit"));

        horizontalLayout->addWidget(btnDeposit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelWithdraw = new QLabel(groupBox_3);
        labelWithdraw->setObjectName(QStringLiteral("labelWithdraw"));

        horizontalLayout_2->addWidget(labelWithdraw);

        lineWithdraw = new QLineEdit(groupBox_3);
        lineWithdraw->setObjectName(QStringLiteral("lineWithdraw"));

        horizontalLayout_2->addWidget(lineWithdraw);

        btnWithdraw = new QPushButton(groupBox_3);
        btnWithdraw->setObjectName(QStringLiteral("btnWithdraw"));

        horizontalLayout_2->addWidget(btnWithdraw);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnTransaction = new QPushButton(groupBox_4);
        btnTransaction->setObjectName(QStringLiteral("btnTransaction"));

        horizontalLayout_3->addWidget(btnTransaction);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 1, 1, 1);

        lineTransaction = new QLineEdit(groupBox_4);
        lineTransaction->setObjectName(QStringLiteral("lineTransaction"));

        gridLayout_3->addWidget(lineTransaction, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        labelReceiver = new QLabel(groupBox_4);
        labelReceiver->setObjectName(QStringLiteral("labelReceiver"));

        gridLayout_3->addWidget(labelReceiver, 1, 0, 1, 1);

        labelTransaction = new QLabel(groupBox_4);
        labelTransaction->setObjectName(QStringLiteral("labelTransaction"));

        gridLayout_3->addWidget(labelTransaction, 0, 0, 1, 1);

        lineReceiver = new QLineEdit(groupBox_4);
        lineReceiver->setObjectName(QStringLiteral("lineReceiver"));

        gridLayout_3->addWidget(lineReceiver, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 3, 0, 2, 1);

        TxClientView->setCentralWidget(centralWidget);
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();

        retranslateUi(TxClientView);

        QMetaObject::connectSlotsByName(TxClientView);
    } // setupUi

    void retranslateUi(QMainWindow *TxClientView)
    {
        TxClientView->setWindowTitle(QApplication::translate("TxClientView", "TxClientView", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TxClientView", "Balance", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TxClientView", "Deposit", Q_NULLPTR));
        labelDeposit->setText(QApplication::translate("TxClientView", "Deposit Value: ", Q_NULLPTR));
        btnDeposit->setText(QApplication::translate("TxClientView", "Confirm", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("TxClientView", "Withdraw", Q_NULLPTR));
        labelWithdraw->setText(QApplication::translate("TxClientView", "Withdraw Value:", Q_NULLPTR));
        btnWithdraw->setText(QApplication::translate("TxClientView", "Confirm", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("TxClientView", "Transaction", Q_NULLPTR));
        btnTransaction->setText(QApplication::translate("TxClientView", "Confirm", Q_NULLPTR));
        labelReceiver->setText(QApplication::translate("TxClientView", "Receiver Account", Q_NULLPTR));
        labelTransaction->setText(QApplication::translate("TxClientView", "Transaction Value", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TxClientView: public Ui_TxClientView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TXCLIENTVIEW_H
