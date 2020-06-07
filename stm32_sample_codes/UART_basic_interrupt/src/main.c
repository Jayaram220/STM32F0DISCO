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

void SystickDelayMS(int n)
{
	SysTick->LOAD = 16000; //reload with number of clocks per milliseconds
	SysTick->VAL = 0; // clear current value register
	SysTick->CTRL = 0x5; // Enable systick

	for(int i = 0; i<n; i++)
	{

		while((SysTick->CTRL & 10000)==0 )
		{
			
		}

	}
	SysTick->CTRL = 0;

}






void LED_Play(int value)
{
	value %= 16;
	for(; value>0 ; value--)
	{
		GPIOA->BSRR = 0X20; // Turn on LED
		SystickDelayMS(500);
		GPIOA->BSRR = 0X00200000; // Turn off LED
		SystickDelayMS(500);
	}
	SystickDelayMS(500);
}


void USART2_Init()
{
				RCC->APB1ENR |= 0X20000;//APB1 bit 17 :USART2
				RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
				//0x48000020
				GPIOA->AFR[0] = 0x0100; // PA2 AF is AF1 SO PA2 is 3rd nibble
				GPIOA->MODER = 0x0020; //set PA2 AF  0010 0000
				USART2->BRR = 480000 / 96; /* (1) Oversampling by 16, 9600 baud OR 0x0683   115200 - 0x008b*/
				USART2->CR1 = 0x0004; // enable RE bit of CR1 register
				USART2->CR1 = 0x0001; // enable ue usart2
				//USART2->CR1 |= 0x2000; // MME mute mode enable ,enable rxr in active mode

}

void USART2_IRQHandler(void)
{
	char c;
	while (USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET);
	c =  USART_ReceiveData(USART2);
	LED_Play(c);
}



int main(void)
{
	//diable_irq
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= 0x400;
	USART2_Init();
	USART2->CR1 = 0x0020; //Enable RX interrupt
	NVIC_EnableIRQ(USART2_IRQn); // enable irq
	while(1)
	{

	}

}
