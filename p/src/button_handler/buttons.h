/*
 * keys.h
 *
 *  Created on: 18.11.2017
 *      Author: OSKI
 */

#ifndef BUTTON_HANDLER_BUTTONS_H_
#define BUTTON_HANDLER_BUTTONS_H_

#define PLUS_PIN GPIO_Pin_9
#define PLUS_PORT GPIOA

#define MINUS_PIN GPIO_Pin_1
#define MINUS_PORT GPIOA

#define NEXT_PIN GPIO_Pin_10
#define NEXT_PORT GPIOA

#define PREVIOUS_PIN GPIO_Pin_0
#define PREVIOUS_PORT GPIOB

#define MENU_PIN GPIO_Pin_8
#define MENU_PORT GPIOA

#define PAUSE_PIN GPIO_Pin_1
#define PAUSE_PORT GPIOB

typedef enum
{
	PRESSED,
	RELEASED,
	HOLDING,
	HOLDING_RELEASED,
	NONE
}BUTTON_STATE;

void buttons_init(void);

BUTTON_STATE nextButton(void);
BUTTON_STATE previousButton(void);
BUTTON_STATE plusButton(void);
BUTTON_STATE minusButton(void);
BUTTON_STATE menuButton(void);
BUTTON_STATE pauseButton(void);

#endif /* BUTTON_HANDLER_BUTTONS_H_ */
