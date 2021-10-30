add_library(SGUI_GUI_EVENT)

set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Event)

target_include_directories(SGUI_GUI_EVENT
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI_EVENT
    PUBLIC
        ${INCROOT}/InputEventMask.hpp
        ${INCROOT}/KeyEvent.hpp
        ${INCROOT}/MouseEvent.hpp
    PRIVATE
        KeyEvent.cpp
        MouseEvent.cpp
    )

target_link_libraries(SGUI_GUI_EVENT
    PUBLIC
        SGUI_CORE_EVENT_SYSTEM
        SGUI_CORE_MATH
    )
