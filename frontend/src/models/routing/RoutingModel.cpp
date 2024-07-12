#include "include/models/routing/RoutingModel.h"


namespace Routing
{
    RoutingModel::RoutingModel(QObject* parent) : QObject(parent)
    {
        m_center = QGeoCoordinate(0, 0);
    }

    RoutingModel::~RoutingModel()
    {

    }

    void RoutingModel::onGeoRouteReply(ResponseType responseType, const QList<QGeoRoute>& routes)
    {
        if(responseType == ResponseType::Success)
        {
            qDebug() << routes.at(0).bounds().center();
            if(m_center != routes.at(0).bounds().center())
            {
                const QGeoCoordinate c = routes.at(0).bounds().center();
                m_center.setLatitude(c.latitude());
                m_center.setLongitude(c.longitude());
                emit centerChanged();

            }

            m_listPath = routes.at(0).path();
            m_variantPath.clear();
            for (const QGeoCoordinate &coord : m_listPath) {
                m_variantPath.append(QVariant::fromValue(coord));
            }
            emit pathChanged();
        }
    }

}
