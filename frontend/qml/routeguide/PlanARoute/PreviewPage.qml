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


    signal toNavigation()

    Rectangle {

        width: parent.width
        height: parent.height

        Navigation {
            //anchors.fill: parent
        }
    }
}
