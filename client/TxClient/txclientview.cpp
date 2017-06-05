#include "txclientview.h"
#include "ui_txclientview.h"
#include <QInputDialog>

TxClientView::TxClientView(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::TxClientView)
{
	ui->setupUi(this);
	this->user_cpf = QInputDialog::getText(this, "Welcome!", "Input your cpf:");
}

TxClientView::~TxClientView()
{
	delete ui;
}
