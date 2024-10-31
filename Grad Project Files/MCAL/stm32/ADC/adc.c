#include "adc.h"
typedef struct 
{
	int SMP0:3;
	int SMP1:3;
	int SMP2:3;
	int SMP3:3;
	int SMP4:3;
	int SMP5:3;
	int SMP6:3;
	int SMP7:3;
	int SMP8:3;
	int SMP9:3;	
}sample_register_3_divide_s;


void ADC_pin_configuration(ADC_Configuration_s *configurations);/*configure pins*/
/*to init the chip*/
void ADC_init(ADC_Configuration_s *configurations)
{	
	ADC_TypeDef * ADC_sample=0; /*variable holding ADC sample register either register 1 or 2*/
	ADC_TypeDef * ADC_control=0; /*variable holding ADC CONTROL register either register 1 or 2*/
	sample_register_3_divide_s *sample_register=0;
	switch(configurations->Channel)
	{

	case ADC_Channel_1:
		/*open clock*/
		Set_Bit(RCC->APB2ENR,8);
		while(Get_Bit(RCC->APB2ENR,8)==0){}/*wait for the clock to start*/
		ADC_sample=ADC1;
		ADC_control=ADC1;
		break;
	case ADC_Channel_2:
		Set_Bit(RCC->APB2ENR,9);
		while(Get_Bit(RCC->APB2ENR,9)==0){}/*wait for the clock to start*/
		ADC_sample=ADC2;
			ADC_control=ADC2;
		break;
	case ADC_Channel_3:
		Set_Bit(RCC->APB2ENR,10); 
		while(Get_Bit(RCC->APB2ENR,10)==0){}/*wait for the clock to start*/
		ADC_sample=ADC3;		
    ADC_control=ADC3;			
		break;
	}


	switch(configurations->IN)
	{
	case ADC_IN_00:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP0=configurations->cycle;
		break;
	case ADC_IN_01:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP1=configurations->cycle;
		break;
	case ADC_IN_02:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP2=configurations->cycle;
		break;
	case ADC_IN_03:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP3=configurations->cycle;
		break;
	case ADC_IN_04:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP4=configurations->cycle;
		break;
	case ADC_IN_05:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP5=configurations->cycle;
		break;
	case ADC_IN_06:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP6=configurations->cycle;
		break;
	case ADC_IN_07:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP7=configurations->cycle;
		break;
	case ADC_IN_08:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP8=configurations->cycle;
		break;
	case ADC_IN_09:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR2);
		sample_register->SMP9=configurations->cycle;
		break;
	case ADC_IN_10:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR1);
		sample_register->SMP0=configurations->cycle;
		break;
	case ADC_IN_11:	
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR1);
		sample_register->SMP0=configurations->cycle;
		break;
	case ADC_IN_12:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR1);
		sample_register->SMP0=configurations->cycle;
		break;
	case ADC_IN_13:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR1);
		sample_register->SMP0=configurations->cycle;
		break;
	case ADC_IN_14:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR1);
		sample_register->SMP0=configurations->cycle;
		break;
	case ADC_IN_15:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR1);
		sample_register->SMP0=configurations->cycle;
		break;
	case ADC_IN_16:
		sample_register=(sample_register_3_divide_s*)(& ADC_sample->SMPR1);
		sample_register->SMP0=configurations->cycle;
		break;
	}

	switch (configurations->resolution)
	{
		case resolution_10:
			Set_Bit(ADC_control->CR1,24);
			Clear_Bit(ADC_control->CR1,25);
			break;
		case resolution_12:
				Clear_Bit(ADC_control->CR1,24);
			Clear_Bit(ADC_control->CR1,25);
			break;
		case resolution_8:
				Set_Bit(ADC_control->CR1,25);
			Clear_Bit(ADC_control->CR1,24);
			break;
		case resolution_9:
				Set_Bit(ADC_control->CR1,24);
			Set_Bit(ADC_control->CR1,25);
			break;
	}
	ADC_control->CR2|=0x1;
	ADC_pin_configuration(configurations);
}


void ADC_pin_configuration(ADC_Configuration_s *configurations)
{
	GPIO_TypeDef* GPIO_Moder;
	switch(configurations->Port)
	{
		case ADC_PORT_A:
			GPIO_Moder= GPIOA;
			break;
		case ADC_PORT_B:
				GPIO_Moder= GPIOB;
			break;
		case ADC_PORT_C:
				GPIO_Moder= GPIOC;
			break;
	}
	
	switch(configurations->Pin)
	{
		case ADC_PIN_0:
			GPIO_Moder->MODER|=0x3;
			break;
		case ADC_PIN_1:
				GPIO_Moder->MODER|=0xC;
			break;
		case ADC_PIN_2:
				GPIO_Moder->MODER|=0x30;
			break;
		case ADC_PIN_3:
				GPIO_Moder->MODER|=0xC0;
			break;
		case ADC_PIN_4:
				GPIO_Moder->MODER|=0x300;
			break;
		case ADC_PIN_5:
				GPIO_Moder->MODER|=0xC00;
			break;
		case ADC_PIN_6:
				GPIO_Moder->MODER|=0x3000;
			break;
		case ADC_PIN_7:
				GPIO_Moder->MODER|=0xC000;
      break;			
	}
}


int ADC_read(ADC_Configuration_s *configurations)/*Read data after sampling*/
{
	static int channels_used=1;
	ADC_TypeDef * ADC_control=0;  
	ADC_TypeDef * ADC_SQR3=0; 
	ADC_TypeDef * ADC_SQR1=0; 
	ADC_TypeDef * ADC_SR=0; 
	int data=0;
	switch(configurations->Channel)
	{
	case ADC_Channel_1:
		ADC_control=ADC1;
		ADC_SQR3=ADC1; 
		ADC_SQR1=ADC1; 
	ADC_SR=ADC1;
		break;
	case ADC_Channel_2:
				ADC_control=ADC2;
		ADC_SQR3=ADC2; 
		ADC_SQR1=ADC2; 
	ADC_SR=ADC2;
		break;
	case ADC_Channel_3:
   	ADC_control=ADC3;
		ADC_SQR3=ADC3; 
		ADC_SQR1=ADC3;
ADC_SR=ADC3; 	
		break;
	}
	
	switch(configurations->IN)
	{
	case ADC_IN_00:
		ADC_SQR1->SQR1|=0;
		break;
	case ADC_IN_01:
		ADC_SQR1->SQR1|=1;
		break;
	case ADC_IN_02:
			ADC_SQR1->SQR1|=2;
		break;
	case ADC_IN_03:
			ADC_SQR1->SQR1|=3;
		break;
	case ADC_IN_04:
			ADC_SQR1->SQR1|=4;
		break;
	case ADC_IN_05:
		ADC_SQR1->SQR1|=5;
		break;
	case ADC_IN_06:
		ADC_SQR1->SQR1|=6;
		break;
	case ADC_IN_07:
		ADC_SQR1->SQR1|=7;
		break;
	case ADC_IN_08:
			ADC_SQR1->SQR1|=8;
		break;
	case ADC_IN_09:
			ADC_SQR1->SQR1|=9;
		break;
	case ADC_IN_10:
			ADC_SQR1->SQR1|=10;
		break;
	case ADC_IN_11:	
		ADC_SQR1->SQR1|=11;
		break;
	case ADC_IN_12:
		ADC_SQR1->SQR1|=12;
		break;
	case ADC_IN_13:
		ADC_SQR1->SQR1|=13;
		break;
	case ADC_IN_14:
		ADC_SQR1->SQR1|=14;
		break;
	case ADC_IN_15:
			ADC_SQR1->SQR1|=15;
		break;
	case ADC_IN_16:
		ADC_SQR1->SQR1|=16;
		break;
	}
	ADC_SQR3->SQR3|=channels_used;
	channels_used++;
	ADC_control->CR2|=0x40000000;/*START CONVERSION*/
	
	while(!(ADC_SR->SR&2)){}
		data=ADC_SR->DR;
	return data;
}