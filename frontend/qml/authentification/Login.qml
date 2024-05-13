import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../custom_controls"

Item {

    id: loginRoot

    property int textfieldWidth:  width * 0.8;
    property int textfieldHeight: 60
    property int fontPointSize: 20
    property int xPos: (width / 2) - textfieldWidth / 2
    property int emailType: 0

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
                id: textFieldEmail
                x: (loginRoot.width / 2) - width / 2
                y: loginRoot.height / 2
                width: 300
                height: 60
                placeholderText: qsTr("Email")
                errorMsg: "Not a valid Email"
                onEditingFinished: {
                    emailType = userModel.onEmailAdressEntered(textFieldEmail.text)
                    switch(emailType)
                    {
                    case 2:
                        isValid = true;
                        isError = false;
                        break;
                    case 1:
                        isValid = true;
                        isError = false;
                        break;
                    case 0:
                    default:
                         isError = true;
                        isValid = false;
                        break;
                    }
                }
            }

            Rectangle {
                y: textFieldEmail.y - 300
                x: textFieldEmail.x + ((textFieldEmail.width - width)/2)
                width: 250
                height: 250
                color: "white"
                radius: 180
            }

            TextField {
                id: textField2
                x: textFieldEmail.x
                y: textFieldEmail.y + 100
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
                x: textField2.x
                y: textField2.y + 100
                width: 300
                height: 60
                text: qsTr("Sign In")
                clip: false
                font.pointSize: 24
                checkable: false
                Material.background: "#391ee9"

                //enabled: textFieldEmail.isValid

                onClicked: {

                    userModel.onLoginAttempt(
                                textFieldEmail.text,
                                textFieldEmail.text
                    );
                    stackLayout.push(map)

                    //ToolTip.show("Wrong password", 3000)
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
