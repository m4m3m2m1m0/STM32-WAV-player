/*
 * functionHandler.c
 *
 *  Created on: 29.11.2017
 *      Author: OSKI
 */
#include "functionHandler.h"


void functionTimer(void)
{
	timer++;
}

void volumeUp(void)
{
	timer = 0;
	switch (MenuState) {
		case BASS:
		{
			player.lowPassVolume += 1;
			if(player.lowPassVolume > 10) player.lowPassVolume = 10;
			DisplayMenu(BASS, player, wav);
			break;
		}
		case TREBLE:
		{
			player.highPassVolume += 1;
			if(player.highPassVolume > 10) player.highPassVolume = 10;
			DisplayMenu(TREBLE, player, wav);
			break;
		}
		default:
		{
			if(player.volume < 8)
				player.volume += 1;
			else if(player.volume >= 8 && player.volume < 20)
				player.volume += 2;
			else if(player.volume >= 20)
				player.volume += 3;


			if(player.volume > 32)
				player.volume = 32;

			player.displayVolume++;

			if(player.displayVolume > 18)
				player.displayVolume = 18;

			DisplayMenu(VOLUME, player, wav);
			break;
		}
	}
}

void volumeDown(void)
{
	timer = 0;
	switch (MenuState) {
		case BASS:
		{
			player.lowPassVolume -= 1;
			if(player.lowPassVolume < -10) player.lowPassVolume = -10;
			uart_putInt(player.lowPassVolume);
			DisplayMenu(BASS, player, wav);
			break;
		}
		case TREBLE:
		{
			player.highPassVolume -= 1;
			if(player.highPassVolume < -10) player.highPassVolume = -10;
			DisplayMenu(TREBLE, player, wav);
			break;
		}
		default:
		{
			if(player.volume > 0 && player.volume <= 8)
				player.volume -= 1;
			else if(player.volume > 8 && player.volume <= 20)
				player.volume -= 2;
			else if(player.volume > 20)
				player.volume -= 3;

			player.displayVolume--;

			if(player.displayVolume < 0)
				player.displayVolume = 0;

			DisplayMenu(VOLUME, player, wav);
			break;
		}
	}
}

void forward(void)
{
	if(player.isPlaying)
	{
		if(wav.currentMin >= wav.min && wav.currentSec >= wav.sec)
			return;

		f_lseek(&plik, f_tell(&plik) + wav.bitRate * 4);
		wav.currentSec++;
		if(wav.currentSec >= 60)
		{
			wav.currentMin++;
			wav.currentSec = 0;
		}
	}
}

void backward(void)
{
	if(player.isPlaying)
	{
		if(wav.currentMin <= 0 && wav.currentSec <= 0)
			return;

		if(f_tell(&plik) <  (wav.bitRate * 4))
		{
			f_tell(&plik) = 0;
			f_lseek(&plik, f_tell(&plik));
		}
		else
			f_lseek(&plik, f_tell(&plik) - wav.bitRate * 4);

		if(wav.currentSec == 0)
		{
			if(wav.currentMin) wav.currentMin--;
			wav.currentSec = 60;
		}
		wav.currentSec--;
	}
}

void nextSong(void)
{
	PlayNextSong(&wav);
	DisplayMenu(DEFAULT, player, wav);
}

void previousSong(void)
{
	PlayPreviousSong(&wav);
	DisplayMenu(DEFAULT, player, wav);
}

void menuSelect(void)
{
	timer = -20;
	if(MenuState == DEFAULT || MenuState == VOLUME)
		MenuState = BASS;
	else if(MenuState == BASS)
		MenuState = TREBLE;
	else if(MenuState == TREBLE)
		MenuState = DEFAULT;
	DisplayMenu(MenuState, player, wav);
}

void audioPlayPause(uint8_t pause)
{
	if(player.audioBtnPause) return;
	player.audio_pause = pause;
}

void toggleBtnPause(void)
{
	player.audioBtnPause ^= 1;
	player.audio_pause = player.audioBtnPause;
}
