#include "include/models/plan_a_route/PlanARouteModel.h"

PlanARouteModel::PlanARouteModel(QObject* parent) : QAbstractListModel(parent)
{

}

void PlanARouteModel::append(WaypointModel& model)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    endInsertRows();
}

PlanARouteModel::~PlanARouteModel()
{
    m_items.clear();
}


int PlanARouteModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_items.size();
}

QVariant PlanARouteModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return {};
    if(index.row() <0 || index.row() >= rowCount())
        return {};
    const WaypointModel &item = m_items[index.row()];
    switch (role) {
    case WaypointModel::WaypointRoles::TownRole:

        break;
    case WaypointModel::WaypointRoles::StreetRole:

        break;
    case WaypointModel::WaypointRoles::HouseNumberRole:

        break;
    default:
        break;
    }
    return {};
}

QHash<int, QByteArray> PlanARouteModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TownRole] = "town";
    return roles;
}

void PlanARouteModel::remove(int index, int count)
{
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_items.removeAt(index);
    }
    endRemoveRows();
}

QVariantList PlanARouteModel::waypointsForQML() const {
    QVariantList routeList;
    for (const WaypointModel &waypoint : m_items) {
        QVariantMap routeMap;
        //routeMap["town"] = waypoint.town;
        //routeList.append(routeMap);
    }
    return routeList;
}



