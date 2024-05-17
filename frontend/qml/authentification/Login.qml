import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../custom_controls"

import UserModel
import EMAIL_T


Item {

    id: loginRoot

    property int textfieldWidth:  width * 0.8;
    property int textfieldHeight: 60
    property int fontPointSize: 20
    property int xPos: (width / 2) - textfieldWidth / 2
    property int emailType: 0

    Connections{
        target: UserModel
        function onUserChanged() {
            if(UserModel.loggedIn) {
                stackLayout.push(map)
            } else {
                wrongUserToolTip.visible = true
                wrongUserToolTipTimer.start()
            }
        }
    }

    Timer {
        id: wrongUserToolTipTimer
        interval: 4000 // 4 sec
        onTriggered: wrongUserToolTip.visible = false
    }

    ToolTip {
        id: wrongUserToolTip
        text: "Username or Password are wrong"
        visible: false
        x: parent.width / 2 - wrongUserToolTip.width / 2
        y: parent.height / 2 - wrongUserToolTip.height / 2

    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        Image {
            id: backgroundImage
            x: 0
            y: 0
            source: "/res/img/background.png"
            fillMode: Image.PreserveAspectCrop


            ValidationTextfield{
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldUsername
                x: (loginRoot.width / 2) - width / 2
                y: loginRoot.height / 2
                width: 300
                height: 60
                placeholderText: qsTr("Username")
            }

            Rectangle {
                y: textFieldUsername.y - 300
                x: textFieldUsername.x + ((textFieldUsername.width - width)/2)
                width: 250
                height: 250
                color: "white"
                radius: 180
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
                id: button
                x: textFieldPassword.x
                y: textFieldPassword.y + 100
                width: 300
                height: 60
                text: qsTr("Sign In")
                clip: false
                font.pointSize: 24
                checkable: false
                Material.background: "#391ee9"
                onClicked: {
                    UserModel.loginAttempt(
                        {
                            ["username"] : textFieldUsername.text,
                            ["password"] : textFieldPassword.text
                        }
                    );
                }

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
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor

                    onEntered: text2.color = "lightBlue"
                    onExited: text2.color = "blue"
                    onClicked: {
                        stackLayout.push(register)
                        toolbarBackVisible = true;
                    }
                }
            }
        }
    }
}
