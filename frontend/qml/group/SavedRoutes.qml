import QtQuick 2.15

import RouteApiRessource

import UserModel

SavedRoutesForm {


    property RouteApiRessource ressource: RouteApiRessource {}


    property int pageIndex : 0

    signal toNavigation()
    swipeView.onCurrentIndexChanged: pageIndex = swipeView.currentIndex
    tabbarHeader.currentIndex: pageIndex
    Component.onCompleted: {
        UserModel.getRoutes()
    }

    pageMyRoutesRoutes: UserModel.routes
    savedRoutesFlickable.onToNavigation: toNavigation()

}
