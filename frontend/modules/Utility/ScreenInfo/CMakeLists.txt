cmake_minimum_required(VERSION 3.16)

project(AbstractRessource VERSION 0.1 LANGUAGES CXX)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

qt_add_library(ScreenInfo STATIC)

qt_add_qml_module(ScreenInfo
    URI ScreenInfo
    SOURCES screeninfo.h screeninfo.cpp
)
