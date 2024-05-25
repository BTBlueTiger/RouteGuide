#ifndef OPENSTREETMAPMANAGER_H
#define OPENSTREETMAPMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QGeoCoordinate>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "include/models/plan_a_route/PlanARouteModel.h"

class QLocationSearch : public QObject
{
    Q_OBJECT
public:
    explicit QLocationSearch(QObject *parent = nullptr);
    Q_INVOKABLE void searchLocation(const QString &locationName);
    Q_INVOKABLE void searchLocation(const PlanARouteModel* model);

signals:
    void locationFound(double latitude, double longitude);
    void errorOccurred(const QString &errorMessage);

private:
    QNetworkAccessManager m_networkManager;
    QString m_apiPath;
    QString m_locationSearchPath(QString&&);
};

#endif // OPENSTREETMAPMANAGER_H
