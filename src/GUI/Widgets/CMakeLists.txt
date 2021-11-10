set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/ButtonBase.hpp
        ${INCROOT}/Label.hpp
        ${INCROOT}/Image.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        ${SRCROOT}/ButtonBase.cpp
        ${SRCROOT}/Label.cpp
        ${SRCROOT}/Image.cpp
        ${SRCROOT}/Widget.cpp
    )
