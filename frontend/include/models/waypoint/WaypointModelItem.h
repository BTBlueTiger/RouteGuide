#ifndef WAYPOINTMODELITEM_H
#define WAYPOINTMODELITEM_H

#include <QObject>
#include <QGeoCoordinate>

namespace Waypoint {

class WaypointModelItem: public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString displayName MEMBER m_displayName CONSTANT);
    Q_PROPERTY(QGeoCoordinate coordinate MEMBER m_coordinate CONSTANT);

    WaypointModelItem(const QString& name, const QGeoCoordinate& coordinate,
                      QObject* parent = nullptr);

    void setDisplayName(const QString& displayName);
    void setCoordinate(const QGeoCoordinate& coordinate);

    QString displayName() const;
    QGeoCoordinate coordinate() const;

private:
    QString m_displayName;
    QGeoCoordinate m_coordinate;
};

}

#endif // WAYPOINTMODELITEM_H
