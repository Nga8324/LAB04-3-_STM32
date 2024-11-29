/*
 * global.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#include "global.h"

int status = INIT;
int STATUS_LED1 = INIT;
int STATUS_LED2 = INIT;
int STATUS_7SEG = INIT;

int STATUS_MODE = INIT;
int STATUS_BLINKY = INIT;

int buffer_7seg[4] = {0};
int led_index = 0;

int TimeRed = 5;
int TimeGreen = 3;
int TimeYellow = 2;

int TimeForLed1 = 5;
int TimeForLed2 = 3;

int value = 0;

int counter_2 = 100;
int counter_3 = 100;
int counter_4 = 25;
int counter_5 = 25;
int counter_6 = 25;
