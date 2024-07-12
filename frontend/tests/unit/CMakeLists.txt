cmake_minimum_required(VERSION 3.5)
include(CMakePrintHelpers)
cmake_policy(SET CMP0099 NEW)

project(tst_unit LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS QuickTest Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS QuickTest Qml)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# no need to copy around qml test files for shadow builds - just set the respective define
add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

set(test_qml_files
    ValidationTextfield.qml
)

file(GLOB_RECURSE QML_FILES *.qml)
add_custom_target(tst_unit_qmlfiles SOURCES ${QML_FILES})

qt_add_executable(tst_unit main.cpp
               setup.cpp setup.h
)

#add_test(NAME tst_login COMMAND tst_login)


add_test(NAME tst_validationTextfield COMMAND tst_validationTextfield)


target_link_libraries(tst_unit PRIVATE
                      Qt${QT_VERSION_MAJOR}::QuickTest
                      Qt${QT_VERSION_MAJOR}::Qml

                      ValidationTextfieldModelplugin
                      ValidationTextfieldplugin
                  )

