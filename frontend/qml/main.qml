import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import "map"
import "navigation"
import "../js/Formatter.js" as Formatter

import ScreenInfo

import ValidationTextfield
import QtTest

import WaypointManager
import RoutingManager

ApplicationWindow {

    id: rootWindow

    property string userType: ""
    property ScreenInfo screenInfo

    property var waypoints : []


    property string searchWaypointModelName: "SearchWaypointModel"
    property string potentialWaypointModelName: "PotentialWaypointModel"
    property string savedWayPointModelName: "SavedWayPointModel"

    // Global waypointManager
    // Has to handle all oure Models that contains waypoints like in Plan a Route or SavedOnes
    WaypointManager{ id: waypointManager}
    // Global default map Plugin
    DefaultMapPlugin { id: defaultMapPlugin }
    // Global default RouteModel
    // Will display manage to display the "blue" route
    DefaultRouteModel {
        id: defaultRouteModel
        onStatusChanged: {
            if(status === RouteModel.Ready)
            {
                if(defaultRouteModel.count > 0) {
                defaultRouteListModel.clear()
                    for (var i = 0; i < defaultRouteModel.get(0).segments.length; i++) {
                        defaultRouteListModel.append({
                            "instruction": defaultRouteModel.get(0).segments[i].maneuver.instructionText,
                             "distance": Formatter.formatDistance(defaultRouteModel.get(0).segments[i].maneuver.distanceToNextInstruction)
                        });
                    }
                }
            }
        }
    }
    //Global Route List Model
    ListModel {id: defaultRouteListModel }

    visible: true
    width: Qt.platform.os === "android" ? screenInfo.screenResolution().width : 1280
    height:  Qt.platform.os === "android" ? screenInfo.screenResolution().height : 720

    title: qsTr("RouteGuide")

    ApplicationFlow {
        width: parent.width
        height: parent.height
    }
}

