/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include "stm32f0308_discovery.h"


int main(void)
{
	RCC->AHBENR |= 524288; // enable GPIOC clock enable 19th bit
	GPIOC->MODER |= 0x10000;    // 00|00 00|00 00|00 00|01 00|00 00|00 00|00 00|00
	//while(1)
	//{
	GPIOC->ODR = 0x100;			 // 0000 0000 0000 0000 0000 0001 0000 0000
	//}
}



/*
int main(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // enable GPIOA clock (131072) enable 17 th bit
		GPIOA->MODER |= 0x01;    // 00|00 00|00 00|00 00|01 00|00 00|00 00|00 00|00
		//while(1)
		//{
		GPIOA->ODR = 0x01;			 // 0000 0000 0000 0000 0000 0001 0000 0000
		//}

}

*/
