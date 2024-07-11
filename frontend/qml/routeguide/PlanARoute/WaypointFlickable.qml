import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

import WaypointModel

import "../../map"

Flickable {

    id: waypointFlickable

    height: parent.height
    width: parent.width

    property WaypointModel model
    property string buttonSource
    property string buttonColor
    property string onClickedMessage


    signal itemClicked(var item, int index)

    flickableDirection: Flickable.VerticalFlick
    contentWidth: waypointFlickable.width
    contentHeight: mapVisible ?
                       (waypointFlickable.height * .4) * cardRepeater.count + tabbarHeight * 2
                              :
                       displayNameLabel === defined ? displayNameLabel.height * 1.2 : 0


    Flow {
        id: waypointFlow
        width: waypointFlickable.width
        height: waypointFlickable.height
        spacing: 10
        z: 0

        Repeater {
            id: cardRepeater
            model: waypointFlickable.model

            delegate: Rectangle {
                id: card
                width: waypointFlickable.width
                height: mapVisible ? waypointFlickable.height * .4 : displayNameLabel.height * 1.2

                MouseArea{
                    anchors.fill: parent
                    onDoubleClicked: {
                        onItemClickedToolTip.visible = true
                        itemClicked(waypointFlickable.model.getModelItem(index), index)
                    }

                    onPressAndHold: {
                        drag.target = card
                    }
                }

                ToolTip {
                    id: onItemClickedToolTip
                    text: onClickedMessage
                    visible: false
                    x: parent.width / 2 - onItemClickedToolTip.width / 2
                    y: parent.height / 2 - onItemClickedToolTip.height / 2
                    onVisibleChanged: {
                        onItemClickedToolTipTimer.start()
                    }
                    Timer {
                        id: onItemClickedToolTipTimer
                        interval: 1000
                        onTriggered: onItemClickedToolTip.visible = false

                    }
                }

                Rectangle {
                    id: textRect
                    width: mapVisible ? card.width * .45 : card.width * .95
                    height: card.height

                    Rectangle{
                        radius: 20
                        opacity: .5
                        width: displayNameLabel.width
                        height: displayNameLabel.height
                        anchors.centerIn: parent

                        Label {
                            anchors.centerIn: parent
                            id: displayNameLabel

                            text:  littlePreviewMap.visible ? model.displayName.split(",").join("\n") : index + 1 + ". " +model.displayName

                            width: textRect.width
                            color: "black"
                            wrapMode: Text.Wrap
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            enabled: false
                            font.bold: true
                        }
                    }
                }

                Rectangle {
                    visible: mapVisible
                    id: mapRect
                    x: card.width * .45
                    width: waypointFlickable.width * .6
                    height: parent.height
                    radius: 20
                    DefaultMap {
                        id: littlePreviewMap
                        center: model.coordinate
                        MapQuickItem{
                            sourceItem: Image {
                                source: "/res/btn/place.svg"
                            }
                            coordinate: model.coordinate
                            anchorPoint.x: sourceItem.width / 2
                            anchorPoint.y: sourceItem.height
                        }
                    }
                }

                RoundButton {
                    id: btnRound
                    width: 50
                    height: 50
                    Material.background: "white"

                    icon {
                        source: buttonSource
                        color: buttonColor
                        width: 50
                        height: 50

                    }
                    y: card.height - btnRound.height
                    x: card.width - btnRound.width
                    onClicked: {
                        onItemClickedToolTip.visible = true
                        itemClicked(waypointFlickable.model.getModelItem(index), index)
                    }
                }
            }
        }
    }
}
