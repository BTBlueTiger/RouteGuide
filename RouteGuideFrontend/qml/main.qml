import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ScreenInfo
import NavigationManager
import UserModel

Window {

    NavigationManager {
        id: navigationManager
        onGoToPage: page => {
            if (typeof page === "string") {
                switch(page) {
                    case "register_page":
                        rootLayout.push(registerPage);
                        pageState = page;
                        iconSource = "/btn/arrow_back.svg";
                        toolBarVisible = true;
                        break;
                    case "login_page":
                        rootLayout.push(loginPage);
                        pageState = page;
                        toolBarVisible = false;
                        break;
                    case "register_little_screen1":
                        rootLayout.push(registerPage1);
                        pageState = page;
                        toolBarVisible = true;
                        break;
                    case "profile":
                        rootLayout.push(profile);
                        pageState = page;
                        toolBarVisible = false;
                        tabBarVisible = true;
                        break;
                    case "map":
                        rootLayout.push(map);
                        pageState = page;
                        break;
                    default:
                        console.error("Invalid page:", page);
                }
            } else {
                console.error("Invalid parameter type:", typeof page);
            }
        }
    }

    UserModel {
        id: userModel;
    }

    id: root
    property var screenInfo: ScreenInfo {}

    property string pageState: "login_page";

    property bool toolBarVisible: false;
    property bool tabBarVisible: false
    property string iconSource: "/btn/arrow_back.svg";
    property bool bigScreen : width > 700 ? true : false

    visible: true
    width: Qt.platform.os === "android" ? screenInfo.screenResolution().width : 1280
    height:  Qt.platform.os === "android" ? screenInfo.screenResolution().height : 720
    title: "Route Guide Login"
    color: "#e6e6e6"

    StackView {
        id: rootLayout
        anchors.top: toolbar.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        initialItem: loginPage
    }

    Component {
        id: loginPage
        Page {
            title: "RouteGuide Login"
            Loader {
                id: loginLoader
                source: "./authentification/login.qml"
                anchors.fill: parent
                onLoaded: {
                    if (item) {
                        item.navigationManager = navigationManager;
                    }
                }
            }
        }
    }

    Component {
        id: registerPage
        Page {
            title: "RouteGuide Register"
            Loader {
                id: registerLoader
                source: {
                    if(bigScreen){
                        return "./authentification/register_big_screen.qml"
                    } else {
                        return "./authentification/register_little_screen0.qml"
                    }
                }
                anchors.fill: parent
                onLoaded: {
                    if (item) {
                        item.navigationManager = navigationManager;
                        item.userModel = userModel;
                    }
                }
            }
        }
    }

    Component {
        id: registerPage1
        Page {
            title: "RouteGuide Register"
            Loader {
                id: registerLoader
                source: {
                    if(bigScreen){
                            return "./authentification/register_big_screen.qml"
                        } else {
                            return "./authentification/register_little_screen1.qml"
                        }
                    }
                anchors.fill: parent
                onLoaded: {
                    if (item) {
                        item.navigationManager = navigationManager;
                        item.userModel = userModel;
                    }
                }
            }
        }
    }

    Component {
        id: profile
        Page {
            title: "RouteGuide"
            Loader {
                id: loginLoader
                source: "./route_guide/profile.qml"
                anchors.fill: parent
                onLoaded: {
                    if (item) {
                        item.navigationManager = navigationManager;
                    }
                }
            }
        }
    }

    Component {
        id: map
        Page {
            title: "RouteGuide Map"
            Loader {
                id: mapLoader
                source: "./route_guide/map.qml"
                anchors.fill: parent
            }
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
            visible: toolBarVisible
            icon.source: iconSource
            icon.color: "#ffffff"
            onClicked: {
                switch(pageState){
                    case "register_page":
                        navigationManager.changePage("login_page");
                        break;
                    case "register_little_screen1":
                        navigationManager.changePage("register_page");
                        break;
                    default:
                        break;
                }
            }
        }
    }
    TabBar {
        id: bottomNavBar
        width: parent.width // Adjust the width as needed
        height: 56 // Height of the bottom navigation bar
        anchors.bottom: parent.bottom // Align the bottom of the bar to the bottom of the parent
        visible: tabBarVisible
        Material.background: "#391ee9"
        TabButton {
            text: bigScreen ? "Map" : ""
            icon.source: "/btn/map.svg"
            onClicked: {
                navigationManager.changePage("map");
            }
        }

        TabButton {
            text: bigScreen ? "Plan a Route" : ""
            icon.source: "/btn/plan_a_route.svg"
            onClicked: {

            }
        }

        TabButton {
            text: bigScreen ? "Community" : ""
            icon.source: "/btn/community.svg"
            onClicked: {

            }
        }

        TabButton {
            text: bigScreen ? "Profile" : ""
            icon.source: "/btn/profile.svg"
            onClicked: {

            }
        }

    }

}
