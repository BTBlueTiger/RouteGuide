import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import ScreenInfo

Window {
    id: window
    property var screenInfo: ScreenInfo {}

    visible: true

    width: Qt.platform.os == "android" ? screenInfo.screenResolution().width : 1280
    height:  Qt.platform.os == "android" ? screenInfo.screenResolution().height : 720
    title: "Route Guide Login"
    color: "#e6e6e6"

    Component.onCompleted: {
        console.log("Window size:", window.height, window.width);
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        Image {
            id: image
            x: 0
            y: 0
            source: "/images/img/Background.png"
            fillMode: Image.PreserveAspectFit


            TextField {
                id: textField
                width: 300
                height: 60
                color: Qt.platform.os === "android" ? "#ffffff" : "#000000"
                anchors.verticalCenter: window.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: window.height / 2
                x: (window.width / 2) - width / 2
                placeholderTextColor:  Qt.platform.os === "android" ? "#ffffff" : "#000000"
                selectionColor: "#391ee9"
                font.pointSize: 24
                placeholderText: qsTr("Email")
                Component.onCompleted: {
                    console.log("TextField position (x, y):", textField.x, textField.y);
                }
            }

            Rectangle {
                y: textField.y - 300
                x: textField.x + ((textField.width - width)/2)
                width: 250
                height: 250
                color: "white"
                radius: 180
            }

            TextField {
                id: textField2
                x: textField.x
                y: textField.y + 100
                width: 300
                height: 60
                color: Qt.platform.os === "android" ? "#ffffff" : "#000000"
                horizontalAlignment: Text.AlignHCenter
                echoMode: TextInput.Password
                placeholderTextColor:  Qt.platform.os === "android" ? "#ffffff" : "#000000"
                selectionColor: "#391ee9"
                placeholderText: qsTr("Password")
                font.pointSize: 24
            }

            Button {
                id: button
                x: textField2.x
                y: textField2.y + 100
                width: 300
                height: 60
                text: qsTr("Sign In")
                clip: false
                font.pointSize: 24
                checkable: false
                Material.background: "#391ee9"
            }

            Text {
                id: text1
                x: button.x
                y: button.y + 80
                text: qsTr("Forgot Password")
                font.pixelSize: 20
            }

            Text {
                id: text2
                x: button.x + button.width - width
                y: button.y + 80

                color: "blue"
                text: qsTr("Sign Up")
                font.pixelSize: 20
            }
        }
    }
}
