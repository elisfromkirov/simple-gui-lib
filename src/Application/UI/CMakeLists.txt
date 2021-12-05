set(INCROOT ${SGUI_SOURCE_DIR}/include/Application/UI)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application/UI)

target_sources(SGUI_APPLICATION
    PUBLIC
        ${INCROOT}/Canvas.hpp
        ${INCROOT}/Editor.hpp
        ${INCROOT}/ToolBar.hpp
    PRIVATE
        ${SRCROOT}/Canvas.cpp
        ${SRCROOT}/Editor.cpp
        ${SRCROOT}/ToolBar.cpp
    )
