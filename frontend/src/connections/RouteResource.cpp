#include "include/connections/RouteResource.h"
#include "qobjectdefs.h"


RouteResource::RouteResource(QObject* parent) : QObject(parent)
{

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

