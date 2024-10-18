#include "stepperTB6600.h"

void stepper_init(Stepper_motor_handler_s *configurations)
{
	DIO_PortInitialize(configurations->Port);
	DIO_PinMode(configurations->Port,configurations->direction_pin,PIN_OUTPUT);
	DIO_PinMode(configurations->Port,configurations->enable_pin,PIN_OUTPUT);
	DIO_PinMode(configurations->Port,configurations->pulse_pin,PIN_OUTPUT);
	DIO_WritePin(configurations->Port,configurations->enable_pin,PIN_HIGH);
}

void Move_steps(Stepper_motor_handler_s *stepperMotor ,
	Stepper_motor_direction_e direction ,unsigned int steps)
	{
		if(direction==clockwise)
		{
			DIO_WritePin(stepperMotor->Port,stepperMotor->direction_pin,PIN_LOW);
		}
		else
			DIO_WritePin(stepperMotor->Port,stepperMotor->direction_pin,PIN_HIGH);
		unsigned int i=0;
		for(;i<steps;i++)
		{
			DIO_WritePin(stepperMotor->Port,stepperMotor->pulse_pin,PIN_HIGH);
			delya_ms(DELAY);
			DIO_WritePin(stepperMotor->Port,stepperMotor->pulse_pin,PIN_LOW);
			delya_ms(DELAY);
		}
	}