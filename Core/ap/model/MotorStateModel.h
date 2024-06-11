/*
 * MotorStateModel.h
 *
 *  Created on: May 2, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_MOTORSTATEMODEL_H_
#define AP_MODEL_MOTORSTATEMODEL_H_

#include "../../Common/Queue/Queue.h"

#define SET			1
#define RESET		0

typedef enum{NONE,STOP,GO,LEFT,RIGHT,BACK,SPEED}MotorState_t;

typedef struct{
	MotorState_t ManualState;
	MotorState_t AutoState;
	int speed;
	int MotorFlag;
}AllMotorState_t;

void MotorState_init();
void MotorState_setSpeed(int speed);
int MotorState_getSpeed();
void MotorManualState_set(MotorState_t state);
uint8_t MotorManualState_get();
void MotorState_setFlag(int flagState);
int MotorState_getFlag();
void MotorAutoState_set(MotorState_t state);
uint8_t MotorAutoState_get();


#endif /* AP_MODEL_MOTORSTATEMODEL_H_ */
