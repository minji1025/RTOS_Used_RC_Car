/*
 * UltraSonic.c
 *
 *  Created on: Apr 24, 2024
 *      Author: kccistc
 */
#include "UltraSonic.h"
#include "../Common/Delayus/delayus.h"

//Trig Port, Trig Pin, Echo Port, Echo Pin, Timer, Flag
void UltraSonic_init(ultraSonic_t *ultraSonic, TIM_HandleTypeDef *hTim,
		GPIO_TypeDef *GPIO_Trig, uint16_t GPIO_TrigPin, GPIO_TypeDef *GPIO_Echo,
		uint16_t GPIO_EchoPin) {
	ultraSonic->hTim = hTim;
	ultraSonic->GPIO_Trig = GPIO_Trig;
	ultraSonic->GPIO_TrigPin = GPIO_TrigPin;
	ultraSonic->GPIO_Echo = GPIO_Echo;
	ultraSonic->GPIO_EchoPin = GPIO_EchoPin;
	ultraSonic->timCounter = 0;
	ultraSonic->echoFlag = 0;
}

int UltraSonic_isCmpltRecvEcho(ultraSonic_t *ultraSonic) {
	return ultraSonic->echoFlag;
}
void UltraSonic_clearEchoFlag(ultraSonic_t *ultraSonic) {
	ultraSonic->echoFlag = 0;
}
void UltraSonic_setEchoFlag(ultraSonic_t *ultraSonic) {
	ultraSonic->echoFlag = 1;
}
int UltraSonic_getEchopinState(ultraSonic_t *ultraSonic) {
	return HAL_GPIO_ReadPin(ultraSonic->GPIO_Echo, ultraSonic->GPIO_EchoPin);
}
void UltraSonic_clearTimer(ultraSonic_t *ultraSonic) {
	__HAL_TIM_SET_COUNTER(ultraSonic->hTim, 0);
}
void UltraSonic_startTimer(ultraSonic_t *ultraSonic) {
	HAL_TIM_Base_Start(ultraSonic->hTim);
}
void UltraSonic_stopTimer(ultraSonic_t *ultraSonic) {
	HAL_TIM_Base_Stop(ultraSonic->hTim);
}
uint16_t UltraSonic_getTimerCounter(ultraSonic_t *ultraSonic) {
	return __HAL_TIM_GET_COUNTER(ultraSonic->hTim);
}

void UltraSonic_startTrig(ultraSonic_t *ultraSonic) {
	HAL_GPIO_WritePin(ultraSonic->GPIO_Trig, ultraSonic->GPIO_TrigPin, SET);
	DelayUS(15);
	HAL_GPIO_WritePin(ultraSonic->GPIO_Trig, ultraSonic->GPIO_TrigPin, RESET);
}

void UltraSonic_ISR_Process(ultraSonic_t *ultraSonic, uint16_t GPIO_Pin) {
	if (GPIO_Pin == ultraSonic->GPIO_EchoPin) {
		// Echo Pin High 유지 시간 측정
		if (UltraSonic_getEchopinState(ultraSonic)) { 	//Rising Edge
			UltraSonic_clearTimer(ultraSonic);					//CNT 0 Setting
			UltraSonic_startTimer(ultraSonic);					//Timer Start
			UltraSonic_clearEchoFlag(ultraSonic);
		}
		else { //Falling Edge
			UltraSonic_stopTimer(ultraSonic);
			ultraSonic->timCounter = UltraSonic_getTimerCounter(ultraSonic);
			UltraSonic_setEchoFlag(ultraSonic);
		}
	}
}

int UltraSonic_getDistance(ultraSonic_t *ultraSonic) {
	int timeout = 0;
	UltraSonic_startTrig(ultraSonic);
	while (!UltraSonic_isCmpltRecvEcho(ultraSonic)) {
		timeout++;
		if (timeout > 20) return 0;
		HAL_Delay(1);
	}
	UltraSonic_clearEchoFlag(ultraSonic);
	return ultraSonic->timCounter * 0.017;	//cm Distance
}
