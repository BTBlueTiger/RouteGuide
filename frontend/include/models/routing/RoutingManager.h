#ifndef ROUTINGMANAGER_H
#define ROUTINGMANAGER_H

#include <QObject>


#include "include/connections/RouteResource.h"
#include "include/models/routing/RoutingModel.h"

namespace Routing
{

    class RoutingManager : public QObject {
        Q_OBJECT
    public:

        RoutingManager(QObject* parent = nullptr);
        Q_INVOKABLE RoutingModel* createRoutingModel(const QString& modelName, const QList<QGeoCoordinate>& coordinates);
        Q_INVOKABLE RoutingModel* getModel(const QString& modelName);

    private:
        QMap<QString, RoutingModel*> m_routingModels;

        RouteResource* routeResource;
    };
}

#endif // ROUTINGMANAGER_H
