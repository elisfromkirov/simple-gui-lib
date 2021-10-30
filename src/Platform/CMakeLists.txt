add_library(SGUI_PLATFORM)

find_package(SFML COMPONENTS graphics REQUIRED)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Platform)

target_include_directories(SGUI_PLATFORM
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_PLATFORM
    PUBLIC
        ${INCROOT}/Color.hpp
        ${INCROOT}/Font.hpp
        ${INCROOT}/Input.hpp
        ${INCROOT}/Renderer.hpp
        ${INCROOT}/Sprite.hpp
        ${INCROOT}/Text.hpp
        ${INCROOT}/Window.hpp
    PRIVATE
        Font.cpp
        Input.cpp
        Renderer.cpp
        Sprite.cpp
        Text.cpp
        Window.cpp
    )

target_link_libraries(SGUI_PLATFORM
    PUBLIC
        SGUI_CORE_EVENT_SYSTEM
        SGUI_CORE_MATH
        SGUI_GUI_EVENT
        sfml-graphics
    )
