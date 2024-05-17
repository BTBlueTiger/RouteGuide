import QtQuick
import QtQuick.Controls

import ValidationTextfieldModel

TextField {

    id: validationTextField
    /***
      * 0 -> default
      * 1 -> error
      * 2 -> valid
      */
    property int state : 0
    property string errorMsg : ""
    property string placeholderDefault: ""

    property ValidationTextfieldModel m_model: ValidationTextfieldModel {}


    placeholderText: placeholderDefault

    background: Rectangle {

        color: m_model.color
        border.color: "dark gray"
        border.width: 1
        radius: 4
        opacity: m_model.opacity

    }

    onStateChanged: {
        m_model.state = state
    }

    property bool isValid: state === 2
}
