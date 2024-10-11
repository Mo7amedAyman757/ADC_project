/* 
 * File:   application.h
 * Author: LEGION
 *
 * Created on September 2, 2024, 2:20 PM
 */


#include "application.h"


STD_ReturnType ret = E_OK;
uint8 ADC_flag;

int main() {
    application_initialize();
    lcd_4bit_send_char_string_pos(&lcd_1, 1, 4, (uint8 *) "ADC TEST");
    __delay_ms(1000);
    lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
    ret = lcd_4bit_send_char_string_pos(&lcd_1, 1, 2, (uint8 *) " POT1: ");
    ret = lcd_4bit_send_char_string_pos(&lcd_1, 2, 1, (uint8 *) "POT2: ");
    while (1) {

        if (ADC_flag == 0) {
            ret = ADC_StartConversion_Interrupt(&adc_1, ADC_CHANNEL_AN0);
        } else if (ADC_flag == 1) {
            ret = ADC_StartConversion_Interrupt(&adc_1, ADC_CHANNEL_AN1);
        } else if (ADC_flag == 2) {
            ret = ADC_StartConversion_Interrupt(&adc_1, ADC_CHANNEL_AN2);
        }

        ret = convert_short_to_string(adc_res_1, adc_res_1_txt);
        ret = convert_short_to_string(adc_res_2, adc_res_2_txt);

        ret = lcd_4bit_send_char_string_pos(&lcd_1, 1, 7, adc_res_1_txt);
        ret = lcd_4bit_send_char_string_pos(&lcd_1, 2, 7, adc_res_2_txt);

        lm35_res_celsuis_mv = (uint16) (lm35_res * 4.88f);
        lm35_res_celsuis_mv /= 10;

        //        ret = convert_short_to_string(lm35_res_celsuis_mv, adc_res_2_txt);
        //        ret = lcd_4bit_send_char_string_pos(&lcd_1, 1, 10, adc_res_2_txt);
        if (lm35_res_celsuis_mv > 25) {
            motor_move_forward(&motor1);
            motor_move_forward(&motor2);
        } else if (lm35_res_celsuis_mv <= 25) {
            motor_move_backward(&motor1);
            motor_move_backward(&motor2);
        } else {

        }
    }
}

void application_initialize(void) {
    ecu_layer_initialize();
    ret = ADC_init(&adc_1);
}

void ADC_Interrupt(void) {
    if (ADC_flag == 0) {
        ret = ADC_GetConversionResult(&adc_1, &adc_res_1);
        ADC_flag = 1;
    } else if (ADC_flag == 1) {
        ret = ADC_GetConversionResult(&adc_1, &adc_res_2);
        ADC_flag = 2;
    } else if (ADC_flag == 2) {
        ret = ADC_GetConversionResult(&adc_1, &lm35_res);
        ADC_flag = 0;
    }
}

