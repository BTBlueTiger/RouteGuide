#ifndef WAYPOINTMODELMANAGER_H
#define WAYPOINTMODELMANAGER_H

#include <QObject>

#include "include/connections/LocationResource.h"


#include "WaypointModel.h"
#include "WaypointModelItem.h"

namespace Waypoint{

    class WaypointManager : public QObject {
        Q_OBJECT

    public:

        //Q_PROPERTY(QGeoRoute* geoRoute MEMBER m_geoRoute NOTIFY waypointRoutChanged FINAL)

        Q_INVOKABLE WaypointModel* createWaypointModel(const QString& modelName);
        Q_INVOKABLE WaypointModel* getWaypointModel(const QString& modelName);

        Q_INVOKABLE void addItemToWaypointModel(const QString& modelName, WaypointModelItem* item);
        Q_INVOKABLE void removeItemFromWaypointModel(const QString& modelName, int index);

        Q_INVOKABLE void searchWithNominatimRessource(const QString& request, const QString& model);

        //Q_INVOKABLE QGeoRoute* createGeoRoute(const QString& modelName);



    private:
        QMap<QString, WaypointModel*> m_waypointModels;
        //QGeoRoute* m_geoRoute;
        LocationResource m_nominatimRessource;

    signals:
        void waypointRoutChanged();

    public slots:


    };

}

#endif // WAYPOINTMODELMANAGER_H
