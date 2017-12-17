#include "stm32f10x.h"
#include "FatFs/ff.h"
#include "FatFs/diskio.h"
#include "LCD/lcd44780.h"
#include "wav_format/wav.h"
#include "menu/menu.h"
#include "player/player.h"
#include "player/functionHandler.h"
#include "delay/delay.h"
#include "button_handler/buttons.h"
#include "spi/SPI.h"
#include "SD_timer/SD_timer.h"
#include "uart/uart.h"

void waitForSD(void);

uint16_t ButtonIntervalTimer;

int main(void)
{
	SysTick_Config(SystemCoreClock / 100);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	buttons_init();
	lcd_init();

	spi_init();
	uart_init();

	SD_timer_init();

	waitForSD();

	spi_DAC_init();

	readPlayerSettings(&player);

	DisplayMenu(START, player, wav);

	PlayFirstSong(&wav);
	DisplayMenu(DEFAULT, player, wav);

	PLAYER_STATE Player_state;
	BUTTON_STATE btnState;

	while (1)
	{

		//NEXT BTN
		btnState = nextButton();
		if(btnState == HOLDING && ButtonIntervalTimer > 3)
		{
			audioPlayPause(1);
			forward();
			ButtonIntervalTimer = 0;
		}
		else if(btnState == RELEASED)
		{
			nextSong();
		}
		else if(btnState == HOLDING_RELEASED)
			audioPlayPause(0);

		//PREVIOUS BTN
		btnState = previousButton();
		if(btnState == HOLDING && ButtonIntervalTimer > 3)
		{
			audioPlayPause(1);
			backward();
			ButtonIntervalTimer = 0;
		}
		else if(btnState == RELEASED)
		{
			previousSong();
		}
		else if(btnState == HOLDING_RELEASED)
			audioPlayPause(0);


		//PLUS BTN
		btnState = plusButton();
		if(btnState == PRESSED)
			volumeUp();
		else if(btnState == HOLDING && ButtonIntervalTimer > 15)
		{
			volumeUp();
			ButtonIntervalTimer = 0;
		}
		else if(btnState == HOLDING_RELEASED || btnState == RELEASED)
			savePlayerSettings();

		//MINUS BTN
		btnState = minusButton();
		if(btnState == PRESSED)
			volumeDown();
		else if(btnState == HOLDING && ButtonIntervalTimer > 15)
		{
			volumeDown();
			ButtonIntervalTimer = 0;
		}
		else if(btnState == HOLDING_RELEASED || btnState == RELEASED)
			savePlayerSettings();

		//MENU BTN
		btnState = menuButton();
		if(btnState == PRESSED)
			menuSelect();

		//PAUSE BTN
		btnState = pauseButton();
		if(btnState == PRESSED)
			toggleBtnPause();


		Player_state = ReadWavData();
		if(Player_state == STARTED_NEW_SONG)
			DisplayMenu(DEFAULT, player, wav);
		else if(Player_state == PLAYER_ERROR)
		{
			DisplayError(GLOBAL_ERR);
			while(1);
		}

		DisplayTime(wav);

		if(timer > 300 && MenuState != DEFAULT)
		{
			DisplayMenu(DEFAULT, player, wav);
		}
	}
}

void SysTick_Handler()
{
	functionTimer();
	ButtonIntervalTimer++;
}

void waitForSD(void)
{
	BUTTON_STATE btnState;

	while(1)
	{
		disk_initialize(0);

		if(!disk_status(0)) break;

		DisplayError(NO_SD_ERR);

		while(1)
		{
			btnState = menuButton();

			if(btnState == PRESSED)
				break;
		}
	}
	f_mount(&g_sFatFs, "", 0);
}

