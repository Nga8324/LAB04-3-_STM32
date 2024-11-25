/*
 * software_timer.h
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define MAX_BUFFER 	6

int timer_flag[MAX_BUFFER];
int timer_counter[MAX_BUFFER];

void setTimer(int index, int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
