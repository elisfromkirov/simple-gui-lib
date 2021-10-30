add_library(SGUI_CORE_MATH)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Core/Math)

target_include_directories(SGUI_CORE_MATH
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_CORE_MATH
    PUBLIC
        ${INCROOT}/Vector2.hpp
        ${INCROOT}/Vector3.hpp
    PRIVATE
        Vector2.cpp
        Vector3.cpp
    )

target_link_libraries(SGUI_CORE_MATH
    PRIVATE
        m
    )
