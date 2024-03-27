cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(Kola C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Project Specific
add_executable(
        kola
        kola.cpp
)

# pull in dependencies
target_link_libraries(
        kola
        pico_stdlib
        pico_cyw43_arch_none
)

# Add Persistent Storage
pico_set_linker_script(kola ${CMAKE_SOURCE_DIR}/memmap_custom.ld)

# Set Program Info and UART
pico_set_program_name(kola "Kola")
pico_set_program_version(kola "0.1")
pico_enable_stdio_uart(kola 0)
pico_enable_stdio_usb(kola 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(kola)