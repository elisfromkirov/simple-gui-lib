cmake_minimum_required(VERSION 3.7)

project(SGUI)

set(CMAKE_CXX_FLAGS "-std=c++11 -O1 -Wall -Wextra")

add_executable(paint)

target_sources(paint
    PRIVATE
        src/main.cpp
    )

add_subdirectory(src/Application)
add_subdirectory(src/Core)
add_subdirectory(src/GUI)

target_link_libraries(paint
    PUBLIC
        SGUI_APPLICATION
        SGUI_CORE
        SGUI_GUI
    )
