set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/EventSystem)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/EventSystem)

target_include_directories(SGUI_CORE
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/EventDispatcher.hpp
        ${INCROOT}/IEvent.hpp
        ${INCROOT}/IEventListener.hpp
    PRIVATE
        ${SRCROOT}/EventDispatcher.cpp
    )

# add_library(SGUI_CORE_EVENT_SYSTEM)

# set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/EventSystem)

# target_include_directories(SGUI_CORE_EVENT_SYSTEM
#     PUBLIC
#         ${INCROOT}
#     )

# target_sources(SGUI_CORE_EVENT_SYSTEM
#     PUBLIC
#         ${INCROOT}/EventDispatcher.hpp
#         ${INCROOT}/IEvent.hpp
#         ${INCROOT}/IEventListener.hpp
#     PRIVATE
#         EventDispatcher.cpp
#     )
