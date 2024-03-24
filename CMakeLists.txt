cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)

pico_sdk_init()

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

# create map/bin/hex file etc.
pico_add_extra_outputs(kola)