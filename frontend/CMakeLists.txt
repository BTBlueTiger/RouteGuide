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
    Positioning
    QuickControls2
)

qt_standard_project_setup(REQUIRES 6.6)

qt_add_executable(frontend
    main.cpp frontend.qrc
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

        qml/routeguide/PlanARoute/PlanARoute.qml
        qml/routeguide/PlanARoute/AddedPage.qml
        qml/routeguide/PlanARoute/SearchPage.qml
        qml/routeguide/PlanARoute/PreviewPage.qml
        qml/routeguide/PlanARoute/WaypointFlickable.qml

        qml/navigation/Navigation.qml

        js/Formatter.js


    SOURCES
        include/utility/ScreenInfo.h src/utility/ScreenInfo.cpp



        include/sqlite/SqliteDatabase.h src/sqlite/SqliteDatabase.cpp
        include/Constants.h

        include/connections/AbstractResource.h
        include/connections/ResponseType.h

        include/connections/LocationResource.h src/connections/LocationResource.cpp
        include/connections/RouteResource.h src/connections/RouteResource.cpp

        include/models/UserModel.h src/models/UserModel.cpp
        include/models/waypoint/WaypointModel.h src/models/waypoint/WaypointModel.cpp
        include/models/waypoint/WaypointModelItem.h src/models/waypoint/WaypointModelItem.cpp
        include/models/waypoint/WaypointModelManager.h src/models/waypoint/WaypointModelManager.cpp

        include/models/routing/RoutingManager.h src/models/routing/RoutingManager.cpp
        include/models/routing/RoutingModel.h src/models/routing/RoutingModel.cpp

        include/connections/GeoPositionRessource.h src/connections/GeoPositionRessource.cpp

    RESOURCES
        qtquickcontrols2.conf

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

add_subdirectory(modules/ValidationTextfield)

target_link_libraries(frontend PRIVATE
    ValidationTextfieldplugin
)


set(MY_UNITTESTS TRUE)
enable_testing()
if(${MY_UNITTESTS})
    add_subdirectory(tests/unit)

endif()
add_subdirectory(tests/integration)


#qt_add_translations(${EXECUTABLE_NAME} TS_FILES
#        ${EXECUTABLE_NAME}_de_DE.ts
#        ${EXECUTABLE_NAME}_en_EN.ts
#    SOURCES ${QML_SOURCES2} ${CPP_SOURCES} ${HPP_SOURCES}
#    RESOURCE_PREFIX "/translations"
#)


install(TARGETS ${EXECUTABLE_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


