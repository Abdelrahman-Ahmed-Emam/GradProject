#include "DIO.h"
/*Intiallize Port to use it*/
 void DIO_PortInitialize(Port_Num_e Port)
 {
	 switch(Port)
        { /*Port A intiallization all pins*/
          case PORT_A:
            SYSCTL_RCGCGPIO_R |= 0X01;/*Open clock for the port*/
            while((SYSCTL_PRGPIO_R & 0X01) == 0);/*we wait until make sure clock for port is activated*/
            GPIO_PORTA_LOCK_R = 0X4C4F434B; /*to unlock GPIOCR (commit) register value in this register is in datasheet*/
            /*To determine which bits of GPIOAFSEL,GPIOPUR,GPIOPDR,GPIODEN are commited
					when a write to these registers is performed*/
						GPIO_PORTA_CR_R = 0XFF;
              break;
					/*Port B intiallization all pins*/
          case PORT_B:
            SYSCTL_RCGCGPIO_R |= 0X02;/*Open clock for the port*/
            while((SYSCTL_PRGPIO_R & 0X02) == 0);/*to unlock GPIOCR (commit) register value is in datasheet*/
            GPIO_PORTB_LOCK_R = 0X4C4F434B;/*to unlock GPIOCR (commit) register value in this register is in datasheet*/
            /*To determine which bits of GPIOAFSEL,GPIOPUR,GPIOPDR,GPIODEN are commited
					when a write to these registers is performed*/
						GPIO_PORTB_CR_R = 0XFF;
              break;
					/*Port C intiallization all pins*/
          case PORT_C:
            SYSCTL_RCGCGPIO_R |= 0X04;/*Open clock for the port*/
            while((SYSCTL_PRGPIO_R & 0X04) == 0);/*to unlock GPIOCR (commit) register value is in datasheet*/
            GPIO_PORTC_LOCK_R = 0X4C4F434B;/*to unlock GPIOCR (commit) register value in this register is in datasheet*/
					/*To determine which bits of GPIOAFSEL,GPIOPUR,GPIOPDR,GPIODEN are commited
					when a write to these registers is performed*/
            GPIO_PORTC_CR_R = 0XFF;
              break;
					/*Port D intiallization all pins*/
          case PORT_D:
            SYSCTL_RCGCGPIO_R |= 0X08;/*Open clock for the port*/
            while((SYSCTL_PRGPIO_R & 0X08) == 0);/*to unlock GPIOCR (commit) register value is in datasheet*/
            GPIO_PORTD_LOCK_R = 0X4C4F434B;/*to unlock GPIOCR (commit) register value in this register is in datasheet*/
					/*To determine which bits of GPIOAFSEL,GPIOPUR,GPIOPDR,GPIODEN are commited
					when a write to these registers is performed*/
            GPIO_PORTD_CR_R = 0XFF;
              break;
					/*Port E intiallization all pins*/
          case PORT_E:
            SYSCTL_RCGCGPIO_R |= 0X10;/*Open clock for the port*/
            while((SYSCTL_PRGPIO_R & 0X10) == 0);/*to unlock GPIOCR (commit) register value is in datasheet*/
            GPIO_PORTE_LOCK_R = 0X4C4F434B;/*to unlock GPIOCR (commit) register value in this register is in datasheet*/
					/*To determine which bits of GPIOAFSEL,GPIOPUR,GPIOPDR,GPIODEN are commited
					when a write to these registers is performed*/
            GPIO_PORTE_CR_R = 0XFF;
              break;
					/*Port F intiallization all pins*/
          case PORT_F:
            SYSCTL_RCGCGPIO_R |= 0X20;/*Open clock for the port*/
            while((SYSCTL_PRGPIO_R & 0X20) == 0);/*to unlock GPIOCR (commit) register value is in datasheet*/
            GPIO_PORTF_LOCK_R = 0X4C4F434B;/*to unlock GPIOCR (commit) register value in this register is in datasheet*/
					/*To determine which bits of GPIOAFSEL,GPIOPUR,GPIOPDR,GPIODEN are commited
					when a write to these registers is performed*/
            GPIO_PORTF_CR_R = 0XFF;
              break;
        }
 }
 /*************************************************************************************************************************************************/
/*Intiallize Pin to be used as output or input pull-up or pull-down*/
 void DIO_PinMode(Port_Num_e Port, Pin_Number_e Pin, Pin_Direction_e Direction)
 {
	 switch(Port)
        {
          case PORT_A:
             Set_Bit(GPIO_PORTA_DEN_R,Pin);/*Make this pin work as a DIO*/
             if (Direction == PIN_OUTPUT)
               Set_Bit(GPIO_PORTA_DIR_R , Pin);
             
             else if( Direction == PIN_INPUT_PULL_UP)
							 {
                Clear_Bit(GPIO_PORTA_DIR_R , Pin);
						  	Set_Bit(GPIO_PORTA_PUR_R,Pin);
						   }
             else if(Direction == PIN_INPUT_PULL_DOWN)
             {
							  Clear_Bit(GPIO_PORTA_DIR_R , Pin);
               Set_Bit(GPIO_PORTA_PDR_R,Pin);
             }
             break;
			/*******************************/
          case PORT_B:
             Set_Bit(GPIO_PORTB_DEN_R , Pin);/*Make this pin work as a DIO*/
             if (Direction == PIN_OUTPUT)
               Set_Bit(GPIO_PORTB_DIR_R , Pin);
             else if( Direction == PIN_INPUT_PULL_UP)
             {
               Clear_Bit(GPIO_PORTB_DIR_R , Pin);
							 Set_Bit(GPIO_PORTB_PUR_R,Pin);
             }
             else if(Direction == PIN_INPUT_PULL_DOWN)
             {
							  Clear_Bit(GPIO_PORTB_DIR_R , Pin);
               Set_Bit(GPIO_PORTB_PDR_R,Pin);
             }
              break;
			/*******************************/
          case PORT_C:
             Set_Bit(GPIO_PORTC_DEN_R , Pin);/*Make this pin work as a DIO*/
             if (Direction == PIN_OUTPUT)
               Set_Bit(GPIO_PORTC_DIR_R , Pin);
             else if( Direction == PIN_INPUT_PULL_UP)
             {
               Clear_Bit(GPIO_PORTC_DIR_R , Pin);
							 Set_Bit(GPIO_PORTC_PUR_R,Pin);
             }
             else if(Direction == PIN_INPUT_PULL_DOWN)
             {
							  Clear_Bit(GPIO_PORTC_DIR_R , Pin);
               Set_Bit(GPIO_PORTC_PDR_R,Pin);
             }
              break;
			 /*******************************/
          case PORT_D:
             Set_Bit(GPIO_PORTD_DEN_R , Pin);/*Make this pin work as a DIO*/
             if (Direction == PIN_OUTPUT)
               Set_Bit(GPIO_PORTD_DIR_R , Pin);
             else if( Direction == PIN_INPUT_PULL_UP)
             {
               Clear_Bit(GPIO_PORTD_DIR_R , Pin);
							 Set_Bit(GPIO_PORTD_PUR_R,Pin);
             }
             else if(Direction == PIN_INPUT_PULL_DOWN)
             {
							 Clear_Bit(GPIO_PORTD_DIR_R , Pin);
               Set_Bit(GPIO_PORTD_PDR_R,Pin);
             }              
             break;
			 /*******************************/
          case PORT_E:
             Set_Bit(GPIO_PORTE_DEN_R , Pin);/*Make this pin work as a DIO*/
             if (Direction == PIN_OUTPUT)
               Set_Bit(GPIO_PORTE_DIR_R , Pin);
             else if( Direction == PIN_INPUT_PULL_UP)
             {
               Clear_Bit(GPIO_PORTE_DIR_R , Pin);
							  Set_Bit(GPIO_PORTE_PUR_R,Pin);
             }
             else if(Direction == PIN_INPUT_PULL_DOWN)
             {
							 Clear_Bit(GPIO_PORTE_DIR_R , Pin);
               Set_Bit(GPIO_PORTE_PDR_R,Pin);
             }
             break;
			 /*******************************/
          case PORT_F:
             Set_Bit(GPIO_PORTF_DEN_R , Pin);/*Make this pin work as a DIO*/
             if (Direction == PIN_OUTPUT)
               Set_Bit(GPIO_PORTF_DIR_R , Pin);
             else if( Direction == PIN_INPUT_PULL_UP)
             {
               Clear_Bit(GPIO_PORTF_DIR_R , Pin);
							 Set_Bit(GPIO_PORTF_PUR_R,Pin);
             }
             else if(Direction == PIN_INPUT_PULL_UP)
             {
							 Clear_Bit(GPIO_PORTF_DIR_R , Pin);
               Set_Bit(GPIO_PORTF_PDR_R,Pin);
             }
             break;
        }
 }
 /*************************************************************************************************************************************************/
/*Write HIGH or LOW on the pin*/
 void DIO_WritePin(Port_Num_e Port, Pin_Number_e Pin, Pin_Status_e Value)
 {
	 switch(Port)
        {
          case PORT_A:
             if (Value == PIN_HIGH)
               Set_Bit(GPIO_PORTA_DATA_R , Pin);
             else if (Value == PIN_LOW)
               Clear_Bit(GPIO_PORTA_DATA_R , Pin);
             break;
			 /*******************************/
          case PORT_B:
             if (Value == PIN_HIGH)
               Set_Bit(GPIO_PORTB_DATA_R , Pin);
             else if (Value == PIN_LOW)
               Clear_Bit(GPIO_PORTB_DATA_R , Pin);
              break;
			 /*******************************/
          case PORT_C:
             if (Value == PIN_HIGH)
               Set_Bit(GPIO_PORTC_DATA_R , Pin);
             else if (Value == PIN_LOW)
               Clear_Bit(GPIO_PORTC_DATA_R , Pin);
              break;
			 /*******************************/
          case PORT_D:
             if (Value == PIN_HIGH)
               Set_Bit(GPIO_PORTD_DATA_R , Pin);
             else if (Value == PIN_LOW)
               Clear_Bit(GPIO_PORTD_DATA_R , Pin);
             break;
			 /*******************************/
          case PORT_E:
             if (Value == PIN_HIGH)
               Set_Bit(GPIO_PORTE_DATA_R , Pin);
             else if (Value == PIN_LOW)
               Clear_Bit(GPIO_PORTE_DATA_R , Pin);
             break;
			 /*******************************/
          case PORT_F:
             if (Value == PIN_HIGH)
               Set_Bit(GPIO_PORTF_DATA_R , Pin);
             else if (Value == PIN_LOW)
               Clear_Bit(GPIO_PORTF_DATA_R , Pin);
             break;
        }
 }
 /*************************************************************************************************************************************************/
/*Read Pin status from a specific port*/
 Pin_Status_e DIO_ReadPin (Port_Num_e Port, Pin_Number_e Pin)
 {
	 switch(Port)
        {
          case PORT_A:
             return Get_Bit((int)GPIO_PORTA_DATA_R, Pin);
              break;
					
          case PORT_B:
              return Get_Bit((int)GPIO_PORTB_DATA_R, Pin);
              break;
					
          case PORT_C:
              return Get_Bit((int)GPIO_PORTC_DATA_R, Pin);
              break;
					
          case PORT_D:
              return Get_Bit((int)GPIO_PORTD_DATA_R, Pin);
              break;
					
          case PORT_E:
              return Get_Bit((int)GPIO_PORTE_DATA_R, Pin);
              break;
					
          case PORT_F:
              return Get_Bit((int)GPIO_PORTF_DATA_R, Pin);
              break;
        }
   return -1;
 }