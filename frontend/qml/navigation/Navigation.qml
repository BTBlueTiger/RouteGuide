import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import QtLocation
import QtPositioning

import GeoPositionRessource

import "../map"
import "../../"


Rectangle {
    RouteGuideMap{
        center: GeoPositionRessource.coordinate
    }
}
