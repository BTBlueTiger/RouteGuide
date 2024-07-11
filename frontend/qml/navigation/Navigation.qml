import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import QtLocation
import QtPositioning


import GeoPositionRessource

import "../map"
import "../../"


Rectangle {

    // Placeholder to use it in Preview that is in Plan a Route
    id: navigation

    RouteGuideMap{
        id: map
    }
}
