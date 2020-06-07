/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/



// causing an action to occur every 1 seconds
// systick->load = 8 000 000 -1
// clock speed = 8 mhz
// 8mhz = 8 000 000 cycles = 1 second
// 1 second = 1000 millisecond
// 8 000 000 = 1000 ms
// 8 000 000/1000 = 1ms
// 8 000 = 1ms --- there fore an action to occur every 1 ms u should  systick->load = 8 000







#include "stm32f0xx.h"
#include "stm32f0308_discovery.h"
			
void SysTick_Handler(void)
{
	GPIOA->ODR ^= 0x20;

}




int main(void)
{
	//disable irq
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= 0x400; //pa5
	SysTick->LOAD = 5*(8000000-1); //reload with number of clocks per milliseconds //at 1hz system clock is 8mhz
	SysTick->VAL = 0;
	SysTick->CTRL = 7;
	// enable irq

	while(1)
	{

	}

}
