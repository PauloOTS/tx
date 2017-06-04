#include "txclientview.h"
#include <QApplication>
#include <QDebug>

#include "webservice.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TxClientView w;
	w.show();

	try{
		WebService webservice("localhost", 5000);

		Deposit d(0, 10.0, "saving");
		qDebug() << webservice.deposit(d);

	}catch(WebServiceError& error){
		qDebug() << error.msg;
	}

	return a.exec();
}
