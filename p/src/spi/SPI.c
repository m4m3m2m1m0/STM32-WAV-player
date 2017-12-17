#include "../spi/SPI.h"


void spi_init(void)
{
	 SPI_InitTypeDef spi;
	 GPIO_InitTypeDef gpio;

	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	 GPIO_StructInit(&gpio);
	 gpio.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7; // SCK, MOSI
	 gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	 gpio.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA, &gpio);

	 gpio.GPIO_Pin = GPIO_Pin_6; // MISO
	 gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	 gpio.GPIO_Speed = GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA, &gpio);

	 gpio.GPIO_Pin = GPIO_Pin_4; // CS
	 gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	 GPIO_Init(GPIOA, &gpio);

	 SPI_StructInit(&spi);
	 spi.SPI_Mode = SPI_Mode_Master;
	 spi.SPI_NSS = SPI_NSS_Soft;
	 spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	 SPI_Init(SPI1, &spi);

	 SPI_Cmd(SPI1, ENABLE);
}

uint8_t spi_sendrecv(void)
{
	 // poczekaj az bufor nadawczy bedzie wolny
	 while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
	 SPI_I2S_SendData(SPI1, 0xff);

	 // poczekaj na dane w buforze odbiorczym
	 while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
	 return SPI_I2S_ReceiveData(SPI1);
}

uint8_t rcvr_spi(void)
{
	 // poczekaj az bufor nadawczy bedzie wolny
	 while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
	 SPI_I2S_SendData(SPI1, 0xff);

	 // poczekaj na dane w buforze odbiorczym
	 while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
	 return SPI_I2S_ReceiveData(SPI1);
}

void xmit_spi (uint8_t byte) // Wyslanie bajtu do SD
{
	// Wyslanie bajtu
	 while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
	 SPI_I2S_SendData(SPI1, byte);
}

void SELECT(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);

}

void DESELECT(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}
