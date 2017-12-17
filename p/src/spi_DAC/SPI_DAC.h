#include "stm32f10x.h"

#include "../uart/uart.h"



void spi_DAC_init(void);
uint8_t spi_DAC_sendrecv(uint16_t byte);
void spi_DAC_resetCS(void);
void spi_DAC_setCS(void);
void spi_DAC_send (uint8_t byte);
uint8_t spi_DAC_recv(void);
void RCC_Configuration(void);
