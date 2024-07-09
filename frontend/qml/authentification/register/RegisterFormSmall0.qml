import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import ValidationTextfield

import UserModel

Item {
    property int textfieldWidth:  width * 0.8;
    property int textfieldHeight: 60
    property int fontPointSize: 20
    property int xPos: (width / 2) - textfieldWidth / 2
    property int emailType: 0

    ColumnLayout {
            id: columnLayout
            anchors.fill: parent

        Image {
            id: image
            x: 0
            y: 0
            z: -1
            source: "/res/img/background.png"
            fillMode: Image.PreserveAspectCrop

            ValidationTextfield{
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldEmail
                x: xPos
                y: columnLayout.height * 0.3
                width: textfieldWidth
                placeholderText: qsTr("Email")
                errorMsg: "Not a valid Email"
                onEditingFinished: {
                    var email_t = UserModel.emailType(textFieldEmail.text);
                    switch(email_t)
                    {
                    case UserModel.ERROR:
                        state = 1
                        break;
                    case UserModel.PRIVATE:
                    case UserModel.PREMIUM:
                    case UserModel.COMPANY:
                        state = 2
                        break;
                    default:
                        state = 0;
                        break;
                    }
                    UserModel.email_t = email_t
                }
            }

            ValidationTextfield {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldPassword
                x: xPos
                y: columnLayout.height * 0.45
                width: textfieldWidth
                placeholderText: qsTr("Passord")
                echoMode: TextInput.Password


            }
            ValidationTextfield {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldPasswordReEntered
                x: xPos
                y: columnLayout.height * 0.6
                width: textfieldWidth
                placeholderText: qsTr("Re enter password")
                echoMode: TextInput.Password
                onTextEdited: {
                    if(text !== textFieldPassword.text) {
                        toolTip.visible = true
                        state = 1
                    } else if(text === textFieldPassword.text) {
                        toolTip.visible = false
                        state = 2
                    }
                    else {
                        toolTip.visible = false
                        state = 0
                    }
                }
                ToolTip{
                    id: toolTip
                    text: "Not the same password"
                    visible: false
                }
            }
            Button {
                width: textfieldWidth
                height: textfieldHeight
                y: columnLayout.height * 0.8
                x: xPos
                text: qsTr("Next")

                enabled: (textFieldEmail.isValid
                          && textFieldPasswordReEntered.isValid)

                onClicked: {
                    registerLoader.registerState = "next"
                }
            }
        }
    }
}
