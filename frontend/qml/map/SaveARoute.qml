import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import UserModel

Dialog {

    property int fontPointSize: 24
    id: saveARouteDialog
    height: rootWindow.height * 0.6
    width: rootWindow.width * 0.8
    x: rootWindow.width / 2 - saveARouteDialog.width / 2
    y: rootWindow.height / 2 - saveARouteDialog.height / 2
    title: "Save A Route"

    // Header
    header: Item {
        id: headerItem
        height: saveARouteDialog.height * 0.2
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
        height: saveARouteDialog.height * 0.6
            ColumnLayout {
                anchors.fill: parent
                x: saveARoute.width / 2 - width / 2
                TextField {
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: fontPointSize
                    id: textfieldUserName
                    width: saveARouteDialog.width * .8
                    placeholderText: qsTr("Route Name")
                }

                Button {
                    font.pointSize: fontPointSize
                    id: buttonHiker
                    height: 70
                    Layout.fillWidth: true
                    text: qsTr("Hiker")
                    property bool isClicked: false
                    onClicked: isClicked = buttonClicked(button3, 2, isClicked)
                }


                Button {
                    font.pointSize: fontPointSize
                    id: buttonSportler
                    height: 70
                    width: parent.width * .8
                    text: qsTr("Sportler")
                    property bool isClicked: false
                    onClicked: isClicked = buttonClicked(button3, 2, isClicked)
                }

                Button {
                    font.pointSize: fontPointSize
                    id: buttonTourist
                    height: 70
                    width: parent.width * .8
                    text: qsTr("Tourist")
                    property bool isClicked: false
                    onClicked: isClicked = buttonClicked(button3, 2, isClicked)
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
        console.log("Accepted: Route Name: " + routeNameField.text + ", Save Location: " + saveLocation.currentText)
        // Add your save logic here
    }

    onRejected: {
        console.log("Rejected")
        // Add your cancel logic here
    }
}
