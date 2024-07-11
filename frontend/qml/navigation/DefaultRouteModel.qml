import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

// Should be used for data that is displayed at the main Navigation
RouteModel {
    id: defaultRouteModel
    query: RouteQuery{
        id: routeQuery
    }
    plugin: defaultMapPlugin
}
