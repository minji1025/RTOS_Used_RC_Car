/*
 * Presenter.h
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#ifndef AP_PRESENTERTASK_PRESENTER_H_
#define AP_PRESENTERTASK_PRESENTER_H_

#include "../model/MotorStateModel.h"
#include "../model/ModeStateModel.h"
#include "../../driver/LCD/LCD.h"
#include "../../driver/Motor/Motor.h"

#define LEFT_DIR1_GPIO 		GPIOC
#define LEFT_DIR1_GPIO_PIN 	GPIO_PIN_7
#define	LEFT_DIR2_GPIO 		GPIOA
#define LEFT_DIR2_GPIO_PIN 	GPIO_PIN_9

#define RIGHT_DIR1_GPIO 	GPIOB
#define RIGHT_DIR1_GPIO_PIN GPIO_PIN_10
#define	RIGHT_DIR2_GPIO 	GPIOA
#define RIGHT_DIR2_GPIO_PIN GPIO_PIN_8
extern TIM_HandleTypeDef htim3;

void Presenter_Init();
void Presenter_excuteTask();
void Presenter_Mode_setState();
void Presenter_Manual_setState();
void Presenter_Auto_setState();
void Presenter_CarGo();
void Presenter_CarStop();
void Presenter_CarLeft();
void Presenter_CarRight();
void Presenter_CarBack();
void Presenter_CarSpeed();

#endif /* AP_PRESENTERTASK_PRESENTER_H_ */
