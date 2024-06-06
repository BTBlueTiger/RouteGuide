import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

RouteModel {
    id: routeModel

    query: RouteQuery{
        id: routeQuery
    }

    property var coordinatesToRoute

    plugin: mapPlugin

    onCoordinatesToRouteChanged: {
        console.log("Hrello")
        for(var i = 0; i < coordinatesToRoute.length; i++){
            routeQuery.addWaypoint(coordinatesToRoute[i])
        }
        routeModel.update()
    }
}
