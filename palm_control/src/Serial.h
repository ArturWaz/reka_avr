/*
 * serial.h
 *
 *  Created on: Jan 29, 2015
 *      Author: Artur
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>


void serial_init();

void serial_sendByte(uint8_t byte);

uint32_t serial_readByte();


#endif /* SERIAL_H_ */
