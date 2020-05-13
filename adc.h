/*
 * adc.h
 *
 * Created: 2020-05-13 21:39:44
 *  Author: Knalle
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "p_drive.h"

#define ADC_REG_OFFSET		0x78

#define ADC_TRIG_FREE_RUN				0
#define ADC_TRIG_ANALOG_COMP			1
#define ADC_TRIG_EXTERNAL_INTERRUPT		2
#define ADC_TRIG_TIMER0_COMP_MATCH		3
#define ADC_TRIG_TIMER0_OVERFLOW		4
#define ADC_TRIG_TIMER1_COMP_MATCH		5
#define ADC_TRIG_TIMER1_OVERFLOW		6
#define ADC_TRIG_TIMER1_CAP_EVENT		7

#define ADC_PS_DIV_2	0
#define ADC_PS_DIV_4	2
#define ADC_PS_DIV_8	3
#define ADC_PS_DIV_16	4
#define ADC_PS_DIV_32	5
#define ADC_PS_DIV_64	6
#define ADC_PS_DIV_128	7

#define ADC_ADMUX_ADC0	0
#define ADC_ADMUX_ADC1	1
#define ADC_ADMUX_ADC2	2
#define ADC_ADMUX_ADC3	3
#define ADC_ADMUX_ADC4	4
#define ADC_ADMUX_ADC5	5
#define ADC_ADMUX_ADC6	6
#define ADC_ADMUX_ADC7	7

#define ADC_REFS_AREF			0
#define ADC_REFS_AVCC			1
#define ADC_REFS_INTERNAL_1V1	2
#define ADC_REFS_INTERNAL_2V56	3





typedef struct {
	
	// ADC – The ADC Data Register
	uint16_t result					: 16;		/**< Register containing the ADC result.*/
	
	// ADCSRA – ADC Control and Status Register A
	uint8_t prescaler				: 3;		/**< These bits determine the division factor between the system oscillator
													 frequency and the input clock to the ADC. Use the macro starting with ADC_PS_.*/
	uint8_t interrupt_enable		: 1;		/**< Enable the ADC complete interrupt. */
	uint8_t interrupt_flag			: 1;		/**< This bit is set when the AD conversion is complete and the data register is updated. */
	uint8_t auto_trig_enable		: 1;		/**< Trig source is set by the "ADC trigger select bits" in control register B. */
	uint8_t start_conversion		: 1;		/**< Set to one to start conversion. */
	uint8_t enable_adc				: 1;		/**< Set to one to enable the ADC. */
	
	// ADCSRB – ADC Control and Status Register B
	uint8_t trig_select				: 3;		/**< These bits selects the trig source for the ADC. Se the macro starting with ADC_TRIG_. */
	uint8_t reserved1				: 5;
	
	// ADMUX – ADC Multiplexer Selection Register
	uint8_t multiplexer				: 5;		/**< The value of these bits selects which combination of analog inputs are connected to the ADC.
														 See the macro starting with ADC_ADMUX_.*/
	uint8_t adlar					: 1;		/**< Write one to ADLAR to left adjust the result. Otherwise, the result is right adjusted, this is the default. */
	uint8_t reference_select		: 2;		/**< These bits select the voltage reference for the ADC. See the macros starting with ADC_REFS_.*/
	
	// Reserved register
	
	// DIDR0 – Digital Input Disable Register 0
	uint8_t digital_input_disabled	: 8;	/**< When an analog signal is applied to the ADC7..0 pin and the digital input from this pin is not needed, 
													 this bit should be written logic one to reduce power consumption in the digital input buffer.*/
	
} adc_regs_t;
	
void adc_init();


#endif /* ADC_H_ */