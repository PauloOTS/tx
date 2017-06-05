#ifndef TXCLIENTVIEW_H
#define TXCLIENTVIEW_H

#include <QMainWindow>

namespace Ui {
class TxClientView;
}

class TxClientView : public QMainWindow
{
	Q_OBJECT

public:
	explicit TxClientView(QWidget *parent = 0);
	~TxClientView();

private:
	Ui::TxClientView *ui;
	QString user_cpf;
};

#endif // TXCLIENTVIEW_H
