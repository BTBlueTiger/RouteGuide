import QtQuick 2.15

import RouteApiRessource

import UserModel

SavedRoutesForm {


    property RouteApiRessource ressource: RouteApiRessource {}


    signal toNavigation()
    swipeView.onCurrentIndexChanged: pageIndex = swipeView.currentIndex
    tabbarHeader.currentIndex: pageIndex
    Component.onCompleted: {
            UserModel.getRoutes(pageIndex)

    }

    onPageIndexChanged: {
        UserModel.getRoutes(pageIndex)
    }

    pageMyRoutesRoutes: UserModel.routes

    savedRoutesFlickablePublic.onToNavigation: toNavigation()
    savedRoutesFlickablePrivate.onToNavigation: toNavigation()

}
