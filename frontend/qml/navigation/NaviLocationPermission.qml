import QtQuick 2.15
import QtCore
import QtQuick.Controls

Dialog {
    id: permissionDialog
    x: rootWindow.width / 2 - permissionDialog.width / 2
    y: rootWindow.height/ 2 - permissionDialog.height / 2

    title: "We need your location \n for Navigation"
    standardButtons: Dialog.Ok | Dialog.Cancel

    Text {
        id: name
        text: qsTr("To provide you the feature \n
                    of Navigation we need your\n
                    permission to use your gps")
    }

    onAccepted: console.log("Ok clicked")
    onRejected: console.log("Cancel clicked")
}
