/*
 * FingerControl.h
 *
 *  Created on: Jan 29, 2015
 *      Author: Artur
 */

#ifndef PALM_H_
#define PALM_H_


#include <stdint.h>


void palm_init();

void palm_pinkyOpen();
void palm_pinkyClose();

void palm_ringOpen();
void palm_ringClose();

void palm_indexOpen();
void palm_indexClose();

void palm_middleOpen();
void palm_middleClose();

void palm_thumbOpen();
void palm_thumbClose();
void palm_thumbAngle(uint16_t duty);
void palm_thumbLeft();
void palm_thumbRight();


#endif /* CONFIG_H_ */
