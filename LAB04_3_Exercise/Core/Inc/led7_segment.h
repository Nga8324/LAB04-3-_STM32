/*
 * led7_segment.h
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_
#include "main.h"
#include "global.h"

#define LED7SEG1	30
#define LED7SEG2	31
#define LED7SEG3	32
#define LED7SEG4	33

void display7SEG(int num);
void update7SEG (int index);

void updateBuffer(int mode);
void display_led7seg();


#endif /* INC_LED7_SEGMENT_H_ */
