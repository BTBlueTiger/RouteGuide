import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import ValidationTextfield

import UserModel

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


    Connections{
        target: UserModel
        function onRegisterSuccessChanged() {


            if(UserModel.registerSuccess) {
                console.log("isSuccess")
                registerAttemptSuccess.visible = true
                registerAttemptSuccessToolTip.start()
            } else {
                console.log("isNotSuccess")
                registerAttemptFailed.visible = true
                registerAttemptFailedToolTip.start()
            }
        }
    }



    function buttonClicked(button, id, clicked) {
        if (!clicked) {
            //userModel.onGroupSelect(id);
            button.Material.background = Material.primary // Change the color to blue when clicked
            UserModel.groupID = id
        } else {
            //userModel.onGroupSelect(id);
            button.Material.background = Material.rippleColor
        }
        return !clicked
    }

    ToolTip {
        id: registerAttemptSuccess
        text: "Check your emails to confirm your registration"
        visible: false
        x: registerForm.width / 2 - registerAttemptSuccess.width / 2
        y: registerForm.height / 2 - registerAttemptSuccess.height / 2

        Timer {
            id: registerAttemptSuccessToolTip
            interval: 4000 // 4 sec
            onTriggered: registerAttemptSuccess.visible = false
        }
    }

    ToolTip {
        id: registerAttemptFailed
        text: "Something went wrong"
        visible: false
        x: registerForm.width / 2 - registerAttemptFailed.width / 2
        y: registerForm.height / 2 - registerAttemptFailed.height / 2

        Timer {
            id: registerAttemptFailedToolTip
            interval: 4000 // 4 sec
            onTriggered: registerAttemptFailed.visible = false
        }
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

                TextField {
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: fontPointSize
                    id: textfieldUserName
                    x: leftSideX
                    y: rowLayout.height * 0.20
                    width: textfieldWidth
                    placeholderText: qsTr("UserName")
                }

                ValidationTextfield{
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: fontPointSize
                    id: textfieldEmail
                    x: leftSideX
                    y: rowLayout.height * 0.35
                    width: textfieldWidth
                    placeholderText: qsTr("Email")
                    errorMsg: "Not a valid Email"
                    onEditingFinished: {
                        var email_t = UserModel.emailType(textfieldEmail.text);
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
                    }
                }

                ValidationTextfield {
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: fontPointSize
                    id: textFieldPassword
                    x: leftSideX
                    y: rowLayout.height * 0.5
                    width: textfieldWidth
                    placeholderText: qsTr("Passord")
                    echoMode: TextInput.Password
                }

                ValidationTextfield {
                    property bool tooltipVisible: false
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: fontPointSize
                    id: textFieldPasswordReEntered
                    x: leftSideX
                    y: rowLayout.height * 0.65
                    width: textfieldWidth
                    placeholderText: qsTr("Re enter password")
                    errorMsg: "Not the same password"
                    echoMode: TextInput.Password

                    onTextEdited: {
                        if(text !== textFieldPassword.text) {
                            state = 1
                        } else if(text === textFieldPassword.text) {
                            state = 2
                        }
                        else {
                            state = 0
                        }
                    }
                }

                Button {
                    font.pointSize: fontPointSize
                    id: buttonHiker
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.1
                    width: textfieldWidth
                    text: qsTr("Hiker")
                    property bool isClicked: true


                    enabled: UserModel.emailType(textfieldEmail.text) === UserModel.PRIVATE

                    onClicked: {
                       isClicked = buttonClicked(button1, 1, isClicked)
                    }
                }


                Button {
                    font.pointSize: fontPointSize
                    id: buttonSportler
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.25
                    width: textfieldWidth
                    text: qsTr("Sportler")
                    property bool isClicked: false

                    enabled: UserModel.emailType(textfieldEmail.text) === UserModel.PRIVATE

                    onClicked: isClicked = buttonClicked(button2, 2, isClicked)
                }

                Button {
                    font.pointSize: fontPointSize
                    id: buttonTourist
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.4
                    width: textfieldWidth
                    text: qsTr("Tourist")
                    property bool isClicked: false

                    enabled: UserModel.emailType(textfieldEmail.text) === UserModel.PRIVATE

                    onClicked: isClicked = buttonClicked(button2, 3, isClicked)
                }

                Button {
                    font.pointSize: fontPointSize
                    id: buttonCompany
                    height: 70
                    x: rightSideX
                    y: rowLayout.height * 0.55
                    width: textfieldWidth
                    text: qsTr("Company")
                    enabled: UserModel.emailType(textfieldEmail.text) === UserModel.COMPANY
                    checked: UserModel.emailType(textfieldEmail.text) === UserModel.COMPANY
                    onCheckedChanged: {
                        if(checked) {
                            text.color = "white"
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
                    enabled: {
                        textFieldPasswordReEntered.isValid &&
                        textfieldEmail.isValid
                    }
                    onClicked: {


                        UserModel.registerAttempt(
                                {
                                    "email": textfieldEmail.text,
                                    "username": textfieldUserName.text,
                                    "password": textFieldPassword.text,
                                    "group": {
                                            "id": UserModel.groupID
                                        }
                                }
                            )
                    }
                }
            }
    }
}
