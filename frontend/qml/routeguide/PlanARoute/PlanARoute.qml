import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QtPositioning

import WaypointManager
import WaypointModel

import GeoPositionRessource

Item {

    property int fontPointSize: 20
    property int pageIndex: 0

    property WaypointModel searchWaypointModel : waypointManager.createWaypointModel(searchWaypointModelName)
    property WaypointModel potentialWaypointModel : waypointManager.createWaypointModel(potentialWaypointModelName)

    property bool fromCurrentPostion: false

    function setWayPoints() {

        routeQuery.clearWaypoints()
        if(fromCurrentPostion){
            routeQuery.addWaypoint(QtPositioning.coordinate(
                                       GeoPositionRessource.coordinate.latitude,
                                       GeoPositionRessource.coordinate.longitude
                                       ))


        }
        var _co = potentialWaypointModel.coordinates
        routeQuery.waypoints = potentialWaypointModel.coordinates
        /*
        for(var i = 0; i < _co.length; i++) {
            routeQuery.addWaypoint(_co[i])
        }
        waypoints = routeQuery.waypoints
        console.log(routeQuery.waypoints)
        */
        routeModel.update()
    }

    id: planARoute

    signal toNavigation()


    Rectangle {
        id: rectangle
        anchors.fill: parent



            Rectangle {
                anchors.fill: parent
                z: 1

                Rectangle {
                    id: tabbarRoot
                    anchors {
                        top: parent.top
                        right: parent.right
                        left: parent.left
                    }
                    width: parent.width
                    height: tabbarHeader.height

                    TabBar {
                        id: tabbarHeader

                        z: 1
                        anchors.fill: parent
                        currentIndex: pageIndex
                        onCurrentIndexChanged: pageIndex = currentIndex

                        TabButton {
                            text: qsTr("Search")

                        }

                        TabButton {
                            text: qsTr("Added Waypoints")
                        }

                        TabButton {
                            text: qsTr("Preview")

                        }
                    }
                }




            Rectangle {
                id: swipeViewRoot
                color: "black"
                y: tabbarRoot.y + tabbarRoot.height
                height: parent.height - tabbarRoot.height * 2
                width: parent.width

                SwipeView {
                    anchors.fill: parent
                    onCurrentIndexChanged: {
                        if(currentIndex === 2) {
                            if(potentialWaypointModel.rowCount() === 0) {
                                currentIndex = 1
                            } else {
                                setWayPoints()
                            }
                        }
                        pageIndex = currentIndex
                    }
                    currentIndex: pageIndex


                    Page {
                        SearchPage{
                            function onitemClicked (item){
                                potentialWaypointModel.appendModelItem(item)
                            }
                        }
                    }

                    Page {
                        title: qsTr("Page 2")
                        AddedPage{

                        }
                    }

                    Page {
                        title: qsTr("Page 3")
                        PreviewPage {
                            id: previewPage
                            height: parent.height
                            width: parent.width
                            onToNavigation: {
                                setWayPoints
                                toNavigation()
                            }
                        }
                    }
                }
            }

        }
    }
}
