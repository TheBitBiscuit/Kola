# Kola
Retrofitting an old soda machine into a smart soda machine!

## Intro
This project is using a Dixie-Narco 240/138 6 Slot Soda machine.  It is basic and lacks a central controller board and
uses general electrical/mechanical logic to operate coin operation and vending.

## Prerequisites
* ### Microcontroller
  * Raspberry Pi Pico-W (RP2040 + Infineon CYW4343)
* ### ARM Toolchain
  *  MacOS (Homebrew)
      ```zsh
     brew update
     brew tap armmbed/formulae
     brew install armmbed/formulae/arm-none-eabi-gcc cmake
      ```
* ### Pico-SDK
  * Will automatically pull the pico-sdk when cmake files are generated.  No need to add specific `$PATH` definitions.

## Building and Compiling
  * Terminal
    ```zsh
    cd <root-of-project> # Navigate to root of the project
    mkdir build
    cd build
    cmake ..
    make
      ```

## Flashing and Installation
1. While holding down the `BOOTSEL` button, plug the Pico-W into a USB port.
2. The Pico-W will appear as a mass storage device in your file manager.
3. Drag-and-drop the `kola.uf2` file from your `build` folder to the Pico, as you would if you were moving a file to a flash drive.
4. The Pico-W will automatically reboot, and start running the Kola firmware.
5. Unplug the Pico-W from the USB cable and transfer to the `KOLA-BOARD` inside the soda machine.
6. With the soda machine connected to power, flip `KOLA-BOARD` power switch to `ON` position.