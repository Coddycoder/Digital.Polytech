#include "ini.h"
 uint8_t count;
 uint8_t button_state;
void initializ (void)
{
/*****************************************************/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
/******************************************************/
	GPIO_InitTypeDef 			GPIO_INI_t;
	GPIO_INI_t.GPIO_Pin 	= GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_INI_t.GPIO_Mode 	= GPIO_Mode_OUT;
	GPIO_INI_t.GPIO_OType = GPIO_OType_PP;
	GPIO_INI_t.GPIO_Speed = GPIO_Low_Speed;
	GPIO_INI_t.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_INI_t);
//========================================================
	GPIO_InitTypeDef 				 GPIO_BOTTON_t;
	GPIO_BOTTON_t.GPIO_Pin   = GPIO_Pin_0;
	GPIO_BOTTON_t.GPIO_Mode	 = GPIO_Mode_IN;
	GPIO_BOTTON_t.GPIO_OType =GPIO_OType_PP;
	GPIO_BOTTON_t.GPIO_PuPd  =GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_BOTTON_t);
//========================================================
	SysTick_Config(SystemCoreClock/999);
//========================================================
}
/************************************************************/
void SysTick_Handler(void)
{
	button_chatter ();
}

/************************************************************/
 inline static uint8_t button_chatter ()
{  
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
	{
		if (count<3) 
		{
		 count++;
		}
		else
		{	
			if (button_state==0)
			{
				button_state= 1;
				return button_state;
			}
		}
	}
	else
	{
		if (count>0)
		{
			count--;
		}
		else 
		{
			button_state= 0;
		}
	}
	return button_state;
}
/**********************************************************/