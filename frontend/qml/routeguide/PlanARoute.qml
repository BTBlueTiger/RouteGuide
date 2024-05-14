import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import "../dialogs"

import PlanARouteModel

Item {

    property int fontPointSize: 20

    PlanARouteModel{
        id: planARouteModel;

    }


    ScrollView {
        id: scrollView
        y: tabbarHeight
        width: parent.width
        height: parent.height / 2
        ListView {
            height: parent.height
            width: parent.width
            model: planARouteModel
            delegate: RowLayout {
                Text {
                    text: town
                    font.pixelSize: 24
                    color: "white"
                }
                Item {
                    Layout.fillWidth: true
                }
                ToolButton {
                    text: "x"
                    onClicked: {
                        planARouteModel.remove(index)
                    }
                }
            }
        }
    }

    Button {
        id: btnAddAStop
        x: parent.width / 2 - (btnAddAStop.width / 2)
        y: scrollView.height + tabbarHeight * 2
        width: parent.width - 50
        text: "Add a stop"
        onClicked: {
            locationDialog.open()
        }
    }

    LocationDialog {
        id: locationDialog

        onLocationAdded: function locationFound (location, latitude, longitude) {

            planARouteModel.append(location, latitude, longitude)
            console.log(location, latitude, longitude)
        }
    }



    Button {
        id: btnPlanARoute
        x: parent.width / 2 - (btnAddAStop.width / 2)
        y: btnAddAStop.y + btnAddAStop.height
        width: parent.width - 50
        text: "Plan the Route"
    }
}
