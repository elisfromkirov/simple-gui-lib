add_library(SGUI_PLATFORM)

find_package(SFML COMPONENTS graphics REQUIRED)

target_include_directories(SGUI_PLATFORM
    PUBLIC
        ${SGUI_SOURCE_DIR}/include
    )

set(INCROOT ${SGUI_SOURCE_DIR}/include/Platform)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Platform)

target_sources(SGUI_PLATFORM
    PUBLIC
        ${INCROOT}/Color.hpp
        ${INCROOT}/Font.hpp
        ${INCROOT}/Input.hpp
        ${INCROOT}/Platform.hpp
        ${INCROOT}/Renderer.hpp
        ${INCROOT}/Sprite.hpp
        ${INCROOT}/Text.hpp
        ${INCROOT}/Window.hpp
    PRIVATE
        ${SRCROOT}/Color.cpp
        ${SRCROOT}/Font.cpp
        ${SRCROOT}/Input.cpp
        ${SRCROOT}/Renderer.cpp
        ${SRCROOT}/Sprite.cpp
        ${SRCROOT}/Text.cpp
        ${SRCROOT}/Window.cpp
    )

target_link_libraries(SGUI_PLATFORM
    PUBLIC
        SGUI_CORE
        SGUI_GUI
        sfml-graphics
    )
