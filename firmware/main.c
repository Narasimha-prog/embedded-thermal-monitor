#define REG(addr) (*(volatile unsigned int*)(addr))

// Hardware Addresses
#define RCC_AHB1ENR  REG(0x40023830)
#define GPIOD_MODER  REG(0x40020C00)
#define GPIOD_ODR    REG(0x40020C14)
#define UART2_DR     REG(0x40004404)

// --- ADD THIS SECTION FOR THE VECTOR TABLE ---
void Reset_Handler(void);

extern int main(void);

// The Vector Table (Placed at the very start of Flash)
__attribute__((section(".vectors")))
unsigned int *my_vectors[] = {
    (unsigned int *)0x20020000, // 1. Initial Stack Pointer (End of RAM)
    (unsigned int *)Reset_Handler // 2. Reset Handler (Where the CPU starts)
};

void Reset_Handler(void) {
    main(); // Jump to your main function
    while(1); // Security loop
}
// ----------------------------------------------

void uart_print(char *str) {
    while(*str) {
        UART2_DR = (*str++); 
    }
}

int main(void) {
    RCC_AHB1ENR |= (1 << 3); 
    GPIOD_MODER |= (1 << 24);

    uart_print("System Booting... Thermal Monitor Active\n");

    while(1) {
        GPIOD_ODR ^= (1 << 12); 
        for(int i = 0; i < 500000; i++) { __asm__("nop"); }
    }
}