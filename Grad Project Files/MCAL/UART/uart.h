#ifndef UART_H
#define UART_H

#include "stm32f446xx.h"

// Function prototypes
void UART_Init(void); // Initialize UART
void UART_Transmit(uint8_t *data, uint16_t size); // Transmit data
void UART_Receive(uint8_t *data, uint16_t size); // Receive data

#endif 
