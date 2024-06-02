
#include "include/models/waypoint/WaypointModel.h"

namespace Waypoint
{

    void Waypoint::WaypointModel::setJsonData(const QJsonArray& array)
    {
        beginResetModel();
        qDeleteAll(m_waypointModelItems);
        m_waypointModelItems.clear();
        beginInsertRows(QModelIndex(), rowCount(), array.size() + 1);
        for(const QJsonValue& value: array)
        {
            m_waypointModelItems.append(
                new WaypointModelItem(
                    value["display_name"].toString(),
                    QGeoCoordinate(
                        value["lat"].toString().toDouble(),
                        value["lon"].toString().toDouble()),
                    this
                    )
                );
        }
        endResetModel();
    }

    void Waypoint::WaypointModel::appendModelItem(WaypointModelItem* item)
    {
        beginResetModel();
        WaypointModelItem* m = new WaypointModelItem(item->displayName(), item->coordinate());
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_waypointModelItems.append(m);
        endResetModel();

    }

    bool Waypoint::WaypointModel::setData(const QModelIndex &index, const QVariant &value, int role)
    {

        if (index.isValid()) {
            switch (role) {
            case DisplayNameRole:
                if (m_waypointModelItems[index.row()]->displayName() != value.toString()) {
                    m_waypointModelItems[index.row()]->setDisplayName(value.toString());
                    emit dataChanged(index, index, { DisplayNameRole, Qt::DisplayRole });
                    return true;
                }
            case CoordinateRole:

            default:
                break;
            }
        }

        return false;
    }

    Waypoint::WaypointModel::~WaypointModel()
    {
        qDeleteAll(m_waypointModelItems);
        m_waypointModelItems.clear();
    }


    QVariant Waypoint::WaypointModel::data(const QModelIndex &index, int role) const
    {
        if(!index.isValid())
            return {};
        if(index.row() <0 || index.row() >= m_waypointModelItems.size())
            return {};
        const WaypointModelItem *item = m_waypointModelItems[index.row()];
        switch (role) {
        case DisplayNameRole:
            return QVariant::fromValue(item->displayName());
            break;
        case CoordinateRole:
            return QVariant::fromValue(item->coordinate());
        default:
            break;
        }
        return {};
    }

    int Waypoint::WaypointModel::rowCount(const QModelIndex &parent) const
    {
        if(parent.isValid())
            return 0;
        return m_waypointModelItems.size();
    }

    QHash<int, QByteArray> Waypoint::WaypointModel::roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles[DisplayNameRole] = "displayName";
        roles[CoordinateRole] = "coordinate";
        return roles;
    }


    void Waypoint::WaypointModel::remove(int index)
    {
        beginRemoveRows(QModelIndex(), index, index);
        m_waypointModelItems.removeAt(index);
        endRemoveRows();
    }

    void Waypoint::WaypointModel::onNominatimRessourceResponse(NominatimRessource::ResponseType responseType, const QJsonArray& data)
    {
        if(responseType == NominatimRessource::Success)
        {
            setJsonData(data);
        }
        else if(responseType == NominatimRessource::Failed)
        {
            qDebug() << "No Response Data";
        }
        else if(responseType == NominatimRessource::NetworkError)
        {
            qDebug() << "No Connection to Nominatim Server";
        }
    }

    Waypoint::WaypointModelItem* Waypoint::WaypointModel::WaypointModel::getModelItem(int index)
    {
        return m_waypointModelItems[index];
    }



}
