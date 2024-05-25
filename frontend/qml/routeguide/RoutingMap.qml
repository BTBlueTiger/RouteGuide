import QtQuick
import QtLocation
import QtPositioning
import QtQuick.Controls


Item {
    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"

            // OSM plugin will auto-append if .png isn't suffix, and that screws up apikey which silently
            // fails authentication (only Wireshark revealed it)
            value: "http://tile.thunderforest.com/atlas/%z/%x/%y.png?apikey=5e174dbc86e5477b90da4369fabe46f5&fake=.png"
        }
    }
    RouteModel {
        id: routeModel
        plugin: mapPlugin
        query: RouteQuery {
            id: routeQuery
        }
        onStatusChanged: {
            console.log(status)

        }
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(52.2125431, 8.7179206)
        zoomLevel: 14
        property geoCoordinate startCentroid
        property int markerCounter: 0
        property var markers: []


        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]

        MapQuickItem {
            parent: map
            coordinate: QtPositioning.coordinate(52.2035924, 8.7771954)
            sourceItem: Image {
                source: "/res/btn/place.svg"
            }
        }

        Component {
            id: marker
            MapQuickItem {
                sourceItem: Image {
                    source: "/res/btn/place.svg"
                }
            }
        }

        function addMarker(lat, lon)
        {
            var pos = QtPositioning.coordinate(lat, lon)
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

        Item {
            anchors.centerIn: parent // Center the Item in the parent (ApplicationWindow)
            TextField {
                background: Rectangle { color: "#391ee9" }
                width: 300
                placeholderText: qsTr("Enter a location here..")
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: TextInput.AlignHCenter
                onAccepted: {
                    console.log("Test")
                    routeQuery.clearWaypoints();
                    map.addMarker(52.2125431, 8.7179206)
                    map.addMarker(52.2035924, 8.7771954)
                    map.addMarker(52.29755845, 8.903021626602502)
                    //routeQuery.addWaypoint(QtPositioning.coordinate(52.2035924, 8.7771954))
                    //routeQuery.addWaypoint(QtPositioning.coordinate(52.29755845, 8.903021626602502))
                    routeQuery.travelModes = RouteQuery.CarTravel
                    routeQuery.routeOptimizations = RouteQuery.FastestRoute
                    routeModel.update();
                }
            }
        }

    }
}
