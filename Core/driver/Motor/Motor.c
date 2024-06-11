/*
 * Motor.c
 *
 *  Created on: Apr 25, 2024
 *      Author: kccistc
 */

#include "Motor.h"


void Motor_init(Motor_t *Motor, TIM_HandleTypeDef *htim, uint32_t Channel,
		GPIO_TypeDef *dir1_GPIO, uint16_t dir1_GPIO_Pin, GPIO_TypeDef *dir2_GPIO,
		uint16_t dir2_GPIO_Pin) {
	Motor-> htim = htim;
	Motor-> Channel = Channel;
	Motor-> dir1_GPIO = dir1_GPIO;
	Motor-> dir1_GPIO_Pin = dir1_GPIO_Pin;
	Motor-> dir2_GPIO = dir2_GPIO;
	Motor-> dir2_GPIO_Pin = dir2_GPIO_Pin;
}

void Motor_stop(Motor_t *Motor) {
	HAL_TIM_PWM_Stop(Motor->htim, Motor->Channel);
}

void Motor_forward(Motor_t *Motor) {
	HAL_GPIO_WritePin(Motor->dir1_GPIO, Motor->dir1_GPIO_Pin, RESET);
	HAL_GPIO_WritePin(Motor->dir2_GPIO, Motor->dir2_GPIO_Pin, SET);
	HAL_TIM_PWM_Start(Motor->htim, Motor->Channel);
}
void Motor_backward(Motor_t *Motor) {
	HAL_GPIO_WritePin(Motor->dir1_GPIO, Motor->dir1_GPIO_Pin, SET);
	HAL_GPIO_WritePin(Motor->dir2_GPIO, Motor->dir2_GPIO_Pin, RESET);
	HAL_TIM_PWM_Start(Motor->htim, Motor->Channel);

}
void Motor_setSpeed(Motor_t *Motor,int speedVal) {
	__HAL_TIM_SET_COMPARE(Motor->htim, Motor->Channel, speedVal);
}
