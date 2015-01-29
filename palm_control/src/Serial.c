/*
 * Serial.c
 *
 *  Created on: Jan 29, 2015
 *      Author: Artur
 */


#include <avr/io.h>


void serial_init(uint16_t ubrr_value){ //todo baudrate conversion

   // Set Baud rate
   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);

   /* Set Frame Format
   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit
   >> char size 8
   */
   UCSRC=(1<<URSEL) | (3<<UCSZ0);

   // Enable The receiver and transmitter
   UCSRB=(1<<RXEN) | (1<<TXEN);
}


void serial_sendByte(uint8_t byte){
	while(!(UCSRA & (1<<UDRE)));
	UDR = byte;
}


uint32_t serial_readByte(){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

