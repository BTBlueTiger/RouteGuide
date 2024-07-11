import QtQuick 2.15
import QtQuick.Controls
import QtLocation
import QtPositioning

MapItemView {
    model: routeModel
    delegate: MapRoute {
        route: routeData
        line.color: "blue"
        line.width: 5
        smooth: true
    }
}
