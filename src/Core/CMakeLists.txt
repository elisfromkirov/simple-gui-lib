add_library(SGUI_CORE)

add_subdirectory(EventSystem)
add_subdirectory(Math)

target_link_libraries(SGUI_CORE
    PRIVATE
        m
    )
