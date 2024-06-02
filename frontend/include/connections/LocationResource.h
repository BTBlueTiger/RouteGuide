#ifndef LOCATIONRESOURCE_H
#define LOCATIONRESOURCE_H

#include "AbstractResource.h"
#include "ResponseType.h"

#include <QGeoCoordinate>
#include <QGeoRoute>
#include <QGeoServiceProvider>

#include <qjsonarray.h>


class LocationResource : public AbstractResource
{
Q_OBJECT

public:

    Q_PROPERTY(QString search WRITE setSearch FINAL)

    LocationResource(QObject *parent = nullptr);

    void setSearch(const QString& search);
    void setRouteCoordinates(const QVector<QGeoCoordinate>);

signals:
    void networkResponse(ResponseType responseType, const QJsonArray& data = QJsonArray());

private slots:
    void networkRequestFinished();

private:
    QString m_search;
    void searchQ();
};


#endif // LOCATIONRESOURCE_H
