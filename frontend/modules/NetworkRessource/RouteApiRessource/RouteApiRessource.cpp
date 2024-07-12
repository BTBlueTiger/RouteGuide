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
    m_url->setHost("94.16.31.72");
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

                qDebug() << "Success";
                return true;
            }
            else
            {
                qDebug() << "Failure";
                return false;
            }
        }
    );
    return false;
}

QVariantList RouteApiRessource::getRoutes(int group)
{
    return QVariantList();
}

QVariantList RouteApiRessource::getFakeRoutes()
{
    QVariantList fakeRoutes;

    QVariantMap fakeRoute;
    QVariantMap group;
    QVariantList addresses;
    QVariantMap fakeAddress;

    // First fake route
    group["group_id"] = 1;
    fakeAddress["identifier"] = "Drabertstraße, Westhafen, Nordstadt, Minden, Kreis Minden-Lübbecke, North Rhine – Westphalia, 32425, Germany";
    fakeAddress["longitude"] = "8.8991998";
    fakeAddress["latitude"] = "52.3010161";
    addresses.append(fakeAddress);

    fakeAddress.clear();
    fakeAddress["identifier"] = "";
    fakeAddress["longitude"] = "8.9083147";
    fakeAddress["latitude"] = "52.296182";
    addresses.append(fakeAddress);

    fakeRoute["name"] = "My parcing slot Uni way";
    fakeRoute["public"] = "true";
    fakeRoute["group"] = group;
    addresses.append(fakeAddress);

    fakeAddress.clear();
    fakeAddress["identifier"] = "Porta Markt, Flurweg, Barkhausen, Porta Westfalica, Kreis Minden-Lübbecke, North Rhine – Westphalia, 32457, Germany";
    fakeAddress["longitude"] = "8.9012467869";
    fakeAddress["latitude"] = "52.2593197";
    addresses.append(fakeAddress);

    fakeRoute["adresses"] = addresses;

    fakeRoutes.append(fakeRoute);


    // Second fake route
    // First clear
    group.clear();
    fakeAddress.clear();
    addresses.clear();
    fakeRoute.clear();

    // 2.

    group["group_id"] = 1;
    fakeAddress["identifier"] = "Löhne, Kreis Herford, North Rhine – Westphalia, 32584, Germany";
    fakeAddress["longitude"] = "8.7141587";
    fakeAddress["latitude"] = "52.1990346";
    addresses.append(fakeAddress);

    fakeAddress.clear();
    fakeAddress["identifier"] = "Marktkauf Löhne, 13, Albert-Schweitzer-Straße, Ulenburg, Löhne, Kreis Herford, North Rhine – Westphalia, 32584, Germany";
    fakeAddress["longitude"] = "8.7202042";
    fakeAddress["latitude"] = "52.2070195";
    addresses.append(fakeAddress);

    fakeRoute["name"] = "Jogger Way";
    fakeRoute["public"] = "true";
    fakeRoute["group"] = group;
    fakeRoute["adresses"] = addresses;

    fakeRoutes.append(fakeRoute);


    return fakeRoutes;
}

