#include "txclientview.h"
#include <QApplication>
#include "client.h"
#include <QJsonDocument>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TxClientView w;
	w.show();

	return a.exec();
}
