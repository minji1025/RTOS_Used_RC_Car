/*
 * ModeStateModel.h
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODESTATEMODEL_H_
#define AP_MODEL_MODESTATEMODEL_H_

#include "../../Common/Queue/Queue.h"

#define MODESET			1
#define MODERESET		0

typedef enum{MANUAL,AUTO}ModeState_t;
typedef enum{NONEFlag,MANUALFlag,AUTOFlag}ModeFlag_t;

typedef struct{
	ModeState_t Modestate;
	ModeFlag_t ModeFlag;
}MODE_t;



void ModeState_init();
void ModeState_set(int ModeState);
int ModeState_get();
void ModeState_setFlag(int flagState);
int ModeState_getFlag();


#endif /* AP_MODEL_MODESTATEMODEL_H_ */
