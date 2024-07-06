cmake_minimum_required(VERSION 3.16)

project(UserModel VERSION 0.1 LANGUAGES CXX)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

qt_add_library(UserModel STATIC)
qt_add_qml_module(UserModel
    URI Usermodel
    SOURCES
        UserModel.h UserModel.cpp
)

target_link_libraries(UserModel PRIVATE Qt6::Core5Compat)
