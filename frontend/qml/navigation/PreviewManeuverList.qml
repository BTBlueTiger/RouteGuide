import QtQuick
import QtQuick.Controls

ListView {
    property string totalTravelTime
    property string totalDistance
    model: ListModel{ id: routeInfoModel }

}
