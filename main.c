/*
 * p_drive.c
 *
 * Created: 2020-05-12 23:42:04
 * Author : Knalle
 */ 
#include "p_drive.h"




volatile uint16_t adc_val;

volatile uint16_t ovf_cnt;

extern volatile timer1_regs_t			*timer1_regs;
extern volatile timer0_regs_t			*timer0_regs;
extern volatile timer_interrupt_reg_t	*timer_interrupt_reg;

extern volatile adc_regs_t	*adc_regs;

void btn_init();

int main(void)
{	
	timer1_fast_pwm_init();
	adc_init();
	timer0_init();
	sei();
	adc_regs->start_conversion	= 1;
	

    while (1) {
		
    }
}


ISR(ADC_vect){
	
	adc_val = adc_regs->result;
	adc_regs->start_conversion	= 1;
	
}

ISR(TIMER1_COMPB_vect) {
	
	timer1_regs->output_capture_reg_a = adc_val;
	timer1_regs->output_capture_reg_b = adc_val;
	
	//timer1_regs->output_capture_reg_a = 1023;
	//timer1_regs->output_capture_reg_b = 1023;
	
	
}

ISR(TIMER0_OVF_vect) {
	ovf_cnt++;
}

void btn_init(){
	BTN_PORT &= ~((1 << BTN1) | (1 << BTN2));
};
