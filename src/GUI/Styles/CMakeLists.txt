set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Styles)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Styles)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/ButtonStyle.hpp
        ${INCROOT}/FilledStyle.hpp
        ${INCROOT}/IStyle.hpp
        ${INCROOT}/SliderStyle.hpp
    PRIVATE
        ${SRCROOT}/ButtonStyle.cpp
        ${SRCROOT}/FilledStyle.cpp
        ${SRCROOT}/SliderStyle.cpp
    )
