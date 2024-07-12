import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtLocation

import "auth"

Item
{
    property alias stacklayout: stackLayout
    property alias pageLogin : login
    // Like our root component
    // every "Item" will be "stacked" on it

    StackView {
        id: stackLayout
        anchors.fill: parent
    }

    Component{ id: login
        Login {}
    }

}
