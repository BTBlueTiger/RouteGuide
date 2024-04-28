import QtQuick
import NavigationManager
import QtQuick.Layouts
import QtQuick.Controls

Item {

    id: registerFormRoot

    property NavigationManager navigationManager
    property bool bigWindow : width > 700 ? true : false

    Rectangle {

    Image {

        source: "/img/background.png"
        x: 0
        y: 0
        fillMode: Image.PreserveAspectCrop

            Rectangle {
                width: parent.width
                height: parent.height
                Loader {
                    id: registerForm0
                    source: "./register_form_left.qml"
        //            anchors.fill: parent
                }

            }
            /*
            Rectangle {
                x: parent.width / 2
                width: parent.width
                height: parent.height
                visible: parent.bigWindow
                Loader {
                    id: registerForm1
                    source: "./register_form_left.qml"
                    anchors.fill: parent
                }
            }
            */
        }
    }
}
