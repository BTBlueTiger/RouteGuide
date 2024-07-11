import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning
import QtQuick.Layouts

import WaypointModel


import "../map"
import "../navigation"

import "../../js/Formatter.js" as Formatter



Flickable {

    id: flickableRoot
    property var savedRoutesModel: savedRoutesModel
    property string buttonSource
    property string buttonColor
    property string onClickedMessage
    signal toNavigation()


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

                property string totalDistance
                property string totalTravelTime
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
                                property var routeInformationList
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
                                onStatusChanged: {
                                    totalTravelTime = flickableRouteModel.count === 0 ? "" : Formatter.formatTime(flickableRouteModel.get(0).travelTime)
                                    totalDistance = flickableRouteModel.count === 0 ? "" : Formatter.formatDistance(flickableRouteModel.get(0).distance)
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
                    height: mapRect.height
                    width: mapRect.width  * .3

                    ColumnLayout {

                        id: textCol
                        height: mapRect.height
                        width: mapRect.width  * .3
                    Label {
                        id: displayNameLabel
                        text: modelData["name"]
                        width: textRect.width
                        color: "white"
                        wrapMode: Text.Wrap
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        enabled: false
                        font.bold: true
                        Layout.alignment: Qt.AlignHCenter
                    }

                    Label {
                        id: totalDistanceLabel
                        text: "Total Distance: " + totalDistance
                        width: textRect.width
                        color: "white"
                        wrapMode: Text.Wrap
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        enabled: false
                        font.bold: true
                        Layout.alignment: Qt.AlignHCenter
                    }
                    Label {
                        id: totalTimeLabel
                        text: "Total Time Required: " + totalTravelTime
                        width: textRect.width
                        color: "white"
                        wrapMode: Text.Wrap
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        enabled: false
                        font.bold: true
                        Layout.alignment: Qt.AlignHCenter
                    }
                    Label {
                        id: totalStopsLabel
                        text: "Stops: " + modelData["adresses"].length
                        width: textRect.width
                        color: "white"
                        wrapMode: Text.Wrap
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        enabled: false
                        font.bold: true
                        Layout.alignment: Qt.AlignHCenter
                    }
}
                }

                RoundButton {
                    id: btnNavigate
                    width: 50
                    height: 50
                    Material.background: "white"

                    icon {
                        source: "/res/btn/navigation_45.svg"
                        color: buttonColor
                        width: 50
                        height: 50
                    }

                    y: card.height - btnNavigate.height
                    x: card.width - btnNavigate.width
                    onClicked: {
                        // Our catched adresses
                        defaultRouteModel.defaultRouteQuery.clearWaypoints()
                        defaultRouteModel.defaultRouteQuery.waypoints = flickableRouteModelquery.waypoints
                        defaultRouteModel.update()
                        center = defaultRouteModel.defaultRouteQuery.waypoints[0]
                        toNavigation();
                    }
                }
                ToolTip{
                    id: btnNavigateToolTip
                    text: "Navigate"
                    visible: btnNavigate.hovered
                    y: btnNavigate.y - btnNavigate.height / 2
                    x: btnNavigate.x - btnNavigate.width / 2
                }
            }
        }
    }

}
