/* This ADC file is for stm32F446RE nucelo
Last updated 28/10/2024
Files used which is not personal made :tm4c.h
Please include it in your directory so the code run
Files used which is personal made: bitwise_operation.h
*/

#ifndef ADC_H_
#define ADC_H_

#include "stm32f446xx.h"
#include "bitwise_operation.h"

typedef enum 
{
	ADC_PORT_A,/*Pins from 0 to 7 can work as analoge*/
	ADC_PORT_B,/*Only pins 0 and 1 can work analoge*/
	ADC_PORT_C/*Pins from 0 to 5 can work as analoge*/
}ADC_Port_e;

typedef enum 
{
	ADC_Channel_1,/*This Channel pins is from PA0 to PA7 and PB0 to PB1 and PC0 to PC5*/
	ADC_Channel_2,/*This Channel pins is from PA0 to PA7 and PB0 to PB1 and PC0 to PC5*/
	ADC_Channel_3/*This Channel pins is from PA0 to PA3 and PC0 to PC5*/
}ADC_Channel_e;

typedef enum 
{
	cycle_3,
	cycle_15,
	cycle_28,
	cycle_56,
	cycle_84,
	cycle_112,
	cycle_144,
	cycle_480
} ADC_cycle_e;
typedef enum 
{
	ADC_PIN_0,
	ADC_PIN_1,
	ADC_PIN_2,
	ADC_PIN_3,
	ADC_PIN_4,
	ADC_PIN_5,
	ADC_PIN_6,
	ADC_PIN_7,
}ADC_Pins_e;

typedef enum 
{
	ADC_IN_00,
	ADC_IN_01,
	ADC_IN_02,
	ADC_IN_03,
	ADC_IN_04,
	ADC_IN_05,
	ADC_IN_06,
	ADC_IN_07,
	ADC_IN_08,
	ADC_IN_09,
	ADC_IN_10,
	ADC_IN_11,
	ADC_IN_12,
	ADC_IN_13,
	ADC_IN_14,
	ADC_IN_15,
	ADC_IN_16,
}ADC_IN_e; /*16 input pins*/

typedef enum 
{
	resolution_8,
	resolution_9,
	resolution_10,
	resolution_12
}ADC_resolution_e;
typedef struct 
{
	ADC_Port_e Port;
	ADC_Channel_e Channel;
	ADC_Pins_e Pin;
	ADC_IN_e IN;
	ADC_resolution_e resolution;
	ADC_cycle_e cycle;
}ADC_Configuration_s;/*structure for the configuration*/

extern void ADC_init(ADC_Configuration_s *configurations);/*to init the chip*/
extern int ADC_read(ADC_Configuration_s *configurations);/*Read data after sampling*/

#endif