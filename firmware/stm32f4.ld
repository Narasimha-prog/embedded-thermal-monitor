/* Define the memory boundaries of the STM32F4 */
MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Define how the "Sections" are placed in memory */
SECTIONS
{
    .text :
    {
        KEEP(*(.vectors)) /* Place the Vector Table FIRST */
        *(.text*)         /* Place all other code (main, uart_print) here */
        *(.rodata*)       /* Place constant strings like "System Booting..." */
    } > FLASH
}