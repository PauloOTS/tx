#ifndef CLIENT_H
#define CLIENT_H
#include "account.h"
#include <QString>
#include <QList>

class Account;

class Client
{
public:
	Client(const QString& cpf, const QString& name);
	bool read(const QJsonObject& json);
	bool write(QJsonObject& json) const;
	QList<Account> accounts;

private:
	static const QString JSON_TYPE;
	QString cpf;
	QString name;
};

#endif // CLIENT_H
