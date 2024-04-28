import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ScreenInfo
import NavigationManager
import UserModel

RowLayout {
    id: bottomNavBar
    width: parent.width // Adjust the width as needed
    height: 56 // Height of the bottom navigation bar
    anchors.bottom: parent.bottom // Align the bottom of the bar to the bottom of the parent
    property NavigationManager navigationManager
    // Define the buttons for navigation items
    Button {
        text: "Home"
        onClicked: console.log("Navigate to Home")
    }

    Button {
        text: "Search"
        onClicked: console.log("Navigate to Search")
    }

    Button {
        text: "Profile"
        onClicked: console.log("Navigate to Profile")
    }

    // Add more buttons as needed
}
