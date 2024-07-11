import QtQuick 2.15
import QtQuick.Controls
import QtLocation
import QtPositioning

import QtSensors

import GeoPositionRessource

import UserModel

import "../navigation"

Map {
    id: defaultMap

    // We dont get a mapplugin we use our default one
    property var customMapPlugin : undefined

    anchors.fill: parent
    plugin: customMapPlugin === undefined ? defaultMapPlugin: customMapPlugin
    center: QtPositioning.coordinate(52.2125431, 8.7179206)
    zoomLevel: 14


    activeMapType: supportedMapTypes[supportedMapTypes.length - 1]

    PinchHandler {
        id: pinch
        target: null
        onActiveChanged: if (active) {
            defaultMap.startCentroid = defaultMap.toCoordinate(pinch.centroid.position, false)
        }
        onScaleChanged: (delta) => {
            defaultMap.zoomLevel += Math.log2(delta)
            defaultMap.alignCoordinateToPoint(defaultMap.startCentroid, pinch.centroid.position)
        }

        onRotationChanged: (delta) => {
            defaultMap.bearing -= delta
            defaultMap.alignCoordinateToPoint(defaultMap.startCentroid, pinch.centroid.position)
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
        onTranslationChanged: (delta) => defaultMap.pan(-delta.x, -delta.y)
    }
    Shortcut {
        enabled: defaultMap.zoomLevel < defaultMap.maximumZoomLevel
        sequence: StandardKey.ZoomIn
        onActivated: defaultMap.zoomLevel = Math.round(defaultMap.zoomLevel + 1)
    }
    Shortcut {
        enabled: defaultMap.zoomLevel > defaultMap.minimumZoomLevel
        sequence: StandardKey.ZoomOut
        onActivated: defaultMap.zoomLevel = Math.round(defaultMap.zoomLevel - 1)
    }


}
