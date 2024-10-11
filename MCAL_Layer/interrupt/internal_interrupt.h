/* 
 * File:   internal_interrupt.h
 * Author: LEGION
 *
 * Created on September 25, 2024, 10:37 PM
 */

#ifndef INTERNAL_INTERRUPT_H
#define	INTERNAL_INTERRUPT_H
/* Section : Includes */
#include "mcal_interrupt.h"

/*Section : Macro Function Declaration*/
/************ADC************/
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable ADC interrupt*/
#define ADC_INTERRUPT_ENABLE()     (PIE1bits.ADIE = 1)
/*Disable ADC interrupt*/
#define ADC_INTERRUPT_DISABLE()     (PIE1bits.ADIE = 0)
/*Clear flag of ADC interrupt*/
#define ADC_INTERRUPT_CLEAR_FLAG() (PIR1bits.ADIF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
/*This macro will enable high  priority of ADC module*/
#define ADC_HIGH_PRIORITY()         (IPR1bits.ADIP = 1)
/*This macro will enable low  priority of ADC module*/
#define ADC_LOW_PRIORITY()         (IPR1bits.ADIP = 0)
#endif
#endif
/************TIMER0************/
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable TIMER0 interrupt*/
#define TIMER0_INTERRUPT_ENABLE()      (INTCONbits.TMR0IE = 1)
/*Disable TIMER0 interrupt*/
#define TIMER0_INTERRUPT_DISABLE()     (INTCONbits.TMR0IE = 0)
/*Clear flag of TIMER0 interrupt*/
#define TIMER0_INTERRUPT_CLEAR_FLAG()  (INTCONbits.TMR0IF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
/*This macro will enable high  priority of TIMER0 module*/
#define TIMER0_HIGH_PRIORITY()        (INTCON2bits.TMR0IP = 1)
/*This macro will enable low  priority of TIMER0 module*/
#define TIMER0_LOW_PRIORITY()         (INTCON2bits.TMR0IP = 0)
#endif
#endif
/************TIMER1************/
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable TIMER1 interrupt*/
#define TIMER1_INTERRUPT_ENABLE()      (PIE1bits.TMR1IE = 1)
/*Disable TIMER1 interrupt*/
#define TIMER1_INTERRUPT_DISABLE()     (PIE1bits.TMR1IE = 0)
/*Clear flag of TIMER1 interrupt*/
#define TIMER1_INTERRUPT_CLEAR_FLAG()  (PIR1bits.TMR1IF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
/*This macro will enable high  priority of TIMER1 module*/
#define TIMER1_HIGH_PRIORITY()        (IPR1bits.TMR1IP = 1)
/*This macro will enable low  priority of TIMER1 module*/
#define TIMER1_LOW_PRIORITY()         (IPR1bits.TMR1IP = 0)
#endif
#endif
/************TIMER2************/
#if TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable TIMER2 interrupt*/
#define TIMER2_INTERRUPT_ENABLE()      (PIE1bits.TMR2IE = 1)
/*Disable TIMER2 interrupt*/
#define TIMER2_INTERRUPT_DISABLE()     (PIE1bits.TMR2IE = 0)
/*Clear flag of TIMER2 interrupt*/
#define TIMER2_INTERRUPT_CLEAR_FLAG()  (PIR1bits.TMR2IF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
/*This macro will enable high  priority of TIMER2 module*/
#define TIMER2_HIGH_PRIORITY()        (IPR1bits.TMR2IP = 1)
/*This macro will enable low  priority of TIMER2 module*/
#define TIMER2_LOW_PRIORITY()         (IPR1bits.TMR2IP = 0)
#endif
#endif
/************TIMER3************/
#if TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable TIMER3 interrupt*/
#define TIMER3_INTERRUPT_ENABLE()      (PIE2bits.TMR3IE = 1)
/*Disable TIMER3 interrupt*/
#define TIMER3_INTERRUPT_DISABLE()     (PIE2bits.TMR3IE= 0)
/*Clear flag of TIMER3 interrupt*/
#define TIMER3_INTERRUPT_CLEAR_FLAG()  (PIR2bits.TMR3IF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
/*This macro will enable high  priority of TIMER3 module*/
#define TIMER3_HIGH_PRIORITY()        (IPR2bits.TMR3IP = 1)
/*This macro will enable low  priority of TIMER3 module*/
#define TIMER3_LOW_PRIORITY()         (IPR2bits.TMR3IP = 0)
#endif
#endif
/*Section : Macro Declaration*/





/*Section : Data Type Declaration*/


/*Section : Function Declaration*/


#endif	/* INTERNAL_INTERRUPT_H */

