#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#include <stdint.h>

// GPIO Pin Numbers
typedef enum {
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15
} GPIO_Pin;

// GPIO Pin Modes
typedef enum {
    GPIO_MODE_INPUT  = 0,
    GPIO_MODE_OUTPUT = 1,
    GPIO_MODE_ALT    = 2,
    GPIO_MODE_ANALOG = 3
} GPIO_Mode;

// GPIO Port representation
typedef struct {
    volatile uint32_t *MODER;
    volatile uint32_t *IDR;
    volatile uint32_t *ODR;
} GPIO_Port;

void Enable_GPIO_Clock(void);
void GPIO_Config_Pin_Mode(GPIO_Port *port, GPIO_Pin pin, GPIO_Mode mode);
uint8_t GPIO_Read_Pin(GPIO_Port *port, GPIO_Pin pin);
void GPIO_Set_Pin(GPIO_Port *port, GPIO_Pin pin);
void GPIO_Reset_Pin(GPIO_Port *port, GPIO_Pin pin);

// GPIO Ports extern declarations (defined in .c)
extern GPIO_Port GPIOA;
extern GPIO_Port GPIOC;

#endif // LED_BUTTON_H
