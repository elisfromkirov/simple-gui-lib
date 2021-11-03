set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/Application)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/Application)

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/Application.hpp
    PRIVATE
        ${SRCROOT}/Application.cpp
    )
