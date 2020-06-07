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
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= 0x800; //set pa5 to AF
	GPIOA->AFR[0] |= 0x00200000; // set pin AF2 for TIM2

	RCC->APB1RSTR = 1;
		TIM2->PSC = 800-1; //divide by 1600 // 8 000 000 divide by 800 = 10 000
		TIM2->ARR = 10000-1; // 10000/10000 = 1
		TIM2->CCMR1 = 0x30; //set o/p to toggle on match
		TIM2->CCR1 = 0; //set match mode
		TIM2->CCER |= 1; //enable ch1 compare mode
		TIM2->CNT = 0; // clear timer counter
		TIM2->CR1 = 1; //enable TIM2

		while(1)
		{

		}

}
