
#include "include/models/waypoint/WaypointModelManager.h"


namespace Waypoint {

    WaypointManager::~WaypointManager()
    {
        qDeleteAll(m_waypointModels);
        m_waypointModels.clear();
    }

    WaypointModel* WaypointManager::createWaypointModel(const QString& modelName)
    {
        WaypointModel* model = new WaypointModel(this);
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


    void WaypointManager::searchWithLocationResource(const QString& request, const QString& model)
    {
        if(!m_waypointModels[model]->isConnectedToLocationRessource())
        {
            connect(&m_nominatimRessource, &LocationResource::networkResponse,
                    m_waypointModels[model], &WaypointModel::onNominatimRessourceResponse);
            m_waypointModels[model]->setIsConnectedToLocationRessource();
        }


        m_nominatimRessource.setSearch(request);
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
