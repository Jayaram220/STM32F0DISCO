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

//#########################################################################################################################
// another calculation based on bits, size in seconds for 16bit timer
// 16 bits = 2^16 = 65,536   ,  16mhz = 16 000 000
// 65,536 * 1/16mhz   = 65,536*(6.25*10^-8) = 4.096*10^-3 --  size in sec = 4.096ms
// if our timer is 16 bit we canot create a delay or counter greater than 4.096ms if clk is 16mhz
// ###############################################################################
// 32 bit timer
// 32 bit = 2^32 = 4,294,967,296
// 16 mhz = 16 000 000
// 4,294,967,296* 1/16mhz = 4,294,967,296*(6.25*10^-8) = 268.435*10^-3 --  size in sec = 268.435ms
// ##############################################################################################
// 16-bits+8-bits (prescaler) = 2^24 = 16,777,216
// 16mhz = 16 000 000
// 16777216*1/16mhz = 16777216* (6.25*10^-8)  = 1.048 sec  for 16bit timer with prescaler
// #########################################################################################################################

//#########################################################################################################################
// another calculation based on bits, size in seconds for 16bit timer
// 16 bits = 2^16 = 65,536   ,  8mhz = 8 000 000
// 65,536 * 1/8mhz   = 65,536*(1.25*10^-8) = .81920*10^-3 --  size in sec = 0.81920*ms
// if our timer is 16 bit we canot create a delay or counter greater than 4.096ms if clk is 8mhz
// ###############################################################################

// 32 bit timer
// 32 bit = 2^32 = 4,294,967,296
// 8 mhz = 8 000 000
// 4,294,967,296* 1/8mhz = 4,294,967,296*(1.25*10^-8) = 53687.09120*10^-3 --  size in sec = 53687.09120ms
// ##############################################################################################

// 16-bits+8-bits (prescaler) = 2^24 = 16,777,216
// 16mhz = 8 000 000
// 16777216*1/8mhz = 16777216* (1.25*10^-8)  = 209.71520 ms  for 16bit timer with prescaler
// #########################################################################################################################




//###########################################################################################################################


#include "stm32f0xx.h"
#include "stm32f0308_discovery.h"
			

int main(void)
{
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
		GPIOA->MODER |= 0x400; //pa5
		// configure systick to generate 200ms
		SysTick->LOAD = 3200000-1; //reload with number of clocks per milliseconds //at 1hz system clock is 8mhz
		SysTick->VAL = 0;
		SysTick->CTRL = 5;
		// enable irq

		while(1)
		{
			// check if count flag is set
			if(SysTick->CTRL&0x10000)
			{
			GPIOA->ODR ^= 0x20; // togle led
			}
		}

}
