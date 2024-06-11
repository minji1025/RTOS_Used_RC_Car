/*
 * USDistanceModel.h
 *
 *  Created on: May 1, 2024
 *      Author: kccistc
 */

#ifndef AP_MODEL_USDISTANCEMODEL_H_
#define AP_MODEL_USDISTANCEMODEL_H_

typedef struct{
	int Distance_Front;
	int Distance_Left;
	int Distance_Right;
}USDistance_t;

void USDistanc_init();
void USDistance_set(int Front_Distance,int Left_Distance,int Right_Distance);
USDistance_t USDistance_get();


#endif /* AP_MODEL_USDISTANCEMODEL_H_ */
