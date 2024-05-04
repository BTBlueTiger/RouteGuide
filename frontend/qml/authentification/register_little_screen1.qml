import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import UserModel
import NavigationManager

Item {
    id: registerRoot

    property NavigationManager navigationManager
    property UserModel userModel
    property int textfieldWidth:  width * 0.8;
    property int textfieldHeight: 60
    property int fontPointSize: 20
    property int xPos: (width / 2) - textfieldWidth / 2

    property int emailType : userModel.onEmailTypeRequestet()

    width : registerLoader.windowWidth;
    height : registerLoader.windowHeight;


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

            Button {
                font.pointSize: fontPointSize
                id: button1
                height: textfieldHeight
                x: xPos
                y: columnLayout.height * 0.1
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
                height: textfieldHeight
                x: xPos
                y: columnLayout.height * 0.25
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
                height: textfieldHeight
                x: xPos
                y: columnLayout.height * 0.4
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
                height: textfieldHeight
                x: xPos
                y: columnLayout.height * 0.55
                width: textfieldWidth
                text: qsTr("Company")
                property bool isClicked: false
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
                height: textfieldHeight
                x: xPos
                y: columnLayout.height * 0.7
                width: textfieldWidth
                text: qsTr("Register")
            }
        }
    }
}
