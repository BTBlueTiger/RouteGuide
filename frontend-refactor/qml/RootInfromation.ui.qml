import QtQuick
import QtQuick.Controls

Item {
    property string title: qsTr("RouteGuide")
    property bool isMobile: Qt.platform.os === "android" || Qt.platform === "ios"

}
