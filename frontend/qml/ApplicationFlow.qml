import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "authentification"
import "authentification/register"
import "custom_controls"
import "routeguide"


Item {
    id: applicationFlow
    state: "Login"
    property string platform: Qt.platform.os
    property string previousState: ""
    property bool toolbarBackVisible: false
    property bool bigscreen: width > 700 ? true : false
    width: parent.width
    height: parent.height

    StackView {
        id: stackLayout
        anchors.top: toolbar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        states: [
            State {
                name: "Login"
            },
            State {
                name: "Register"
            }
        ]

        initialItem: Login {
            id: login
        }

        Component {
            id: register
            Page {
                title: "RouteGuide Register"
                Loader {
                    property string registerState: ""
                    id: registerLoader
                    anchors.fill: parent
                    source: {
                        if(bigscreen){
                            return "./authentification/register/RegisterFormBig.qml"
                        } else if(registerState.length == 0) {
                            return "./authentification/register/RegisterFormSmall0.qml"
                        } else {
                            return "./authentification/register/RegisterFormSmall1.qml"
                        }
                    }
                }
            }
        }
    }

    Component {
        id: routeGuide
        RouteGuide{

        }
    }
    Component {
        id: planARoute
        PlanARoute{

        }
    }

    ToolBar{
        id: toolbar
        position: ToolBar.Footer
        anchors.right: parent.right
        anchors.left: parent.left
        contentHeight: toolButton.implicitHeight
        Material.background: "#391ee9"
        ToolButton {
            id: toolButton
            Material.background : "#ffffff"
            visible: toolbarBackVisible
            icon.source: "/res/btn/arrow_back"
            icon.color: "#ffffff"
            onClicked: {
                stackLayout.pop()
            }
        }
    }
}
