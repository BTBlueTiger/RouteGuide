cmake_minimum_required(VERSION 3.16)

project(UserModel VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS QuickTest Qml Core5Compat)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS QuickTest Qml Core5Compat)


add_library(UserModel STATIC
    UserModel.cpp UserModel.h
)

target_link_libraries(UserModel PRIVATE
    Qt${QT_VERSION_MAJOR}::QuickTest
    Qt${QT_VERSION_MAJOR}::Qml
    Qt6::Core5Compat
    AbstractRessource
)
