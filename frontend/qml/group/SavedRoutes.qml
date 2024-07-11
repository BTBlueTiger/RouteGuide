import QtQuick 2.15

import RouteApiRessource

SavedRoutesForm {


    property RouteApiRessource ressource: RouteApiRessource {}


    property int pageIndex : 0

    signal toNavigation()
    swipeView.onCurrentIndexChanged: pageIndex = swipeView.currentIndex
    tabbarHeader.currentIndex: pageIndex
    pageMyRoutesRoutes: ressource.getFakeRoutes()
    savedRoutesFlickable.onToNavigation: toNavigation()

}
