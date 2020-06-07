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
int timestamp;
//@arg GPIO_AF_1: USART2, CEC, Tim3, USART1, IR_OUT,EVENTOUT, I2C1, I2C2, TIM15
int main(void)
{
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
		GPIOA->MODER |= 0x800; //set pa5 to AF
		GPIOA->AFR[0] |= 0x00200000; // set pin AF2 for TIM2
		RCC->APB1RSTR = 1;
		TIM2->PSC = 800-1; //divide by 1600 // 8 000 000 divide by 800 = 10 000
		TIM2->ARR = 10000-1; // 10000/10000 = 1
		TIM2->CCMR1 = 0x330; //set o/p to toggle on match
		TIM2->CCR1 = 0; //set match mode
		TIM2->CCER |= 1; //enable ch1 compare mode
		TIM2->CNT = 0; // clear timer counter
		TIM2->CR1 = 1; //enable TIM2

		// configure pa6 as inout of TIM3 ch1
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
		GPIOA->MODER |= 0x2000; //set pa6to AF tim3
		GPIOA->AFR[0] |= 0x01000000; // set pin AF1 for TIM3

		//config TIM3
		RCC->APB1RSTR |= 2;
		TIM3->PSC = 16000; //divide by 16000
		TIM3->CCMR1 = 0x41; // 0100 0001 set CH1 to capture to every edge
		TIM3->CCER = 1; // enable ch1 compare mode
		TIM2->CR1 = 1;

		while(1)
		{
			while((!TIM3->SR & 2))
			{

			}
			timestamp = TIM2->CCR1;
		}



}
