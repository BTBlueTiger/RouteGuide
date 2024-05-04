import QtQuick
import QtQuick.Controls



TextField {

    id: validationTextField
    property bool isError : false
    property bool isValid : false
    property string errorMsg : ""
    property string placeholderDefault: ""

    placeholderText: placeholderDefault

    property Rectangle _error: Rectangle {
        implicitHeight: textFieldEmail.height
        implicitWidth: textFieldEmail.width

        opacity: 0.2
        color: "red"
        radius: 4
    }

    property Rectangle _valid: Rectangle {
        implicitHeight: textFieldEmail.height
        implicitWidth: textFieldEmail.width
        color: "green"
        opacity: 0.2
        border.color: "#90EE90"
    }

    property Rectangle _default: Rectangle {
        implicitHeight: textFieldEmail.height
        implicitWidth: textFieldEmail.width
        color: "transparent"
        opacity: 0.2
    }

    onIsErrorChanged: {
        if(isError) {
            background = _error
        }
    }
    onIsValidChanged: {
        if(isValid) {
            background = _valid
        }
    }

    Label {
        id: textFieldEmailError
        font.pointSize: 16
        text: errorMsg
        color: "red"
        x: (validationTextField.x - validationTextField.width / 5)
        y: validationTextField.height
        background: Rectangle{
            color: "white"
            radius: 4
            opacity: 0.35
        }
        visible: isError
    }
}


