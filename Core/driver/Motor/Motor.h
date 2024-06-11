/*
 * Motor.h
 *
 *  Created on: Apr 25, 2024
 *      Author: kccistc
 */

#ifndef DRIVER_MOTOR_MOTOR_H_
#define DRIVER_MOTOR_MOTOR_H_

#include "stm32f4xx_hal.h"

typedef struct {
	TIM_HandleTypeDef *htim;
	uint32_t Channel;
	GPIO_TypeDef *dir1_GPIO;
	uint16_t dir1_GPIO_Pin;
	GPIO_TypeDef *dir2_GPIO;
	uint16_t dir2_GPIO_Pin;
} Motor_t;

void Motor_init(Motor_t *Motor, TIM_HandleTypeDef *htim, uint32_t Channel,
		GPIO_TypeDef *dir1_GPIO, uint16_t dir1_GPIO_Pin, GPIO_TypeDef *dir2_GPIO,
		uint16_t dir2_GPIO_Pin);
void Motor_stop(Motor_t *Motor);
void Motor_forward(Motor_t *Motor);
void Motor_backward(Motor_t *Motor);
void Motor_setSpeed(Motor_t *Motor,int speedVal);

#endif /* DRIVER_MOTOR_MOTOR_H_ */
