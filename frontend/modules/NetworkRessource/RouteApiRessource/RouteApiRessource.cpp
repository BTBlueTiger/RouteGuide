#include "RouteApiRessource.h"

#include <QtNetwork/qhttpheaders.h>
#include <QtNetwork/qrestaccessmanager.h>
#include <QtNetwork/qrestreply.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>

RouteApiRessource::RouteApiRessource(QObject *parent)
    : AbstractRessource{parent}
{
    // Base url
    m_url->setScheme("http");
    //m_url->setHost("94.16.31.72");
    m_url->setPort(8080);

    // setting to abstract ressource
    m_api->setBaseUrl(*m_url);

    // setting http headers
    m_headers->append("Content-Type", "application/json");
    m_api->setCommonHeaders(*m_headers);
}

bool RouteApiRessource::createRoute(const QVariantMap& data)
{
        QNetworkReply* response = postRequest(
            *qVariantMapToQByteArray(data),
            m_api->createRequest("/route/create")
            );
        // Verbinden von der angekommenen Nachricht
        qDebug() << data;
        QObject::connect(response, &QNetworkReply::finished, [=](){
            if(response->error() == QNetworkReply::NoError)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    );
    return false;
}
