import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtLocation
import QtPositioning

import "authentification"
import "authentification/register"
import "routeguide"
import "routeguide/PlanARoute"
import "navigation"
import "profil"
import "group"
import "map"

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

    width : parent.width
    height: parent.height

    // Will control if a User is logged in or not
    // only logged in user can "use" the app
    Connections{
        target: UserModel
        function onUserChanged() {
            if(UserModel.loggedIn) {
                stackLayout.clear()
                stackLayout.push(routeguideMap)
            } else {
                stackLayout.clear()
                stackLayout.push(login)
            }
        }
    }


    // Our Main View
    StackView {
        id: stackLayout
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        initialItem: Login {
            id: login
        }
    }

    // Register Component
    Component {
        id: register
        Page {
            title: "RouteGuide Register"
            Loader {
                property string registerState: ""
                id: registerLoader
                anchors.fill: parent
                // Big and small screen
                // Issues with image forced to this solution
                // Never doing such thing again !
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

    //global setting center once! at new route start
    property var center: QtPositioning.coordinate(52.2125431, 8.7179206)
    // Is like our Map
    Component { id: routeguideMap

        RouteGuideMap {
            id: defaultMap
            center: applicationFlow.center
        }
    }

    // Plan a Route is like the creating Component
    Component { id: planARoute

        PlanARoute{
            onToNavigation:
            {
                stackLayout.clear()
                bottomNavBar.currentIndex = 0
                stackLayout.push(routeguideMap)
            }
        }
    }

    Component {
        id: userProfil
        UserProfil {

        }
    }

    // Its our Community or Company Routes
    Component {
        id: savedRoutes
        SavedRoutes{
            anchors.fill: parent
        }
    }


    // Only nessacary at the beginning for switching to register and back

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

    // Our Bottom Navigation, here we switch between the main Task of the app
    // We decide if there is text like "Map" at the bottom by the size of the screen
    // Directories to bottom tab choice
    // Map          , Plan A Route  , Community/Company , profil
    // navigation   , routeguide    , Group             , profil
    TabBar {

            id: bottomNavBar
            width: parent.width // Adjust the width as needed
            height: tabbarHeight // Height of the bottom navigation bar
            anchors.bottom: parent.bottom // Align the bottom of the bar to the bottom of the parent
            visible: tabbarVisible

            TabButton {
                text: bigscreen ? "Map" : ""
                icon.source: "/res/btn/map.svg"
                onClicked: {
                    stackLayout.clear()
                    stackLayout.push(navigation)
                }
            }

            TabButton {
                text: bigscreen ? "Plan a Route" : ""
                icon.source: "/res/btn/plan_a_route.svg"
                onClicked: {
                    stackLayout.clear()
                    stackLayout.push(planARoute)
                }
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
                    stackLayout.clear()
                    stackLayout.push(savedRoutes)
                }
            }


            TabButton {
                text: bigscreen ? "Profile" : ""
                icon.source: "/res/btn/profile.svg"
                onClicked: {
                    stackLayout.clear()
                    stackLayout.push(userProfil)
                }
            }

        }
}
