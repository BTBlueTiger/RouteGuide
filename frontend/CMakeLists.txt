cmake_minimum_required(VERSION 3.16)
project(frontend LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Location
    Qml
    Quick
    Core5Compat
    Sql
    Network
    QuickControls2
)

qt_standard_project_setup(REQUIRES 6.6)

qt_add_executable(frontend
    main.cpp frontend.qrc
    include/utility/ScreenInfo.h src/utility/ScreenInfo.cpp
    include/map_control/QLocationSearch.h src/map_control/QLocationSearch.cpp

    include/models/plan_a_route/PlanARouteModel.h src/models/plan_a_route/PlanARouteModel.cpp
    include/models/plan_a_route/WaypointModel.h src/models/plan_a_route/WaypointModel.cpp

    include/sqlite/SqliteDatabase.h src/sqlite/SqliteDatabase.cpp
    include/connections/AbstractResource.h
    include/Constants.h
)

qt_add_qml_module(frontend
    URI routeguide
    QML_FILES
        qml/main.qml
        qml/ApplicationFlow.qml

        qml/authentification/Login.qml

        qml/authentification/register/RegisterFormBig.qml
        qml/authentification/register/RegisterFormSmall0.qml
        qml/authentification/register/RegisterFormSmall1.qml

        qml/custom_controls/ValidationTextfield.qml

        qml/routeguide/RouteGuide.qml
        qml/routeguide/PlanARoute.qml

        qml/dialogs/WaypointDialog.qml


    SOURCES
        include/models/UserModel.h src/models/UserModel.cpp

    RESOURCES
        qtquickcontrols2.conf
        SOURCES
)

set_target_properties(frontend PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

if (ANDROID)
    include(./lib/android_openssl/android_openssl.cmake)
    add_android_openssl_libraries(frontend)
endif()

target_link_libraries(frontend PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Location
    Qt6::Qml
    Qt6::Quick
    Qt6::Network
    Qt6::Core5Compat
    Qt6::Sql
    Qt6::QuickControls2
)



