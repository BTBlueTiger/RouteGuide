#include "include/models/plan_a_route/WaypointModel.h"


WaypointModelItem::WaypointModelItem(const QString &houseNumber)
    : m_houseNumber(std::move(houseNumber))
{

}

void WaypointModelItem::updateHouseNumber(const QString& houseNumber)
{
    m_houseNumber = houseNumber;
}

WaypointModel::WaypointModel(QObject* parent) : QAbstractListModel(parent)
{

}

QString WaypointModelItem::houseNumber() const
{
    return m_houseNumber;
}

QString WaypointModel::town() const
{
    return m_town;
}

QString WaypointModel::street() const
{
    return m_street;
}

QVector<WaypointModelItem> WaypointModel::houseNumbers() const
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

void WaypointModel::setHouseNumbers(const QVector<WaypointModelItem>& houseNumbers)
{
    emit houseNumbersChanged(houseNumbers);
}



bool WaypointModel::setData(const QModelIndex &index, const QVariant &value, int role)
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


int WaypointModel::getLenghtOfList() const
{
    return m_items.size();
}

void WaypointModel::changeItem(int index, const QString& houseNumber, int count)
{

}

void WaypointModel::append(const QString &houseNumber)
{
    WaypointModelItem item(houseNumber);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append(item);
    endInsertRows();
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
    const WaypointModelItem &item = m_items[index.row()];
    if(role == HouseNumberRole)
        return item.houseNumber();
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

void WaypointModel::remove(int index, int count)
{
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_items.removeAt(index);
    }
    endRemoveRows();
}

QVariantList WaypointModel::qVariantListhouseNumbers() const {
    QVariantList routeList;
    for (const WaypointModelItem &item : m_items) {
        QVariantMap routeMap;
        routeMap["house_number"] = item.houseNumber();
        routeList.append(routeMap);
    }
    return routeList;
}
