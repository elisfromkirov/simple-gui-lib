set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/EventManager)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/EventManager)

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/Event.hpp
        ${INCROOT}/EventCallback.hpp
        ${INCROOT}/EventDispatcher.hpp
        ${INCROOT}/EventManager.hpp
        ${INCROOT}/IEventListener.hpp
    PRIVATE
        ${SRCROOT}/Event.cpp
        ${SRCROOT}/EventDispatcher.cpp
        ${SRCROOT}/EventManager.cpp
    )
