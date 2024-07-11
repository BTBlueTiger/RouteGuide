cmake_minimum_required(VERSION 3.16)

project(AbstractRessource VERSION 0.1 LANGUAGES CXX)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(AbstractRessource SHARED
    AbstractRessource.h AbstractRessource.cpp
)

target_link_libraries(AbstractRessource PRIVATE
    Qt6::Core
    Qt6::Network
)
