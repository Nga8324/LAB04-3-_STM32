/*
 * button.h
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET
#define NUM_button				3
#define TIME_INTO_LONG_PRESSED	200

int isButtonPressed(int but);

void getKeyInput();


#endif /* INC_BUTTON_H_ */
