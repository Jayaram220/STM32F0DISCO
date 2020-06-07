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
#define LED_PIN GPIO_Pin_9

void delay(int counter)
{
	int i;
	for(i = 0; i < counter*1000; i++)
	{

	}

}


int main(void)
{
	//Initialize the GPIO data structre
	GPIO_InitTypeDef gpio;
	/* Enable the peripheral Clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);
	//Fills each GPIO_InitStruct member with its default value.
	/* Reset GPIO init structure parameters values */
	GPIO_StructInit(&gpio);
	// Assign pin number
	gpio.GPIO_Pin = LED_PIN;
	// make as out put pin
	gpio.GPIO_Mode = GPIO_Mode_OUT;
	//Initializes the GPIOx peripheral according to the specified
	 // * parameters in the GPIO_InitStruct.
	GPIO_Init(GPIOC,&gpio);
	GPIO_SetBits(GPIOC,LED_PIN);



	while(1)
	{
		GPIO_SetBits(GPIOC,LED_PIN);
		delay(200);
		GPIO_ResetBits(GPIOC,LED_PIN);
		delay(200);
	}


}
