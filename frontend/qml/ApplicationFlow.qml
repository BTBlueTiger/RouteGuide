import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtLocation

import "authentification"
import "authentification/register"
import "routeguide"
import "routeguide/PlanARoute"

import UserModel

Item {
    id: applicationFlow
    state: "Login"

    property string platform: Qt.platform.os
    property string previousState: ""

    property bool toolbarBackVisible: false
    property bool tabbarVisible: UserModel.loggedIn
    property bool bigscreen: width > 700 ? true : false

    property int tabbarHeight: 56

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"

            // OSM plugin will auto-append if .png isn't suffix, and that screws up apikey which silently
            // fails authentication (only Wireshark revealed it)
            value: "http://tile.thunderforest.com/atlas/%z/%x/%y.png?apikey=5e174dbc86e5477b90da4369fabe46f5&fake=.png"
        }
    }

    property alias mapPlugin: mapPlugin


    width: parent.width
    height: parent.height

    StackView {
        id: stackLayout
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        Connections{
            target: UserModel
            function onUserChanged () {
                if(UserModel.user) {
                    console.log(UserModel.user)
                }
            }
        }
        initialItem: Login {
            id: login
            onLoggedIn: {
                stackLayout.push(planARoute)
            }
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
        id: planARoute
        PlanARoute{

        }
    }

    RouteModel {
        id: routeModel
        plugin: mapPlugin
        query: RouteQuery {
            id: routeQuery
        }
        onStatusChanged: {
            if(routeModel.count > 0) {
                totalTime = formatTime(routeModel.get(0).travelTime)
                distance = formatDistance(routeModel.get(0).distance)
            }
        }
    }





    ToolBar{
        id: toolbar
        position: ToolBar.Footer
        anchors.right: parent.right
        anchors.left: parent.left
        contentHeight: toolButton.implicitHeight
        Material.background: "transparent"
        visible: true
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
    TabBar {
            id: bottomNavBar
            width: parent.width // Adjust the width as needed
            height: tabbarHeight // Height of the bottom navigation bar
            anchors.bottom: parent.bottom // Align the bottom of the bar to the bottom of the parent
            visible: tabbarVisible

            TabButton {
                text: bigscreen ? "Plan a Route" : ""
                icon.source: "/res/btn/plan_a_route.svg"
                onClicked: {
                    stackLayout.push(planARoute)
                }
            }

            Component.onCompleted: {
                console.log(UserModel.emailType)
            }

            TabButton {
                text: {
                    if(bigscreen){
                        if(UserModel.email_t === UserModel.COMPANY) {
                            return "Community"
                        } else {
                            return "Company"
                        }
                    }
                }

                icon.source: {
                    if(UserModel.email_t === UserModel.COMPANY) {
                        "/res/btn/community.svg"
                    } else {
                        "/res/btn/bully.svg"
                    }
                }

                onClicked: {

                }
            }


            TabButton {
                text: bigscreen ? "Profile" : ""
                icon.source: "/res/btn/profile.svg"
                onClicked: {

                }
            }

        }
}
