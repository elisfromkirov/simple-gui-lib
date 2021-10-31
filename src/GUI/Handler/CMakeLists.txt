add_library(SGUI_GUI_HANDLER)

set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Handler)

target_include_directories(SGUI_GUI_HANDLER
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI_HANDLER
    PUBLIC
        ${INCROOT}/Handler.hpp
        ${INCROOT}/ButtonHandler.hpp
    PRIVATE
        ButtonHandler.cpp
    )

target_link_libraries(SGUI_GUI_HANDLER
    PUBLIC
        SGUI_CORE_EVENT_SYSTEM
        SGUI_CORE_MATH
        SGUI_GUI_EVENT
        SHUI_PLATFORM
    )
