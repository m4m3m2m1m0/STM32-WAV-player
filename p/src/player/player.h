/*
 * player.h
 *
 *  Created on: 18.11.2017
 *      Author: OSKI
 */
#include "stm32f10x.h"
#include "../FatFs/ff.h"
#include "../spi_DAC/SPI_DAC.h"
#include "../wav_format/wav.h"

#ifndef PLAYER_PLAYER_H_
#define PLAYER_PLAYER_H_

#define BUFFER_SIZE 8192

typedef enum
{
	STARTED_NEW_SONG,
	PLAYING,
	PLAYER_ERROR
}PLAYER_STATE;

typedef struct
{
	int8_t highPassVolume, lowPassVolume;
	uint8_t isPlaying, canRead, flag;
	uint8_t audio_pause, audioBtnPause;
	int8_t volume, displayVolume;

}PLAYER;

FRESULT fresult;
FIL plik;
FATFS g_sFatFs;
UINT read;


DIR dir;
FILINFO fileinfo;

PLAYER player;

void PlaySong(char* fileName, WAV_FORMAT *wav);
void StopPlaying(void);
void PlayNextSong(WAV_FORMAT *wav);
void PlayPreviousSong(WAV_FORMAT *wav);
void PlayFirstSong(WAV_FORMAT *wav);
PLAYER_STATE ReadWavData(void);


void readPlayerSettings(PLAYER *player);
void savePlayerSettings(void);

#endif /* PLAYER_PLAYER_H_ */
