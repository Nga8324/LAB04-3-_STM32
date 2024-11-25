/*
 * software_timer.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#include "software_timer.h"
#define TICK 	10

void setTimer(int index, int duration){
	timer_flag[index] = 0;
	timer_counter[index] = duration / TICK;
}

void timerRun(){
	for(int i = 0; i < MAX_BUFFER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i] --;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
