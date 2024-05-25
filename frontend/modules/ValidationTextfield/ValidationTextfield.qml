import QtQuick
import QtQuick.Controls
import QtTest
import ValidationTextfieldModel


TextField {

    enum ValidationType{
        None,
        Email
    }

    enum ValidationState{
        Default,
        Error,
        Valid
    }

    ValidationTextfieldModel{
        id: model
    }

    id: validationTextField
    property int state : 0
    property int validationType: 0
    property string errorMsg : ""
    property string placeholderDefault: ""


    placeholderText: placeholderDefault

    background: Rectangle {

        color: model.color
        border.width: 1
        radius: 4
        opacity: model.opacity
        border.color: "darkGrey"

    }

    onStateChanged: {
        model.state = state
    }

    property bool isValid: state === 2
}
