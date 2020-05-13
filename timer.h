/*
 * timer.h
 *
 * Created: 2020-05-12 23:47:02
 *  Author: Knalle
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>

#define TIMER_INTERRUPT_REG_OFFSET	0x6E

#define TIMER1_CONT_REG_OFFSET		0x80


#define NORMAL_OPERATION			0
#define WGM1_FAST_PWM_ICR_TOP		2
#define WGM2_FAST_PWM_ICR_TOP		3

#define WGM1_FAST_PWM_OCR_TOP		3
#define WGM2_FAST_PWM_OCR_TOP		3

#define COM1_NORMAL_OP				0
#define COM1_TOGGLE_ON_MATCH		1
#define COM1_CLEAR_ON_MATCH			2
#define COM1_SET_ON_MATCH			3


#define CS1_NO_CLOCK				0
#define CS1_FCPU_DIV_1				1
#define CS1_FCPU_DIV_8				2
#define CS1_FCPU_DIV_64				3
#define CS1_FCPU_DIV_256			4
#define CS1_FCPU_DIV_1024			5
#define CS1_EXTERNAL_FALLING		6
#define CS1_EXTERNAL_RISING			7



typedef struct {
	// TCCR1A – Timer/Counter1 Control Register A
	uint8_t waveform_gen_mode1		: 2;	/**< Combined with the waveform_gen_mode2 (WGMn3:2) bits in the TCCR1B Register, 
												 type of waveform generated. Use the macros starting with WGM1_.*/
	uint8_t reserved1				: 2;	/**< Reserved bits, read only.*/
	uint8_t COM1B					: 2;	/**< Compare Output Mode for Channel B. Use macro starting with COM1_.*/
	uint8_t COM1A					: 2;	/**< Compare Output Mode for Channel A. Use macro starting with COM1_*/
	
	// TCCR1B – Timer/Counter1 Control Register B
	uint8_t clock_sel				: 3;	/**< Selects the clock source to be used by the Timer/Counter 1. Use the macro starting with CS1_*/
	uint8_t waveform_gen_mode2		: 2;	/**< Combined with the waveform_gen_mode1 (WGMn1:0) bits in the TCCR1A Register, 
												 type of waveform generated.  Use the macros starting with WGM2_.*/
	uint8_t reserved2				: 1;	/**< Reserved bits, read only.*/
	uint8_t incap_edge_sel			: 1;	/**< This bit selects which edge on the Input Capture pin (ICPn) that is used to trigger a capture event.*/
	uint8_t incap_n_canceler		: 1;	/**< Setting this bit activates the Input Capture Noise Canceler.*/
	
	// TCCR1C – Timer/Counter1 Control Register C
	uint8_t reserved3				: 6;	/**< Reserved bits, read only.*/
	uint8_t force_out_cap_compare_b	: 1;	/**< When writing a logical one to the FOCnA/FOCnB bit, an immediate 
												 compare match is forced on the Waveform Generation unit. Must be 
												 set to zero when TCCRnA is written when operating in a PWM mode*/
	uint8_t force_out_cap_compare_a	: 1;	/**< See force_out_cap_compare_b.*/
	
	// Reserved Register
	uint8_t reserved4				: 8;	/**< Reserved bits, read only.*/
	
	// TCNT1H and TCNT1L –Timer/Counter1
	uint16_t count_reg				: 16;	/**< Counter register of timer/counter 1. */
	
	// ICR1 - Input Capture Register 1
	uint16_t input_capture_reg		: 16;	/**< The output compare register for channel a of timer/counter 1. */
	
	// OCR1A and OCR1B – Output Compare Register 1 A and B
	uint16_t output_capture_reg_a	: 16;	/**< The output compare register for channel a of timer/counter 1. */
	uint16_t output_capture_reg_b	: 16;	/**< The output compare register for channel b of timer/counter 1. */
	
	
} timer1_regs_t;


typedef struct {
	// TIMSK0 – Timer/Counter0 Interrupt Mask Register
	uint8_t timer0_overflow_int				: 1;	/**< Set to one enables the overflow interrupt of timer 1. */
	uint8_t timer0_output_comp_match_a_int	: 1;	/**< Set to one enables the output compare match interrupt for channel a. */
	uint8_t timer0_output_comp_match_b_int	: 1;	/**< Set to one enables the output compare match interrupt for channel b. */
	uint8_t timer0_reserved1				: 5;	/**< Reserved bits, read only.*/
		
	
	// TIMSK1 – Timer/Counter1 Interrupt Mask Register
	uint8_t timer1_overflow_int				: 1;	/**< Set to one enables the overflow interrupt of timer 1. */
	uint8_t timer1_output_comp_match_a_int	: 1;	/**< Set to one enables the output compare match interrupt for channel a. */
	uint8_t timer1_output_comp_match_b_int	: 1;	/**< Set to one enables the output compare match interrupt for channel b. */
	uint8_t timer1_reserved2				: 2;	/**< Reserved bits, read only.*/
	uint8_t timer1_input_cap_interrupt		: 1;	/**< Set to one enables the input capture interrupt of timer 1.*/
	uint8_t timer1_reserved3				: 2;	/**< Reserved bits, read only.*/
	
	
	// TIMSK2 – Timer/Counter2 Interrupt Mask Register
	uint8_t timer2_overflow_int				: 1;	/**< Set to one enables the overflow interrupt of timer 1. */
	uint8_t timer2_output_comp_match_a_int	: 1;	/**< Set to one enables the output compare match interrupt for channel a. */
	uint8_t timer2_output_comp_match_b_int	: 1;	/**< Set to one enables the output compare match interrupt for channel b. */
	uint8_t timer2_reserved1				: 5;	/**< Reserved bits, read only.*/
	
} timer_interrupt_reg_t;



#endif /* TIMER_H_ */