cmake_minimum_required(VERSION 3.16)

project(ValidationTextfield VERSION 0.1 LANGUAGES CXX)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

qt_add_library(ValidationTextfield STATIC)
qt_add_qml_module(ValidationTextfieldModel
    URI ValidationTextfieldModel
    SOURCES ValidationTextfieldModel.cpp ValidationTextfieldModel.h
)

qt_add_qml_module(ValidationTextfield
    URI ValidationTextfield
    VERSION
    QML_FILES ValidationTextfield.qml
)
