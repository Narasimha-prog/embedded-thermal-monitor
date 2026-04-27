# Toolchain definition
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# Compiler flags: Cortex-M4, Thumb mode, and Debug symbols
CFLAGS = -mcpu=cortex-m4 -mthumb -g -O0

# Linker flags: Use our custom .ld script
LDFLAGS = -T stm32f4.ld -nostdlib

all: firmware.bin

firmware.elf: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -o firmware.elf

# Convert ELF to a raw binary for the simulator
firmware.bin: firmware.elf
	$(OBJCOPY) -O binary firmware.elf firmware.bin

clean:
	rm -f *.elf *.bin