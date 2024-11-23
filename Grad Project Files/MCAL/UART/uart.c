#include "uart.h"
#include "DIO.h"
#include "stm32f446xx.h"

//UART_HandleTypeDef huart2;

// Initialize UART (USART2)
void UART_Init(void) {
    // Enable GPIO port clock for GPIOA
    DIO_PortInitialize(GPIOA); //This function call initializes the GPIO port for GPIOA

    // Enable USART2 clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    //This line enables the clock for the USART2 peripheral by setting the corresponding bit in the APB1ENR register of the Reset and Clock Control (RCC) peripheral

    // This configures pin PA2 as an output pin to be used as an alternate function (USART2 TX)
    DIO_PinMode(GPIOA, 2, OUTPUT, NONE); // Set PA2 as output for alternate function
    GPIOA->AFR[0] |= (7 << (2 * 4));     // Set PA2 alternate function to AF7 (USART2_TX)

    // This configures pin PA3 as an input pin to be used as an alternate function (USART2 RX)
    DIO_PinMode(GPIOA, 3, INPUT, NONE);  // Set PA3 as input for alternate function
    GPIOA->AFR[0] |= (7 << (3 * 4));     // Set PA3 alternate function to AF7 (USART2_RX)

    // Configure USART2: 115200 baud rate, 8 data bits, 1 stop bit, no parity
    USART2->BRR = 0x008B; /* 115200 baud @ 16 MHz */ // Set baud rate
    USART2->CR1 |= USART_CR1_UE; // Enable USART
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE; // Enable transmitter and receiver
}


// Transmit data
void UART_Transmit(uint8_t *data, uint16_t size) {
    for (uint16_t i = 0; i < size; i++) {
        while (!(USART2->SR & USART_SR_TXE)); //Waits until the transmit buffer is empty before sending data
        USART2->DR = data[i]; // Send data byte at index i over UART
    }
    while (!(USART2->SR & USART_SR_TC)); // Waits for the transmission of the current byte to complete.
}

// Receive data
void UART_Receive(uint8_t *data, uint16_t size) {
    for (uint16_t i = 0; i < size; i++) {
        while (!(USART2->SR & USART_SR_RXNE)); // Waits until data is received before reading it
        data[i] = USART2->DR; // Reads the received data byte from the USART2 data register
    }
}
