#include "../FatFs/ff.h"
#include "stm32f10x.h"


#ifndef WAV_FORMAT_WAV_H_
#define WAV_FORMAT_WAV_H_

typedef struct
{
	char title[30];
	char titleToDisplay[26];
	uint32_t bitRate;
	uint32_t doubleBitRate;
	uint8_t mono;
	uint32_t dataSize;
	uint8_t min;
	uint8_t sec;
	uint8_t currentMin;
	uint8_t currentSec;
	uint8_t error;
} WAV_FORMAT;

WAV_FORMAT wav;

WAV_FORMAT GetWavFormat(FIL *plik);

#endif /* WAV_FORMAT_WAV_H_ */
