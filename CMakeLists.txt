cmake_minimum_required(VERSION 3.5)

project(Doodle-Jump VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        platform.h
        platform.cpp
        platform1.h
        platform1.cpp
        platform2.h
        platform2.cpp
        platform3.h
        platform3.cpp
        platform-generator.h
        platform-generator.cpp
        monster.h
        monster.cpp
        monster1.h
        monster1.cpp
        monster2.h
        monster2.cpp
        monster3.h
        monster3.cpp
        trampo.h
        trampo.cpp
        bullet.h
        basics.h
        basics.cpp
        bullet.cpp
        resources.qrc
        jetpack.cpp
        jetpack.h
        shield.cpp
        shield.h
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Doodle-Jump
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Doodle-Jump APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Doodle-Jump SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Doodle-Jump
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Doodle-Jump PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Doodle-Jump PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Doodle-Jump
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Doodle-Jump)
endif()
