# Project Executable
add_executable(
        kola-server
        kola-server.cpp
)

# pull in dependencies
target_link_libraries(
        kola-server
        pico_stdlib
        pico_cyw43_arch_none
)

# Add Persistent Storage
pico_set_linker_script(kola-server ${CMAKE_SOURCE_DIR}/libs/persistent-storage/memmap_custom.ld)

# Set Program Info and UART
pico_set_program_name(kola-server "Kola-Server")
pico_set_program_version(kola-server "0.1")
pico_enable_stdio_uart(kola-server 0)
pico_enable_stdio_usb(kola-server 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(kola-server)

add_custom_command(
        TARGET kola-server POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/build/bin/kola-server/
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/kola-server.hex
        ${CMAKE_SOURCE_DIR}/build/bin/kola-server/kola-server.hex
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/kola-server.uf2
        ${CMAKE_SOURCE_DIR}/build/bin/kola-server/kola-server.uf2
)