#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "client.h"
#include <QJsonObject>

class Account
{
public:
	Account(const int& id,
		const QString& client_cpf,
		const int& branch_id,
		const int& bank_id,
		const QString& bank_name,
		const double& balance,
		const double& saving);
		
	bool read(const QJsonObject& json);
	bool write(QJsonObject& json) const;
	
private:
	static const QString JSON_TYPE; 
	int id;        
	QString client_cpf; 
	int branch_id; 
	int bank_id;   
	QString bank_name; 
	double balance;   
	double saving;    
};

#endif // ACCOUNT_H
