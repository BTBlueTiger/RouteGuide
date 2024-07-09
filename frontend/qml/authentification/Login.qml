import QtQuick
import QtQuick.Window

import UserModel

LoginForm {


    btnLogin.onClicked: {
        UserModel.loginAttempt
        (
            {
                ["username"] : userName.text,
                ["password"] : userPassword.text
            }
        )
    }

    Connections{
        target: UserModel
        function onUserChanged() {
            if(!UserModel.loggedIn) {
                wrongCredentialsToolTip.visible = true
            }
        }
    }

    wrongCredentialsToolTip.onVisibleChanged: wrongCredentialsToolTipTimer.start()

}

