import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

// Should be used for data that is displayed at the main Navigation
Plugin {
    name: "osm"

    PluginParameter {
        name: "osm.mapping.custom.host"

        // OSM plugin will auto-append if .png isn't suffix, and that screws up apikey which silently
        // fails authentication (only Wireshark revealed it)
        value: "http://tile.thunderforest.com/atlas/%z/%x/%y.png?apikey=5e174dbc86e5477b90da4369fabe46f5&fake=.png"

        //value: "http:192.168.178.23:7070/tile/%z/%x/%y.png"
    }
}
