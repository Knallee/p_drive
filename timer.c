/*
 * timer.c
 *
 * Created: 2020-05-12 23:47:17
 *  Author: Knalle
 */ 

#include "timer.h"

volatile timer1_regs_t			*timer1_regs			= (volatile timer1_regs_t *)			TIMER1_CONT_REG_OFFSET;
volatile timer0_regs_t			*timer0_regs			= (volatile timer0_regs_t *)			TIMER0_CONT_REG_OFFSET;
volatile timer_interrupt_reg_t	*timer_interrupt_reg	= (volatile timer_interrupt_reg_t *)	TIMER_INTERRUPT_REG_OFFSET;


void timer1_fast_pwm_init() {
	DDRD |= (1 << LED);
	DDRD |= (1 << PUMP);
	
	timer1_regs->waveform_gen_mode1			= TIMER1_WGM1_FAST_PWM_ICR_TOP;
	timer1_regs->waveform_gen_mode2			= TIMER1_WGM2_FAST_PWM_ICR_TOP;
	timer1_regs->COM1A						= TIMER1_COM1_CLEAR_ON_MATCH;
	timer1_regs->COM1B						= TIMER1_COM1_CLEAR_ON_MATCH;
	timer1_regs->clock_sel					= TIMER1_CS1_FCPU_DIV_64;
	timer1_regs->input_capture_reg			= MAX_ADC_RES;
	timer1_regs->output_capture_reg_b		= (MAX_ADC_RES >> 1);
	timer1_regs->output_capture_reg_a		= (MAX_ADC_RES >> 1);
	
	timer_interrupt_reg->timer1_output_comp_match_b_int = 1;
}

void timer0_init(){
	
	timer0_regs->clock_sel = TIMER0_CS0_FCPU_DIV_1024;
	timer_interrupt_reg->timer0_overflow_int = 1;
	
}