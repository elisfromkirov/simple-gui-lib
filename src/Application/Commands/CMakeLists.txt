set(INCROOT ${SGUI_SOURCE_DIR}/include/Application/Commands)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application/Commands)

target_sources(SGUI_APPLICATION
    PUBLIC
        ${INCROOT}/Commands.hpp
    PRIVATE
        ${SRCROOT}/Commands.cpp
    )
