#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>
#include <QJsonObject>

class Transaction
{
public:
	Transaction();
	Transaction(const int& sender_id,
		    const int& receiver_id,
		    const QString& sender_method,
		    const QString& receiver_method,
		    const double& value);

	bool read(const QJsonObject& json);
	bool write(QJsonObject& json) const;

private:
	static const QString JSON_TYPE;
	int sender_id;
	int receiver_id;
	QString sender_method;
	QString receiver_method;
	double value;
};

#endif // TRANSACTION_H
