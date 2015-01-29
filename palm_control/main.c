/*
 * main.c
 *
 *  Created on: Jan 29, 2015
 *      Author: Artur
 */

#include "Config.h"
#include "Palm.h"
#include "Serial.h"
#include <stdint.h>

void readAndSetFingers();

int main(){

	palm_init();
	//serial_init(); // todo baudrate

	while(1){

		readAndSetFingers();

	}

	return 0;
}


void readAndSetFingers(){
	uint8_t finger = 0, state = 0;

	if (((finger = serial_readByte()) & 0x81) != 0x81) return;

	state = serial_readByte();
	if (state == OPEN){
		if (finger & (1<<THUMB_OC)) palm_thumbOpen();
		if (finger & (1<<INDEX_OC)) palm_indexOpen();
		if (finger & (1<<MIDDLE_OC)) palm_middleOpen();
		if (finger & (1<<RING_OC)) palm_ringOpen();
		if (finger & (1<<PINKY_OC)) palm_pinkyOpen();

		if (finger & (1<<THUMB_LRM)) palm_thumbRight();
	}
	else if (state == CLOSE){
		if (finger & (1<<THUMB_OC)) palm_thumbClose();
		if (finger & (1<<INDEX_OC)) palm_indexClose();
		if (finger & (1<<MIDDLE_OC)) palm_middleClose();
		if (finger & (1<<RING_OC)) palm_ringClose();
		if (finger & (1<<PINKY_OC)) palm_pinkyClose();

		if (finger & (1<<THUMB_LRM)) palm_thumbLeft();
	}
	else if (state == MIDDLE){
		if (finger & (1<<THUMB_LRM)) palm_thumbMid();
		return;
	}

}
