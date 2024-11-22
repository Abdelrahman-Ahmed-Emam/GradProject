#include "DIO.h"

// Enable clock for the specific GPIO port
//Used the STM32 RCC->AHB1ENR register to enable GPIO ports
void DIO_PortInitialize(GPIO_TypeDef *Port) {
    if (Port == GPIOA) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    } else if (Port == GPIOB) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    } else if (Port == GPIOC) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    } else if (Port == GPIOD) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    } else if (Port == GPIOE) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    } else if (Port == GPIOF) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
    } else if (Port == GPIOG) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
    } else if (Port == GPIOH) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    }
}

// Configure pin mode (direction and pull configuration)
// Adapted MODER for mode selection (Input, Output, or Analog).
// Configured PUPDR for pull-up, pull-down, or no resistor
void DIO_PinMode(GPIO_TypeDef *Port, uint16_t Pin, uint8_t Direction, uint8_t Type) {
    uint32_t pinPosition = (1UL << Pin);

    // Set pin as INPUT or OUTPUT
    if (Direction == OUTPUT) {
        Port->MODER &= ~(3UL << (Pin * 2)); // Clear mode bits
        Port->MODER |= (1UL << (Pin * 2));  // Set as OUTPUT
    } else if (Direction == INPUT) {
        Port->MODER &= ~(3UL << (Pin * 2)); // Set as INPUT
    } else if (Direction == ANALOG) {
        Port->MODER |= (3UL << (Pin * 2)); // Set as ANALOG
    }

    // Configure pull-up/pull-down resistors
    if (Type == PUR) {
        Port->PUPDR &= ~(3UL << (Pin * 2)); // Clear pull configuration
        Port->PUPDR |= (1UL << (Pin * 2));  // Set pull-up
    } else if (Type == PDR) {
        Port->PUPDR &= ~(3UL << (Pin * 2)); // Clear pull configuration
        Port->PUPDR |= (2UL << (Pin * 2));  // Set pull-down
    } else if (Type == NONE) {
        Port->PUPDR &= ~(3UL << (Pin * 2)); // No pull-up or pull-down
    }
}

// Write value to pin
//We used BSRR for atomic set/reset of GPIO pins.
void DIO_WritePin(GPIO_TypeDef *Port, uint16_t Pin, uint8_t Value) {
    if (Value == 1) {
        Port->BSRR = (1UL << Pin); // Set pin
    } else if (Value == 0) {
        Port->BSRR = (1UL << (Pin + 16)); // Reset pin
    }
}

// Read value from pin
//We used IDR to read the input state of GPIO pins.
uint8_t DIO_ReadPin(GPIO_TypeDef *Port, uint16_t Pin) {
    return (uint8_t)((Port->IDR & (1UL << Pin)) >> Pin);
}
