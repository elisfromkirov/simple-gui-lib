add_library(SGUI_GUI_WIDGETS)

set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)

target_include_directories(SGUI_GUI_WIDGETS
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI_WIDGETS
    PUBLIC
        ${INCROOT}/Button.hpp
        ${INCROOT}/ContainerWidget.hpp
        ${INCROOT}/ImageWidget.hpp
        ${INCROOT}/TextWidget.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        Button.cpp
        ContainerWidget.cpp
        ImageWidget.cpp
        TextWidget.cpp
        Widget.cpp
    )

target_link_libraries(SGUI_GUI_WIDGETS
    PUBLIC
        SGUI_CORE_EVENT_SYSTEM
        SGUI_CORE_MATH
        SGUI_GUI_EVENT
        SGUI_GUI_HANDLER
        SGUI_PLATFORM
    )
