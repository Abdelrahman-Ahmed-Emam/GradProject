/* This DIO file for tivaC 
Last updated 4/10/2024
Files used which is not personal made :tm4c.h
Please include it in your directory so the code run
Files used which is personal made: bitwise_operation.h
*/
#ifndef DIO_H_
#define DIO_H_
#include "bitwise_operation.h"
#include "tm4c.h"
/*Pin output is it High or Low */
typedef enum{
	PIN_HIGH,
	PIN_LOW
}Pin_Status_e;

/*Pin Direction it is output or pull up input or pull down input*/
typedef enum{
	PIN_OUTPUT,
	PIN_INPUT_PULL_UP,
	PIN_INPUT_PULL_DOWN
}Pin_Direction_e;

/*Ports in TivaC weh have From Port A to Port F 
NOTE: PORT C NEED EXTERNAL ACTIVATION FROM TIVA C WEBSITE NOT PREFRED TO USE*/
typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
}Port_Num_e;

/*Pins number in tivaC we have 8 pins*/
typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}Pin_Number_e;

/*Intiallize Port to use it*/
extern void DIO_PortInitialize(Port_Num_e Port);
/*Intiallize Pin to be used as output or input pull-up or pull-down*/
extern void DIO_PinMode(Port_Num_e Port, Pin_Number_e Pin, Pin_Direction_e Direction);
/*Write HIGH or LOW on the pin*/
extern void DIO_WritePin(Port_Num_e Port, Pin_Number_e Pin, Pin_Status_e Value);
/*Read Pin status from a specific port*/
extern Pin_Status_e DIO_ReadPin (Port_Num_e Port, Pin_Number_e Pin);

#endif