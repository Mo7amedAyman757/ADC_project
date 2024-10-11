/* 
 * File:   interrrupt_manager.c
 * Author: LEGION
 *
 * Created on September 25, 2024, 10:37 PM
 */

#include "interrrupt_manager.h"
#if INTERRUPT_PORIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

void __interrupt() InterruptHighManager(void) {
    if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR)) {
        INT0_ISR();
    } else {
        /*Nothing*/
    }
}

void __interrupt(low_priority) InterruptLowManager(void) {


}

#else 

void __interrupt() InterruptManager(void) {
    if ((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR)) {
        INT0_ISR();
    } else {
        /*Nothing*/
    }
    //    if ((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCUR)) {
    //        INT1_ISR();
    //    } else {
    //        /*Nothing*/
    //    }
    if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (IOCBbits.IOCB4 == INTERRUPT_OCCUR) && (PORTBbits.RB4 == GPIO_HIGH)) {
        RB4_ISR(1);
    } else if ((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && (IOCBbits.IOCB4 == INTERRUPT_OCCUR) && (PORTBbits.RB4 == GPIO_LOW)) {
        RB4_ISR(0);
    } else {
        /*Nothing*/
    }
    if ((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCUR == PIR1bits.ADIF)) {
        ADC_ISR();
    } else {
        /*Nothing*/
    }

    if ((INTERRUPT_ENABLE == INTCONbits.TMR0IE) && (INTERRUPT_OCCUR == INTCONbits.TMR0IF)) {
        TMR0_ISR();
    } else {
        /*Nothing*/
    }
    if ((INTERRUPT_ENABLE == PIE1bits.TMR1IE) && (INTERRUPT_OCCUR == PIR1bits.TMR1IF)) {
        TMR1_ISR();
    } else {
        /*Nothing*/
    }
    if ((INTERRUPT_ENABLE == PIE1bits.TMR2IE) && (INTERRUPT_OCCUR == PIR1bits.TMR2IF)) {
        TMR2_ISR();
    } else {
        /*Nothing*/
    }
    if ((INTERRUPT_ENABLE == PIE2bits.TMR3IE) && (INTERRUPT_OCCUR == PIR2bits.TMR3IF)) {
        TMR3_ISR();
    } else {
        /*Nothing*/
    }
}
#endif