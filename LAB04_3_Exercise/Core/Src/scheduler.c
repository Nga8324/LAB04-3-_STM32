/*
 * scheduler.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Admin
 */
#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task (i);
	}
	//Error_code_G= 0;
	//Timer_init();
	//Watchdog_init();
}
void SCH_Update(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		if (SCH_tasks_G[i].pTask) {
			if (SCH_tasks_G[i].Delay <= 0) {
				SCH_tasks_G[i].RunMe ++;
				if (SCH_tasks_G[i].Period) {
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				}
			}else {
				SCH_tasks_G[i].Delay --;
			}
		}
	}
}

unsigned char SCH_Add_Task(void (*pFunction)(),  unsigned int DELAY,  unsigned int PERIOD) {
	// find gap
	unsigned char i = 0;
	while ((SCH_tasks_G[i].pTask != 0) && (i < SCH_MAX_TASKS)) {
		i++;
	}
	// Not find gap
	if (i == SCH_MAX_TASKS) {
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[i].pTask = pFunction;
	SCH_tasks_G[i].Delay = DELAY / TICK ;
	SCH_tasks_G[i].Period = PERIOD / TICK ;
	SCH_tasks_G[i].RunMe = 0;

	//SCH_tasks_G[i].TaskID = i; // Luu giu vi tri he thong
	return i;
}

void SCH_Dispatch_Tasks(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		if (SCH_tasks_G[i].RunMe > 0) {
			(*SCH_tasks_G[i].pTask)();
			SCH_tasks_G[i].RunMe--;

			// ONE-SHOT
			if(SCH_tasks_G[i].Period == 0){
				SCH_Delete_Task(i);
			}
		}
	}

}

unsigned char SCH_Delete_Task(uint32_t ID) {
	if(SCH_tasks_G[ID].pTask == 0 || ID >= SCH_MAX_TASKS){
		 //Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK
		return RETURN_ERROR;
	}
	SCH_tasks_G[ID].pTask = 0x0000;
	SCH_tasks_G[ID].Delay = 0;
	SCH_tasks_G[ID].Period = 0;
	SCH_tasks_G[ID].RunMe = 0;
	return RETURN_NORMAL;
}



