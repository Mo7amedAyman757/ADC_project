/* 
 * File:   mcal_interrupt_cfg.h
 * Author: LEGION
 *
 * Created on September 25, 2024, 10:36 PM
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H

/* Section : Includes */
#include"../GPIO/hal_gpio.h"
/*Section : Macro Function Declaration*/
#define INTERRUPT_FEATURE_ENABLE  1U

//#define INTERRUPT_PRIORITY_LEVEL_ENABLE    INTERRUPT_FEATURE_ENABLE

#define EXTERNAL_INTERRUPT_INTX_ENABLE      INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_ONCHANGE_ENABLE  INTERRUPT_FEATURE_ENABLE

#define ADC_INTERRUPT_FEATURE_ENABLE    INTERRUPT_FEATURE_ENABLE

#define TIMER0_INTERRUPT_FEATURE_ENABLE    INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_FEATURE_ENABLE    INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_FEATURE_ENABLE    INTERRUPT_FEATURE_ENABLE
#define TIMER3_INTERRUPT_FEATURE_ENABLE    INTERRUPT_FEATURE_ENABLE
/*Section : Macro Declaration*/

/*Section : Data Type Declaration*/

/*Section : Function Declaration*/

#endif	/* MCAL_INTERRUPT_CFG_H */

