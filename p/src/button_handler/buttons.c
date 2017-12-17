/*
 * buttons.c
 *
 *  Created on: 18.11.2017
 *      Author: OSKI
 */
#include "buttons.h"
#include "stm32f10x.h"

#include "../uart/uart.h"

#define DEBOUNCE 64000
#define CURSOR_HOLDON_TIME 40000
#define VOL_HOLDON_TIME 20000
#define MENU_HOLDON_TIME 10000

void buttons_init(void)
{

	GPIO_InitTypeDef gpio;

	GPIO_StructInit(&gpio);

	gpio.GPIO_Pin = NEXT_PIN;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(NEXT_PORT, &gpio);

	gpio.GPIO_Pin = PREVIOUS_PIN;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(PREVIOUS_PORT, &gpio);

	gpio.GPIO_Pin = PLUS_PIN;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(PLUS_PORT, &gpio);

	gpio.GPIO_Pin = MINUS_PIN;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(MINUS_PORT, &gpio);

	gpio.GPIO_Pin = MENU_PIN;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(MENU_PORT, &gpio);

	gpio.GPIO_Pin = PAUSE_PIN;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(PAUSE_PORT, &gpio);
}

BUTTON_STATE nextButton(void)
{
	BUTTON_STATE result = NONE;
	static uint16_t key_lock;
	static uint32_t holdOn;

	if( !key_lock && !GPIO_ReadInputDataBit(NEXT_PORT, NEXT_PIN) )
	{
		key_lock = DEBOUNCE;

		result = PRESSED;
		holdOn = 1;
	}
	else if( key_lock && GPIO_ReadInputDataBit(NEXT_PORT, NEXT_PIN) )
	{
		key_lock++;
	}
	else if(holdOn && !GPIO_ReadInputDataBit(NEXT_PORT, NEXT_PIN))
	{
		if(holdOn > CURSOR_HOLDON_TIME)
		{
			result = HOLDING;
		}
		else
			holdOn++;
	}
	else if( holdOn && holdOn <= CURSOR_HOLDON_TIME && GPIO_ReadInputDataBit(NEXT_PORT, NEXT_PIN) )
	{
		result = RELEASED;
		holdOn = 0;
	}
	else if( holdOn > CURSOR_HOLDON_TIME && GPIO_ReadInputDataBit(NEXT_PORT, NEXT_PIN) )
	{
		result = HOLDING_RELEASED;
		holdOn = 0;
	}
	return result;
}

BUTTON_STATE previousButton(void)
{
	BUTTON_STATE result = NONE;
	static uint16_t key_lock;
	static uint32_t holdOn;

	if( !key_lock && !GPIO_ReadInputDataBit(PREVIOUS_PORT, PREVIOUS_PIN) )
	{
		key_lock = DEBOUNCE;

		result = PRESSED;
		holdOn = 1;
	}
	else if( key_lock && GPIO_ReadInputDataBit(PREVIOUS_PORT, PREVIOUS_PIN) )
	{
		key_lock++;
	}
	else if(holdOn && !GPIO_ReadInputDataBit(PREVIOUS_PORT, PREVIOUS_PIN))
	{

		if(holdOn > CURSOR_HOLDON_TIME)
		{
			result = HOLDING;
		}
		else
			holdOn++;
	}
	else if( holdOn && holdOn <= CURSOR_HOLDON_TIME && GPIO_ReadInputDataBit(PREVIOUS_PORT, PREVIOUS_PIN) )
	{
		result = RELEASED;
		holdOn = 0;
	}
	else if( holdOn > CURSOR_HOLDON_TIME && GPIO_ReadInputDataBit(PREVIOUS_PORT, PREVIOUS_PIN) )
	{
		result = HOLDING_RELEASED;
		holdOn = 0;
	}
	return result;
}

BUTTON_STATE plusButton(void)
{
	BUTTON_STATE result = NONE;
	static uint16_t key_lock;
	static uint32_t holdOn;

	if( !key_lock && !GPIO_ReadInputDataBit(PLUS_PORT, PLUS_PIN) )
	{
		key_lock = DEBOUNCE;

		result = PRESSED;
		holdOn = 1;
	}
	else if( key_lock && GPIO_ReadInputDataBit(PLUS_PORT, PLUS_PIN) )
	{
		key_lock++;
	}
	else if(holdOn && !GPIO_ReadInputDataBit(PLUS_PORT, PLUS_PIN))
	{
		if(holdOn > VOL_HOLDON_TIME)
		{
			result = HOLDING;
		}
		else
			holdOn++;
	}
	else if( holdOn && holdOn <= VOL_HOLDON_TIME && GPIO_ReadInputDataBit(PLUS_PORT, PLUS_PIN) )
	{
		result = RELEASED;
		holdOn = 0;
	}
	else if( holdOn > VOL_HOLDON_TIME && GPIO_ReadInputDataBit(NEXT_PORT, NEXT_PIN) )
	{
		result = HOLDING_RELEASED;
		holdOn = 0;
	}
	return result;
}

BUTTON_STATE minusButton(void)
{
	BUTTON_STATE result = NONE;
	static uint16_t key_lock;
	static uint32_t holdOn;

	if( !key_lock && !GPIO_ReadInputDataBit(MINUS_PORT, MINUS_PIN) )
	{
		key_lock = DEBOUNCE;

		result = PRESSED;
		holdOn = 1;
	}
	else if( key_lock && GPIO_ReadInputDataBit(MINUS_PORT, MINUS_PIN) )
	{
		key_lock++;
	}
	else if(holdOn && !GPIO_ReadInputDataBit(MINUS_PORT, MINUS_PIN))
	{
		if(holdOn > VOL_HOLDON_TIME)
		{
			result = HOLDING;
		}
		else
			holdOn++;
	}
	else if( holdOn && holdOn <= VOL_HOLDON_TIME && GPIO_ReadInputDataBit(MINUS_PORT, MINUS_PIN) )
	{
		result = RELEASED;
		holdOn = 0;
	}
	else if( holdOn > VOL_HOLDON_TIME && GPIO_ReadInputDataBit(NEXT_PORT, NEXT_PIN) )
	{
		result = HOLDING_RELEASED;
		holdOn = 0;
	}
	return result;
}

BUTTON_STATE menuButton(void)
{
	BUTTON_STATE result = NONE;
	static uint16_t key_lock;
	static uint32_t holdOn;

	if( !key_lock && !GPIO_ReadInputDataBit(MENU_PORT, MENU_PIN) )
	{
		key_lock = DEBOUNCE;

		result = PRESSED;
		holdOn = 1;
	}
	else if( key_lock && GPIO_ReadInputDataBit(MENU_PORT, MENU_PIN) )
	{
		key_lock++;
	}
	else if(holdOn && !GPIO_ReadInputDataBit(MENU_PORT, MENU_PIN))
	{
		if(holdOn > MENU_HOLDON_TIME)
		{
			result = HOLDING;
		}
		else
			holdOn++;
	}
	else if( holdOn && holdOn <= MENU_HOLDON_TIME && GPIO_ReadInputDataBit(MENU_PORT, MENU_PIN) )
	{
		result = RELEASED;
		holdOn = 0;
	}
	return result;
}

BUTTON_STATE pauseButton(void)
{
	BUTTON_STATE result = NONE;
	static uint16_t key_lock;
	static uint32_t holdOn;

	if( !key_lock && !GPIO_ReadInputDataBit(PAUSE_PORT, PAUSE_PIN) )
	{
		key_lock = DEBOUNCE;

		result = PRESSED;
		holdOn = 1;
	}
	else if( key_lock && GPIO_ReadInputDataBit(PAUSE_PORT, PAUSE_PIN) )
	{
		key_lock++;
	}
	else if(holdOn && !GPIO_ReadInputDataBit(PAUSE_PORT, PAUSE_PIN))
	{
		if(holdOn > MENU_HOLDON_TIME)
		{
			result = HOLDING;
		}
		else
			holdOn++;
	}
	else if( holdOn && holdOn <= MENU_HOLDON_TIME && GPIO_ReadInputDataBit(PAUSE_PORT, PAUSE_PIN) )
	{
		result = RELEASED;
		holdOn = 0;
	}
	return result;
}
