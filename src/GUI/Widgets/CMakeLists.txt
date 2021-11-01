set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_include_directories(SGUI_GUI
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/Button.hpp
        ${INCROOT}/ImageWidget.hpp
        ${INCROOT}/RectWidget.hpp
        ${INCROOT}/TextWidget.hpp
        ${INCROOT}/Title.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        ${SRCROOT}/Button.cpp
        ${SRCROOT}/ImageWidget.cpp
        ${SRCROOT}/RectWidget.cpp
        ${SRCROOT}/TextWidget.cpp
        ${SRCROOT}/Title.cpp
        ${SRCROOT}/Widget.cpp
    )
