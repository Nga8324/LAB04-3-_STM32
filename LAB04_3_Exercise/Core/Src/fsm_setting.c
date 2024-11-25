/*
 * fsm_setting.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#include "fsm_setting.h"

void fsm_setting_run(){
	switch(STATUS_MODE){
	case INIT:
		STATUS_MODE = MODE1;
		break;
	case MODE1:
		if(isButtonPressed(0)){
			STATUS_MODE = MODE2;
			value = TimeRed;
			STATUS_BLINKY = INIT;
		}
		break;
	case MODE2:
		if(isButtonPressed(0)){
			STATUS_MODE = MODE3;
			value = TimeYellow;
			STATUS_BLINKY = INIT;
		}
		else if(isButtonPressed(2)){
			TimeRed = value;
		}
		break;
	case MODE3:
		if(isButtonPressed(0)){
			STATUS_MODE = MODE4;
			value = TimeGreen;
			STATUS_BLINKY = INIT;
		}
		else if(isButtonPressed(2)){
			TimeYellow = value;
		}
		break;
	case MODE4:
		if(isButtonPressed(0)){
			STATUS_MODE = MODE1;

			STATUS_LED1 = INIT;
			STATUS_LED2 = INIT;
			STATUS_7SEG = INIT;

			STATUS_BLINKY = INIT;
		}
		else if(isButtonPressed(2)){
			TimeGreen = value;
		}
		break;
	default:
		break;
	}


}
