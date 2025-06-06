cmake_minimum_required(VERSION 3.16)
project(RouteGuide LANGUAGES CXX)

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
    Network
    Positioning
    Sensors
)

qt_standard_project_setup(REQUIRES 6.6)

qt_add_executable(RouteGuide
    main.cpp frontend.qrc
)

qt_add_qml_module(RouteGuide
    URI routeguide

    SOURCES
        include/Constants.h

        include/connections/AbstractResource.h
        include/connections/ResponseType.h

        include/connections/LocationResource.h src/connections/LocationResource.cpp
        include/connections/RouteResource.h src/connections/RouteResource.cpp

        include/models/waypoint/WaypointModel.h src/models/waypoint/WaypointModel.cpp
        include/models/waypoint/WaypointModelItem.h src/models/waypoint/WaypointModelItem.cpp
        include/models/waypoint/WaypointModelManager.h src/models/waypoint/WaypointModelManager.cpp

        include/models/routing/RoutingManager.h src/models/routing/RoutingManager.cpp
        include/models/routing/RoutingModel.h src/models/routing/RoutingModel.cpp

        include/connections/GeoPositionRessource.h src/connections/GeoPositionRessource.cpp

    RESOURCES
        qtquickcontrols2.conf
)

set_target_properties(RouteGuide PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

if (ANDROID)
    include(./lib/android_openssl/android_openssl.cmake)
    add_android_openssl_libraries(RouteGuide)
endif()

target_link_libraries(RouteGuide PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Location
    Qt6::Qml
    Qt6::Quick
    Qt6::Network
    Qt6::Core5Compat

    Qt6::Sensors
)

add_subdirectory(modules)

target_link_libraries(RouteGuide PRIVATE
    ValidationTextfieldplugin
    AbstractRessource
    UserModel
    ScreenInfoplugin
    RouteApiRessource
)


set(MY_UNITTESTS TRUE)
enable_testing()
if(${MY_UNITTESTS})
    add_subdirectory(tests/unit)

endif()


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


