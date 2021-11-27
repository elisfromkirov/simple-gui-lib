set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Events)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Events)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/WidgetEvent.hpp
    PRIVATE
        ${SRCROOT}/WidgetEvent.cpp
    )
