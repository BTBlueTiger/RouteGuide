import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import "map"

import ScreenInfo
//! [Set application window size]

import ValidationTextfield
import QtTest

import WaypointManager
import RoutingManager

ApplicationWindow {

    id: rootWindow

    property string userType: ""
    property var screenInfo: ScreenInfo {}


    WaypointManager{ id: waypointManager }

    Plugin {
        id: mapPlugin
        name: "osm"

        PluginParameter {
            name: "osm.mapping.custom.host"

            // OSM plugin will auto-append if .png isn't suffix, and that screws up apikey which silently
            // fails authentication (only Wireshark revealed it)
            value: "http://tile.thunderforest.com/atlas/%z/%x/%y.png?apikey=5e174dbc86e5477b90da4369fabe46f5&fake=.png"

            //value: "http:192.168.178.23:7070/tile/%z/%x/%y.png"
        }
    }
    RouteModel {
        id: routeModel

        query: RouteQuery{
            id: routeQuery
        }
        plugin: mapPlugin

    }



    visible: true
    width: Qt.platform.os === "android" ? screenInfo.screenResolution().width : 1280
    height:  Qt.platform.os === "android" ? screenInfo.screenResolution().height : 720

    title: qsTr("RouteGuide")
    ApplicationFlow {
        width: parent.width
        height: parent.height
    }
}

