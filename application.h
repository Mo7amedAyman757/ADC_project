/* 
 * File:   application.h
 * Author: LEGION
 *
 * Created on September 2, 2024, 2:20 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "ECU_Layer/ecu_layer_init.h"
#include "MCAL_Layer/interrupt/external_interrupt.h"
#include "MCAL_Layer/eeprom/hal_eeprom.h"
#include "MCAL_Layer/ADC/hal_adc.h"
#include "MCAL_Layer/Timers/hal_timer0.h"
#include "MCAL_Layer/Timers/hal_timer1.h"
#include "MCAL_Layer/Timers/hal_timer2.h"
#include "MCAL_Layer/Timers/hal_timer3.h"
/*Section : Macro Declaration*/


/*Section : Macro Function Declaration*/

/*Section : Data Type Declaration*/
extern led_t led1;
extern led_t led2;
extern led_t led3;
extern led_t led4;
//extern button_t btn1;
//extern button_t btn2;
//extern relay_t relay;
extern motor_t motor1;
extern motor_t motor2;
//extern segment_t seg;
//extern keypad_t keypad;
extern chr_lcd_4bit_t lcd_1;

uint8 program_selected = 0;
/*Section : Function Declaration*/
void application_initialize(void);

uint16 adc_res_1,adc_res_2, adc_res_3;
uint8 adc_res_1_txt[6],adc_res_2_txt[6],adc_res_3_txt[6];
uint16 lm35_res, lm35_res_celsuis_mv;

void ADC_Interrupt(void);

ADC_config_t adc_1 = {
    .InterruptHandler = ADC_Interrupt,
    .Aquisition_time = ADC_12_TAD,
    .Channel_Select = ADC_CHANNEL_AN0,
    .Conversion_Clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLE,
};

#endif	/* APPLICATION_H */

