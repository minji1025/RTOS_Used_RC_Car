/*
 * ModeStateModel.c
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#include "ModeStateModel.h"

MODE_t Mode;

void ModeState_init(){
	Mode.Modestate = MANUAL;
	Mode.ModeFlag = MODERESET;
}

void ModeState_set(int ModeState){
	Mode.Modestate = ModeState;
}

int ModeState_get(){
	return Mode.Modestate;
}

void ModeState_setFlag(int flagState){
	Mode.ModeFlag = flagState;
}

int ModeState_getFlag(){
	return Mode.ModeFlag;
}
