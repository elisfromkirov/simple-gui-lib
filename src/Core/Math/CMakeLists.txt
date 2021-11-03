set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/Math)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/Core/Math)

target_sources(SGUI_CORE
    PUBLIC
        ${INCROOT}/Vector2.hpp
        ${INCROOT}/Vector3.hpp
    PRIVATE
        ${SRCROOT}/Vector2.cpp
        ${SRCROOT}/Vector3.cpp
    )
