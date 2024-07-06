#include "AbstractRessource.h"
#include "QJsonDocument"


AbstractRessource::AbstractRessource(QObject *parent)
    : QObject{parent}
{
    m_url = std::make_shared<QUrl>();
    m_headers = std::make_shared<QHttpHeaders>();
    m_manager =  std::make_shared<QNetworkAccessManager>();
    m_api = std::make_shared<QNetworkRequestFactory>();
}

int AbstractRessource::checkedSharedRessources() const
{
    if(!m_manager)
        return -1;
    if(!m_api)
        return -2;
    if(!m_url)
        return -3;
    if(!m_headers)
        return -4;
    return 1;
}

void warnRessourceNotSet(int res)
{
    switch (res) {
    case -1:
        qDebug() << "Manager not set";
        break;
    case -2:
        qDebug() << "Api not set";
        break;
    case -3:
        qDebug() << "Url not set";
        break;
    case -4:
        qDebug() << "Headers not set";
        break;
    default:
        break;
    }
}

std::unique_ptr<QByteArray> AbstractRessource::qVariantMapToQByteArray(const QVariantMap& data)
{
    QJsonDocument doc = QJsonDocument::fromVariant(data);
    return std::make_unique<QByteArray>(doc.toJson());
}

QNetworkReply* AbstractRessource::postRequest(const QByteArray& data, const QNetworkRequest& request)
{
    if(!checkedSharedRessources())
    {
        warnRessourceNotSet(checkedSharedRessources());
        return nullptr;
    }
    return m_manager->post(request, data);
}

QNetworkReply* AbstractRessource::getRequest(const QNetworkRequest& request)
{
    if(!checkedSharedRessources())
    {
        warnRessourceNotSet(checkedSharedRessources());
        return nullptr;
    }
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
