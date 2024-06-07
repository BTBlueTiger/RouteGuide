cmake_minimum_required(VERSION 3.16)

project(UserModel VERSION 0.1 LANGUAGES CXX)

qt_add_library(UserModel STATIC)


qt_add_qml_module(UserModel
    URI UserModel
    SOURCES UserModel.cpp UserModel.h
)

target_link_libraries(UserModel PRIVATE
    AbstractRessourceplugin
)
