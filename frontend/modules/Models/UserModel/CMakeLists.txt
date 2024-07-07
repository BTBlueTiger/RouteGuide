cmake_minimum_required(VERSION 3.16)

# Das Projekt an sich

project(UserModel VERSION 0.1 LANGUAGES CXX)

# Such die benötigten Componenten

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Qml)
find_package(Qt6 REQUIRED COMPONENTS Qml)

# Erstelle das Modul/Library das später zum Hauptprojekt hinzugefügt werden soll

add_library(UserModel STATIC
    UserModel.cpp UserModel.h

)

# Linke die benötigten libs

target_link_libraries(UserModel PRIVATE
    Qt6::Qml
    AbstractRessource
)

### Test Projekt ####

# Aktieviere das testen

enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Test Widgets)

# Setze das das Testprojekt auf

qt_standard_project_setup()

qt_add_executable(test_userModel
    test_usermodel.cpp
    test_usermodel.h
)

# linke die libs

target_link_libraries(test_userModel PRIVATE
    Qt6::Core
    Qt6::Qml
    Qt6::Test
    UserModel
)


# boilerplate installation

set_target_properties(test_userModel PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

install(TARGETS test_userModel
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)



