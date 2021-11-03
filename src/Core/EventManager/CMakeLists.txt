set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/EventManager)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/EventManager)

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/EventManager.hpp
        ${INCROOT}/Event.hpp
        ${INCROOT}/IEventListener.hpp
    PRIVATE
        ${SRCROOT}/EventManager.cpp
        ${SRCROOT}/Event.cpp
    )
