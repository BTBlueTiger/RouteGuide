#include "AbstractRessource.h"
#include "QJsonDocument"


AbstractRessource::AbstractRessource(QObject *parent)
    : QObject{parent}
{}


std::unique_ptr<QByteArray> AbstractRessource::qVariantMapToQByteArray(const QVariantMap& data)
{
    QJsonDocument doc = QJsonDocument::fromVariant(data);
    return std::make_unique<QByteArray>(doc.toJson());
}

QNetworkReply* AbstractRessource::postRequest(const QByteArray& data, const QNetworkRequest& request)
{
    return m_manager->post(request, data);
}

QNetworkReply* AbstractRessource::getRequest(const QNetworkRequest& request)
{
    return m_manager->get(request);
}

void AbstractRessource::setAccessManager(std::shared_ptr<QNetworkAccessManager> manager)
{
    m_manager = manager;
}

void AbstractRessource::setServiceApi(std::shared_ptr<QNetworkRequestFactory> serviceApi)
{
    m_api = serviceApi;
}

void AbstractRessource::setServiceURL(std::shared_ptr<QUrl> serviceURL)
{
    m_url = serviceURL;
}

void AbstractRessource::setHttpHeaders(std::shared_ptr<QHttpHeaders> httpHeaders)
{
    m_headers = httpHeaders;
}
