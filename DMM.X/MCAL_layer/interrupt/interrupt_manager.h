/* 
 * File:   interrupt_manager.h
 * Author: ideapad GAMING
 *
 * Created on August 27, 2023, 11:50 PM
 */

#ifndef INTERRUPT_MANAGER_H
#define	INTERRUPT_MANAGER_H

#include "interrupt_config.h"
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(void);
void RB4_ISR2(void);
void RB5_ISR(void);

void RB5_ISR2(void);
void RB6_ISR(void);
void RB6_ISR2(void);
void RB7_ISR(void);

void RB7_ISR2(void);
void adc_isr (void);
void timer0_isr (void);
void timer1_isr (void);
void timer2_isr (void);
void timer3_isr (void);
void ccp1_isr (void);
void ccp2_isr (void);
void rx_isr (void);
void tx_isr (void);
void i2c_isr (void);


#endif	/* INTERRUPT_MANAGER_H */

