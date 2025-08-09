#include "digital_input.h"

#define RCC_BASE       0x40023800U
#define GPIOA_BASE     0x40020000U
#define GPIOC_BASE     0x40020800U

#define RCC_AHB1ENR    (*(volatile uint32_t *)(RCC_BASE + 0x30))

// Define GPIO port structs with base addresses
GPIO_Port GPIOA = {
    (volatile uint32_t *)(GPIOA_BASE + 0x00),
    (volatile uint32_t *)(GPIOA_BASE + 0x10),
    (volatile uint32_t *)(GPIOA_BASE + 0x14)
};

GPIO_Port GPIOC = {
    (volatile uint32_t *)(GPIOC_BASE + 0x00),
    (volatile uint32_t *)(GPIOC_BASE + 0x10),
    (volatile uint32_t *)(GPIOC_BASE + 0x14)
};

void Enable_GPIO_Clock(void) {
    RCC_AHB1ENR |= (1 << 0) | (1 << 2);  // Enable GPIOA and GPIOC clocks
}

void GPIO_Config_Pin_Mode(GPIO_Port *port, GPIO_Pin pin, GPIO_Mode mode) {
    *(port->MODER) &= ~(0x3 << (pin * 2));      // Clear mode bits for pin
    *(port->MODER) |=  ((uint32_t)mode << (pin * 2)); // Set mode bits
}

uint8_t GPIO_Read_Pin(GPIO_Port *port, GPIO_Pin pin) {
    return ((*(port->IDR) & (1 << pin)) != 0);
}

void GPIO_Set_Pin(GPIO_Port *port, GPIO_Pin pin) {
    *(port->ODR) |= (1 << pin);
}

void GPIO_Reset_Pin(GPIO_Port *port, GPIO_Pin pin) {
    *(port->ODR) &= ~(1 << pin);
}
