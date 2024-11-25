/*
 * traffic_light.h
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "global.h"

#define RED		40
#define YELLOW	41
#define GREEN 	42

void OffAll1();
void OffAll2();

void OnLedRed1();
void OnLedRed2();
void OnLedYellow1();
void OnLedYellow2();
void OnLedGreen1();
void OnLedGreen2();

void BlinkyLedRed();
void BlinkyLedYellow();
void BlinkyLedGreen();

void BlinkyLed(int led);
void System_Initilization();

#endif /* INC_TRAFFIC_LIGHT_H_ */
