#ifndef WITHDRAW_H
#define WITHDRAW_H
#include <QString>
#include <QJsonObject>

class Withdraw
{
public:
	Withdraw();
	Withdraw(const int& account_id, const double& value, const QString& withdraw_method);
	bool write(QJsonObject& json) const;
	bool read(QJsonObject& json);
private:
	static const QString JSON_TYPE;
	int account_id;
	double value;
	QString withdraw_method;
};

#endif // WITHDRAW_H
