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

volatile int pb10_counter;
volatile int pc13_counter;

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




void EXTI4_15_IRQhandler(void)
{
	//pc13 switch
	if(EXTI->PR == 0x2000)
	{
		GPIOA->BSRR = 0x20; // turn on led
			SystickDelayMS(300);
			GPIOA->BSRR = 0x002;// turn off led
			SystickDelayMS(300);


		pc13_counter++;
		EXTI->PR = 0x2000; // clear interrupt pending flag
	}
	// pb10 switch
	else if(EXTI->PR == 0x400)
	{
		GPIOA->BSRR = 0x20; // turn on led
			SystickDelayMS(300);
			GPIOA->BSRR = 0x002;// turn off led
			SystickDelayMS(300);
			GPIOA->BSRR = 0x20; // turn on led
				SystickDelayMS(300);
				GPIOA->BSRR = 0x002;// turn off led
				SystickDelayMS(300);

		pb10_counter++;
		EXTI->PR = 0x400; // clear interrupt pending flag
	}


}






int main(void)
{

		RCC->AHBENR |= RCC_AHBENR_GPIOAEN; //enable clock acess to porta
		RCC->AHBENR |= RCC_AHBENR_GPIOBEN; //enable clock acess to portb
		RCC->AHBENR |= RCC_AHBENR_GPIOCEN; //enable clock acess to portc

		RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // Enable syscfg clock
		GPIOA->MODER |= 0x400;    // 00|00 00|00 00|00 00|00 00|00 01|00 00|00 00|00
		//GPIOA->BSRR = 0x20; // turn on led
		SYSCFG->EXTICR[3] = 0x0020; // select portc for ext13

		EXTI->IMR |= 0x2000; // unmask EXTI13
		EXTI->FTSR|= 0x2000; //Select falling edge trigger

		GPIOB->PUPDR |= 00100000; //enable pull up resistor for pb10

		SYSCFG->EXTICR[2] |= 0x0100; // select portb for ext10
		EXTI->IMR |= 0x0400; // unmask EXTI10
		EXTI->FTSR|= 0x0400; //Select falling edge trigger

		NVIC_EnableIRQ(EXTI4_15_IRQn);

		while(1)
		{

		}
}
