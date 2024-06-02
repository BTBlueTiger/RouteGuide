
#include "include/models/waypoint/WaypointModelManager.h"


namespace Waypoint {

    WaypointModel* WaypointManager::createWaypointModel(const QString& modelName)
    {
        WaypointModel* model = new WaypointModel;
        m_waypointModels[modelName] = model;
        return model;
    }


    WaypointModel* WaypointManager::getWaypointModel(const QString& modelName)
    {
        if(m_waypointModels.contains(modelName))
        {
            return m_waypointModels[modelName];
        }
        return nullptr;
    }




    void WaypointManager::searchWithNominatimRessource(const QString& request, const QString& model)
    {
        m_nominatimRessource.setSearch(request);
        connect(&m_nominatimRessource, &LocationResource::networkResponse, m_waypointModels[model], &WaypointModel::onNominatimRessourceResponse);
    }

    void WaypointManager::addItemToWaypointModel(const QString& modelName, WaypointModelItem* item)
    {
        WaypointModel* model = getWaypointModel(modelName);
        if(model != nullptr)
        {
            model->appendModelItem(item);
        }
        else
        {
            qDebug() << modelName << " not found";
        }
    }


    void WaypointManager::removeItemFromWaypointModel(const QString& modelName, int index)
    {
        WaypointModel* model = getWaypointModel(modelName);
        if(model != nullptr)
        {
            model->remove(index);
        }
        else
        {
            qDebug() << modelName << " not found";
        }
    }
}
