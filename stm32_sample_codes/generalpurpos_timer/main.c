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
//GPIO_AF_2: TIM2, TIM1, EVENTOUT, TIM16, TIM17

int main(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= 0x400; //pa5

	//TIM2 config
	RCC->APB1RSTR = 1;
	TIM2->PSC = 1600-1; //divide by 1600 // 16 000 000 divide by 1600 = 10 000
	TIM2->ARR = 10000-1; // 10000/10000 = 1
	TIM2->CNT = 0; // clear timer counter
	TIM2->CR1 = 1; //enable TIM2

	while(1)
	{
		while((!TIM2->SR & 1))
		{

		}
		TIM2->SR &= ~1;
		GPIOA->ODR ^= 0X20;

	}



}
