cmake_minimum_required(VERSION 3.16)

project(UserModel VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Qml)
find_package(Qt6 REQUIRED COMPONENTS Qml)


add_library(UserModel STATIC
    UserModel.cpp UserModel.h

)

target_link_libraries(UserModel PRIVATE
    Qt6::Qml
    AbstractRessource
)


enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Test Widgets)

qt_standard_project_setup()

qt_add_executable(test_userModel
    test_usermodel.cpp
    test_usermodel.h
)

target_link_libraries(test_userModel PRIVATE
    Qt6::Core
    Qt6::Qml
    Qt6::Gui
    Qt6::Test
    Qt6::Widgets
    UserModel
)


set_target_properties(test_userModel PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

install(TARGETS test_userModel
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)



