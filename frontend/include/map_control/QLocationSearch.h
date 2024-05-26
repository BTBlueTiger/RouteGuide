#ifndef OPENSTREETMAPMANAGER_H
#define OPENSTREETMAPMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QGeoCoordinate>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class QLocationSearch : public QObject
{
    Q_OBJECT
public:
    explicit QLocationSearch(QObject *parent = nullptr);

    Q_INVOKABLE void searchLocation(const QString &locationName);

signals:
    void locationFound(double latitude, double longitude);
    void errorOccurred(const QString &errorMessage);

private:
    QNetworkAccessManager m_networkManager;
};

#endif // OPENSTREETMAPMANAGER_H
