import QtQuick 2.15

import QtLocation
import QtPositioning

import QtSensors

Map {


    Compass {
        id: compass  // Assign an ID to the Compass element for reference

        active : true
    }

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            var angleDiff = compass.reading ? compass.reading.azimuth - map.rotation : 0
            marker.rotation = angleDiff + (360 / 4)
        }
    }


    MapItemView {
        model: routingModel
        delegate: MapRoute {
            route: routeData
            line.color: "blue"
            line.width: 5
            smooth: true
        }
    }

    id: map
    anchors.fill: parent
    plugin: mapPlugin
    center: QtPositioning.coordinate(52.2125431, 8.7179206)
    zoomLevel: 14
    property var startCentroid

    activeMapType: supportedMapTypes[supportedMapTypes.length - 1]

    MapQuickItem {
        id: marker
        sourceItem: Image{
            source: "/res/btn/navigation.svg"
        }
        coordinate: {
            center
        }

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
        /*
        onRotationChanged: (delta) => {
            map.bearing -= delta
            map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
        }

    */
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
