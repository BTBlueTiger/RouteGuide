#include "include/models/plan_a_route/PlanARouteModel.h"

PlanARouteModel::PlanARouteModel(QObject* parent) : QAbstractListModel(parent)
{

}

void PlanARouteModel::appendNewWayPointModel(int row)
{
    WaypointModel* newModel = new WaypointModel();
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append(newModel);
    endInsertRows();
}

PlanARouteModel::~PlanARouteModel()
{
    qDeleteAll(m_items);
    m_items.clear();
}

WaypointModel* PlanARouteModel::getModel(int index)
{
    if (index < 0 || index >= m_items.size())
        return nullptr;
    return m_items.at(index);
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
    if(role == WayPoinModelRole)
    {
        return QVariant::fromValue<WaypointModel*>(m_items[index.row()]);
    }
    return {};
}

QHash<int, QByteArray> PlanARouteModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[WayPoinModelRole] = "waypoint_model_role";
    return roles;
}

void PlanARouteModel::remove(int index)
{
    if (index < 0 || index >= rowCount()) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    delete m_items.takeAt(index);
    endRemoveRows();
}

QVariantList PlanARouteModel::waypointsForQML() const {
    QVariantList routeList;
    for (const WaypointModel &waypoint : m_items) {
        QVariantMap routeMap;
    }
    return routeList;
}



int PlanARouteModel::index() const
{
    return m_items.size() - 1;
}

void PlanARouteModel::setModel(int index, WaypointModel* model)
{
    m_items.removeAt(index);
    m_items.insert(index, model);
    emit waypointModelChanged(index);
    qDebug() << "Test";
}
