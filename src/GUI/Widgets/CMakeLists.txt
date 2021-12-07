set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Widgets)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Widgets)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/Button.hpp
        ${INCROOT}/ContainerWidget.hpp
        ${INCROOT}/Icon.hpp
        ${INCROOT}/Label.hpp
        ${INCROOT}/LayeredWidget.hpp
        ${INCROOT}/List.hpp
        ${INCROOT}/MenuBar.hpp
        ${INCROOT}/ScrollBar.hpp
        ${INCROOT}/Slider.hpp
        ${INCROOT}/TabBar.hpp
        ${INCROOT}/TitleBar.hpp
        ${INCROOT}/Widget.hpp
        ${INCROOT}/Window.hpp
    PRIVATE
        ${SRCROOT}/Button.cpp
        ${SRCROOT}/ContainerWidget.cpp
        ${SRCROOT}/Icon.cpp
        ${SRCROOT}/Label.cpp
        ${SRCROOT}/LayeredWidget.cpp
        ${SRCROOT}/List.cpp
        ${SRCROOT}/MenuBar.cpp
        ${SRCROOT}/ScrollBar.cpp
        ${SRCROOT}/Slider.cpp
        ${SRCROOT}/TabBar.cpp
        ${SRCROOT}/TitleBar.cpp
        ${SRCROOT}/Widget.cpp
        ${SRCROOT}/Window.cpp
    )
