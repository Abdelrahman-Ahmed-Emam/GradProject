#include "uart.h" 
#include "esp32.h" 
#include "stm32f446xx.h"

int main(void) {
    // Initialize UART for communication with ESP32
    UART_Init();

    // Initialize ESP32 module
    ESP32_Init();

    // Test sending AT command and receiving response
    char command[] = "AT\r\n";
    char response[50];

    // Send AT command to ESP32
    ESP32_SendCommand(command);

    // Receive response from ESP32
    ESP32_ReceiveResponse(response, sizeof(response));

    while (1) {
        // Main program loop
    }
}