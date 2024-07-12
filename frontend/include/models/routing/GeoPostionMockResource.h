/*
#ifndef GEOPOSTIONMOCKRESOURCE_H
#define GEOPOSTIONMOCKRESOURCE_H

#include <QGeoPositionInfoSource>
#include <QTimer>

class GeoPositionMockResource : public QGeoPositionInfoSource {
    Q_OBJECT
public:
    GeoPositionMockResource(QObject *parent = nullptr);

    void startUpdates() override;
    void stopUpdates() override;
    void requestUpdate(int timeout = 0) override;
    QGeoPositionInfo lastKnownPosition(bool fromSatellitePositioningMethodsOnly = false) const override{}
    int minimumUpdateInterval() const override {return 0;}
    QGeoPositionInfoSource::PositioningMethods supportedPositioningMethods() const override {return QGeoPositionInfoSource::NonSatellitePositioningMethods;}
    QGeoPositionInfoSource::Error error() const override {return QGeoPositionInfoSource::Error::NoError;}

private slots:
    void emitPosition();

private:
    QTimer *timer;
    QGeoPositionInfo createMockPosition() const;
};

#endif // GEOPOSTIONMOCKRESOURCE_H
*/
