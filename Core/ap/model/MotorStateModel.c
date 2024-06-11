/*
 * MotorStateModel.c
 *
 *  Created on: May 2, 2024
 *      Author: kccistc
 */

#include "MotorStateModel.h"

AllMotorState_t MotorState;

void MotorState_init(){
	MotorState.ManualState = STOP;
	MotorState.AutoState = NONE;
	MotorState.speed = 0;
}

void MotorState_setSpeed(int speed){
	MotorState.speed = speed;
}
int MotorState_getSpeed(){
	return MotorState.speed;
}


void MotorManualState_set(MotorState_t state){
	MotorState.ManualState = state;
}
uint8_t MotorManualState_get(){
	return MotorState.ManualState;
}

void MotorState_setFlag(int flagState){
	MotorState.MotorFlag = flagState;
}
int MotorState_getFlag(){
	return MotorState.MotorFlag;
}

void MotorAutoState_set(MotorState_t state){
	MotorState.AutoState = state;
}
uint8_t MotorAutoState_get(){
	return MotorState.AutoState;
}

