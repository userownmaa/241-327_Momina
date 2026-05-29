cmake_minimum_required(VERSION 3.16)
project(lab3 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)

set(SOURCES
    main.cpp
    medicine.cpp
    httpclient.cpp
    mainwindow.cpp
    mainwindow.ui
)

set(HEADERS
    medicine.h
    httpclient.h
    mainwindow.h
)

add_executable(lab3 ${SOURCES} ${HEADERS})

target_link_libraries(lab3
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)
