import QtQuick
import QtQuick.Controls

import ScreenInfo
//! [Set application window size]
ApplicationWindow {



    property string userType: ""

    property int userTypeCompany: 2
    property int userTypePrivate: 1

    property var screenInfo: ScreenInfo {}

    visible: true
    width: Qt.platform.os === "android" ? screenInfo.screenResolution().width : 1280
    height:  Qt.platform.os === "android" ? screenInfo.screenResolution().height : 720

    title: qsTr("RouteGuide")
    ApplicationFlow {
        width: parent.width
        height: parent.height
    }
}
