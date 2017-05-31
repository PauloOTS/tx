#include "webservice.hpp"

const QString WebServiceError::JSON_TYPE = "error";

WebServiceError::WebServiceError()
{}

WebServiceError::WebServiceError(const QString& msg, int code)
{
	this->msg = msg;
	this->code = code;
}

bool WebServiceError::read(const QJsonObject &json)
{
	if(json["type"] != WebServiceError::JSON_TYPE)
		return false;

	this->msg = json["msg"].toString();

	return true;
}

WebService::WebService(const std::string& ip, short port)
{
	this->ip = ip;
	this->port = port;
}

Account WebService::getAccount(int id)
{
	const std::string path = "/accounts/" + std::to_string(id);
	QJsonObject j = requestJson(path);

	Account a;
	if(!a.read(j))
		throw WebServiceError("Cannot read server response", -1);

	return a;
}

Client WebService::getClient(const QString& cpf)
{
	const std::string path = "/clients/" + cpf.toStdString();
	QJsonObject j = requestJson(path);

	Client c;
	if(!c.read(j))
		throw WebServiceError("Cannot read server response", -1);

	return c;
}

std::string WebService::request(
	const std::string &path,
	const std::string &method)
{
	curlpp::Cleanup cleanup;

	curlpp::Easy request;
	std::stringstream s;

	std::string url = this->ip
			+ ":"
			+ std::to_string(this->port)
			+ path;

	request.setOpt(new curlpp::options::CustomRequest(method));
	request.setOpt(new curlpp::options::Url(url));
	request.setOpt(new curlpp::options::WriteStream(&s));
	request.perform();

	int code = curlpp::infos::ResponseCode::get(request);
	if(code >= 300){
		WebServiceError error;
		error.code = code;

		error.read(strToJson(s.str()));
		throw error;
	}

	return s.str();
}

QJsonObject WebService::strToJson(const std::string& s)
{
	QByteArray array(s.c_str(), s.size());
	return QJsonDocument::fromJson(array).object();
}

QJsonObject WebService::requestJson(
	const std::string& path,
	const std::string& method)
{
	return strToJson(request(path, method));
}
