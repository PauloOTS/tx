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
		this->user_cpf = QInputDialog::getText(this, "Welcome!", "Input your cpf:");
		if (this->user_cpf != ""){


			try {
				this->c = this->web_service->getClient(this->user_cpf);
			}catch(WebServiceError& e){
				QMessageBox::critical(this, tr("Error"), e.msg);
				continue;
			}
			break;
		}

		QMessageBox::critical(
		    this,
		    tr("Error"),
		    tr("Insert a valid username.") );
	}


	this->initializeTable();
	this->initializeComboBoxes();
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

	for (int i = 0; i < this->c.accounts.size(); i++){
		ui->tableAccounts->setItem(i, 0, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getId())));
		ui->tableAccounts->setItem(i, 1, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getBranch_id())));
		ui->tableAccounts->setItem(i, 2, new QTableWidgetItem(this->c.accounts.at(i).getBank_name()));
		ui->tableAccounts->setItem(i, 3, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getBalance())));
		ui->tableAccounts->setItem(i, 4, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getSaving())));
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

void TxClientView::atualizeTable(){
	this->c = this->web_service->getClient(this->user_cpf);
	ui->tableAccounts->setRowCount(this->c.accounts.size());

	for (int i = 0; i < this->c.accounts.size(); i++){
		ui->tableAccounts->setItem(i, 0, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getId())));
		ui->tableAccounts->setItem(i, 1, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getBranch_id())));
		ui->tableAccounts->setItem(i, 2, new QTableWidgetItem(this->c.accounts.at(i).getBank_name()));
		ui->tableAccounts->setItem(i, 3, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getBalance())));
		ui->tableAccounts->setItem(i, 4, new QTableWidgetItem(QString::number(this->c.accounts.at(i).getSaving())));
	}
}


TxClientView::~TxClientView()
{
	delete ui;
}


void TxClientView::on_btnDeposit_clicked(){
	int i = ui->tableAccounts->itemAt(0, ui->tableAccounts->currentRow())->text().toInt();
	double d = ui->lineDeposit->text().toDouble();
	QString s = ui->comboDeposit->currentText().toLower();
	Deposit dep(i, d, s);

	try{
		this->web_service->deposit(dep);
	}catch(WebServiceError& e){
		QMessageBox::critical(this, tr("Error"), e.msg);
	}

	this->atualizeTable();
}


void TxClientView::on_btnWithdraw_clicked()
{
	int i = ui->tableAccounts->itemAt(0, ui->tableAccounts->currentRow())->text().toInt();
	double d = ui->lineWithdraw->text().toDouble();
	QString s = ui->comboWithdraw->currentText().toLower();
	Withdraw w(i, d, s);

	try{
		QString r = this->web_service->withdraw(w);
		qDebug() << r;
	}catch(WebServiceError& e){
		QMessageBox::critical(this, tr("Error"), e.msg);
	}

	this->atualizeTable();
}

void TxClientView::on_btnTransaction_clicked()
{
	int s_id = ui->tableAccounts->itemAt(0, ui->tableAccounts->currentRow())->text().toInt();
	int r_id = ui->lineReceiver->text().toInt();
	QString s_m = ui->ComboSender->currentText().toLower();
	QString r_m = ui->comboReceiver->currentText().toLower();
	double v = ui->lineTransaction->text().toDouble();
	Transaction t(s_id, r_id, s_m, r_m, v);

	try{
		this->web_service->transaction(t);
	}catch(WebServiceError& e){
		QMessageBox::critical(this, tr("Error"), e.msg);
	}

	this->atualizeTable();
}
