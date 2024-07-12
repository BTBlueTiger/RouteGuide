import QtQuick
import QtQuick.Controls

import QtLocation
import QtPositioning

Rectangle {


    id:planARouteAddedPage

    property bool mapVisible: true
    anchors.fill: parent

    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightslategray" }
        GradientStop { position: 1.0; color: "black" }
    }

    SearchBox{
        id: searchBox
    }

    WaypointFlickable{
        y: searchBox.height
        width: parent.width
        height: parent.height
        model: potentialWaypointModel
        buttonSource: "/res/btn/clear.svg"
        buttonColor: "red"
        onClickedMessage: "Item is Removed"
        onItemClicked: function itemClicked(_, index) {
            waypointManager.removeItemFromWaypointModel(potentialWaypointModelName, index);
        }
    }

}
