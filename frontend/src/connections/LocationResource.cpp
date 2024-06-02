#include "include/connections/LocationResource.h"



LocationResource::LocationResource(QObject *parent): AbstractResource(parent)
{
    url->setScheme("http");
    url->setHost("192.168.178.23");
    url->setPort(8080);
    m_api->setBaseUrl(*url);

}

void LocationResource::setSearch(const QString& search)
{
    if(m_search != search)
    {
        m_search = search;
        searchQ();
    }
}

void LocationResource::searchQ()
{
    if(m_search.isEmpty())
        return;
    QString requestString = "search?q=";
    requestString += m_search;
    qDebug() << requestString;
    QNetworkReply *reply = getRequest(m_api->createRequest(requestString));
    connect(reply, &QNetworkReply::finished, this, &LocationResource::networkRequestFinished);
}

void LocationResource::networkRequestFinished() {
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply) {
        if (reply->error() != QNetworkReply::NoError)
        {
            emit networkResponse(ResponseType::NetworkError);
        } else {
            QByteArray responseData = reply->readAll();
            if (responseData.isEmpty())
            {
                emit networkResponse(ResponseType::Failed);
            }
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            const QJsonArray jsonArray = jsonDoc.array();
            if(jsonArray.isEmpty())
            {
                emit networkResponse(ResponseType::Failed);
            }
            else
            {
                emit networkResponse(ResponseType::Success, jsonArray);
            }
        }
        reply->deleteLater();
    } else {
        emit networkResponse(ResponseType::NetworkError);
    }
}
