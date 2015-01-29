/*
 * FingerControl.c
 *
 *  Created on: Jan 29, 2015
 *      Author: Artur
 */

#include "Palm.h"
#include <avr/io.h>


#define PINKY_I1 PIN0 // port C
#define PINKY_I2 PIN1 // port C
#define PINKY_PWM PIN2 // port C

#define RING_I1 PIN3 // port C
#define RING_I2 PIN5 // port C
#define RING_PWM PIN4 // port C

#define INDEX_I1 PIN5 // port B
#define INDEX_I2 PIN7 // port C
#define INDEX_PWM PIN6 // port C

#define MIDDLE_I1 PIN2 // port B
#define MIDDLE_I2 PIN3 // port B
#define MIDDLE_PWM PIN4 // port B

#define THUMB_I1 PIN6 // port D
#define THUMB_I2 PIN7 // port D
#define THUMB_PWM PIN0 // port B



void palm_init(){
	DDRB |= (1<<INDEX_I1) |  (1<<MIDDLE_I1) | (1<<MIDDLE_I2) | (1<<MIDDLE_PWM) |  (1<<THUMB_PWM);
	DDRC |= (1<<PINKY_I1) | (1<<PINKY_I2) | (1<<PINKY_PWM) | (1<<RING_I1) | (1<<RING_I2) | (1<<RING_PWM) | (1<<INDEX_I2) | (1<<INDEX_PWM);
	DDRD |= (1<<THUMB_I1) | (1<<THUMB_I2);


}


void palm_pinkyOpen(){
	PORTC &= ~(1<<PINKY_I2);
	PORTC |= (1<<PINKY_I1) | (1<<PINKY_PWM);
}
void palm_pinkyClose(){
	PORTC &= ~(1<<PINKY_I1);
	PORTC |= (1<<PINKY_I2) | (1<<PINKY_PWM);
}


void palm_ringOpen(){
	PORTC &= ~(1<<RING_I2);
	PORTC |= (1<<RING_I1) | (1<<RING_PWM);
}
void palm_ringClose(){
	PORTC &= ~(1<<RING_I1);
	PORTC |= (1<<RING_I2) | (1<<RING_PWM);
}


void palm_indexOpen(){
	PORTC &= ~(1<<INDEX_I2);
	PORTB |= (1<<INDEX_I1);
	PORTC |= (1<<INDEX_PWM);
}
void palm_indexClose(){
	PORTB &= ~(1<<INDEX_I1);
	PORTC |= (1<<INDEX_I2) | (1<<INDEX_PWM);
}


void palm_middleOpen(){
	PORTB &= ~(1<<MIDDLE_I2);
	PORTB |= (1<<MIDDLE_I1) | (1<<MIDDLE_PWM);
}
void palm_middleClose(){
	PORTB &= ~(1<<MIDDLE_I1);
	PORTB |= (1<<MIDDLE_I2) | (1<<MIDDLE_PWM);
}


void palm_thumbOpen(){
	PORTD &= ~(1<<THUMB_I2);
	PORTD |= (1<<THUMB_I1);
	PORTB |= (1<<THUMB_PWM);
}
void palm_thumbClose(){
	PORTD &= ~(1<<THUMB_I1);
	PORTD |= (1<<THUMB_I2);
	PORTB |= (1<<THUMB_PWM);
}


void palm_thumbAngle(uint8_t PWM){
}
void palm_thumbLeft(){
}
void palm_thumbRight(){
}
