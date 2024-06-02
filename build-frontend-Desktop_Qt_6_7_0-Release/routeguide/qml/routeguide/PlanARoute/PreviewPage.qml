import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

Rectangle {

    id: planARoutePreviewPage

    //property var center: waypointManager.waypointRoute.center


    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        //center: planARoutePreviewPage.center
        zoomLevel: 14
        property geoCoordinate startCentroid
        property int markerCounter: 0
        property var markers: []


        TapHandler {
            id: tapHandler
            property variant lastCoordinate
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onPressedChanged: (eventPoint, button) => {
                if (pressed) {
                    lastCoordinate = view.map.toCoordinate(tapHandler.point.position)
                }
            }
        }




        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]

        Component {
            id: marker
            MapQuickItem {
                sourceItem: Image {
                    source: "/res/btn/place.svg"
                }
            }
        }


        function addMarker(pos)
        {
            var count = map.markers.length
            markerCounter++
            var marker = Qt.createQmlObject('
                import QtQuick
                import QtLocation
                MapQuickItem {
                sourceItem: Image {
                    source: "/res/btn/place.svg"
                }
            }
            ', map)
            map.addMapItem(marker)
            marker.z = map.z+1
            marker.coordinate = pos
            markers.push(marker)
            routeQuery.addWaypoint(pos)
        }


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

        MapItemView{
            parent: map
            model: routeModel
            delegate: routeDelegate
        }

        Component {
            id: routeDelegate

            MapRoute {
                id: route
                route: routeData
                line.color: "#46a2da"
                line.width: 5
                smooth: true
                opacity: 0.8
            }
        }

    }
}
