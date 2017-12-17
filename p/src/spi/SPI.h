#include "stm32f10x.h"



void spi_init(void);
uint8_t spi_sendrecv(void);
void SELECT(void);
void DESELECT(void);
void xmit_spi (uint8_t byte);
uint8_t rcvr_spi(void);
