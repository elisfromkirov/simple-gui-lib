set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Style)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Style)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/IStyle.hpp
        ${INCROOT}/FilledStyle.hpp
    PRIVATE
        ${SRCROOT}/FilledStyle.cpp
    )
