/*
 * functionHandler.h
 *
 *  Created on: 29.11.2017
 *      Author: OSKI
 */
#include "stm32f10x.h"
#include "../menu/menu.h"
#include "player.h"

#ifndef PLAYER_FUNCTIONHANDLER_H_
#define PLAYER_FUNCTIONHANDLER_H_
int16_t timer;

void volumeUp(void);
void volumeDown(void);
void menuSelect(void);
void forward(void);
void backward(void);
void nextSong(void);
void previousSong(void);
void toggleBtnPause(void);
void audioPlayPause(uint8_t pause);

void functionTimer(void);

#endif /* PLAYER_FUNCTIONHANDLER_H_ */
