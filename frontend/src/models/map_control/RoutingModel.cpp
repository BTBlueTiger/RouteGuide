#include "include/models/map_control/RoutingModel.h"

RoutingModelItem::RoutingModelItem(const QString& town, const QString& street, const QString& houseNumber, QObject* parent)
    : m_town(std::move(town)), m_street(std::move(street)), m_houseNumber(std::move(houseNumber)), QObject(parent)
{

}


RoutingModelItem::RoutingModelItem(const QString& town, const QString& street, const QString& houseNumber, const qreal lat, const qreal lon, QObject* parent)
    : m_town(std::move(town)), m_street(std::move(street)), m_houseNumber(std::move(houseNumber)), m_latitude(lat), m_longitude(lon), QObject(parent)
{

}

RoutingModelItem::~RoutingModelItem(){}

void RoutingModelItem::setLatitude(qreal latitude)
{
    if (m_latitude != latitude)
    {
        m_latitude = latitude;
    }
}

void RoutingModelItem::setLongitude(qreal longitude)
{
    if (m_longitude != longitude)
    {
        m_longitude = longitude;
    }
}

void RoutingModelItem::setHouseNumber(const QString& houseNumber)
{
    if(m_houseNumber != houseNumber)
    {
        m_houseNumber = houseNumber;
    }
}

QString RoutingModelItem::getExplicitStop() const
{
    QString stop;
    stop += m_town;
    stop += " ";
    stop += m_street;
    stop += " ";
    stop += m_houseNumber;
    return stop;
}

QString RoutingModelItem::town() const
{
    return m_town;
}


RoutingModel::RoutingModel(QObject* parent) : QObject(parent) {

}

RoutingModel::RoutingModel(QVector<RoutingModelItem*>& items, QObject* parent)
    : m_locations(std::move(items)), QObject(parent)
{

}

RoutingModel::~RoutingModel(){

}

QString RoutingModel::name() const
{
    return m_name;
}

QVector<RoutingModelItem*> RoutingModel::locations() const
{
    return m_locations;
}

void RoutingModel::setName(const QString& name)
{
    if(m_name != name)
    {
        m_name = name;
        emit nameChanged();
    }
}

void RoutingModel::setLocations(const QVector<RoutingModelItem*>& locations)
{
    if(m_locations.size() != locations.size())
    {
        m_locations = locations;
        emit locationsChanged();
    }
}


