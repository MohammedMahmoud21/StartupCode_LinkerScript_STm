# Startup File and Linker Script for STM32F446 MCU

This repository contains the startup file and linker script for the STM32F446 MCU. The startup file has an array of pointers to functions which represent the vector table. The linker script has information about memory sections and memory types in the MCU.

## Startup File

The startup file is responsible for initializing the MCU and jumping to the main function. It also contains the vector table, which is an array of pointers to functions that are called when certain events occur, such as a reset or a hardware interrupt.

The startup file for the STM32F446 MCU is called `Stm32F4_startup`. It is written in assembly language and can be assembled using the `arm-none-eabi-gcc` compiler.

## Linker Script

The linker script is responsible for linking the different sections of the code together and placing them in the correct memory locations. It also contains information about the memory types in the MCU, such as the flash memory, the RAM memory, and the EEPROM memory.

The linker script for the STM32F446 MCU is called `Stm32F4_Ls.ld`. It can be written in either assembly language or C language.

## Usage

To use the startup file and linker script, you will need to download the repository and add the files to your project. You will also need to configure the linker script to match the memory layout of your MCU.

Once you have configured the linker script, you can compile and link your project. The startup file and linker script will be used to initialize the MCU and load your code into the correct memory locations.
