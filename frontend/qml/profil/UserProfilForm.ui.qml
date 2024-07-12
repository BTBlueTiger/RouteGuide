import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects

import ValidationTextfield

import UserModel

Item {

    id: userProfilForm

    property alias userName : userName
    property alias group : group
    property alias changeGroupMenu : changeGroupMenu
    property alias routes: routes


    ColumnLayout{
        x: 0
        y: 0
        anchors.fill: parent
        // Background Image
        Image {
            source: "/res/img/background.png"
            fillMode: Image.PreserveAspectCrop

            // Place Holder for Profil Picture, not a prototyp target
            Rectangle {
                y: userName.y - 150
                x: userName.x + ((userName.width - width) / 2)
                width: 100
                height: 100
                color: "transparent"
                radius: 125 // Making it fully circular
                clip: true // Clip the content to the bounds of the Rectangle

                // PLatzhalter Logo
                Image {
                        x:0
                        id: sourceItem
                        source: "/res/img/logo.jpeg"
                        anchors.centerIn: parent
                        width: 250
                        height: 250
                        visible: false
                    }

                    MultiEffect {
                        x:0
                        source: sourceItem
                        anchors.fill: sourceItem
                        maskEnabled: true
                        maskSource: mask
                    }

                    Item {
                        id: mask
                        width: sourceItem.width
                        height: sourceItem.height
                        layer.enabled: true
                        visible: false

                        Rectangle {

                            width: sourceItem.width
                            height: sourceItem.height
                            radius: width/2
                            color: "black"
                        }
                    }
            }

            // Username
            Button{
                enabled: false
                id: userName
                font.pointSize: 20
                width: 300
                height: 60
                x: (userProfilForm.width / 2) - width / 2
                y: userProfilForm.height / 3.5
            }

            //Password
            Button {
                text: "Change Password"
                id: btnChangePassword
                x: userName.x
                y: userName.y + 70
                width: 300
                height: 60
                font.pointSize: 20
            }
            Button {
                text: "Delete Account"
                id: btnDeleteAccount
                x: btnChangePassword.x
                y: btnChangePassword.y + 70
                width: 300
                height: 60
                font.pointSize: 20
            }

            Button {
                id: group
                x: btnDeleteAccount.x
                y: btnDeleteAccount.y + 70
                width: 300
                height: 60
                font.pointSize: 20
                Menu {
                    id: changeGroupMenu
                    visible: false
                    MenuItem{
                        text: "Hiker"
                    }
                    MenuItem {
                        text: "Sportler"
                    }
                    MenuItem {
                        text: "Tourist"
                    }
                }
            }

            Button {
                id: routes
                text: "Show Routes"
                x: group.x
                y: group.y + 70
                width: 300
                height: 60
                font.pointSize: 20
            }
        }
    }
}
