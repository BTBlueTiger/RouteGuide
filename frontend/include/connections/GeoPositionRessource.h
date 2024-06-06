#ifndef GEOPOSITIONRESSOURCE_H
#define GEOPOSITIONRESSOURCE_H

#include <QObject>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>
#include <QQmlEngine>
#include <QJSEngine>

class GeoPositionRessource : public QObject
{
    Q_OBJECT


    Q_PROPERTY(QGeoCoordinate coordinate MEMBER m_coordinate NOTIFY coordinateChanged)

public:
    GeoPositionRessource(QObject *parent = nullptr);
    static QObject* createSingletonInstance(QQmlEngine *engine,  QJSEngine *scriptEngine);

private:
    static GeoPositionRessource *m_instance;
    QGeoPositionInfoSource *m_source;
    QGeoCoordinate m_coordinate;

public slots:
    void positionUpdated(const QGeoPositionInfo& gpsPos);
    void positionError(QGeoPositionInfoSource::Error e){}

signals:
    void coordinateChanged();
    void readyChanged();
    void useGpsChanged();
};

#endif // GEOPOSITIONRESSOURCE_H
