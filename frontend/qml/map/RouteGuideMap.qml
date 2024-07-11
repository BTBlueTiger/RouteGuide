import QtQuick 2.15
import QtQuick.Controls
import QtLocation
import QtPositioning

import QtSensors

import GeoPositionRessource

import UserModel

import "../navigation"

DefaultMap {
    id: map

    MarkerRepeater {
        id: markerRepeater
        model: defaultRouteModel.defaultRouteQuery.waypoints
    }

    property SaveARoute saveARoute: SaveARoute {}


    Button {
        id: btnOpenMenu
        anchors {
            top: parent.top
            left: parent.left
            margins: 10
        }
        icon.source: "/res/btn/menu.svg"
        icon {
            height: 50
            width: 50
            color: "blue"
        }
        onClicked: menu.open()
        Menu {
                id: menu

                MenuItem {
                    text: "New..."
                    onClicked: {
                        defaultRouteModel.defaultRouteQuery.clearWaypoints()
                        defaultRouteModel.reset()
                        if(waypointManager.getWaypointModel(potentialWaypointModelName) !== null) {
                            waypointManager.getWaypointModel(potentialWaypointModelName).clearCoordinates()
                        }

                        defaultRouteModel.update()

                        markerRepeater.update()
                        map.update()
                    }
                }
                MenuItem {
                    text: "Save"
                    onClicked: saveARoute.open()
                }
            }
    }

    Button {
        id: tbtnFollowGPS

        anchors {
            top: parent.top
            right: parent.right
            margins: 10
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
    property bool followGPS: false
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


    // our simple blue route
    MapItemView {
        id: mapRoute
        model: defaultRouteModel
        delegate: MapRoute {
            route: routeData
            line.color: "blue"
            line.width: 5
            smooth: true
        }
    }


    // Start Marker
    MapQuickItem {
        visible: followGPS ? true: false
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

}
