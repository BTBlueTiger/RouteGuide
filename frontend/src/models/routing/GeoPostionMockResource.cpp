#include "include/models/routing/GeoPostionMockResource.h"

GeoPositionMockResource::GeoPositionMockResource(QObject *parent)
    : QGeoPositionInfoSource(parent), timer(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &GeoPositionMockResource::emitPosition);
}

void GeoPositionMockResource::startUpdates() {
    timer->start(1000); // Emit positions every second
}

void GeoPositionMockResource::stopUpdates() {
    timer->stop();
}

void GeoPositionMockResource::requestUpdate(int /*timeout*/) {
    emitPosition();
}

void GeoPositionMockResource::emitPosition() {
    QGeoPositionInfo info = createMockPosition();
    emit positionUpdated(info);
}

QGeoPositionInfo GeoPositionMockResource::createMockPosition() const {
    QGeoCoordinate coordinate(52.52, 13.405); // Example: Berlin coordinates
    QGeoPositionInfo info(coordinate, QDateTime::currentDateTime());
    info.setAttribute(QGeoPositionInfo::Direction, 90.0); // Example direction (east)
    info.setAttribute(QGeoPositionInfo::GroundSpeed, 10.0); // Example speed (10 m/s)
    return info;
}
