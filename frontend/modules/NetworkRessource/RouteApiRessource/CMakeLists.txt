
cmake_minimum_required(VERSION 3.16)

# Das Projekt an sich

project(RouteApiRessource VERSION 0.1 LANGUAGES CXX)

# Such die benötigten Componenten

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Qml)
find_package(Qt6 REQUIRED COMPONENTS Qml)

# Erstelle das Modul/Library das später zum Hauptprojekt hinzugefügt werden soll

qt_add_library(RouteApiRessource STATIC)

qt_add_qml_module(RouteApiRessource
    URI RouteApiRessource
    SOURCES
    RouteApiRessource.cpp
    RouteApiRessource.h

)

# Linke die benötigten libs

target_link_libraries(RouteApiRessource PRIVATE
    Qt6::Qml
    AbstractRessource
)

### Test Projekt ####

# Aktieviere das testen

