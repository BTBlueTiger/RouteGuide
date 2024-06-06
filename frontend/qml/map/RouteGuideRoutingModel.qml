import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

RouteModel {
    id: routeModel

    query: RouteQuery{
        id: routeQuery
    }

    property var mapPlugin
    property var coordinatesToRoute

    plugin: mapPlugin

    onCoordinatesToRouteChanged: {
        for(var i = 0; i < coordinates.length; i++){
            routeQuery.addWaypoint(coordinatesToRoute[i])
        }
        routeModel.update()
    }
}
