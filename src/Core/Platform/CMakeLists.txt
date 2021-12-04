set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/Platform)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/Platform)

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/Color.hpp
        ${INCROOT}/Font.hpp
        ${INCROOT}/Image.hpp
        ${INCROOT}/Input.hpp
        ${INCROOT}/InputEvent.hpp
        ${INCROOT}/IRenderTarget.hpp
        ${INCROOT}/NativePlatform.hpp
        ${INCROOT}/Rectangle.hpp
        ${INCROOT}/RenderTexture.hpp
        ${INCROOT}/RenderWindow.hpp
        ${INCROOT}/Text.hpp
        ${INCROOT}/Texture.hpp
    PRIVATE
        ${SRCROOT}/Color.cpp
        ${SRCROOT}/Font.cpp
        ${SRCROOT}/Image.cpp
        ${SRCROOT}/Input.cpp
        ${SRCROOT}/InputEvent.cpp
        ${SRCROOT}/Rectangle.cpp
        ${SRCROOT}/RenderTexture.cpp
        ${SRCROOT}/RenderWindow.cpp
        ${SRCROOT}/Text.cpp
        ${SRCROOT}/Texture.cpp        
    )
