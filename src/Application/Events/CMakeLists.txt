set(INCROOT ${SGUI_SOURCE_DIR}/include/Application/Events)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Application/Events)

target_sources(SGUI_APPLICATION
    PUBLIC
        ${INCROOT}/ApplicationEvent.hpp
    PRIVATE
        ${SRCROOT}/ApplicationEvent.cpp
    )
