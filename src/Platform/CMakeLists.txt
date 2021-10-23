add_library(SGUI_PLATFORM)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Platform)

find_package(SDL2 REQUIRED)

target_include_directories(SGUI_PLATFORM
    PUBLIC
        ${INCROOT}/Input
        ${INCROOT}/Render
        ${SDL2_INCLUDE_DIRS}
    )

target_sources(SGUI_PLATFORM
    PUBLIC
        ${INCROOT}/Input/Input.hpp
        ${INCROOT}/Input/KeyboardEvent.hpp
        ${INCROOT}/Input/MouseEvent.hpp
        ${INCROOT}/Input/QuitEvent.hpp
        ${INCROOT}/Render/Renderer.hpp
        ${INCROOT}/Render/Texture.hpp
        ${INCROOT}/Render/Window.hpp
    PRIVATE
        Input/Input.cpp
        Input/KeyboardEvent.cpp
        Input/MouseEvent.cpp
        Input/QuitEvent.cpp
        Render/Renderer.cpp
        Render/Texture.cpp
        Render/Window.cpp
    )

target_link_libraries(SGUI_PLATFORM
    PUBLIC
        SGUI_MATH
        SGUI_EVENT_SYSTEM
    )
