/*
 * Controller.h
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#ifndef AP_CONTROLLERTASK_CONTROLLER_H_
#define AP_CONTROLLERTASK_CONTROLLER_H_

#include "../model/BT_dataQue.h"
#include "../model/MotorStateModel.h"
#include "../model/ModeStateModel.h"
#include "../model/USDistanceModel.h"
#include "../../driver/LCD/LCD.h"

void Controller_init();
void Controller_excuteTask();
void Controller_BTData();
void Controller_getData(uint8_t *Buff);
void Controller_Mode_decision(uint8_t *Buff);
void Controller_Mode_parsingData(uint8_t *Buff) ;
void Controller_Manual_parsingData(uint8_t *Buff) ;
void Controller_Auto_parsingData(uint8_t *Buff) ;
void Controller_Auto_DistanceState();

#endif /* AP_CONTROLLERTASK_CONTROLLER_H_ */
