add_library(SGUI_EDITOR)

target_include_directories(SGUI_EDITOR
    PUBLIC
    ${SGUI_SOURCE_DIR}/include
    )

set(INCROOT ${SGUI_SOURCE_DIR}/include/Editor)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Editor)    

target_sources(SGUI_EDITOR
    PUBLIC
        ${INCROOT}/ColorSheme.hpp
        ${INCROOT}/Editor.hpp
        ${INCROOT}/MainPanel.hpp
    PRIVATE
        ${SRCROOT}/Editor.cpp
        ${SRCROOT}/MainPanel.cpp
    )

target_link_libraries(SGUI_EDITOR
    PUBLIC
        SGUI_CORE
        SGUI_GUI
        SGUI_PLATFORM
    )
