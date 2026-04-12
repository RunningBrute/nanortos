set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m4)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CPU_FLAGS "-mcpu=cortex-m4 -mthumb")

set(CMAKE_C_FLAGS "${CPU_FLAGS} -ffreestanding -fno-exceptions -fno-rtti")
set(CMAKE_CXX_FLAGS "${CPU_FLAGS} -ffreestanding -fno-exceptions -fno-rtti")