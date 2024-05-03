import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import NavigationManager
import ScreenInfo

Item {

    id: loginRoot

    property NavigationManager navigationManager : loginLoader.navigationManager

    width : loginLoader.windowWidth
    height : loginLoader.windowHeight

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        Image {
            id: backgroundImage
            x: 0
            y: 0
            source: "/img/background.png"
            fillMode: Image.PreserveAspectCrop


            TextField {
                id: textField
                width: 300
                height: 60
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: loginRoot.height / 2
                x: (loginRoot.width / 2) - width / 2
                font.pointSize: 20
                placeholderText: qsTr("Email")
            }

            Rectangle {
                y: textField.y - 300
                x: textField.x + ((textField.width - width)/2)
                width: 250
                height: 250
                color: "white"
                radius: 180
            }

            TextField {
                id: textField2
                x: textField.x
                y: textField.y + 100
                width: 300
                height: 60
                horizontalAlignment: Text.AlignHCenter
                echoMode: TextInput.Password
                selectionColor: "#391ee9"
                placeholderText: qsTr("Password")
                font.pointSize: 20
            }

            Button {
                id: button
                x: textField2.x
                y: textField2.y + 100
                width: 300
                height: 60
                text: qsTr("Sign In")
                clip: false
                font.pointSize: 24
                checkable: false
                Material.background: "#391ee9"
                onClicked: navigationManager.changePage("map");

            }

            Text {
                id: text1
                x: button.x
                y: button.y + 80
                text: qsTr("Forgot Password")
                font.pixelSize: 20
            }

            Text {
                id: text2
                x: button.x + button.width - width
                y: button.y + 80

                color: "blue"
                text: qsTr("Sign Up")
                font.pixelSize: 20
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor

                    onEntered: text2.color = "lightBlue"
                    onExited: text2.color = "blue"
                    onClicked: navigationManager.changePage("register_page")
                }
            }
        }
    }
}
