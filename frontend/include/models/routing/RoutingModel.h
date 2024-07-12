#ifndef ROUTINGMODEL_H
#define ROUTINGMODEL_H

#include <QObject>

#include <QGeoRoute>
#include <QGeoRectangle>
#include <QGeoCoordinate>

#include "include/connections/ResponseType.h"

namespace Routing
{

    class RoutingModel : public QObject {
        Q_OBJECT
    public:

        Q_PROPERTY(QGeoCoordinate center MEMBER m_center NOTIFY centerChanged FINAL)
        Q_PROPERTY(QVariantList path MEMBER m_variantPath NOTIFY pathChanged FINAL)

        RoutingModel(QObject* parent = nullptr);
        ~RoutingModel();


    private:
        QGeoCoordinate m_center;

        QVariantList m_variantPath;
        QList<QGeoCoordinate> m_listPath;

    public slots:
        void onGeoRouteReply(ResponseType responseType, const QList<QGeoRoute>&);

    signals:
        void centerChanged();
        void pathChanged();
    };
}


#endif // ROUTINGMODEL_H
