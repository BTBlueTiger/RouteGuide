import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import WaypointModel


Rectangle {

    id: planaRouteSearchPage

    property bool mapVisible: true
    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightslategray" }
        GradientStop { position: 1.0; color: "lightblue" }
    }
    anchors.fill: parent

    WaypointFlickable{
        width: parent.width
        height: parent.height
        model: searchWaypointModel
        onClickedMessage: "Item was added"
        onItemClicked: function itemClicked(item, _) {
            waypointManager.addItemToWaypointModel(potentialWaypointModelName, item);
        }
    }

    Rectangle {
        color: "black"
        height: 120
        id: searchRectRoot
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left


            TextField {
                id: textFieldSearch
                placeholderText: qsTr("Search")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                onTextChanged: waypointManager.searchWithNominatimRessource(text, searchWaypointModelName)

                y: searchRectRoot.height / 2 - searchRectRoot.height / 4
                anchors {
                    left: parent.left
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
