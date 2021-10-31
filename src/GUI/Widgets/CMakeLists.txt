set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_include_directories(SGUI_GUI
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/Button.hpp
        ${INCROOT}/ContainerWidget.hpp
        ${INCROOT}/ImageWidget.hpp
        ${INCROOT}/TextWidget.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        ${SRCROOT}/Button.cpp
        ${SRCROOT}/ContainerWidget.cpp
        ${SRCROOT}/ImageWidget.cpp
        ${SRCROOT}/TextWidget.cpp
        ${SRCROOT}/Widget.cpp
    )
