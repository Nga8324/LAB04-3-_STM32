/*
 * global.h
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "traffic_light.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT			1
#define AUTO_RED1		2
#define AUTO_YELLOW1	3
#define AUTO_GREEN1		4
#define AUTO_RED2		5
#define AUTO_YELLOW2	6
#define AUTO_GREEN2		7

#define MODE1			22
#define MODE2			23
#define MODE3			24
#define MODE4 			25

#define MAX_7SEG		4

extern int status;
extern int led_index;
extern int buffer_7seg[MAX_7SEG];

extern int STATUS_7SEG;
extern int STATUS_LED1;
extern int STATUS_LED2;

extern int TimeRed;
extern int TimeGreen;
extern int TimeYellow;
extern int TimeForLed1;
extern int TimeForLed2;

extern int value;

extern int STATUS_MODE;
extern int STATUS_BLINKY;

#endif /* INC_GLOBAL_H_ */
