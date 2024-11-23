#include "uart.h"
#include "esp32.h"

// Initialize ESP32 (ensure UART is ready)
void ESP32_Init(void) {
    UART_Init(); // Initialize UART for communication with ESP32
}

// Send AT command to ESP32
/*
 "AT command" typically refers to sending a specific command string that starts with
 the characters "AT" followed by additional characters that define the command or query
 we want to send to the module.
*/
void ESP32_SendCommand(const char *command) {
    UART_Transmit((uint8_t *)command, strlen(command));
}

// Receive ESP32 response
void ESP32_ReceiveResponse(char *response, uint16_t size) {
    UART_Receive((uint8_t *)response, size);
}