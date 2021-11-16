set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/ButtonBase.hpp
        ${INCROOT}/CompositeWidget.hpp
        ${INCROOT}/Icon.hpp
        ${INCROOT}/Label.hpp
        ${INCROOT}/Slider.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        ${SRCROOT}/ButtonBase.cpp
        ${SRCROOT}/CompositeWidget.cpp
        ${SRCROOT}/Icon.cpp
        ${SRCROOT}/Label.cpp
        ${SRCROOT}/Slider.cpp
        ${SRCROOT}/Widget.cpp
    )
