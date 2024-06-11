/*
 * BT_dataQue.h
 *
 *  Created on: Apr 30, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_BT_DATAQUE_H_
#define AP_MODEL_BT_DATAQUE_H_

#include "../../Common/Queue/Queue.h"

#define BTSET			1
#define BTRESET		0

void BT_init();
void BT_enQue(uint8_t rxData);
uint8_t BT_deQue();
void BT_setFlag(int flagState);
int BT_getFlag();

#endif /* AP_MODEL_BT_DATAQUE_H_ */
