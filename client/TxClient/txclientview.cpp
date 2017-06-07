#include "txclientview.h"
#include "ui_txclientview.h"
#include <QInputDialog>
#include <QMessageBox>

TxClientView::TxClientView(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::TxClientView)
{
	ui->setupUi(this);

	this->web_service = new WebService("localhost", 5000);

	while(1){
		this->user_cpf = QInputDialog::getText(
					this,
					"Welcome!",
					"Input your cpf:");

		if (this->user_cpf != ""){

			try {
				this->c = this	->web_service
						->getClient(this->user_cpf);

			}catch(WebServiceError& e){
				QMessageBox::critical(this, tr("Error"), e.msg);
				continue;
			}
			break;
		}

		QMessageBox::critical(
			this,
			tr("Error"),
			tr("Insert a valid username."));
	}

	this->initializeTable();
	this->initializeComboBoxes();
}

QTableWidgetItem* TxClientView::createTableItem(const QString &value)
{
	return new QTableWidgetItem(value);
}

QTableWidgetItem* TxClientView::createTableItem(int value)
{
	return createTableItem(QString::number(value));
}

QTableWidgetItem* TxClientView::createTableItem(double value)
{
	return createTableItem(QString::number(value));
}

void TxClientView::initializeTable(){

	ui->tableAccounts->setColumnCount(5);
	ui->tableAccounts->setRowCount(this->c.accounts.size());

	QStringList headers;

	ui->tableAccounts
		->horizontalHeader()
		->setSectionResizeMode(QHeaderView::Stretch);

	ui->tableAccounts
		->verticalHeader()
		->setVisible(false);

	ui->tableAccounts
		->setEditTriggers(QAbstractItemView::NoEditTriggers);

	headers <<	tr("Account")
		<<	tr("Branch ID")
		<<	tr("Bank")
		<<	tr("Balance")
		<<	tr("Saving");

	ui->tableAccounts
		->setHorizontalHeaderLabels(headers);

	int row = 0;
	for (Account& c : this->c.accounts){
		ui->tableAccounts->setItem(row, 0,
			createTableItem(c.getId()));

		ui->tableAccounts->setItem(row, 1,
			createTableItem(c.getBranch_id()));

		ui->tableAccounts->setItem(row, 2,
			createTableItem(c.getBank_name()));

		ui->tableAccounts->setItem(row, 3,
			createTableItem(c.getBalance()));

		ui->tableAccounts->setItem(row, 4,
			createTableItem(c.getSaving()));

		row++;
	}
}

void TxClientView::initializeComboBoxes(){
	ui->comboDeposit->addItem("Saving");
	ui->comboDeposit->addItem("Current");
	ui->comboReceiver->addItem("Saving");
	ui->comboReceiver->addItem("Current");
	ui->comboWithdraw->addItem("Saving");
	ui->comboWithdraw->addItem("Current");
	ui->ComboSender->addItem("Saving");
	ui->ComboSender->addItem("Current");
}

void TxClientView::atualizeTable()
try{
	this->c = this->web_service->getClient(this->user_cpf);
	ui->tableAccounts->setRowCount(this->c.accounts.size());

	int row = 0;
	for (Account& c : this->c.accounts){
		ui->tableAccounts->setItem(row, 0,
			createTableItem(c.getId()));

		ui->tableAccounts->setItem(row, 1,
			createTableItem(c.getBranch_id()));

		ui->tableAccounts->setItem(row, 2,
			createTableItem(c.getBank_name()));

		ui->tableAccounts->setItem(row, 3,
			createTableItem(c.getBalance()));

		ui->tableAccounts->setItem(row, 4,
			createTableItem(c.getSaving()));


		row++;
	}
}catch(WebServiceError& e){
	QMessageBox::critical(this, tr("Error"), e.msg);
}


TxClientView::~TxClientView()
{
	delete ui;
}


void TxClientView::on_btnDeposit_clicked()
try{
	int i = ui->tableAccounts->itemAt(0, ui->tableAccounts->currentRow())->text().toInt();
	double d = ui->lineDeposit->text().toDouble();
	QString s = ui->comboDeposit->currentText().toLower();
	Deposit dep(i, d, s);

	QString r = this->web_service->deposit(dep);
	QMessageBox::information(this, "Result", r, QMessageBox::Ok);

	this->atualizeTable();

}catch(WebServiceError& e){
	QMessageBox::critical(this, tr("Error"), e.msg);
}

void TxClientView::on_btnWithdraw_clicked()
try{
	int i = ui->tableAccounts
		->itemAt(0, ui->tableAccounts->currentRow())
		->text().toInt();

	double d = ui->lineWithdraw->text().toDouble();
	QString s = ui->comboWithdraw->currentText().toLower();
	Withdraw w(i, d, s);

	QString r = this->web_service->withdraw(w);
	QMessageBox::information(this, "Result", r, QMessageBox::Ok);
	this->atualizeTable();

}catch(WebServiceError& e){
	QMessageBox::critical(this, tr("Error"), e.msg);
}

void TxClientView::on_btnTransaction_clicked()
try{
	int s_id = ui
		->tableAccounts
		->itemAt(0, ui->tableAccounts->currentRow())
		->text().toInt();

	int r_id = ui->lineReceiver->text().toInt();
	QString s_m = ui->ComboSender->currentText().toLower();
	QString r_m = ui->comboReceiver->currentText().toLower();
	double v = ui->lineTransaction->text().toDouble();
	Transaction t(s_id, r_id, s_m, r_m, v);

	QString r = this->web_service->transaction(t);
	QMessageBox::information(this, "Result", r, QMessageBox::Ok);
	this->atualizeTable();
}catch(WebServiceError& e){
	QMessageBox::critical(this, tr("Error"), e.msg);
}
