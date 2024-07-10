import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QtPositioning


Rectangle {
    id: rectangle
    anchors.fill: parent



        Rectangle {
            anchors.fill: parent
            z: 1

            Rectangle {
                id: tabbarRoot
                anchors {
                    top: parent.top
                    right: parent.right
                    left: parent.left
                }
                width: parent.width
                height: tabbarHeader.height

                TabBar {
                    id: tabbarHeader

                    z: 1
                    anchors.fill: parent
                    currentIndex: pageIndex
                    onCurrentIndexChanged: pageIndex = currentIndex

                    TabButton {
                        text: qsTr("My Routes")

                    }

                    TabButton {
                        text: qsTr("Public Routes")
                    }
                }
            }




        Rectangle {
            id: swipeViewRoot
            color: "black"
            y: tabbarRoot.y + tabbarRoot.height
            height: parent.height - tabbarRoot.height * 2
            width: parent.width

            SwipeView {
                anchors.fill: parent
                currentIndex: pageIndex


                Page {

                }

                Page {

                }

                Page {

                }
            }
        }

    }
}
