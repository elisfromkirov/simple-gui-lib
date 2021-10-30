cmake_minimum_required(VERSION 3.7)

project(SGUI)

set(CMAKE_CXX_FLAGS "-std=c++11 -O1 -Wall -Wextra -Wno-unused-parameter")

add_executable(paint)

target_sources(paint
    PRIVATE
        src/main.cpp
    )

target_link_libraries(paint
    PUBLIC
        SGUI_APPLICAION
        SGUI_CORE_EVENT_SYSTEM
        SGUI_CORE_MATH
        SGUI_GUI_EVENT
        SGUI_PLATFORM
    )

add_subdirectory(src/Application)
add_subdirectory(src/Core)
add_subdirectory(src/GUI)
add_subdirectory(src/Platform)
