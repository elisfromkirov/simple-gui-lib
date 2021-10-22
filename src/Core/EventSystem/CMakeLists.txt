set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/EventSystem)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/EventSystem)

target_include_directories(SGUI_CORE
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/EventManager.hpp
        ${INCROOT}/IEvent.hpp
        ${INCROOT}/IEventListener.hpp
    PRIVATE
        ${SRCROOT}/EventManager.cpp
    )
