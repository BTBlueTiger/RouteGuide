import QtQuick
import QtQuick.Controls

import QtLocation
import QtPositioning

Rectangle {


    id:planARouteAddedPage

    property bool mapVisible: true

    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightblue" }
        GradientStop { position: 1.0; color: "lightslategray" }
    }
    anchors.fill: parent

    signal itemClicked(var item)

    WaypointFlickable{
        width: parent.width
        height: parent.height
        model: potentialWaypointModel
        onClickedMessage: "Item is Removed"
        onItemClicked: function itemClicked(_, index) {
            waypointManager.removeItemFromWaypointModel(potentialWaypointModelName, index);
        }
    }


    Rectangle {
        color: "black"
        height: 120
        id: searchRectRoot
        anchors.bottom: parent.bottom
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
                right: parent.right
                leftMargin: parent.width * .05
                rightMargin: parent.width * .05
            }
        }
    }
}
