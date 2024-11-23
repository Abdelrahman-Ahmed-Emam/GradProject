#ifndef DIO_H
#define DIO_H
#define INPUT 0
#define OUTPUT 1
#define PUR 2
#define PDR 3
#define ANALOG 4
#define NONE 5
#include "stm32f446xx.h"

// Note: Instead of char Port, STM32 uses the GPIO_TypeDef * structure for referencing ports (GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH)
//So pins are passed as a bit position (0–15). for Ports A,B and C

// Port initialization
extern void DIO_PortInitialize(GPIO_TypeDef *Port); 

// Define pin direction (INPUT/OUTPUT) and pull configuration (Pull-up/Pull-down/Analog)
extern void DIO_PinMode(GPIO_TypeDef *Port, uint16_t Pin, uint8_t Direction, uint8_t Type);

// Write to a pin (HIGH or LOW)
extern void DIO_WritePin(GPIO_TypeDef *Port, uint16_t Pin, uint8_t Value);

// Read from a pin
extern uint8_t DIO_ReadPin(GPIO_TypeDef *Port, uint16_t Pin);

#endif
