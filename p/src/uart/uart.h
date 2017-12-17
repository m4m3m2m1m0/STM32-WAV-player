#ifndef UART_H_
#define UART_H_
#include "stm32f10x.h"


#endif /* UART_H_ */

void uart_init(void);
void uart_putc(char c);
void uart_putInt(int i);
void uart_putString(const char* s);
void uart_putHexBuf(const uint8_t *buf);
char uart_getChar(void);
void uart_putBinary(uint8_t i);
