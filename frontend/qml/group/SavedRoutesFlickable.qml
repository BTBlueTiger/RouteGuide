import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import WaypointModel




Flickable {

    id: flickableRoot
    property var savedRoutesModel: savedRoutesModel
    property string buttonSource
    property string buttonColor
    property string onClickedMessage

    anchors.fill: parent

    flickableDirection: Flickable.VerticalFlick
    contentWidth: flickableRoot.width
    contentHeight: flickableRoot.height * .4 * cardRepeater.count + 56 * 2

    Flow {
        anchors.fill: parent
        id: waypointFlow
        spacing: 10
        z: 0

        Repeater {
            id: cardRepeater
            model: savedRoutesModel

            delegate: Rectangle {
                id: card
                width: flickableRoot.width / 2
                height: flickableRoot.height * .4

                MouseArea{
                    anchors.fill: parent
                }

                Rectangle {
                    id: textRect
                    width: card.width * .45
                    height: card.height

                    Rectangle{
                        radius: 20
                        opacity: .5
                        width: displayNameLabel.width
                        height: displayNameLabel.height
                        anchors.centerIn: parent

                        Label {
                            anchors.centerIn: parent
                            id: displayNameLabel

                            width: textRect.width
                            color: "black"
                            wrapMode: Text.Wrap
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            enabled: false
                            font.bold: true
                        }
                    }
                }

                Rectangle {
                    id: mapRect
                    x: card.width * .45
                    width: flickableRoot.width * .6
                    height: parent.height
                    radius: 20
                    Map {
                        id: map
                        zoomLevel: 20

                        MapItemView {
                            model:  RouteModel {
                                id: flickableRouteModel
                                query: RouteQuery{
                                    id: flickableRouteModelquery
                                    Component.onCompleted: {
                                        var adresses = modelData["adresses"]
                                        for(var i = 0; i < adresses.length; i++) {
                                            flickableRouteModelquery.addWaypoint(
                                                        QtPositioning.coordinate(
                                                           adresses[i]["lat"],
                                                            adresses[i]["long"]
                                                                   ))
                                        }
                                        flickableRouteModel.update()
                                    }
                                }
                                plugin: mapPlugin
                            }

                            delegate: MapRoute {
                                route: routeData
                                line.color: "blue"
                                line.width: 5
                                smooth: true
                            }
                        }

                        anchors.fill: mapRect
                        plugin:     Plugin {
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
                        center: QtPositioning.coordinate(modelData["adresses"][0]["lat"], modelData["adresses"][0]["long"])
                        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]


                        MapQuickItem{
                            sourceItem: Image {
                                source: "/res/btn/place.svg"
                            }
                            coordinate: QtPositioning.coordinate(modelData["adresses"][0]["lat"], modelData["adresses"][0]["long"])
                            anchorPoint.x: sourceItem.width / 2
                            anchorPoint.y: sourceItem.height
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
                    }
                }

                RoundButton {
                    id: btnRound
                    width: 50
                    height: 50
                    Material.background: "white"

                    icon {
                        source: buttonSource
                        color: buttonColor
                        width: 50
                        height: 50

                    }
                    y: card.height - btnRound.height
                    x: card.width - btnRound.width
                }
            }
        }
    }

}
