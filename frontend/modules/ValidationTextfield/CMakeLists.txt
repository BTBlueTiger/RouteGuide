cmake_minimum_required(VERSION 3.16)

project(ValidationTextfield VERSION 0.1 LANGUAGES CXX)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


qt_add_library(ValidationTextfield STATIC)
qt_add_library(ValidationTextfieldModel STATIC)


qt_add_qml_module(ValidationTextfieldModel
    URI ValidationTextfieldModel
    SOURCES ValidationTextfieldModel.cpp ValidationTextfieldModel.h
)

qt_add_qml_module(ValidationTextfield
    URI ValidationTextfield
    VERSION
    QML_FILES
    ValidationTextfieldForm.ui.qml
    ValidationTextfield.qml
)

target_link_libraries(ValidationTextfieldModel PRIVATE
    AbstractRessource
)



enable_testing()

add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE QML_FILES *.qml)



add_executable(tst_ValidationTextField main.cpp
               setup.cpp setup.h
               tst_validationTextfield.qml
)


add_test(NAME tst_validationTextfield COMMAND tst_validationTextfield)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS QuickTest Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS QuickTest Qml)


target_link_libraries(tst_ValidationTextField PRIVATE
                      Qt${QT_VERSION_MAJOR}::QuickTest
                      Qt${QT_VERSION_MAJOR}::Qml

                      ValidationTextfieldModelplugin
                      ValidationTextfieldplugin
                  )
