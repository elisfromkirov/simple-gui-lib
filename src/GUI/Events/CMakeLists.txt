set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Event)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Event)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/WidgetEvent.hpp
    PRIVATE
        ${SRCROOT}/WidgetEvent.cpp
    )
