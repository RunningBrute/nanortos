# NanoRTOS
A minimal, real-time operating system for STM32 Nucleo development boards

## Installation

### Toolchain ARM

Download file from:
`https://developer.arm.com/-/media/Files/downloads/gnu/15.2.rel1/binrel/arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi.tar.xz`

Install:

```bash
cd ~
tar -xf arm-gnu-toolchain-*.tar.xz
mv arm-gnu-toolchain-* arm-toolchain
```

and add to `.bashrc` followinf line:

```bash
export PATH=$HOME/arm-toolchain/bin:$PATH
```

### OpenOCD & Debugger

```bash
sudo apt install openocd
```

Add following line: `ATTRS{idVendor}=="0483", ATTRS{idProduct}=="3748", MODE="0666"`

to file

```bash
sudo nano /etc/udev/rules.d/49-stlink.rules
```

and relead them

```bash
sudo udevadm control --reload-rules
sudo udevadm trigger
```

after `lsusb` if everything is set up correctly, we should see something like:
`Bus 001 Device 006: ID 0483:374b STMicroelectronics ST-LINK/V2.1`

## Build

```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain.cmake
cmake --build .
```

## Flash

```bash
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg
```

## Debug

Run gdb `arm-none-eabi-gdb build/nano_rtos.elf` and connect with board using command: `target remote localhost:3333`