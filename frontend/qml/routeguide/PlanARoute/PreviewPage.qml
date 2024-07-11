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

    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightslategray" }
        GradientStop { position: 1.0; color: "black" }
    }

    property var routeListModel

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

    PreviewManeuverList{
        width: parent.width
        height: parent.height
    }

}
