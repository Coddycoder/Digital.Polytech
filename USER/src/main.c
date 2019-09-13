#include <stdio.h>
#include "ini.h"


/*************************************MAIN*********************************/
int main()
{
	initializ();
	while (1)
	{
		if (button_state)
		{
			GPIOD->ODR^=GPIO_ODR_ODR_13;
		}
	}
}
/*************************************END_MAIN****************************/

