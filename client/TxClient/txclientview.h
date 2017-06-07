#ifndef TXCLIENTVIEW_H
#define TXCLIENTVIEW_H

#include <QMainWindow>
#include <QList>
#include "webservice.hpp"

namespace Ui {
class TxClientView;
}

class TxClientView : public QMainWindow
{
	Q_OBJECT

public:
	explicit TxClientView(QWidget *parent = 0);
	~TxClientView();

private slots:
	void on_btnDeposit_clicked();

	void on_btnWithdraw_clicked();

	void on_btnTransaction_clicked();

private:
	void initializeTable();
	void initializeComboBoxes();
	void atualizeTable();
	Ui::TxClientView *ui;
	QString user_cpf;
	WebService* web_service;
	Client c;

};

#endif // TXCLIENTVIEW_H
