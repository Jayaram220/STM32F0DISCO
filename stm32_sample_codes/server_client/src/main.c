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
#include<string.h>
char ReceivedData;
char buff[10]="hello";

void delay(int counter)
{
	int i;
	for(i = 0; i < counter*1000; i++)
	{

	}

}


int main(void)
{
			USART_InitTypeDef USART_InitStructure;
			GPIO_InitTypeDef GPIO_InitStructure;
			RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);//PA2 TX
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);//PA3 RX

			/* Configure USART2 pins: Rx and Tx ----------------------------*/
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;// Push pull
			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
			GPIO_Init(GPIOA, &GPIO_InitStructure);
			//USART peripheral
			USART_InitStructure.USART_BaudRate = 9600;
			USART_InitStructure.USART_WordLength = USART_WordLength_8b;
			USART_InitStructure.USART_StopBits = USART_StopBits_1;
			USART_InitStructure.USART_Parity = USART_Parity_No;
			USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
			USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
			//AF mode settings for pin
			USART_Init(USART2, &USART_InitStructure);
			USART_Cmd(USART2,ENABLE);

			for(int i=0; i<strlen(buff); i++)
			{
				while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
				//{

				//}
				USART_SendData(USART2, buff[i]);
				delay(1000);
			}
			USART_SendData(USART2, '\r');
			USART_SendData(USART2, '\n');
			while(1)
			{

			while (USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET);
			ReceivedData = USART_ReceiveData(USART2);
			delay(3000);
			USART_SendData(USART2,ReceivedData);
			}



}
