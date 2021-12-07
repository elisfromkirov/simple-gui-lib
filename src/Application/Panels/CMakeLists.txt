set(INCROOT ${SGUI_SOURCE_DIR}/include/Application/Panels)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application/Panels)

target_sources(SGUI_APPLICATION
    PUBLIC
        ${INCROOT}/Editor.hpp
        ${INCROOT}/EditorPanel.hpp
        ${INCROOT}/MainPanel.hpp
        ${INCROOT}/Palette.hpp
        ${INCROOT}/PreferencesPanels.hpp
        ${INCROOT}/ToolPanel.hpp
    PRIVATE
        ${SRCROOT}/Editor.cpp
        ${SRCROOT}/EditorPanel.cpp
        ${SRCROOT}/MainPanel.cpp
        ${SRCROOT}/Palette.cpp
        ${SRCROOT}/PreferencesPanels.cpp
        ${SRCROOT}/ToolPanel.cpp
    )
