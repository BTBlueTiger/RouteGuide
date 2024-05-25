import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import "../dialogs"

import PlanARouteModel
import WaypointModel

import QLocationSearch

Item {

    property int fontPointSize: 20

    id: planARoute

    PlanARouteModel{
        id: planARouteModel;
    }

    ScrollView {
        id: scrollView
        y: tabbarHeight
        width: parent.width
        height: parent.height / 2
        anchors.margins: 20
        ListView {
            height: parent.height
            width: parent.width
            model: planARouteModel
            delegate: ColumnLayout {

                anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined

                RowLayout {

                    Text {
                        text: "Stadt: " + waypoint_model_role.town
                        font.pixelSize: 24
                        color: "white"
                        Layout.alignment: Qt.AlignLeft
                    }

                    Text {
                        text: " Straße: " + waypoint_model_role.street
                        font.pixelSize: 24
                        color: "white"
                        Layout.alignment: Qt.AlignLeft
                    }

                    Item {
                        Layout.fillWidth: true
                    }
                    ToolButton {
                        icon.source: "/res/btn/modify.svg"
                        onClicked: {
                            locationDialog.waypointModel = planARouteModel.getModel(planARouteModel.index)
                            locationDialog.open()
                        }
                    }

                    ToolButton {
                        icon.source: "/res/btn/clear.svg"
                        onClicked: {
                            planARouteModel.remove(index)
                        }
                        Layout.alignment: Qt.AlignRight
                    }
                }


                RowLayout {
                    width: parent.width
                    height: parent.height

                    Repeater {
                        model: waypoint_model_role.houseNumbers
                        delegate: RowLayout {
                            Text {
                                text: modelData
                                font.pixelSize: 20
                                color: "white"
                            }
                        }
                    }
                }
            }
        }
    }

    WaypointModel {
        id: waypointModel
    }

    Button {
        id: btnAddAStop
        x: parent.width / 2 - (btnAddAStop.width / 2)
        y: scrollView.height + tabbarHeight * 2
        width: parent.width - 50
        text: "Add a stop"
        onClicked: {
            planARouteModel.appendNewWayPointModel(planARouteModel.rowCount + 1)
            locationDialog.waypointModel = planARouteModel.getModel(planARouteModel.index)
            if(defaultTown.text.length > 0) {
                locationDialog.waypointModel.town = defaultTown.text
            }
            locationDialog.open()
        }
    }

    WaypointDialog {
        id: locationDialog

        onLocationAdded: function locationAdded () {
            locationDialog.close()
        }
    }


    QLocationSearch {
        id: qLocationSearchPlugin

    }

    Button {
        id: btnPlanARoute
        x: parent.width / 2 - (btnAddAStop.width / 2)
        y: btnAddAStop.y + btnAddAStop.height
        width: parent.width - 50
        text: "Plan the Route"
        onClicked: {
            qLocationSearchPlugin.searchLocation(planARouteModel)
        }
    }

    TextField {
        id: defaultTown
        x: parent.width / 2 - (btnAddAStop.width / 2)
        y: btnPlanARoute.y + btnPlanARoute.height
        width: parent.width - 50
        placeholderText: qsTr("Default Town")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
