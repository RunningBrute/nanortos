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

## Run with QEMU simulator

Install `sudo apt install qemu-system-arm` and then run simulator with minimal run. For now it is possible to use only one of the supported and simplest board `olimex-stm32-h405`:

```bash
qemu-system-arm -machine help | grep stm32
olimex-stm32-h405    Olimex STM32-H405 (Cortex-M4)
stm32vldiscovery     ST STM32VLDISCOVERY (Cortex-M3)
```

```bash
qemu-system-arm \
    -M olimex-stm32-h405 \
    -kernel firmware.elf \
    -nographic
```

We can run qemu with gdb adding `-S` (CPU start halted) and `-s` (we have possibility to connect to gdb server at `localhost:1234`) options.

```bash
qemu-system-arm \
    -M olimex-stm32-h405 \
    -kernel firmware.elf \
    -S -s \
    -nographic
```

Then we connect from gdb as normal using `target remote localhost:1234` command.