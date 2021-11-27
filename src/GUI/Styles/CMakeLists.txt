set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Styles)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Styles)

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/DefaultStyle.hpp
        ${INCROOT}/FilledStyle.hpp
        ${INCROOT}/Style.hpp
    PRIVATE
        ${SRCROOT}/DefaultStyle.cpp
        ${SRCROOT}/FilledStyle.cpp
    )
