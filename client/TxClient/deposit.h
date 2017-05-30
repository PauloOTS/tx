#ifndef DEPOSIT_H
#define DEPOSIT_H
#include <QString>
#include <QJsonObject>

class Deposit
{
public:
	Deposit();
	Deposit(const int& account_id, const double& value, const QString& deposit_method);
	bool write(QJsonObject& json) const;
	bool read(QJsonObject& json);

private:
	static const QString JSON_TYPE;
	int account_id;
	double value;
	QString deposit_method;
};

#endif // DEPOSIT_H
