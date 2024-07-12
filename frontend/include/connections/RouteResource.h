#ifndef ROUTERESOURCE_H
#define ROUTERESOURCE_H

#include "ResponseType.h"

#include <QGeoRoutingManager>
#include <QGeoRouteRequest>
#include <QGeoRouteReply>
#include <QGeoServiceProvider>
#include <QGeoCoordinate>
#include <QMap>

class RouteResource : public QObject
{
    Q_OBJECT
public:
    RouteResource(QObject *parent = nullptr);


    void setCoordinates(const QList<QGeoCoordinate>& coordinates);

private:
    QList<QGeoCoordinate> m_coordinates;
    QGeoServiceProvider* m_geoServiceProvider;
    QGeoRoutingManager* m_routingManager;
    void searchQ();

signals:
    void networkResponse(ResponseType responseType, const QList<QGeoRoute>& routes = QList<QGeoRoute>());

private slots:
    void onGeoRouteReply();

    void routeCalculated(QGeoRouteReply *reply);

    void routeError(QGeoRouteReply *reply);

};

#endif // ROUTERESOURCE_H
