import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import UserModel

import ValidationTextfield


Dialog {

    property int fontPointSize: 24
    id: saveARouteDialog
    height: rootWindow.height * 0.75
    width: rootWindow.width * 0.8
    x: rootWindow.width / 2 - saveARouteDialog.width / 2
    y: rootWindow.height / 2 - saveARouteDialog.height / 2
    title: "Save A Route"

    // Header
    header: Item {
        id: headerItem
        height: saveARouteDialog.height * 0.05
        width: parent.width
            Text {
                y: headerItem.height / 2 - height/ 2
                text: "Where to save the Route"
                font.pixelSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
                color: "white"
            }
    }

    // Content
    contentItem: Item {
        width: saveARouteDialog.width
        height: saveARouteDialog.height * 0.8
        ColumnLayout {
            anchors.fill: parent
            x: saveARoute.width / 2 - width / 2
            ValidationTextfield{
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textfieldRouteName
                Layout.fillWidth: true
                placeholderText: qsTr("Route Name")
                errorMsg: "You have to enter a route name with more than 3 letters"
                onTextChanged: {
                    if(textfieldRouteName.text.length <= 3) {
                        textfieldRouteName.state = 1;
                    } else if(textfieldRouteName.text.length > 3) {
                        textfieldRouteName.state = 2;
                    } else {
                        textfieldRouteName.state = 0
                    }
                }
            }

            Button {
                font.pointSize: fontPointSize
                id: btnType
                height: 30
                Layout.fillWidth: true
                text: UserModel.email_t === UserModel.COMPANY ? "Company" : UserModel.group
                property bool isClicked: false
                Material.background : isClicked ? Material.primary : Material.rippleColor
            }

            Button {
                property bool isClicked : false
                font.pointSize: fontPointSize
                id: buttonPrivate
                height: 30
                Layout.fillWidth: true
                onClicked: isClicked = !isClicked
                text: isClicked ?  qsTr("Private Route") : qsTr("Public Route")
                Material.background : isClicked ? Material.primary : Material.rippleColor

            }
        }
    }

    // Footer
    footer: Item {
        height: saveARouteDialog.height * 0.2
        width: parent.width
        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10
            Button {
                text: "OK"
                onClicked: {
                    saveARouteDialog.accepted()
                    saveARouteDialog.close()
                }
                enabled: textfieldRouteName.state === 2
            }
            Button {
                text: "Cancel"
                onClicked: {
                    saveARouteDialog.rejected()
                    saveARouteDialog.close()
                }
            }
        }
    }

    onAccepted: {

        var waypointModel = waypointManager.getWaypointModel(potentialWaypointModelName)
        var addresses = waypointModel.waypointInformations

        UserModel.createRoute
        (
            {
                ["name"] : textfieldRouteName.text,
                ["isPublic"] : buttonPrivate.isClicked ? false : true,
                ["addresses"]: addresses
            },

        )

    }

    onRejected: {
        console.log("Rejected")
        // Add your cancel logic here
    }
}
