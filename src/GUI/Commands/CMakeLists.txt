set(INCROOT ${SGUI_SOURCE_DIR}/include/GUI/Commands)
set(SRCROOT ${SGUI_SOURCE_DIR}/src/GUI/Commands)

target_include_directories(SGUI_GUI
    PUBLIC
        ${INCROOT}
    )

target_sources(SGUI_GUI
    PUBLIC
        ${INCROOT}/CommandQueue.hpp
        ${INCROOT}/Commands.hpp
        ${INCROOT}/ICommand.hpp
    PRIVATE
        ${SRCROOT}/CommandQueue.cpp
        ${SRCROOT}/Commands.cpp      
    )
