set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/WidgetManager)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/WidgetManager)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/WidgetManager.hpp
    PRIVATE
        ${SRCROOT}/WidgetManager.cpp
    )
