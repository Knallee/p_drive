/*
 * p_drive.c
 *
 * Created: 2020-05-12 23:42:04
 * Author : Knalle
 */ 
#include "p_drive.h"




volatile timer1_regs_t			*timer1_regs			= (volatile timer1_regs_t *)			TIMER1_CONT_REG_OFFSET;
volatile timer_interrupt_reg_t	*timer_interrupt_reg	= (volatile timer_interrupt_reg_t *)	TIMER_INTERRUPT_REG_OFFSET;


int main(void)
{
	DDRD |= (1 << LED);
	DDRD |= (1 << PUMP);
	
	timer1_regs->waveform_gen_mode1			= WGM1_FAST_PWM_ICR_TOP;
	timer1_regs->waveform_gen_mode2			= WGM2_FAST_PWM_ICR_TOP;
	timer1_regs->COM1A						= COM1_CLEAR_ON_MATCH;
	timer1_regs->COM1B						= COM1_CLEAR_ON_MATCH;
	timer1_regs->clock_sel					= CS1_FCPU_DIV_64;
	timer1_regs->input_capture_reg			= MAX_ADC_RES;
	timer1_regs->output_capture_reg_b		= (MAX_ADC_RES >> 1);
	timer1_regs->output_capture_reg_a		= (MAX_ADC_RES >> 1);
	
	timer_interrupt_reg->timer1_output_comp_match_b_int = 1;
	sei();
	

    while (1) {
		
    }
}

