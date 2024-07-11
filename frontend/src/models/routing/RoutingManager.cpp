#include "include/models/routing/RoutingManager.h"


namespace Routing
{
    RoutingManager::RoutingManager(QObject* parent) : QObject(parent)
    {
        routeResource = new RouteResource(this);
    }

    RoutingModel* RoutingManager::createRoutingModel(const QString& modelName, const QList<QGeoCoordinate>& coordinates)
    {
        RoutingModel* model = new RoutingModel(this);
        m_routingModels[modelName] = model;
        routeResource->setCoordinates(coordinates);
        connect(routeResource, &RouteResource::networkResponse, model, &RoutingModel::onGeoRouteReply);
        return model;
    }

    RoutingModel* RoutingManager::getModel(const QString& modelName)
    {
        if(m_routingModels.contains(modelName))
        {
            return m_routingModels[modelName];
        }
        return nullptr;
    }

}
