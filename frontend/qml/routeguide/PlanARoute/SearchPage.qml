import QtQuick
import QtQuick.Controls

import QtLocation
import QtPositioning

import WaypointModel


Rectangle {

    id: planaRouteSearchPage

    gradient: Gradient {
        GradientStop { position: 0.0; color: "black" }
        GradientStop { position: 1.0; color: "lightslategray" }
    }
    property bool mapVisible: true
    anchors.fill: parent


    SearchBox{
        id: searchBox
        onMapVisibleChanged: planaRouteSearchPage.mapVisible = searchBox.mapVisible
    }

    WaypointFlickable{
        y: searchBox.height
        width: parent.width
        height: parent.height - searchBox.height
        model: searchWaypointModel
        buttonSource: "/res/btn/add_circle.svg"
        buttonColor: "green"
        onClickedMessage: "Item was added"
        onItemClicked: function itemClicked(item, _) {
            waypointManager.addItemToWaypointModel(potentialWaypointModelName, item);
        }
    }


}
