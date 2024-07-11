import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import RoutingModel
import RoutingManager

import GeoPositionRessource

import "../../map"
import "../../navigation"


Rectangle {

    id: planARoutePreviewPage

    property var coordinates

    height: parent.height
    width: parent.width

    Button {
        id: btnNavigate
        icon.source: "/res/btn/navigation_45.svg"
        y: planARoutePreviewPage.height / 2 - planARoutePreviewPage.height / 4
        onClicked: {
            var stops = planARoute.fromCurrentPostion ? 1 : 0
            stops += potentialWaypointModel.rowCount()
            if(stops >= 2) {
                stackLayout.clear()
                stackLayout.push(routeguideMap)
            }
        }
    }

    signal toNavigation()

    Rectangle {

        id: prevMap
        width: parent.width * .9
        height: parent.height * .9

        x : parent.width / 2 - prevMap.width / 2
        y : parent.height / 2 - prevMap.height / 2

        RouteGuideMap {
            center: defaultRouteModel.defaultRouteQuery.waypoints.length === 0 ?
                        QtPositioning.coordinate(52.2125431, 8.7179206)
                      :
                        defaultRouteModel.defaultRouteQuery.waypoints[0]
            MarkerRepeater {
                id: markerRepeater
                model: defaultRouteModel.defaultRouteQuery.waypoints
            }
        }
    }
}
