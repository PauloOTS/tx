#include "txclientview.h"
#include "ui_txclientview.h"

TxClientView::TxClientView(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::TxClientView)
{
	ui->setupUi(this);
}

TxClientView::~TxClientView()
{
	delete ui;
}
