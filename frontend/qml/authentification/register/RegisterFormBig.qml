import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "../../custom_controls"

Item {
    id: registerForm

    width: registerLoader.width
    height: registerLoader.height
    property int state: 0
    property int textfieldWidth:  (width * 0.8) / 2;
    property int leftSideX: (width / 4) - (width / 6)
    property int rightSideX: (width / 4) + (width / 3.5)
    property int fontPointSize: 24
    property int emailType: 0

    function buttonClicked(button, id, clicked) {
        if (!clicked) {
            userModel.onGroupSelect(id);
            button.Material.background = Material.primary // Change the color to blue when clicked
        } else {
            userModel.onGroupSelect(id);
            button.Material.background = Material.rippleColor
        }
        return !clicked
    }

    RowLayout {
            id: rowLayout
            anchors.fill: parent

            Image {
                id: backgroundImage
                source: "/res/img/background.png"
                x: 0
                y: 0
                fillMode: Image.PreserveAspectCrop

                ValidationTextfield{
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: fontPointSize
                    id: textFieldEmail
                    x: leftSideX
                    y: rowLayout.height * 0.3
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
                    x: leftSideX
                    y: rowLayout.height * 0.45
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
                    x: leftSideX
                    y: rowLayout.height * 0.6
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
                    font.pointSize: fontPointSize
                    id: button1
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.1
                    width: textfieldWidth
                    text: qsTr("Hiker")
                    property bool isClicked: false

                    enabled: emailType == 1

                    onClicked: {
                       isClicked = buttonClicked(button1, 0, isClicked)
                    }
                }


                Button {
                    font.pointSize: fontPointSize
                    id: button2
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.25
                    width: textfieldWidth
                    text: qsTr("Sportler")
                    property bool isClicked: false

                    enabled: emailType == 1

                    onClicked: {
                       isClicked = buttonClicked(button2, 1, isClicked)
                    }
                }

                Button {
                    font.pointSize: fontPointSize
                    id: button3
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.4
                    width: textfieldWidth
                    text: qsTr("Tourist")
                    property bool isClicked: false

                    enabled: emailType == 1

                    onClicked: {
                       isClicked = buttonClicked(button3, 2, isClicked)
                    }
                }

                Button {
                    font.pointSize: fontPointSize
                    id: button4
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.55
                    width: textfieldWidth
                    text: qsTr("Company")
                    enabled: emailType == 2
                    checked: emailType == 2
                    onCheckedChanged: {
                        if(checked) {
                            Material.background = Material.primary
                            Material.foreground = Material.foreground
                        } else {
                            Material.background = Material.rippleColor
                        }
                    }
                    checkable: false
                }

                Button {
                    font.pointSize: fontPointSize
                    id: button5
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.7
                    width: textfieldWidth
                    text: qsTr("Register")
                    enabled: (textFieldEmail.isValid
                              && textFieldPassword.isValid
                              && textFieldPasswordReEntered.isValid)
                }
            }
    }
}
