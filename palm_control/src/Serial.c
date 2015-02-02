/*
 * Serial.c
 *
 *  Created on: Jan 29, 2015
 *      Author: Artur
 */


#include <avr/io.h>
#include <avr/iomx8.h>

#define BAUDRATE 9600

void serial_init(){

	DDRD |= (1<<PIN1);
	uint16_t ubrr_value = (((F_CPU / (BAUDRATE * 16UL))) - 1);

    // Set Baud rate
	UBRR0L = ubrr_value;
	UBRR0H = (ubrr_value>>8);

	/* Set Frame Format
   	 >> Asynchronous mode
   	 >> No Parity
   	 >> 1 StopBit
     >> char size 8
	 */
	UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);

	// Enable The receiver and transmitter
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}


void serial_sendByte(uint8_t byte){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}


uint32_t serial_readByte(){
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

