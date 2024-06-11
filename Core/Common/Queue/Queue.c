/*
 * Queue.c
 *
 *  Created on: Apr 26, 2024
 *      Author: kccistc
 */
#include "Queue.h"

void Que_init(Que_t *Que)
{
	Que->head = 0;
	Que->tail = 0;
	Que->QueCounter = 0;
	Que->cmpltFlag = 0;
}

void setQueFlag(Que_t *Que, int flagState){
	Que->cmpltFlag = flagState;
}

int getQueFlag(Que_t *Que){
	return Que->cmpltFlag;
}


int QueFull(Que_t *Que)
{
	//if(head == ((tail+1) % BUF_SIZE))
	if(Que->QueCounter == BUF_SIZE)
		return 1;
	else
		return 0;
}
int QueEmpty(Que_t *Que)
{
	//if(head == tail)
	if(Que->QueCounter == 0)
		return 1;
	else
		return 0;
}

void enQue(Que_t *Que, uint8_t data)			// push(write)
{
	if(QueFull(Que)) return;

	Que->QueBuff[Que->tail] = data;
	Que->tail = (Que->tail+1) % BUF_SIZE;			// tail : 0~3
	Que->QueCounter++;
}

uint8_t deQue(Que_t *Que)			// pop(read)
{
	if(QueEmpty(Que)) return -1;

	uint8_t temp = Que->QueBuff[Que->head];
	Que->head = (Que->head+1) % BUF_SIZE;			// head : 0~3
	Que->QueCounter--;

	return temp;
}
