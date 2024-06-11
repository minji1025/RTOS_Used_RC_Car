/*
 * Controller.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "Controller.h"
#include <stdlib.h>
#include <stdio.h>

MODE_t CMode;

void Controller_init() {
	BT_init();
	MotorState_init();
}

void Controller_excuteTask() {
	CMode.Modestate = ModeState_get();

	Controller_BTData();
	if (CMode.Modestate == AUTO) {
		Controller_Auto_DistanceState();
	}
}

void Controller_BTData() {
	int BTflag = BT_getFlag();
	if (!BTflag) return;

	uint8_t rxBuff[10];

	Controller_getData(rxBuff); //Uart data rxBuff에 저장
	Controller_Mode_parsingData(rxBuff);	//Buff에 저장된 값 판단
	Controller_Mode_decision(rxBuff);	//모드 결정하여 나머지 파싱 실행

	BT_setFlag(BTRESET);
}
void Controller_getData(uint8_t *Buff) {
	uint8_t rxData = 1;

	for (int i = 0; rxData; i++) {
		rxData = BT_deQue();
		Buff[i] = rxData;
	}
}

void Controller_Mode_decision(uint8_t *Buff) {

	if (CMode.Modestate == MANUAL) {
		Controller_Manual_parsingData(Buff); //Buff에 저장된 값 판단
	}
	if (CMode.Modestate == AUTO) {
		//UltraSonic 계산 추가
		Controller_Auto_parsingData(Buff); //Buff에 저장된 값 판단
	}
}

void Controller_Mode_parsingData(uint8_t *Buff) {
	if (Buff[0] == 'm') {
		ModeState_set(MANUAL);
		ModeState_setFlag(MANUALFlag);
	}
	if (Buff[0] == 'a') {
		ModeState_set(AUTO);
		ModeState_setFlag(AUTOFlag);
	}
}

void Controller_Manual_parsingData(uint8_t *Buff) {
	if (Buff[0] == 'g') {	//go
		MotorManualState_set(GO);
	}
	else if (Buff[0] == 'b') {	//back
		MotorManualState_set(BACK);
	}
	else if (Buff[0] == 'l') {	//left
		MotorManualState_set(LEFT);
	}
	else if (Buff[0] == 'r') {	//right
		MotorManualState_set(RIGHT);
	}
	else if (Buff[0] == 's') {	//stop
		MotorManualState_set(STOP);
	}
	else if (Buff[0] == 'p') {	//speed p98'0'
		MotorManualState_set(SPEED);
		int speed = atoi(&Buff[1]);	//해당 주소부터 숫자가 아닌 것까지 계산
		MotorState_setSpeed(speed);
	}
	MotorState_setFlag(SET);
}

void Controller_Auto_parsingData(uint8_t *Buff) {
	if (Buff[0] == 's') {	//응급 상황시 사람이 stop
		MotorAutoState_set(STOP);
	}
	if (Buff[0] == 'n') {	//Auto Run
		MotorState_setSpeed(550);
		MotorAutoState_set(NONE);
	}
	MotorState_setFlag(SET);
}

void Controller_Auto_DistanceState() {
	static int OldautoState;
	int autoState = MotorAutoState_get();
	USDistance_t USDistance;
	USDistance = USDistance_get();

	if (autoState == STOP) return;

	if (USDistance.Distance_Front < 22) {
		if (USDistance.Distance_Left < USDistance.Distance_Right) {
			MotorAutoState_set(RIGHT);
		}
		else {
			MotorAutoState_set(LEFT);
		}
	}
	else if (USDistance.Distance_Left < 27) {
		MotorAutoState_set(RIGHT);
	}
	else if (USDistance.Distance_Right < 27) {
		MotorAutoState_set(LEFT);
	}
	else {
		MotorAutoState_set(GO);
	}
	if (OldautoState != autoState) {
		OldautoState = autoState;
		MotorState_setFlag(SET);
	}
}

