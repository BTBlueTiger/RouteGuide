import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects

import ValidationTextfield

Item {

    // Not implemented yet
    property alias btnForgotPassword: btnForgotPassword
    property alias btnLogin: btnLogin
    property alias btnSignUp: btnSignUpMouseArea

    id: loginform
    anchors.fill: parent
    ColumnLayout{
        x: 0
        y: 0
        anchors.fill: parent
        // Background Image
        Image {
            source: "/res/img/background.png"
            fillMode: Image.PreserveAspectCrop

            Rectangle {
                y: textFieldUsername.y - 300
                x: textFieldUsername.x + ((textFieldUsername.width - width) / 2)
                width: 250
                height: 250
                color: "transparent"
                radius: 125 // Making it fully circular
                clip: true // Clip the content to the bounds of the Rectangle

                Image {
                    x:0
                        id: sourceItem
                        source: "/res/img/logo.jpeg"
                        anchors.centerIn: parent
                        width: 250
                        height: 250
                        visible: false
                    }

                    MultiEffect {
                        x:0
                        source: sourceItem
                        anchors.fill: sourceItem
                        maskEnabled: true
                        maskSource: mask
                    }

                    Item {
                        id: mask
                        width: sourceItem.width
                        height: sourceItem.height
                        layer.enabled: true
                        visible: false

                        Rectangle {

                            width: sourceItem.width
                            height: sourceItem.height
                            radius: width/2
                            color: "black"
                        }
                    }
            }

            // User Name Login
            ValidationTextfield{
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 20
                id: textFieldUsername
                width: 300
                height: 60
                placeholderText: qsTr("Username")
                x: (loginform.width / 2) - width / 2
                y: loginform.height / 2
            }

            TextField {
                id: textFieldPassword
                x: textFieldUsername.x
                y: textFieldUsername.y + 100
                width: 300
                height: 60
                horizontalAlignment: Text.AlignHCenter
                echoMode: TextInput.Password
                selectionColor: "#391ee9"
                placeholderText: qsTr("Password")
                font.pointSize: 20
            }

            Button {
                id: btnLogin
                x: textFieldPassword.x
                y: textFieldPassword.y + 100
                width: 300
                height: 60
                text: qsTr("Sign In")
                clip: false
                font.pointSize: 24
                checkable: false
                Material.background: "#391ee9"
            }

            //TODO: Implement Page
            Text {
                id: btnForgotPassword
                x: btnLogin.x
                y: btnLogin.y + 80
                text: qsTr("Forgot Password")
                font.pixelSize: 20
            }

            Text {
                id: btnSignUp
                x: btnLogin.x + btnLogin.width - width
                y: btnLogin.y + 80

                color: "blue"
                text: qsTr("Sign Up")
                font.pixelSize: 20
                MouseArea {
                    id: btnSignUpMouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onEntered: btnSignUp.color = "lightBlue"
                    onExited: btnSignUp.color = "blue"
                }
            }
        }
    }
}