#include "include/models/plan_a_route/PlanARouteModelItem.h"

PlanARouteModelItem::PlanARouteModelItem(const QString& town, const double latitude, const double longitude)
    : m_town(town), m_latitude(latitude), m_longitude(longitude) {}

QString PlanARouteModelItem::town() const
{
    return m_town;
}

double PlanARouteModelItem::latitude() const
{
    return m_latitude;
}

double PlanARouteModelItem::longitude() const
{
    return m_longitude;
}
