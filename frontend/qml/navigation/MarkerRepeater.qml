import QtQuick 2.15
import QtQuick.Controls
import QtLocation
import QtPositioning

Repeater {
    property alias model: model
    delegate: MapQuickItem{
        property alias markers: markers
        id: markers
        coordinate: model.modelData
        anchorPoint.x: icon.width / 2
        anchorPoint.y: icon.height
        sourceItem: Image {
            id: icon
            source: "/res/btn/map.svg"  // Path to your marker icon
            width: 40
            height: 40
        }
    }
}
