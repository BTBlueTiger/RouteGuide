cmake_minimum_required(VERSION 3.16)
project(RouteGuide LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Location Qml Core5Compat)

set (_QML_IMPORT_PATHS "")

list (APPEND _QML_IMPORT_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/qml/controls/)

set(PROJECT_SOURCES
    src/main.cpp
)

qt_add_executable(RouteGuide
    src/main.cpp
    src/map_controls/QLocationSearch.cpp
    include/map_control/QLocationSearch.h
    src/map_controls/QLocationSearch.cpp
    res/.qrc
    include/utility/ScreenInfo.h
    src/utility/ScreenInfo.cpp
    include/model/UserModel.h
    src/model/UserModel.cpp
    include/navigation/NavigationManager.h
    src/navigation/NavigationManager.cpp
    include/group/Group.h
    src/group/Group.cpp
)

qt_add_qml_module(RouteGuide
    URI CustomControls
    VERSION 1.0
    QML_FILES qml/controls/ValidationTextField.qml
)

if (ANDROID)
    include(./lib/android_openssl/android_openssl.cmake)
endif()

target_link_libraries(RouteGuide PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Location
    Qt::Qml
    Qt6::Core5Compat
)
if (ANDROID)
    add_android_openssl_libraries(RouteGuide)
endif()


set(qml_resource_files
    "qml/main.qml"

    "qml/authentification/login.qml"
    "qml/authentification/register_little_screen0.qml"
    "qml/authentification/register_big_screen.qml"
    "qml/authentification/register_little_screen1.qml"

    "qml/route_guide/bottom_navigation.qml"
    "qml/route_guide/profile.qml"
    "qml/route_guide/map.qml"

)



qt6_add_resources(RouteGuide "qml"
    PREFIX
        "/"
    FILES
        ${qml_resource_files}
)

