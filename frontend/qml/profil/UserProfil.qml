import QtQuick 2.15

import UserModel

UserProfilForm {

    // Show User Model user name
    userName.text: UserModel.user

    // Shouw User Group
    group.text : UserModel.group

    // Clicked will call a menu to change the group
    group.onClicked: changeGroupMenu.visible = true

    routes.onClicked: {

    }

    //routes:

}
