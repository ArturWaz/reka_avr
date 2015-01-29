/*
 * PWM.h
 *
 *  Created on: Jan 29, 2015
 *      Author: Artur
 */

#ifndef SERVO_H_
#define SERVO_H_


#include <avr/io.h>


 //todo finish this section

/*
 * Servo parameters:
 *
 * Cycle: 20ms (50Hz)
 * Duty (middle): 1.5ms (...)
 * Clock frequency: 8MHz
 * Timer: OC1A
 *
 */
void servo_init(){
	DDRB |= (1<<PIN1); // set OC1A as a output
	ICR1 = 20001; // set cycle equal 20ms
	servo_setMiddle(); // set servo in the middle

	// set FAST PWM, with prescaler eaqual to 8
	TCCR1A = (1<<WGM11) | (1<<COM1A0);
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS11);
}

inline void servo_setMiddle(){ OCR1A = 1500; } // 1.5ms

inline void servo_setMin(){ OCR1A = 1000; } // 1ms

inline void servo_setMax(){ OCR1A = 2000; } // 2ms

inline void servo_set(uint16_t duty){ OCR1A = duty; }


#endif /* SERVO_H_ */
