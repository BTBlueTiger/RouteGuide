import QtQuick
import NavigationManager
import UserModel
import QtQuick.Layouts
import QtQuick.Controls

Item {

    id: registerRoot

    property NavigationManager navigationManager
    property UserModel userModel
    property int textfieldWidth:  (width * 0.8) / 2;

    property int leftSideX: (rowLayout.width / 4) - (rowLayout.width / 6)
    property int rightSideX: (rowLayout.width / 4) + (rowLayout.width / 3.5)

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
        width: parent.width
        height: parent.height

        Image {
            id: backgroundImage
            source: "/img/background.png"
            x: 0
            y: 0
            fillMode: Image.PreserveAspectCrop

            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldFirstName
                x: leftSideX
                y: rowLayout.height * 0.1
                width: textfieldWidth
                placeholderText: qsTr("First Name")

                onEditingFinished: {

                }

            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldLastName
                x: leftSideX
                y: rowLayout.height * 0.25
                width: textfieldWidth
                placeholderText: qsTr("Last Name")
            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldEmail
                x: leftSideX
                y: rowLayout.height * 0.4
                width: textfieldWidth
                placeholderText: qsTr("Email")
                onEditingFinished: {
                    emailType = userModel.onEmailAdressEntered(textFieldEmail.text)
                    if(emailType == 2)
                    {
                        button4.clicked()
                    }
                }
                background: Rectangle{
                    implicitHeight: textFieldEmail.height
                    implicitWidth: textFieldEmail.width
                    color: "transparent"
                    opacity: 1
                    border.color: "red"
                    radius: 4
                }

                Label {
                    id: textFieldEmailError
                    font.pointSize: 16
                    text: "Not a valid email"
                    color: "red"
                    x: (textFieldEmail.x - textfieldWidth / 5)
                    y: textFieldEmail.height
                    background: Rectangle{
                        color: "white"
                        radius: 4
                        opacity: 0.35
                    }
                }


            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldPassword
                x: leftSideX
                y: rowLayout.height * 0.55
                width: textfieldWidth
                placeholderText: qsTr("Passord")
                echoMode: TextInput.Password
            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textFieldPasswordReEntered
                x: leftSideX
                y: rowLayout.height * 0.7
                width: textfieldWidth
                placeholderText: qsTr("Re enter password")
                echoMode: TextInput.Password
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

                enabled: false
            }
        }

    }
}
