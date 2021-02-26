cmake_minimum_required(VERSION 3.5)

project(WinSnap LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WIN32_EXECUTABLE ON)

if(NOT WIN32)
    message(FATAL "This project is for Windows!")
endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(WinSnap
    main.cpp
    snapwindow.cpp
    snapwindow.h
    winsnap.cpp
    winsnap.h
)

target_link_libraries(WinSnap PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    $<${WIN32}:dwmapi>
)
