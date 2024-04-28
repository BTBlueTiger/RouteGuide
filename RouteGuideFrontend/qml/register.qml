import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import NavigationManager

Item {

    id: registerRoot

    property NavigationManager navigationManager : registerLoader.navigationManager

    width : registerLoader.windowWidth
    height : registerLoader.windowHeight

    property int textfieldWidth:  width * 0.7;


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
                height: 60
                color: Qt.platform.os === "android" ? "#ffffff" : "#000000"
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.175
                x: (registerRoot.width / 2) - width / 2
                placeholderTextColor:  Qt.platform.os === "android" ? "#ffffff" : "#000000"
                selectionColor: "#391ee9"
                font.pointSize: 20
                placeholderText: qsTr("Email")
            }
            TextField {
                id: textField1
                width: textfieldWidth
                height: 60
                color: Qt.platform.os === "android" ? "#ffffff" : "#000000"
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.3
                x: (registerRoot.width / 2) - width / 2
                placeholderTextColor:  Qt.platform.os === "android" ? "#ffffff" : "#000000"
                selectionColor: "#391ee9"
                font.pointSize: 20
                placeholderText: qsTr("Email")
            }
            TextField {
                id: textField2
                width: textfieldWidth
                height: 60
                color: Qt.platform.os === "android" ? "#ffffff" : "#000000"
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.425
                x: (registerRoot.width / 2) - width / 2
                placeholderTextColor:  Qt.platform.os === "android" ? "#ffffff" : "#000000"
                selectionColor: "#391ee9"
                font.pointSize: 20
                placeholderText: qsTr("Email")
            }
            TextField {
                id: textField3
                width: textfieldWidth
                height: 60
                color: Qt.platform.os === "android" ? "#ffffff" : "#000000"
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.55
                x: (registerRoot.width / 2) - width / 2
                placeholderTextColor:  Qt.platform.os === "android" ? "#ffffff" : "#000000"
                selectionColor: "#391ee9"
                font.pointSize: 20
                placeholderText: qsTr("Email")
            }
            TextField {
                id: textField4
                width: textfieldWidth
                height: 60
                color: Qt.platform.os === "android" ? "#ffffff" : "#000000"
                anchors.verticalCenter: root.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                y: registerRoot.height * 0.675
                x: (registerRoot.width / 2) - width / 2
                placeholderTextColor:  Qt.platform.os === "android" ? "#ffffff" : "#000000"
                selectionColor: "#391ee9"
                font.pointSize: 20
                placeholderText: qsTr("Email")
            }
        }
    }
}
