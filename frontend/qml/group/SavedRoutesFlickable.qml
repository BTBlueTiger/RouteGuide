import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import WaypointModel


import "../map"
import "../navigation"



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
                    id: mapRect

                    width: flickableRoot.width
                    height: flickableRoot.height * .4
                    radius: 20



                    DefaultMap {
                        id: littlePreviewMap
                        property var wayPoints: []
                        plugin:
                            DefaultMapPlugin {
                            id: littlePreviewMapPlugin
                        }
                        center: QtPositioning.coordinate(modelData["adresses"][0]["lat"], modelData["adresses"][0]["long"])

                        property alias flickableRouteModel : flickableRouteModel



                        MapItemView {

                            model:  RouteModel {
                                id: flickableRouteModel
                                property alias flickableRouteModelquery: flickableRouteModelquery
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
                                plugin: littlePreviewMapPlugin
                            }

                            delegate: MapRoute {
                                route: routeData
                                line.color: "blue"
                                line.width: 5
                                smooth: true
                            }
                        }

                        MarkerRepeater { model: flickableRouteModelquery.waypoints }
                    }
                }
                Rectangle {
                    id: textRect
                    color: "black"
                    height: mapRect.height * .2
                    width: mapRect.width  * .3
                    Label {
                        anchors.centerIn: parent
                        id: displayNameLabel
                        text: modelData["name"]
                        width: textRect.width
                        color: "white"
                        wrapMode: Text.Wrap
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        enabled: false
                        font.bold: true
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
