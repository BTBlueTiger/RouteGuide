import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import RoutingModel
import RoutingManager

import GeoPositionRessource

import "../../navigation"

Rectangle {

    id: planARoutePreviewPage

    property var coordinates
    //property var center: waypointManager.waypointRoute.center

   // property RoutingModel routingModel

    height: parent.height
    width: parent.width

    onCoordinatesChanged: {
        for(var i = 0; i < coordinates.length; i++){
            if(i == 0) {
                map.center = coordinates[i]
            }
            routeQuery.addWaypoint(coordinates[i])
        }
        routeModel.update();
    }


    signal toNavigation()

    Rectangle {

        width: parent.width
        height: parent.height

        Navigation {}
    }
}
