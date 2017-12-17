#include "SPI_DAC.h"

void spi_DAC_init(void)
{
	SPI_InitTypeDef spi;
	GPIO_InitTypeDef gpio;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

//
	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_15|GPIO_Pin_13; // SCK, MOSI
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);

	gpio.GPIO_Pin = GPIO_Pin_14; // MISO
	gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);

	gpio.GPIO_Pin = GPIO_Pin_12; // CS
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &gpio);

	SPI_StructInit(&spi);
	spi.SPI_FirstBit = SPI_FirstBit_MSB;
	spi.SPI_Mode = SPI_Mode_Master;
	spi.SPI_NSS = SPI_NSS_Soft;
	spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
	spi.SPI_CPOL = SPI_CPOL_Low;
	spi.SPI_CPHA = SPI_CPHA_1Edge;
	spi.SPI_DataSize = SPI_DataSize_16b;
	SPI_Init(SPI2, &spi);

	SPI_Cmd(SPI2, ENABLE);


}

uint8_t spi_DAC_sendrecv(uint16_t byte)
{
	 // poczekaj az bufor nadawczy bedzie wolny
	 while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
	 SPI_I2S_SendData(SPI2, byte);

	 // poczekaj na dane w buforze odbiorczym
//	 while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
	 return 0;
}

uint8_t spi_DAC_recv(void)
{
	 // poczekaj az bufor nadawczy bedzie wolny
	 while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE) == RESET);
	 SPI_I2S_SendData(SPI3, 0xff);

	 // poczekaj na dane w buforze odbiorczym
	 while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE) == RESET);
	 return SPI_I2S_ReceiveData(SPI3);
}

void spi_DAC_send (uint8_t byte) // Wyslanie bajtu do SD
{
	// Wyslanie bajtu
	 while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE) == RESET);
	 SPI_I2S_SendData(SPI3, byte);
}

void spi_DAC_resetCS(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);

}

void spi_DAC_setCS(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}
