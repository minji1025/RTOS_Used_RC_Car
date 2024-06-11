/*
 * Listener.c
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#include "Listener.h"
#include <stdio.h>

button_t ManualButton, AutoButton;
ultraSonic_t ultraSonic_Front,ultraSonic_Left,ultraSonic_Right;

void Listner_init(TIM_HandleTypeDef *htim1, TIM_HandleTypeDef *htim2 ,TIM_HandleTypeDef *htim4) {
	ModeState_init();
	DelayInit();
	USDistanc_init();
	UltraSonic_init(&ultraSonic_Front, htim1, FRONT_GPIO_TRIG,
			FRONT_GPIO_TRIG_PIN,FRONT_GPIO_ECHO, FRONT_GPIO_ECHO_PIN);
	UltraSonic_init(&ultraSonic_Left, htim2, LEFT_GPIO_TRIG,
			LEFT_GPIO_TRIG_PIN,LEFT_GPIO_ECHO,LEFT_GPIO_ECHO_PIN);
	UltraSonic_init(&ultraSonic_Right, htim4, RIGHT_GPIO_TRIG,
			RIGHT_GPIO_TRIG_PIN,RIGHT_GPIO_ECHO, RIGHT_GPIO_ECHO_PIN);
	button_init(&ManualButton, GPIOC, GPIO_PIN_10);
	button_init(&AutoButton, GPIOC, GPIO_PIN_11);
}

void Listener_UART_ISR_Process(uint8_t rxData) {
	if (rxData == ';') {
		BT_enQue('\0');
		BT_setFlag(BTSET);
	}
	else {
		BT_enQue(rxData);
		BT_setFlag(BTRESET);
	}
}

void Listener_US_ISR_Process(uint16_t GPIO_Pin) {
	UltraSonic_ISR_Process(&ultraSonic_Front, GPIO_Pin);
	UltraSonic_ISR_Process(&ultraSonic_Left, GPIO_Pin);
	UltraSonic_ISR_Process(&ultraSonic_Right, GPIO_Pin);
}

void Listener_Button() {
	if (button_getState(&ManualButton) == ACT_RELEASED) {
		ModeState_set(MANUAL);
		ModeState_setFlag(MANUALFlag);
	}
	if (button_getState(&AutoButton) == ACT_RELEASED) {
		ModeState_set(AUTO);
		ModeState_setFlag(AUTOFlag);
	}
}

void Listener_UltraSonic_Distance(){
	int ModeState_Auto = ModeState_getFlag();
		if(ModeState_Auto != AUTOFlag) return;
		static int UltraSonicCount;
		static int distance_Front;
		static int distance_Left;
		static int distance_Right;

		switch (UltraSonicCount) {
			case 0:
				distance_Front = UltraSonic_getDistance(&ultraSonic_Front);
				printf("F : %d", distance_Front);
				break;
			case 1:
				distance_Left = UltraSonic_getDistance(&ultraSonic_Left);
				printf("L : %d", distance_Left);
				break;
			case 2:
				distance_Right = UltraSonic_getDistance(&ultraSonic_Right);
				printf("R : %d\n", distance_Right);
				break;
		}
		UltraSonicCount = (UltraSonicCount+1)%3;
		//printf("F:%d,L:%d,R:%d",distance_Front, distance_Left, distance_Right);
		USDistance_set(distance_Front, distance_Left, distance_Right);

}

