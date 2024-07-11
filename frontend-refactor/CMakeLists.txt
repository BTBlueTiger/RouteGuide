cmake_minimum_required(VERSION 3.16)
project(RouteGuide LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


# find all required components
find_package(Qt6 6.4 REQUIRED COMPONENTS
    # qt core modules
    Quick
    Core
    Gui
    Qml

    #qt extensions modules
    Network
    Location
    Sensors

)

qt_standard_project_setup(REQUIRES 6.4)

# add the main executable and the .qrc for qml and ressources
qt_add_executable(RouteGuide
    main.cpp routeguide.qrc
)

qt_add_qml_module(RouteGuide
    URI routeguide
    SOURCES
        include/utility/ScreenInfo.h src/utility/ScreenInfo.cpp
        #include/ressource/AbstractRessource.h src/ressource/AbstractRessource.cpp
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
    #qt core modules
    Qt6::Quick
    Qt6::Core
    Qt6::Gui
    Qt6::Qml

    #qt extensions blugins
    Qt6::Network
    Qt6::Location
    Qt6::Sensors
)

add_subdirectory(modules)



target_link_libraries(RouteGuide PRIVATE
    ValidationTextfieldplugin
    AbstractRessource
    UserModel
)

install(TARGETS ${EXECUTABLE_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set(MY_UNITTESTS TRUE)
enable_testing()
if(${MY_UNITTESTS})
    add_subdirectory(tests/unit)
endif()
