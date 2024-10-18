#ifndef STEPPER_TB6600_H_
#define STEPPER_TB6600_H_

#include "General_Functions.h"

/*include your DIO for your own microcontroller*/
#include "DIO.h"

#define DELAY 10

typedef struct {
	Pin_Number_e enable_pin;
	Pin_Number_e direction_pin;
	Pin_Number_e pulse_pin;
	Port_Num_e Port;
}Stepper_motor_handler_s;

typedef enum
{
	clockwise,
	anticlockwise
}Stepper_motor_direction_e;

extern void stepper_init(Stepper_motor_handler_s *configurations);

extern void Move_steps(Stepper_motor_handler_s *stepperMotor ,
	Stepper_motor_direction_e direction ,unsigned int steps);


#endif