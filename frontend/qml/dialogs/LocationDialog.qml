// CustomDialog.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../custom_controls"

import PlanARouteHouseNumberModel
import QLocationSearch


Dialog {
    id: wayPointDialog
    property int waypointID
    width: parent.width * 0.75
    height: parent.height * 0.75
    x: parent.width / 2 - wayPointDialog.width / 2
    y: parent.height / 2 - wayPointDialog.height / 2
    title: "Add a stop"

    property string location: ""
    signal locationAdded(location: string, houseNumbers: PlanARouteHouseNumberModel)

    PlanARouteHouseNumberModel{
        id: planARouteHouseNumberModel
    }

    ValidationTextfield{
        id: textfieldTown
        x: parent.width / 2 - textfieldTown.width / 2
        width: wayPointDialog.width - 60
        horizontalAlignment: Text.AlignHCenter

        placeholderDefault: "Enter a Town"
        onIsErrorChanged: {
            ToolTip: ("Not found in the Database", 3000)
        }
    }

    ValidationTextfield{
        id: textfieldStreet
        x: parent.width / 2 - textfieldTown.width / 2
        y: textfieldTown.height + 10
        width: wayPointDialog.width - 60
        horizontalAlignment: Text.AlignHCenter

        placeholderDefault: "Enter a Street"
        onIsErrorChanged: {
            ToolTip: ("Not found in the Database", 3000)
        }
    }

    Button {
        id: searchButton

        property int houseNumberLen: planARouteHouseNumberModel.getLenghtOfList();
        text: {
            if(houseNumberLen == 0) {
                "Add Street"
            } else if(houseNumberLen() == 1) {
                "Add the waypoint"
            } else {
                "Add the waypoints"
            }
        }

        y: parent.height - searchButton.height
        x: parent.width / 2 - searchButton.width / 2

        property var houseNumbers: []
        onClicked: {
            location = textfieldTown.text + " " +  textfieldStreet.text
            planARouteHouseNumberModel.setQSetttings();
            locationAdded(location, planARouteHouseNumberModel)
            close()
        }
    }


    Flickable{
        id: houseNumbersFlickable
        y: addHouseNumbersButton.y +  addHouseNumbersButton.height * 1.4
        width: parent.width
        height: parent.height * 0.4
        clip: true
        flickableDirection: Flickable.VerticalFlick
        contentWidth: houseNumbersFlickable.width * .24 // Set the contentWidth to the width of the Flow
        contentHeight: houseNumbersFlow.height // Set the contentHeight to the height of
        ScrollBar.vertical: ScrollBar {
            id: scrollBar
            policy: ScrollBar.AlwaysOn
            anchors.left: houseNumbersFlickable.right
            anchors.top: houseNumbersFlickable.top
            anchors.right: houseNumbersFlickable.right
            anchors.bottom: houseNumbersFlickable.bottom
            anchors.bottomMargin: 20
        }

            Flow {
                id: houseNumbersFlow
                width: houseNumbersFlickable.width
                spacing: 5

                Repeater {
                    model: planARouteHouseNumberModel // Set the model for the Repeater
                    delegate: TextField {
                        id: planARouteHouseNumberModelItem
                        width: houseNumbersFlickable.width * .24
                        text: house_number
                        onEditingFinished: house_number = text
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
        }
    }



    Button {
        id: addHouseNumbersButton
        text: "Add House Number"
        y: textfieldStreet.y + addHouseNumbersButton.height * 1.5
        x: parent.width / 2 - addHouseNumbersButton.width / 2
        onClicked: {
            planARouteHouseNumberModel.append("")
        }
    }
}