/*
 * USDistanceModel.c
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#include "USDistanceModel.h"

USDistance_t USDistance;

void USDistanc_init(){
	USDistance.Distance_Front = 0;
	USDistance.Distance_Left = 0;
	USDistance.Distance_Right = 0;
}

void USDistance_set(int Front_Distance,int Left_Distance,int Right_Distance){
	USDistance.Distance_Front = Front_Distance;
	USDistance.Distance_Left = Left_Distance;
	USDistance.Distance_Right = Right_Distance;
}

USDistance_t USDistance_get(){
	return USDistance;
}
