import QtQuick 2.15
import QtQuick.Controls
import QtLocation
import QtPositioning

import QtSensors

import GeoPositionRessource

import UserModel

Map {
    id: map


    Button {

    }

    Repeater {
        model: waypointManager.getWaypointModel(potentialWaypointModelName) === null
               ? [] :  waypointManager.getWaypointModel(potentialWaypointModelName).getCoordinates()
        delegate: MapQuickItem{
            coordinate: model.modelData
            anchorPoint.x: icon.width / 2
            anchorPoint.y: icon.height
            sourceItem: Image {
                id: icon
                source: "qrc:/res/btn/map.svg"  // Path to your marker icon
                width: 40
                height: 40
            }
        }
    }

    Button {
        id: tbtnFollowGPS

        anchors {
            top: parent.top
            right: parent.right
            margins: 10 // Adjust margins as needed
        }
        icon.source: map.followGPS ? "/res/btn/my_location.svg" : "/res/btn/free_location.svg"
        icon {
            height: 50
            width: 50
            color: "blue"
        }

        onClicked: map.followGPS = !map.followGPS
    }
    property real azimuth : 0
    property bool followGPS: true
    property var lastCenter: QtPositioning.coordinate(52.2125431, 8.7179206)

    Connections{
        target: GeoPositionRessource
        function onCoordinateChanged () {
            if(followGPS) {
                lastCenter = center
                center = GeoPositionRessource.coordinate
            }
        }
    }


    Compass {
        id: compass  // Assign an ID to the Compass element for reference

        active : true
        onReadingChanged: {
            if (Math.abs(map.Azimuth - compass.reading.azimuth) > 50) {
                mapAzimuth = compass.reading.azimuth;
            }
        }
    }

    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            if(compass.reading) {
                map.azimuth = compass.reading.azimuth
            }

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
        transform: Rotation {
            origin.x: marker.sourceItem.width / 2
            origin.y: marker.sourceItem.height / 2
            angle: azimuth
            Behavior on angle {
                NumberAnimation { duration: 100; easing.type: Easing.InOutQuad }
            }
        }
        coordinate: followGPS ? center : QtPositioning.coordinate(0, 0)
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


}
