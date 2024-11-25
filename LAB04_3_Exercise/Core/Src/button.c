/*
 * button.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */

#include "button.h"

int KeyReg0[NUM_button] = {NORMAL_STATE};
int KeyReg1[NUM_button] = {NORMAL_STATE};
int KeyReg2[NUM_button] = {NORMAL_STATE};

int KeyReg3[NUM_button] = {NORMAL_STATE};
int TimerForKeyPress[NUM_button] = {TIME_INTO_LONG_PRESSED};

int button_flag[NUM_button] = {0};

void get_input_button(int index, GPIO_TypeDef *GPIOx, int GPIO_Pin){
	KeyReg0[index] = KeyReg1[index];
	KeyReg1[index] = KeyReg2[index];
	KeyReg2[index] = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

int isButtonPressed(int but){
	if(button_flag[but] == 1){
		button_flag[but] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	get_input_button(0, Button1_GPIO_Port, Button1_Pin);
	get_input_button(1, Button2_GPIO_Port, Button2_Pin);
	get_input_button(2, Button3_GPIO_Port, Button3_Pin);

	for(int but = 0; but < 3; but ++){
		if((KeyReg0[but] == KeyReg1[but]) && (KeyReg1[but] == KeyReg2[but])){
			// Nhấn nhanh
			if(KeyReg3[but] != KeyReg2[but]){
				KeyReg3[but] = KeyReg2[but];
				if(KeyReg2[but] == PRESSED_STATE){
					//TODO
					button_flag[but] = 1;
					TimerForKeyPress[but] = TIME_INTO_LONG_PRESSED;
					}
				}
				// Nhấn đè
				else{
					if(KeyReg2[but] == PRESSED_STATE){
						TimerForKeyPress[but] --;
						if(TimerForKeyPress[but] == 0){
							button_flag[but] = 1;
							TimerForKeyPress[but] = TIME_INTO_LONG_PRESSED;
						}
					}
				}
		}
	}
}

