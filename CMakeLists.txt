cmake_minimum_required(VERSION 3.7)

project(SGUI)

set(CMAKE_CXX_FLAGS "-std=c++11 -O1 -DNDEBUG -W -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field")
set(CMAKE_EXE_LINKER_FLAGS "-lm -lSDL2")

add_executable(SGUI)

find_package(SDL2 REQUIRED)

include_directories(SGUI ${SDL2_INCLUDE_DIRS})

target_sources(SGUI
    PRIVATE
        src/main.cpp
    )

target_link_libraries(SGUI
    PUBLIC
        SGUI_CORE
        SGUI_PLATFORM
        ${SDL2_LIBRARIES}
    )

add_subdirectory(src/Core)
add_subdirectory(src/Platform)
