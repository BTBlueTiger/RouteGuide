#include "include/models/waypoint/WaypointModelItem.h"

namespace Waypoint

{
    WaypointModelItem::WaypointModelItem(const QString& name, const QGeoCoordinate& coordinate,
                                         QObject* parent)
        : QObject(parent), m_displayName(name), m_coordinate(coordinate) {}

    void WaypointModelItem::setDisplayName(const QString& displayName)
    {
        m_displayName = displayName;
    }

    void WaypointModelItem::setCoordinate(const QGeoCoordinate& coordinate)
    {
        m_coordinate = coordinate;
    }

    QString WaypointModelItem::displayName() const
    {
        return m_displayName;
    }

    QGeoCoordinate WaypointModelItem::coordinate() const
    {
        return m_coordinate;
    }

}
