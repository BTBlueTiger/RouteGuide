#include "include/connections/RouteResource.h"
#include "qobjectdefs.h"


RouteResource::RouteResource(QObject* parent) : QObject(parent)
{
    if(m_routingManager != nullptr)
        return;
    QMap<QString,QVariant> params;
    params["osm.geocoding.host"] = "localhost:8080";
    m_geoServiceProvider = new QGeoServiceProvider( "osm", params );
    if (m_geoServiceProvider->error() != QGeoServiceProvider::NoError) {
        qDebug() << "Error initializing GeoServiceProvider:" << m_geoServiceProvider->errorString();
    } else {
        qDebug() << "Service available";
    }
    m_routingManager = m_geoServiceProvider->routingManager();
    if (!m_routingManager) {
        qDebug() << "Routing manager not available from service provider";
    } else {
        qDebug() << "Routing manager available";
    }
}

void RouteResource::setCoordinates(const QList<QGeoCoordinate>& coordinates)
{
    if(m_coordinates != coordinates)
    {
        m_coordinates = coordinates;
        searchQ();
    }
}

void RouteResource::onGeoRouteReply()
{
    QGeoRouteReply *reply = qobject_cast<QGeoRouteReply*>(sender());
    if (reply) {
        if (reply->error() != QGeoRouteReply::NoError)
        {
            emit networkResponse(ResponseType::NetworkError);
        } else {

            if(reply->routes().isEmpty())
            {
                emit networkResponse(ResponseType::Failed);
            }
            else
            {
                emit networkResponse(ResponseType::Success, reply->routes());
            }
        }
        reply->deleteLater();
    } else {
        emit networkResponse(ResponseType::NetworkError);
    }
}

void RouteResource::searchQ()
{
    QGeoRouteRequest request(m_coordinates);
    QGeoRouteReply *reply = m_routingManager->calculateRoute(request);
    connect(reply, &QGeoRouteReply::finished, this, &RouteResource::onGeoRouteReply);
}

void RouteResource::routeCalculated(QGeoRouteReply *reply)
{
    emit networkResponse(ResponseType::Success, reply->routes());
    reply->deleteLater();
}


void RouteResource::routeError(QGeoRouteReply *reply)
{
    qDebug() << reply->errorString();
    emit networkResponse(ResponseType::Failed);
    reply->deleteLater();
}

