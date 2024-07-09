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



    Component.onCompleted: {
        GeoPositionRessource.setMockResource()
    }


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

    function addMapQuickItem(waypoint, i) {
        var component = Qt.createComponent("MapQuickItem");
        if (component.status === Component.Ready) {
            var mapItem = component.createObject(map, {
                coordinate: QtPositioning.coordinate(waypoint.latitude, waypoint.longitude)
            });
            if (mapItem === null) {
                console.log("Error creating MapQuickItem");
            }
        } else {
            console.log("Error loading MapQuickItem component");
        }

        /*
        var mapQuickItemStr = `
                import QtQuick
                import QtLocation
                import QtPositioning

                MapQuickItem {
                    coordinate: QtPositioning.coordinate(${waypoint})
                    anchorPoint.x: icon.width / 2
                    anchorPoint.y: icon.height
                    sourceItem: Image {
                        id: icon
                        source: "qrc:/res/btn/map.svg"  // Path to your marker icon
                        width: 40
                        height: 40
                    }
                }
            `;

            var component = Qt.createQmlObject(mapQuickItemStr, map, "dynamicMapQuickItem %i");
            if (component === null) {
                console.log("Error creating MapQuickItem");
            }
            */
    }

    onMapWayPointsChanged: {
        for(var i = 0; i < mapWayPoints.length; i++) {
            addMapQuickItem(mapWayPoints[i], i);
            /*
                var component = Qt.createQmlObject
                    (`
                    import QtQuick 2.15
                    import QtLocation
                    import QtPositioning
                    MapQuickItem {
                     anchorPoint.x: marker.width / 4
                     anchorPoint.y: marker.height
                         sourceItem: Image{
                             id: icon
                             source: ":/res/btn/map.svg"
                             sourceSize.width: 40
                             sourceSize.height: 40
                         }
                     }`

                        )
            console.log("Hey")
            if (component.status === Component.Ready) {
                compontent.anchorPoint.x = mapWayPoints[i].latitude
                compontent.anchorPoint.x = mapWayPoints[i].longitude
                map.addMapItem(component)
                if (mapItem === null) {
                    console.log("Error creating MapQuickItem");
                }
            } else {
                console.log("Error loading MapQuickItem component");
            }
        }
        */
        }
    }

    RouteGuideMap{
        id: map
    }
}
