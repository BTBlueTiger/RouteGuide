#include "include/map_control/QLocationSearch.h"


QLocationSearch::QLocationSearch(QObject *parent) : QObject(parent)
{
    m_apiPath = QString("http://localhost:8080/");

    /*
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
*/
}

QString QLocationSearch::m_locationSearchPath(QString&& location)
{
    QString path = m_apiPath;
    path += "/search.php?=";
    path += location;
    return path;
}

void QLocationSearch::searchLocation(const QString &locationName)
{
    const QString apiUrl = QString("https://nominatim.openstreetmap.org/search?q=%1&format=json").arg(locationName);
    qDebug() << apiUrl;
    QNetworkReply *reply = m_networkManager.get(QNetworkRequest(QUrl(apiUrl)));
    connect(reply, &QNetworkReply::errorOccurred, this, [this](QNetworkReply::NetworkError error) {
        emit errorOccurred(&"Network error: " [error]);
    });
}

void QLocationSearch::searchLocation(const PlanARouteModel* model)
{
    const QVector<WaypointModel*> models =  model->waypointModels();
    QStringList locations;
    for (WaypointModel* model : models) {
        QString place;
        place += model->town();
        place += " ";
        place += model->street();
        place += " ";
        for(QString stop: model->houseNumbers())
        {
            QString explicitStop;
            explicitStop += place;
            explicitStop += stop;
            locations.append(explicitStop);
        }
    }
    for(const QString& explicitStop: locations)
    {
        qDebug() << explicitStop;
    }
}
