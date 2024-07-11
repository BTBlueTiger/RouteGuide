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
    width : registerLoader.windowWidth;
    height : registerLoader.windowHeight;

    Component.onCompleted: {
        console.log(UserModel.email_t)
    }

    function buttonClicked(button, id, clicked) {
        if (!clicked) {
            ////.onGroupSelect(id);
            button.Material.background = Material.primary // Change the color to blue when clicked
        } else {
            ////.onGroupSelect(id);
            button.Material.background = Material.rippleColor
        }
        return !clicked
    }

    ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            spacing: 5

        Image {
            id: image
            x: 0
            y: 0
            source: "/res/img/background.png"
            fillMode: Image.PreserveAspectCrop

            Button {
                font.pointSize: fontPointSize
                id: buttonHiker
                height: 70
                x: xPos
                y: parent.height * 0.1
                width: textfieldWidth
                text: qsTr("Hiker")
                property bool isClicked: true


                enabled: UserModel.email_t === UserModel.PRIVATE

                onClicked: {
                   isClicked = buttonClicked(buttonHiker, 1, isClicked)
                }
            }


            Button {
                font.pointSize: fontPointSize
                id: buttonSportler
                height: 70
                x: xPos
                y: parent.height * 0.25
                width: textfieldWidth
                text: qsTr("Sportler")
                property bool isClicked: false

                enabled: UserModel.email_t === UserModel.PRIVATE

                onClicked: isClicked = buttonClicked(buttonSportler, 2, isClicked)
            }

            Button {
                font.pointSize: fontPointSize
                id: buttonTourist
                height: 70
                x: xPos
                y: parent.height * 0.4
                width: textfieldWidth
                text: qsTr("Tourist")
                property bool isClicked: false

                enabled: UserModel.email_t === UserModel.PRIVATE

                onClicked: isClicked = buttonClicked(buttonTourist, 3, isClicked)
            }

            Button {
                font.pointSize: fontPointSize
                id: buttonCompany
                height: 70
                x: xPos
                y: parent.height * 0.55
                width: textfieldWidth
                text: qsTr("Company")
                enabled: UserModel.email_t === UserModel.COMPANY
                checked: UserModel.email_t === UserModel.COMPANY
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
                x: xPos
                y: parent.height * 0.7
                width: textfieldWidth
                text: qsTr("Register")
                enabled: {
                    textFieldPasswordReEntered.isValid &&
                    textfieldEmail.isValid
                }
                onClicked: {


                    UserModel.registerAttempt(
                            {
                                "email": UserModel.email_t.text,
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
