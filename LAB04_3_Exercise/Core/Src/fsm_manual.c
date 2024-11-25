/*
 * fsm_manual.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(STATUS_MODE){
	case MODE2:
		BlinkyLed(RED);
		updateBuffer(STATUS_MODE);
		display_led7seg();

		if(isButtonPressed(1)){
			value = (value < 99) ? value + 1 : 1;
		}

		break;
	case MODE3:
		BlinkyLed(YELLOW);
		updateBuffer(STATUS_MODE);
		display_led7seg();

		if(isButtonPressed(1)){
			value = (value < 99) ? value + 1 : 1;
		}

		break;
	case MODE4:
		BlinkyLed(GREEN);
		updateBuffer(STATUS_MODE);
		display_led7seg();

		if(isButtonPressed(1)){
			value = (value < 99) ? value + 1 : 1;
		}
		break;
	default:
		break;
	}
}
