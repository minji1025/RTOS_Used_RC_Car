/*
 * Presenter.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "Presenter.h"
#include <stdio.h>
Motor_t leftMotor, rightMotor;

void Presenter_Init() {
	Motor_init(&leftMotor, &htim3, TIM_CHANNEL_1,
	LEFT_DIR1_GPIO, LEFT_DIR1_GPIO_PIN, LEFT_DIR2_GPIO, LEFT_DIR2_GPIO_PIN);
	Motor_init(&rightMotor, &htim3, TIM_CHANNEL_2,
	RIGHT_DIR1_GPIO, RIGHT_DIR1_GPIO_PIN, RIGHT_DIR2_GPIO, RIGHT_DIR2_GPIO_PIN);
	//초기 MotorSpeed
	Motor_setSpeed(&leftMotor, 550);
	Motor_setSpeed(&rightMotor, 550);
}

void Presenter_excuteTask() {
	int MotorFlag = MotorState_getFlag();
	static int OldModeFlag = NONE;
	int ModeFlag = ModeState_getFlag();

	if ((OldModeFlag==ModeFlag)&&!MotorFlag) return;	//둘 중 하나가 set되면 실행
	OldModeFlag = ModeFlag;
	Presenter_Mode_setState();

	MotorState_setFlag(RESET);
}

void Presenter_Mode_setState() {
	ModeState_t ModeState;
	ModeState = ModeState_get();
	switch (ModeState) {
		case MANUAL:
			LCD_writeStringXY(0, 0, "Car Manual!         ");
			Presenter_Manual_setState();
			break;
		case AUTO:
			LCD_writeStringXY(0, 0, "Car AUTO!           ");
			Presenter_Auto_setState();
			break;
	}
}

void Presenter_Manual_setState() {
	uint8_t ManualMotorState = MotorManualState_get();
	switch (ManualMotorState) {
		case GO:
			Presenter_CarGo();
			break;
		case BACK:
			Presenter_CarBack();
			break;
		case LEFT:
			Presenter_CarLeft();
			break;
		case RIGHT:
			Presenter_CarRight();
			break;
		case STOP:
			Presenter_CarStop();
			break;
		case SPEED:
			Presenter_CarSpeed();
			break;
//		default: //Stop
//			Presenter_CarStop();
//			break;
	}
}
void Presenter_CarGo() {
	LCD_writeStringXY(1, 0, "Car Go!        ");
	Motor_forward(&leftMotor);
	Motor_forward(&rightMotor);
}
void Presenter_CarStop() {
	LCD_writeStringXY(1, 0, "Car Stop!         ");
	Motor_stop(&leftMotor);
	Motor_stop(&rightMotor);
}
void Presenter_CarLeft() {
	LCD_writeStringXY(1, 0, "Car Left!        ");
	Motor_backward(&leftMotor);
	Motor_forward(&rightMotor);

}
void Presenter_CarRight() {
	LCD_writeStringXY(1, 0, "Car Right!          ");
	Motor_backward(&rightMotor);
	Motor_forward(&leftMotor);

}
void Presenter_CarBack() {
	LCD_writeStringXY(1, 0, "Car Back!          ");
	Motor_backward(&leftMotor);
	Motor_backward(&rightMotor);

}
void Presenter_CarSpeed() {
	char buff[30];
	sprintf(buff, "Car Speed!:%d", MotorState_getSpeed());
	LCD_writeStringXY(1, 0, buff);
	Motor_setSpeed(&leftMotor, MotorState_getSpeed());
	Motor_setSpeed(&rightMotor, MotorState_getSpeed());
}

void Presenter_Auto_setState() {
	uint8_t AutoMotorState = MotorAutoState_get();
	switch (AutoMotorState) {
		case GO:
			Presenter_CarGo();
			break;
		case BACK:
			Presenter_CarBack();
			break;
		case LEFT:
			Presenter_CarLeft();
			break;
		case RIGHT:
			Presenter_CarRight();
			break;
		case STOP:
			Presenter_CarStop();
			break;
		case NONE:
			Presenter_CarSpeed();
			break;
//		default: //Stop
//			Presenter_CarStop();
//			break;
	}
}
