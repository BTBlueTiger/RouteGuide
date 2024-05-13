#include "include/models/plan_a_route/PlanARouteModel.h"

PlanARouteModel::PlanARouteModel(QObject* parent) : QAbstractListModel(parent)
{

}

void PlanARouteModel::append(const QString &town, const double latitude, const double longitude)
{
    PlanARouteModelItem item(town, latitude, longitude);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append(item);
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
    const PlanARouteModelItem &item = m_items[index.row()];
    if(role == TownRole)
        return item.town();
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
        //m_items.removeAt(index);
    }
    endRemoveRows();
}

QVariantList PlanARouteModel::getTownsForQML() const {
    QVariantList routeList;
    for (const PlanARouteModelItem &route : m_items) {
        QVariantMap routeMap;
        routeMap["name"] = route.town();
        routeList.append(routeMap);
    }
    return routeList;
}
