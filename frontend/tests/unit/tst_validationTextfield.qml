import QtQuick 2.15
import QtTest

import ValidationTextfield

TestCase {

    ValidationTextfield{
        id: field
        errorMsg: "Error"
        placeholderDefault: "Default"
    }

    function test_initialState() {
        verify(field.state === ValidationTextfield.ValidationState.Default)
        verify(field.errorMsg === "Error")
        verify(field.placeholderDefault === "Default")
    }


    function test_State() {
        //initial
        verify(field.state === 0)

    }

}

