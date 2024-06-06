import QtQuick
import QtQuick.Controls


Rectangle {
    property bool mapVisible: true
    color: "black"
    height: 120
    id: searchRectRoot
    anchors.top : parent.top
    anchors.right: parent.right
    anchors.left: parent.left

    Button {
        id: btnToggleMap
        icon.source: mapVisible ? "/res/btn/button_checked.svg" : "/res/btn/button_unchecked.svg"
        y: searchRectRoot.height / 2 - searchRectRoot.height / 4

        onClicked: mapVisible = !mapVisible

        MouseArea{
            onHoveredChanged: {
                btnToggleMapToolTip.visible = !btnToggleMapToolTip.visible
            }
        }
        ToolTip{
            id: btnToggleMapToolTip
            text: "Toggle Map"
            visible: btnToggleMap.hovered
            y: btnNavigate.y - btnNavigate.height
        }
        anchors {
            topMargin: 25
            bottomMargin: 25
            left: parent.left
            leftMargin: parent.width * .05
            rightMargin: parent.width * .05
        }
    }
        TextField {
            id: textFieldSearch
            placeholderText: qsTr("Search")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            onTextChanged: waypointManager.searchWithLocationResource(text, searchWaypointModelName)

            y: searchRectRoot.height / 2 - searchRectRoot.height / 4
            anchors {
                left: btnToggleMap.right
                leftMargin: parent.width * .05
                right: btnNavigate.left
                rightMargin: parent.width * .05
            }
        }
    Button {
        id: btnNavigate
        icon.source: "/res/btn/navigation_45.svg"
        y: searchRectRoot.height / 2 - searchRectRoot.height / 4
        onClicked: {
            var stops = planARoute.fromCurrentPostion ? 1 : 0
            stops += potentialWaypointModel.rowCount()
            if(stops >= 2) {
                planARoute.setWayPoints()
                toNavigation()
            }
        }

        MouseArea{
            onHoveredChanged: {
                btnNavigateToolTip.visible = !btnNavigateToolTip.visible
            }
        }
        ToolTip{
            id: btnNavigateToolTip
            text: "Navigate"
            visible: btnNavigate.hovered
            y: btnNavigate.y - btnNavigate.height
        }
        anchors {
            topMargin: 25
            bottomMargin: 25
            right: btnFromCurrentPosition.left
            leftMargin: parent.width * .05
            rightMargin: parent.width * .01
        }
    }

    Button {
        id: btnFromCurrentPosition
        icon.source: planARoute.fromCurrentPostion ? "/res/btn/layers.svg" : "/res/btn/layers_clear.svg"
        y: searchRectRoot.height / 2 - searchRectRoot.height / 4
        onClicked: {
            planARoute.fromCurrentPostion = !planARoute.fromCurrentPostion
        }
        MouseArea{
            onHoveredChanged: {
                btnNavigateToolTip.visible = !btnNavigateToolTip.visible
            }
        }
        ToolTip{
            id: btnFromCurrentPositionToolTip
            text: planARoute.fromCurrentPostion ? "Plan not from your Postion" : "Plan from your Position"
            visible: btnFromCurrentPosition.hovered
            y: btnFromCurrentPosition.y - btnFromCurrentPosition.height
        }
        anchors {
            topMargin: 25
            bottomMargin: 25
            right: parent.right
            leftMargin: parent.width * .01
            rightMargin: parent.width * .05
        }
    }
}
