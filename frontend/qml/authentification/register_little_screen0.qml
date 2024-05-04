import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import NavigationManager
import UserModel

import CustomControls

Item {

    id: registerRoot

    property NavigationManager navigationManager
    property UserModel userModel
    property int textfieldWidth:  width * 0.8;
    property int textfieldHeight: 60
    property int fontPointSize: 20
    property int xPos: (width / 2) - textfieldWidth / 2

    property int validTextfields: 0

    property int emailType : 0

    width : registerLoader.windowWidth;
    height : registerLoader.windowHeight;

    ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            spacing: 5

        Image {
            id: image
            x: 0
            y: 0
            source: "/img/background.png"
            fillMode: Image.PreserveAspectCrop

            ValidationTextField{
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldEmail
                y: columnLayout.height * 0.2
                x: xPos
                width: textfieldWidth
                placeholderText: qsTr("Email")
                errorMsg: "Not a valid Email"
                onEditingFinished: {
                    emailType = userModel.onEmailAdressEntered(textFieldEmail.text)
                    if(emailType == 1 || emailType == 2){
                        isValid = true;
                        isError = false;
                    } else {
                        isError = true;
                        isValid = false;
                    }
                    if(isValid){
                        validTextfields ++
                    } else if(!isValid){
                        validTextfields --
                    }
                }
            }
            ValidationTextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldPassword
                x: xPos
                y: columnLayout.height * 0.35
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
                    if(isValid){
                        validTextfields ++
                    } else if(!isValid){
                        validTextfields --
                    }
                }
            }
            ValidationTextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldPasswordReEntered
                x: xPos
                y: columnLayout.height * 0.5
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
                    if(isValid){
                        validTextfields ++
                    } else if(!isValid){
                        validTextfields --
                    }
                }
            }
            Button {
                font.pointSize: fontPointSize
                height: 70
                x: xPos
                y: columnLayout.height * 0.65
                width: textfieldWidth
                text: qsTr("Next")

                enabled: (textFieldEmail.isValid
                          && textFieldPassword.isValid
                          && textFieldPasswordReEntered.isValid)
                onClicked: {
                    navigationManager.changePage("register_little_screen1");
                }
            }
        }
    }
}
