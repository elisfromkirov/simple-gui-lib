add_library(SGUI_PLATFORM)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Platform)

find_package(SDL2 REQUIRED)

target_include_directories(SGUI_PLATFORM
    PUBLIC
        ${INCROOT}
        ${SDL2_INCLUDE_DIRS}
    )

target_sources(SGUI_PLATFORM
    PUBLIC
        ${INCROOT}/Color.hpp
        ${INCROOT}/IRenderTarget.hpp
        ${INCROOT}/Rect.hpp
        ${INCROOT}/Renderer.hpp
        ${INCROOT}/Texture.hpp
        ${INCROOT}/Window.hpp
    PRIVATE
        Color.cpp
        Renderer.cpp
        Texture.cpp
        Window.cpp
    )

target_link_libraries(SGUI_PLATFORM
    PUBLIC
        SGUI_MATH
)
