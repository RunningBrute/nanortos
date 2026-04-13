cmake_minimum_required(VERSION 3.20)

project(NanoRTOS C CXX ASM)

add_executable(nano_rtos.elf
    src/main.cpp
    src/startup.cpp
    startup/startup.s
)

target_link_options(nano_rtos.elf PRIVATE
    -T${CMAKE_SOURCE_DIR}/linker/stm32.ld
    -nostdlib
)

target_compile_options(nano_rtos.elf PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -O0
    -g
)