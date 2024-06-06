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

    property alias mapPlugin: mapPlugin

    WaypointManager{ id: waypointManager }
    RouteGuideMapPlugin{ id: mapPlugin }
    RouteGuideRoutingModel{ id: routingModel }


    visible: true
    width: Qt.platform.os === "android" ? screenInfo.screenResolution().width : 1280
    height:  Qt.platform.os === "android" ? screenInfo.screenResolution().height : 720

    title: qsTr("RouteGuide")
    ApplicationFlow {
        width: parent.width
        height: parent.height
    }
}

