set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/ResourceManager)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/ResourceManager)

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/ResourceManager.hpp
    PRIVATE
        ${SRCROOT}/ResourceManager.cpp
    )
