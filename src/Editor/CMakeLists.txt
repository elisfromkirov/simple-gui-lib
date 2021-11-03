add_library(SGUI_EDITOR)

target_include_directories(SGUI_EDITOR
    PUBLIC
    ${SGUI_SOURCE_DIR}/include
    )

set(INCROOT ${SGUI_SOURCE_DIR}/include/Editor)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Editor)    

target_sources(SGUI_EDITOR
    PUBLIC
        ${INCROOT}/Editor.hpp
    PRIVATE
        ${SRCROOT}/Editor.cpp
    )

target_link_libraries(SGUI_EDITOR
    PUBLIC
        SGUI_CORE
        SGUI_GUI
        SGUI_PLATFORM
    )
