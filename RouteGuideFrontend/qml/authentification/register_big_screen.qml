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
                id: textField0
                x: leftSideX
                y: rowLayout.height * 0.1
                width: textfieldWidth
                placeholderText: qsTr("First Name")
            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textField1
                x: leftSideX
                y: rowLayout.height * 0.25
                width: textfieldWidth
                placeholderText: qsTr("Last Name")
            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textField2
                x: leftSideX
                y: rowLayout.height * 0.4
                width: textfieldWidth
                placeholderText: qsTr("Email")
            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textField3
                x: leftSideX
                y: rowLayout.height * 0.55
                width: textfieldWidth
                placeholderText: qsTr("Passord")
                echoMode: TextInput.Password
            }
            TextField {
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: fontPointSize
                id: textField4
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
                property bool isClicked: false
                onClicked: {
                   isClicked = buttonClicked(button4, 3, isClicked)
                }
            }

            Button {
                font.pointSize: fontPointSize
                id: button5
                height: 70
                x: rightSideX
                y: rowLayout.height * 0.7
                width: textfieldWidth
                text: qsTr("Register")
            }
        }

    }
}
