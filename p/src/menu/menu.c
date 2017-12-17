/*
 * menu.c
 *
 *  Created on: 18.11.2017
 *      Author: OSKI
 */
#include "menu.h"
#include "../delay/delay.h"


void DisplayError(MENU_OPTIONS menuOption)
{
	MenuState = menuOption;

	switch(menuOption)
	{
		case NO_SD_ERR:
		{
			lcd_locate(0,0);
			lcd_str("No SD. Insert");
			lcd_locate(1,0);
			lcd_str("SD and press +");
			break;
		}
		case GLOBAL_ERR:
		{
			lcd_locate(0,0);
			lcd_str("Error occured,  ");
			lcd_locate(1,0);
			lcd_str("please restart  ");
			break;
		}
	}
}

void DisplayMenu(MENU_OPTIONS menuOption, PLAYER player,  WAV_FORMAT wav)
{
	MenuState = menuOption;

	switch(menuOption)
	{
		case VOLUME:
		{
			lcd_locate(1,0);
			lcd_str("Volume:  ");
			lcd_int(player.displayVolume);
			lcd_str("      ");
			break;
		}
		case BASS:
		{
			lcd_locate(0,0);
			lcd_str("Tone controll   ");
			lcd_locate(1,0);
			lcd_str("Bass:  ");
			lcd_int(player.lowPassVolume);
			lcd_str("      ");

			break;
		}
		case TREBLE:
		{
			lcd_locate(0,0);
			lcd_str("Tone controll   ");
			lcd_locate(1,0);
			lcd_str("Treble:  ");
			lcd_int(player.highPassVolume);
			lcd_str("      ");
			break;
		}
		case START:
		{
			lcd_locate(0,0);
			lcd_str("**WAVE  PLAYER**");
			lcd_locate(1,0);
			lcd_str(" Oskar Morawiec");
			delay_ms(2000);
			lcd_locate(1,0);
			lcd_str("Maciej Urbanczyk");
			delay_ms(2000);
			break;
		}
		default:
		{
			MenuState = DEFAULT;
			lcd_locate(0,0);
			lcd_str(wav.titleToDisplay);
			lcd_str("                ");
			DisplayTime(wav);
			DisplaySongLenght(wav);
			break;
		}
	}
}

void DisplayTime(WAV_FORMAT wav)
{
	uint32_t min = wav.currentMin, sec = wav.currentSec;
	char buf[6];
	static uint8_t lastSec;

	if(MenuState || (lastSec == wav.currentSec && wav.currentSec != 0)) return;

	lastSec = wav.currentSec;

	lcd_locate(1,0);
	if(min < 10)
	{
		buf[0] = '0';
		itoa(min, &buf[1], 10);
	}else
		itoa(min, &buf[0], 10);
	buf[2] = ':';
	if(sec < 10)
	{
		buf[3] = '0';
		itoa(sec, &buf[4], 10);
	}else
		itoa(sec, &buf[3], 10);
	lcd_str(buf);
}

void DisplaySongLenght(WAV_FORMAT wav)
{
	uint32_t min = wav.min, sec = wav.sec;
	char buf[5];

	lcd_locate(1,5);
	buf[0] = '/';
	if(min < 10)
	{
		buf[1] = '0';
		itoa(min, &buf[2], 10);
	}else
		itoa(min, &buf[1], 10);
	buf[3] = ':';
	if(sec < 10)
	{
		buf[4] = '0';
		itoa(sec, &buf[5], 10);
	}else
		itoa(sec, &buf[4], 10);
	lcd_str(buf);
	lcd_str("     ");
}
