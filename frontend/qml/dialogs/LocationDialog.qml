// CustomDialog.qml
import QtQuick
import QtQuick.Controls


import "../custom_controls"

import QLocationSearch


Dialog {
    id: customDialog
    width: 600
    height: 400
    x: parent.width / 2 - customDialog.width / 2
    y: parent.height / 2 - customDialog.height / 2
    title: "Add a stop"

    property string location: ""

    signal locationIsFound(location: string, latitude: double, longitude: double)

    ValidationTextfield{
        id: textfieldTown
        x: parent.width / 2 - textfieldTown.width / 2
        width: customDialog.width - 60
        horizontalAlignment: Text.AlignHCenter

        placeholderDefault: "Enter a Town"
        onIsErrorChanged: {
            ToolTip: ("Not found in the Database", 3000)
        }
    }

    ValidationTextfield{
        id: textfieldStreet
        x: parent.width / 2 - textfieldTown.width / 2
        y: textfieldTown.height + 10
        width: customDialog.width - 60
        horizontalAlignment: Text.AlignHCenter

        placeholderDefault: "Enter a Street"
        onIsErrorChanged: {
            ToolTip: ("Not found in the Database", 3000)
        }
    }

    Button{
        id: searchButton
        text: "Search"

        y: parent.height - searchButton.height
        x: parent.width / 2 - searchButton.width / 2


        onClicked: {
            location = textfieldTown.text + " " +  textfieldStreet.text
            qLocationSearchPlugin.searchLocation(textfieldTown.text + " " +  textfieldStreet.text)
        }
    }



    QLocationSearch {
        id: qLocationSearchPlugin
        onLocationFound: function locationFount (latitude, longitude) {
            locationIsFound(textfieldTown.text + " " + textfieldStreet.text, latitude, longitude)
            close()
        }
    }
}
