set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/ImageWidget.hpp
        ${INCROOT}/TextWidget.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        ${SRCROOT}/ImageWidget.cpp
        ${SRCROOT}/TextWidget.cpp
        ${SRCROOT}/Widget.cpp
    )
