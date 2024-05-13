import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../custom_controls"

Item {
    property int textfieldWidth:  width * 0.8;
    property int textfieldHeight: 60
    property int fontPointSize: 20
    property int xPos: (width / 2) - textfieldWidth / 2
    property int emailType: 0

    width : registerLoader.windowWidth;
    height : registerLoader.windowHeight;

    ColumnLayout {
            id: columnLayout
            anchors.fill: parent

        Image {
            id: image
            x: 0
            y: 0
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
                    emailType = userModel.onEmailAdressEntered(textFieldEmail.text)
                    switch(emailType)
                    {
                    case 2:
                        button4.clicked()
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

            ValidationTextfield {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldPassword
                x: xPos
                y: columnLayout.height * 0.45
                width: textfieldWidth
                placeholderText: qsTr("Passord")
                echoMode: TextInput.Password
                onEditingFinished: {
                    if(userModel.onPasswordEntered(textFieldPassword.text)){
                        isValid = true;
                        isError = false
                    } else {
                        isError = true;
                        isValid = false;
                    }
                }
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
                    if(userModel.onSecondPasswordEntered(textFieldPasswordReEntered.text)){
                        isValid = true;
                        isError = false
                    } else {
                        isError = true;
                        isValid = false;
                    }
                }
            }
            Button {
                width: textfieldWidth
                height: textfieldHeight
                y: columnLayout.height * 0.8
                x: xPos
                text: qsTr("Next")

                enabled: (textFieldEmail.isValid
                          && textFieldPassword.isValid
                          && textFieldPasswordReEntered.isValid)

                onClicked: {
                    registerLoader.registerState = "next"
                }
            }
        }
    }
}
