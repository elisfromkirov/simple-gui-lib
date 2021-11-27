set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/Button.hpp
        ${INCROOT}/CompositeWidget.hpp
        ${INCROOT}/Icon.hpp
        ${INCROOT}/Label.hpp
        ${INCROOT}/List.hpp
        # ${INCROOT}/Slider.hpp
        ${INCROOT}/TitleBar.hpp
        ${INCROOT}/Widget.hpp
    PRIVATE
        ${SRCROOT}/Button.cpp
        ${SRCROOT}/CompositeWidget.cpp
        ${SRCROOT}/Icon.cpp
        ${SRCROOT}/Label.cpp
        ${SRCROOT}/List.cpp
        # ${SRCROOT}/Slider.cpp
        ${SRCROOT}/TitleBar.cpp
        ${SRCROOT}/Widget.cpp
    )
