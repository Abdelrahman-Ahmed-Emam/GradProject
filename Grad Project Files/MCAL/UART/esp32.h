#ifndef ESP32_H
#define ESP32_H

#include "stm32f446xx.h"

// Function prototypes
void ESP32_Init(void); // Initialize ESP32
void ESP32_SendCommand(const char *command); // Send AT command to ESP32
void ESP32_ReceiveResponse(char *response, uint16_t size); // Receive ESP32 response

#endif // ESP32_H
