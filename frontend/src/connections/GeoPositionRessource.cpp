#include "include/connections/GeoPositionRessource.h"


GeoPositionRessource *GeoPositionRessource::m_instance = nullptr;

GeoPositionRessource::GeoPositionRessource(QObject* parent) : QObject(parent)
{
    m_source = QGeoPositionInfoSource::createDefaultSource(0);
    if (m_source)
    {
        m_source->setUpdateInterval(0);
        m_source->startUpdates();
        connect(m_source, SIGNAL(positionUpdated(QGeoPositionInfo)), this, SLOT(positionUpdated(QGeoPositionInfo)));
    }
}

void GeoPositionRessource::positionUpdated(const QGeoPositionInfo& gpsPos)
{
    if(m_coordinate != gpsPos.coordinate())
    {
        m_coordinate = gpsPos.coordinate();
        emit coordinateChanged();
    }
}

QObject* GeoPositionRessource::createSingletonInstance(QQmlEngine *engine, QJSEngine *scriptEngine){
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    if(m_instance==nullptr) { m_instance = new GeoPositionRessource;}
    return m_instance;
}
