cmake_minimum_required(VERSION 3.16)

project(AbstracRessource VERSION 0.1 LANGUAGES CXX)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

qt_add_library(AbstracRessource STATIC
    AbstractRessource.h AbstractRessource.cpp
)

target_link_libraries(AbstracRessource PRIVATE Qt6::Core Qt6::Qml Qt6::Network Shared)
