import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import NavigationManager
import UserModel

Item {

    id: registerRoot

    property NavigationManager navigationManager
    property UserModel userModel
    property int textfieldWidth:  width * 0.8;
    property int textfieldHeight: 60
    property int fontPointSize: 20
    property int xPos: (width / 2) - textfieldWidth / 2

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

            TextField {
                id: textField0
                width: textfieldWidth
                height: textfieldHeight
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.175
                x: xPos
                selectionColor: "#391ee9"
                font.pointSize: fontPointSize
                placeholderText: qsTr("First Name")
            }
            TextField {
                id: textField1
                width: textfieldWidth
                height: PlaceholderText
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.3
                x: xPos
                selectionColor: "#391ee9"
                font.pointSize: fontPointSize
                placeholderText: qsTr("Last Name")
            }
            TextField {
                id: textField2
                width: textfieldWidth
                height: textfieldHeight
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.425
                x: xPos
                selectionColor: "#391ee9"
                font.pointSize: fontPointSize
                placeholderText: qsTr("Email")
            }
            TextField {
                id: textField3
                width: textfieldWidth
                height: textfieldHeight
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.55
                x: xPos
                selectionColor: "#391ee9"
                font.pointSize: fontPointSize
                placeholderText: qsTr("Password")
                echoMode: "PasswordEchoOnEdit"
            }
            TextField {
                id: textField4
                width: textfieldWidth
                height: textfieldHeight
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.675
                x: xPos
                selectionColor: "#391ee9"
                font.pointSize: 20
                placeholderText: qsTr("Reenter Password")
                echoMode: "PasswordEchoOnEdit"
            }
            Button {
                width: textfieldWidth
                height: textfieldHeight
                y: registerRoot.height * 0.8
                x: xPos
                text: qsTr("Next")
                onClicked: {
                    navigationManager.changePage("register_little_screen1");
                }
            }
        }
    }
}
