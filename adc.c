/*
 * adc.c
 *
 * Created: 2020-05-13 22:59:19
 *  Author: Knalle
 */ 

#include "adc.h"

volatile adc_regs_t	*adc_regs = (volatile adc_regs_t *) ADC_REG_OFFSET;

void adc_init(){
	adc_regs->enable_adc		= 1;
	adc_regs->prescaler			= ADC_PS_DIV_64;
	adc_regs->interrupt_enable	= 1;
	adc_regs->multiplexer		= ADC_ADMUX_ADC5;
	adc_regs->reference_select	= ADC_REFS_AVCC;
	
}