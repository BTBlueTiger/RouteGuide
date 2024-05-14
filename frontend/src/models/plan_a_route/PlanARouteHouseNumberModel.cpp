#include "include/models/plan_a_route/PlanARouteHouseNumberModel.h"


PlanARouteHouseNumberModelItem::PlanARouteHouseNumberModelItem(const QString &houseNumber)
    : m_houseNumber(std::move(houseNumber))
{

}

void PlanARouteHouseNumberModelItem::updateHouseNumber(const QString& houseNumber)
{
    m_houseNumber = houseNumber;
}

PlanARouteHouseNumberModel::PlanARouteHouseNumberModel(QObject* parent) : QAbstractListModel(parent)
{

}

QString PlanARouteHouseNumberModelItem::houseNumber() const
{
    return m_houseNumber;
}



bool PlanARouteHouseNumberModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == HouseNumberRole) {
        // Set data in model here. It can also be a good idea to check whether
        // the new value actually differs from the current value
        if (m_items[index.row()].houseNumber() != value.toString()) {
            m_items[index.row()] = value.toString();
            emit dataChanged(index, index, { HouseNumberRole, Qt::DisplayRole });
            return true;
        }
    }
    return false;
}

void PlanARouteHouseNumberModel::setQSetttings()
{
    qDebug() <<m_items.size();
    for(int i = 0; i < m_items.size(); i++)
    {
        qDebug() << m_items.at(i).houseNumber();
    }
/*
    for(int i = 0; i < qVariantListhouseNumbers().size(); i++)
    {

    }
*/

}

int PlanARouteHouseNumberModel::getLenghtOfList() const
{
    return m_items.size();
}

void PlanARouteHouseNumberModel::changeItem(int index, const QString& houseNumber, int count)
{

}

void PlanARouteHouseNumberModel::append(const QString &houseNumber)
{
    PlanARouteHouseNumberModelItem item(houseNumber);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append(item);
    endInsertRows();
}

PlanARouteHouseNumberModel::~PlanARouteHouseNumberModel()
{
    //m_items.clear();
}


int PlanARouteHouseNumberModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_items.size();
}

QVariant PlanARouteHouseNumberModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return {};
    if(index.row() <0 || index.row() >= rowCount())
        return {};
    const PlanARouteHouseNumberModelItem &item = m_items[index.row()];
    if(role == HouseNumberRole)
        return item.houseNumber();
    return {};
}

QHash<int, QByteArray> PlanARouteHouseNumberModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[HouseNumberRole] = "house_number";
    return roles;
}

void PlanARouteHouseNumberModel::remove(int index, int count)
{
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_items.removeAt(index);
    }
    endRemoveRows();
}

QVariantList PlanARouteHouseNumberModel::qVariantListhouseNumbers() const {
    QVariantList routeList;
    for (const PlanARouteHouseNumberModelItem &item : m_items) {
        QVariantMap routeMap;
        routeMap["house_number"] = item.houseNumber();
        routeList.append(routeMap);
    }
    return routeList;
}
