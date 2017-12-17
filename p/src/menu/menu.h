/*
 * menu.h
 *
 *  Created on: 18.11.2017
 *      Author: OSKI
 */
#include <stdlib.h>

#include "../wav_format/wav.h"
#include "../LCD/lcd44780.h"
#include "../player/player.h"

#ifndef MENU_MENU_H_
#define MENU_MENU_H_

typedef enum
{
	DEFAULT,
	VOLUME,
	BASS,
	TREBLE,
	START,
	NO_SD_ERR,
	GLOBAL_ERR
} MENU_OPTIONS;

MENU_OPTIONS MenuState;

void DisplayTime(WAV_FORMAT wav);
void DisplayMenu(MENU_OPTIONS menuOption, PLAYER player, WAV_FORMAT wav);
void DisplayError(MENU_OPTIONS menuOption);
void DisplaySongLenght(WAV_FORMAT wav);

#endif /* MENU_MENU_H_ */
