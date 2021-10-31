set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Event)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Event)

target_include_directories(SGUI_GUI
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/InputEventMask.hpp
        ${INCROOT}/KeyEvent.hpp
        ${INCROOT}/MouseEvent.hpp
    PRIVATE
        ${SRCROOT}/KeyEvent.cpp
        ${SRCROOT}/MouseEvent.cpp
    )
