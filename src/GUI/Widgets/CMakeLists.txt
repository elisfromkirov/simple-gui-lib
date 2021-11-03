set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/ImageVeiw.hpp
        ${INCROOT}/TextVeiw.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        ${SRCROOT}/ImageVeiw.cpp
        ${SRCROOT}/TextVeiw.cpp
        ${SRCROOT}/Widget.cpp
    )
