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
#include <avr/io.h>
#include <util/delay.h>
//#include <avr/iomx8.h>

void readAndSetFingers();
void readFromPort();

uint8_t GLOBAL_finger;
uint8_t GLOBAL_state;


// interrupt
//void serial_interruptInit(){ UCSR0B |= (1<<RXCIE0); }
//ISR(USART_RX_vect){
//	uint8_t temp;
//	temp = serial_readByte();
//	if ((temp & 0x81) == 0x81){
//		GLOBAL_finger = temp;
//		serial_sendByte(temp);
//	}
//	else if ((temp & 0x81) == 0x00){
//		GLOBAL_state = temp;
//		serial_sendByte(temp);
//	}
//	else
//		serial_sendByte(0x0F);
//}




int main(){

	OSCCAL = 0xC2; // calibration for 8MHz
	palm_init();
	serial_init();
	//serial_interruptInit();

	while(1){

		readFromPort();
		readAndSetFingers();

	}

	return 0;
}


void readFromPort(){
	uint8_t temp;
	temp = serial_readByte();
//	serial_sendByte(temp);
	if ((temp & 0x81) == 0x81){
		GLOBAL_finger = temp;
		serial_sendByte(temp);
	}
	else if ((temp & 0x81) == 0x00){
		GLOBAL_state = temp;
		serial_sendByte(temp);
	}
	else
		serial_sendByte(0x0F);
}


void readAndSetFingers(){
	uint8_t finger = GLOBAL_finger;
	uint8_t state = GLOBAL_state;

	if ((finger & 0x81) != 0x81) return;

	if (state == OPEN){
		if (finger & (1<<THUMB_OC)) palm_thumbOpen();
		if (finger & (1<<INDEX_OC)) palm_indexOpen();
		if (finger & (1<<MIDDLE_OC)) palm_middleOpen();
		if (finger & (1<<RING_OC)) palm_ringOpen();
		if (finger & (1<<PINKY_OC)) palm_pinkyOpen();

		if (finger & (1<<THUMB_LRM)) palm_thumbRight();
		return;
	}
	else if (state == CLOSE){
		if (finger & (1<<THUMB_OC)) palm_thumbClose();
		if (finger & (1<<INDEX_OC)) palm_indexClose();
		if (finger & (1<<MIDDLE_OC)) palm_middleClose();
		if (finger & (1<<RING_OC)) palm_ringClose();
		if (finger & (1<<PINKY_OC)) palm_pinkyClose();

		if (finger & (1<<THUMB_LRM)) palm_thumbLeft();
		return;
	}
	else if (state == MIDDLE){
		if (finger & (1<<THUMB_LRM)) palm_thumbMid();
		return;
	}
}
