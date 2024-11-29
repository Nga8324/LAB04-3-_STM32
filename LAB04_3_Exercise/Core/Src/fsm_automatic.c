/*
 * fsm_automatic.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	if (STATUS_MODE != MODE1) return;
	//
	if (TimeRed != TimeYellow + TimeGreen) {
        TimeRed = 5;
        TimeYellow = 2;
        TimeGreen = 3;
    }

	switch(STATUS_LED1){
	case INIT:
		OffAll1();

		STATUS_LED1 = AUTO_RED1;
		TimeForLed1 = TimeRed;
		//setTimer(2, 1000);
		counter_2 = 50;
		break;
	case AUTO_RED1:
		OnLedRed1();

	    updateBuffer(MODE1);
	    display_led7seg();
		//if(timer_flag[2] == 1){
			//setTimer(2, 1000);
	    counter_2 --;
	    if(counter_2 <= 0){
	    	counter_2 = 50;
			TimeForLed1 --;
			if(TimeForLed1 <= 0){
				TimeForLed1 = TimeGreen;
				STATUS_LED1 = AUTO_GREEN1;
			}
	    }
		//}
		break;
	case AUTO_GREEN1:
		OnLedGreen1();

	    updateBuffer(MODE1);
	    display_led7seg();
		//if(timer_flag[2] == 1){
			//setTimer(2, 1000);
	    counter_2 --;
	    if(counter_2 <= 0){
	    	counter_2 = 50;
			TimeForLed1 --;
			if(TimeForLed1 <= 0){
				TimeForLed1 = TimeYellow;
				STATUS_LED1 = AUTO_YELLOW1;
			}

	    }
		//}
		break;
	case AUTO_YELLOW1:
		OnLedYellow1();

	    updateBuffer(MODE1);
	    display_led7seg();

		//if(timer_flag[2] == 1){
			//setTimer(2, 1000);
	    counter_2 --;
	    if(counter_2 <= 0){
	    	counter_2 = 50;
			TimeForLed1 --;
			if(TimeForLed1 <= 0){
				TimeForLed1 = TimeRed;
				STATUS_LED1 = AUTO_RED1;
			}
	    }
		//}
		break;
	default:
		break;
	}
	//
	switch(STATUS_LED2){
	case INIT:
		OffAll2();

	    updateBuffer(MODE1);
	    display_led7seg();

		STATUS_LED2 = AUTO_GREEN2;
		TimeForLed2 = TimeGreen;
		//setTimer(3, 1000);
		counter_3 = 50;
		break;
	case AUTO_RED2:
		OnLedRed2();

	    updateBuffer(MODE1);
	    display_led7seg();

		//if(timer_flag[3] == 1){
			//setTimer(3, 1000);
	    counter_3 --;
	    if(counter_3 <= 0)
	    {
	    	counter_3 = 50;
			TimeForLed2 --;
			if(TimeForLed2 <= 0){
				TimeForLed2 = TimeGreen;
				STATUS_LED2 = AUTO_GREEN2;
			}
	    }
		//}
		break;
	case AUTO_GREEN2:
		OnLedGreen2();

	    updateBuffer(MODE1);
	    display_led7seg();

		//if(timer_flag[3] == 1){
			//setTimer(3, 1000);
	    counter_3 --;
	    if(counter_3 <= 0)
	    {
	    	counter_3 = 50;
			TimeForLed2 --;
			if(TimeForLed2 <= 0){
				TimeForLed2 = TimeYellow;
				STATUS_LED2 = AUTO_YELLOW2;
			}

	   }
		//}
		break;
	case AUTO_YELLOW2:
		OnLedYellow2();

	    updateBuffer(MODE1);
	    display_led7seg();
		//if(timer_flag[3] == 1){
			//setTimer(3, 1000);
	    counter_3 --;
	    if(counter_3 <= 0){
	    	counter_3 = 50;
			TimeForLed2 --;
			if(TimeForLed2 <= 0){
				TimeForLed2 = TimeRed;
				STATUS_LED2 = AUTO_RED2;
			}
		 }
		//}
		break;
	default:
		break;
	}
}
