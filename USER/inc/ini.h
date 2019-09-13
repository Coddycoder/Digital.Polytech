#ifndef _INI_H_
#define _INI_H_
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
void initializ (void);
void SysTick_Handler(void);

uint8_t button_chatter();
extern uint8_t count;
extern uint8_t button_state;
#endif
