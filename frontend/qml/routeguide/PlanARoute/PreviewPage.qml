import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import RoutingModel
import RoutingManager

import GeoPositionRessource

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

        Map {
            Button {
                text: qsTr("Back")
                onClicked: {
                    pageIndex = 1
                }
            }

            MapItemView {
                model: routeModel
                delegate: MapRoute {
                    route: routeData
                    line.color: "blue"
                    line.width: 5
                    smooth: true
                }
            }

            Button {
                id: btnNavigate
                x: parent.width - btnNavigate.width
                text: qsTr("Navigate")
                onClicked:  {
                   planARoute.toNavigation()
                }
            }
            id: map
            anchors.fill: parent
            plugin: mapPlugin
            center: GeoPositionRessource.coordinate

            zoomLevel: 14
            activeMapType: supportedMapTypes[supportedMapTypes.length - 1]


            PinchHandler {
                id: pinch
                target: null
                onActiveChanged: if (active) {
                    map.startCentroid = map.toCoordinate(pinch.centroid.position, false)
                }
                onScaleChanged: (delta) => {
                    map.zoomLevel += Math.log2(delta)
                    map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
                }
                onRotationChanged: (delta) => {
                    map.bearing -= delta
                    map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
                }
                grabPermissions: PointerHandler.TakeOverForbidden
            }
            WheelHandler {
                id: wheel
                // workaround for QTBUG-87646 / QTBUG-112394 / QTBUG-112432:
                // Magic Mouse pretends to be a trackpad but doesn't work with PinchHandler
                // and we don't yet distinguish mice and trackpads on Wayland either
                acceptedDevices: Qt.platform.pluginName === "cocoa" || Qt.platform.pluginName === "wayland"
                                 ? PointerDevice.Mouse | PointerDevice.TouchPad
                                 : PointerDevice.Mouse
                rotationScale: 1/120
                property: "zoomLevel"
            }
            DragHandler {
                id: drag
                target: null
                onTranslationChanged: (delta) => map.pan(-delta.x, -delta.y)
            }
            Shortcut {
                enabled: map.zoomLevel < map.maximumZoomLevel
                sequence: StandardKey.ZoomIn
                onActivated: map.zoomLevel = Math.round(map.zoomLevel + 1)
            }
            Shortcut {
                enabled: map.zoomLevel > map.minimumZoomLevel
                sequence: StandardKey.ZoomOut
                onActivated: map.zoomLevel = Math.round(map.zoomLevel - 1)
            }
        }
    }
}
