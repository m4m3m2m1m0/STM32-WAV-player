#include "wav.h"
#include <stdlib.h>
#include <string.h>

WAV_FORMAT GetWavFormat(FIL *plik)
{
	UINT read;
	WAV_FORMAT result;
	result.error = 1;

	uint32_t data = 0;
	uint8_t buf[8];

	f_read(plik, buf, 4, &read);
	if(strstr((char *)buf, "RIFF") == NULL)
		return result;

	f_read(plik, buf, 4, &read);


	f_read(plik, buf, 4, &read);
	if(strstr((char *)buf, "WAVE") == NULL)
		return result;

	//searching for "fmt" in wav format/ timeout after 2000 bytes
	for(int i = 0; i < 1000; i++)
	{
		f_read(plik, buf, 2, &read);
		if(strstr((char *)buf, "fm") != NULL)
		{
			f_read(plik, buf, 2, &read);
			if(strstr((char *)buf, "t ") != NULL)
			{
				break;
			}
		}
	}

	f_read(plik, buf, 8, &read);

	//bit rate
	f_read(plik, buf, 4, &read);

	data = buf[3];
	data <<= 8;
	data |= buf[2];
	data <<= 8;
	data |= buf[1];
	data <<= 8;
	data |= buf[0];

	result.bitRate = data;
	result.doubleBitRate = data * 2;
	//

	//searching for "data" in wav format/ timeout after 2000 bytes
	for(int i = 0; i < 1000; i++)
	{
		f_read(plik, buf, 2, &read);
		if(strstr((char *)buf, "da") != NULL)
		{
			f_read(plik, buf, 2, &read);
			if(strstr((char *)buf, "ta") != NULL)
			{
				break;
			}
		}
	}

	//data size
	f_read(plik, buf, 4, &read);

	data = buf[3];
	data <<= 8;
	data |= buf[2];
	data <<= 8;
	data |= buf[1];
	data <<= 8;
	data |= buf[0];

	result.dataSize = data;

	//song time
	data = result.dataSize / (result.bitRate * 2 * 2);
	result.min = data / 60;
	result.sec = data - result.min*60;
	//

	result.currentMin = 0;
	result.currentSec = 0;
	result.error = 0;
	return result;

}
