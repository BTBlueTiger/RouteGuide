import QtQuick
import QtQuick.Controls

import ScreenInfo

ApplicationWindow {

    visible : true

    // Some Basic informations
    RootInfromation {
        id: rootInformation
    }

    width: rootInformation.isMobile ? screenInfo.screenResolution().width : 1280
    height:  rootInformation.isMobile ? screenInfo.screenResolution().height : 720

    title: rootInformation.title

    RouteGuideFlow{
        width: parent.width
        height: parent.height
    }
}
