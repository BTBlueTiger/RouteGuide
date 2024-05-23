import QtQuick 2.15
import QtTest

import ValidationTextfield

TestCase {

    ValidationTextfield{
        id: field
        errorMsg: "Error"
        placeholderDefault: "Default"
        validationType: ValidationTextfield.ValidationState.Email
    }

    function test_initialState() {
        verify(field.state === ValidationTextfield.ValidationState.Default)
        verify(field.errorMsg === "Error")
        verify(field.placeholderDefault === "Default")
        verify(field.validationType === ValidationTextfield.ValidationType.Email)
    }


    function test_State() {
        //initial state = 0

    }



}

