set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Handler)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Handler)

target_include_directories(SGUI_GUI
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/Handler.hpp
        ${INCROOT}/ButtonHandler.hpp
    PRIVATE
        ${SRCROOT}/Handler.cpp
        ${SRCROOT}/ButtonHandler.cpp
    )
