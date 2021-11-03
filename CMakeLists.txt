cmake_minimum_required(VERSION 3.7)

project(SGUI)

set(CMAKE_CXX_FLAGS "-std=c++11 -O1 -Wall -Wextra -Wno-unused-parameter")

add_executable(editor)

target_sources(editor
    PRIVATE
        src/main.cpp
    )

target_link_libraries(editor
    PUBLIC
        SGUI_CORE
        SGUI_EDITOR
        SGUI_GUI
        SGUI_PLATFORM
    )

add_subdirectory(src/Core)
add_subdirectory(src/Editor)
add_subdirectory(src/GUI)
add_subdirectory(src/Platform)
