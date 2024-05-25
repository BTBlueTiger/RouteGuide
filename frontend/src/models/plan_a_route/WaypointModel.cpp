#include "include/models/plan_a_route/WaypointModel.h"


WaypointModel::WaypointModel(QObject* parent) : QAbstractListModel(parent)
{

}

QString WaypointModel::town() const
{
    return m_town;
}

QString WaypointModel::street() const
{
    return m_street;
}

QStringList WaypointModel::houseNumbers() const
{
    return m_items;
}

void WaypointModel::setTown(const QString& town)
{
    if(m_town == town)
        return;
    m_town = town;
    emit townChanged(town);
}

void WaypointModel::setStreet(const QString& street)
{
    if(m_street == street)
        return;
    m_street = street;
    emit streetChanged(street);
}

void WaypointModel::setHouseNumbers(const QStringList& houseNumbers)
{
    if (m_items != houseNumbers) {
        m_items = houseNumbers;
        emit houseNumbersChanged();
    }
}



bool WaypointModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == HouseNumberRole) {
     if (m_items[index.row()] != value.toString()) {
            m_items[index.row()] = value.toString();
            emit dataChanged(index, index, { HouseNumberRole, Qt::DisplayRole });
            return true;
        }
    }
    return false;
}

/*

int WaypointModel::getLenghtOfList() const
{
    return m_items.size();
}

void WaypointModel::changeItem(int index, const QString& houseNumber, int count)
{
    m_items[index] = houseNumber;
}
*/

void WaypointModel::append()
{

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append("");
    endInsertRows();
    emit houseNumbersChanged();
}


WaypointModel::~WaypointModel()
{
    //m_items.clear();
}


int WaypointModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_items.size();
}

QVariant WaypointModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return {};
    if(index.row() <0 || index.row() >= rowCount())
        return {};
    return {};
}

QHash<int, QByteArray> WaypointModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[HouseNumberRole] = "house_number";
    roles[TownRole] = "town";
    roles[StreetRole] = "street";
    return roles;
}


void WaypointModel::remove(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_items.removeAt(index);
    endRemoveRows();
}

QVariantList WaypointModel::qVariantListhouseNumbers() const {
    QVariantList routeList;
    for (const QString &item : m_items) {
        QVariantMap routeMap;
        routeMap["house_number"] = item;
        routeList.append(routeMap);
    }
    return routeList;
}

void WaypointModel::removeEmptyStops()
{
    for (int i = m_items.size() - 1; i >= 0; --i) {
        if (m_items[i].trimmed().isEmpty()) {
            m_items.removeAt(i);
        }
    }
    emit houseNumbersChanged();
}


