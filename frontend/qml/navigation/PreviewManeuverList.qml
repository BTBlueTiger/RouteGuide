import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../js/Formatter.js" as Formatter

ListView {
    id: previewManeuverList
    property string totalTravelTime
    property string totalDistance
    property var routeInfoModel
    model: defaultRouteListModel
    interactive: true

    header: RowLayout {
            spacing: 10
            width: parent.width
            anchors.margins: 20
            height: 56

            Label {
                anchors.leftMargin: 20
                id: timeLabel
                font.pointSize: 16
                color: "white"
                text: defaultRouteModel.count > 0 ?
                    Formatter.formatTime(defaultRouteModel.get(0).travelTime)
                        :
                          ""
                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            }

            Button {
                id: btnNavigate
                text: "Navigate"
                x: previewManeuverList.width / 2 - btnNavigate.width / 2
                onClicked: {
                    stackLayout.clear()
                    stackLayout.push(routeguideMap)
                }
            }

            Label {
                anchors.rightMargin: 20
                id: kmLabel
                font.pointSize: 16
                color: "white"
                text: defaultRouteModel.count > 0 ?
                    Formatter.formatDistance(defaultRouteModel.get(0).distance) : ""
                Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            }
        }


    delegate: Rectangle {
                width: parent ? parent.width : undefined
                height: indexLabel.height * 3
                color: Material.primary
                border.color: "white"
                border.width: 1
                radius: 5
                anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined
                anchors.margins: 10

                RowLayout {
                    spacing: 10
                    anchors.fill: parent
                    anchors.margins: 10

                    Label {
                        id: indexLabel
                        font.pointSize: 16
                        color: "white"
                        text: index + 1 + "."
                        Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                    }

                    Label {
                        font.pointSize: 16
                        color: "white"
                        text: instruction
                        wrapMode: Text.WordWrap
                        Layout.alignment: Qt.AlignVCenter
                        Layout.fillWidth: true
                    }

                    Label {
                        font.pointSize: 16
                        color: "white"
                        text: distance
                        Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                    }
                }
            }


}
