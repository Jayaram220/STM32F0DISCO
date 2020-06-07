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

void delayMs(int delay)
{
	int i;
	for(i = 0; i < delay*1000; i++)
	{

	}
}


void USART2_Init(void)
{
		RCC->APB1ENR |= 0X20000;//APB1 bit 17 :USART2
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
		GPIOA->AFR[0] = 0x1000; // PA2 AF is AF1 SO PA3 is 4th nibble
		GPIOA->MODER = 0x0080; //set PA3 AF  1000 0000
		USART2->BRR = 480000 / 96; /* (1) Oversampling by 16, 9600 baud OR 0x0683 */
		USART2->CR1 = 0x0004; // enable RE bit of CR1 register
		USART2->CR1 |= 0x2000; // MME mute mode enable ,enable rxr in active mode

}

char USART_Read(void)
{
	//Wait while TX buffer is empty
	while(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) != SET); // instead of ; u can use {}
	return USART2->RDR;
}

void LED_Play(int value)
{
	value %= 16;
	for(; value>0 ; value--)
	{
		GPIOA->BSRR = 0X20; // Turn on LED
		delayMs(500);
		GPIOA->BSRR = 0X00200000; // Turn off LED
		delayMs(500);
	}
	delayMs(500);
}



int main(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // enable clock for port A
	GPIOA->MODER = 0x400; //set PA5 o/p  0100 0000 0000
	USART2_Init();
	char ch;

	while(1)
	{
		ch = USART_Read();
		LED_Play(ch);
	}
}
