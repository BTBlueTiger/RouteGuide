import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import QtLocation
import QtPositioning


import GeoPositionRessource

import "../map"
import "../../"


Rectangle {

    property var mapWayPoints: []



    MapQuickItem {
        id: mapItem
        property variant coordinate
        anchorPoint.x: icon.width / 2
        anchorPoint.y: icon.height
        sourceItem: Image {
            id: icon
            source: "qrc:/res/btn/map.svg"  // Path to your marker icon
            width: 40
            height: 40
        }
    }



    Connections{
        target: GeoPositionRessource
        function onCoordinateChanged() {
            console.log("Hey")
        }
    }


    RouteGuideMap{
        id: map
    }
}
