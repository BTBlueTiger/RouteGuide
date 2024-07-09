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

        ~WaypointManager();

        Q_INVOKABLE WaypointModel* createWaypointModel(const QString& modelName);
        Q_INVOKABLE WaypointModel* getWaypointModel(const QString& modelName);

        Q_INVOKABLE void addItemToWaypointModel(const QString& modelName, WaypointModelItem* item);
        Q_INVOKABLE void removeItemFromWaypointModel(const QString& modelName, int index);

        Q_INVOKABLE void searchWithLocationResource(const QString& request, const QString& model);
        Q_INVOKABLE void clearModels()
        {
            qDeleteAll(m_waypointModels);
            m_waypointModels.clear();
        }


    private:
        QMap<QString, WaypointModel*> m_waypointModels;
        LocationResource m_nominatimRessource;

    signals:
        void waypointRoutChanged();
        void onWayPointModelChanged();
    public slots:


    };

}

#endif // WAYPOINTMODELMANAGER_H
