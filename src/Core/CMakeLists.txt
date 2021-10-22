add_library(SGUI_CORE)

set(INCROOT ${SGUI_SOURCE_DIR}/include/Core)

add_subdirectory(EventSystem)
add_subdirectory(Math)



target_link_libraries(SGUI_CORE
    PRIVATE
        m
    )
