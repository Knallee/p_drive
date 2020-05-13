/*
 * p_drive.h
 *
 * Created: 2020-05-13 01:14:39
 *  Author: Knalle
 */ 


#ifndef P_DRIVE_H_
#define P_DRIVE_H_

#define F_CPU	8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

// IOs
#define OCR1_PORT	PORTD
#define LED			(4)
#define PUMP		(5)

#define BTN_PORT	PORTA
#define BTN1		(6)
#define BTN2		(7)

#define MAX_ADC_RES	1023



#endif /* P_DRIVE_H_ */