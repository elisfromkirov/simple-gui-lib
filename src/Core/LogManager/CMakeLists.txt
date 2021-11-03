set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/LogManager)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/LogManager)

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/LogManager.hpp
    PRIVATE
        ${SRCROOT}/LogManager.cpp
    )
