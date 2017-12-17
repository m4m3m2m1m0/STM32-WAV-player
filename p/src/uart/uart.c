#include "../uart/uart.h"

#include "stm32f10x.h"

#include <stdlib.h>



void uart_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	//uart
	GPIO_InitTypeDef gpio;
	USART_InitTypeDef uart;

	GPIO_StructInit(&gpio);
//
	gpio.GPIO_Pin = GPIO_Pin_10;
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &gpio);

	gpio.GPIO_Pin = GPIO_Pin_11;
	gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &gpio);


	USART_StructInit(&uart);
	uart.USART_BaudRate = 115200;
	USART_Init(USART3, &uart);

	USART_Cmd(USART3, ENABLE);

}

void uart_putBinary(uint8_t data)
{
	for(int i = 7; i >= 0; i--)
	{
		if((data>>i)&0x01)
			uart_putc('1');
		else
			uart_putc('0');
	}
}

char uart_getChar(void)
{
	if (USART_GetFlagStatus(USART3, USART_FLAG_RXNE)) {
	    char c = USART_ReceiveData(USART3);
	    return c;
	}
	return 0;
}


void uart_putInt(int i)
{
	char buf[16];
	itoa(i, buf, 10);
	uart_putString(buf);
	uart_putString("\r\n");
}

void uart_putString(const char* s)
{
    while (*s)
        uart_putc(*s++);
}

void uart_putc(char c)
{
    while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
    USART_SendData(USART3, c);
}

void uart_putHexBuf(const uint8_t *buf)
{
	char temp[16];
    while (*buf)
    {
    	itoa(*buf++, temp, 16);
        uart_putString(temp);
        uart_putString(" ");
    }
}
