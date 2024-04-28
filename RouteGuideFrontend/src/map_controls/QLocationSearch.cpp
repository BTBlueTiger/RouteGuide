#include "include/map_control/QLocationSearch.h"


QLocationSearch::QLocationSearch(QObject *parent) : QObject(parent)
{
    connect(&m_networkManager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply)
    {
        if (reply->error() != QNetworkReply::NoError)
        {
            emit errorOccurred(reply->errorString());
            reply->deleteLater();
            return;
        }
        const QByteArray data = reply->readAll();
        const QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

        QJsonArray jsonArray = jsonDoc.array();
        if (jsonArray.isEmpty()) {
            // Handle empty JSON array
            return;
        }

        QJsonObject firstObject = jsonArray.at(0).toObject();
        QString latitude = firstObject.value("lat").toString();
        QString longitude = firstObject.value("lon").toString();

        // Convert latitude and longitude to double if needed
        double latValue = latitude.toDouble();
        double lonValue = longitude.toDouble();

        emit locationFound(latValue, lonValue);

        reply->deleteLater();
    });
}

void QLocationSearch::searchLocation(const QString &locationName)
{
    const QString apiUrl = QString("https://nominatim.openstreetmap.org/search?q=%1&format=json").arg(locationName);
    QNetworkReply *reply = m_networkManager.get(QNetworkRequest(QUrl(apiUrl)));
    connect(reply, &QNetworkReply::errorOccurred, this, [this](QNetworkReply::NetworkError error) {
        emit errorOccurred(&"Network error: " [error]);
    });

}
