/* 
 * File:   external_interrupt.h
 * Author: ideapad GAMING
 *
 * Created on August 27, 2023, 11:49 PM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H

#include "interrupt_config.h"

#if INTERRUT_EXTERNAL_INTX ==ENABLE
#define INT0_ENABLE() (INTCONbits.INT0IE=1)
#define INT0_DISABLE() (INTCONbits.INT0IE=0)
#define INT0_CLEAR_FLAG()(INTCONbits.INT0IF=0)
#define INT0_RISING_EDGE() (INTCON2bits.INTEDG0=1)
#define INT0_FALLING_EDGE() (INTCON2bits.INTEDG0=0)

#define INT1_ENABLE() (INTCON3bits.INT1IE=1)
#define INT1_DISABLE() (INTCON3bits.INT1IE=0)
#define INT1_CLEAR_FLAG()(INTCON3bits.INT1IF=0)
#define INT1_RISING_EDGE() (INTCON2bits.INTEDG1=1)
#define INT1_FALLING_EDGE() (INTCON2bits.INTEDG1=0)


#define INT2_ENABLE() (INTCON3bits.INT2IE=1)
#define INT2_DISABLE() (INTCON3bits.INT2IE=0)
#define INT2_CLEAR_FLAG()(INTCON3bits.INT2IF=0)
#define INT2_RISING_EDGE() (INTCON2bits.INTEDG2=1)
#define INT2_FALLING_EDGE() (INTCON2bits.INTEDG2=0)
#if INTERRUPT_PRIORITY==ENABLE

#define INT1_HIGH_PRIORITY() (INTCON3bits.INT1IP=1)
#define INT1_LOW_PRIORITY() (INTCON3bits.INT1IP=0)
#define INT2_HIGH_PRIORITY() (INTCON3bits.INT2IP=1)
#define INT2_LOW_PRIORITY() (INTCON3bits.INT2IP=0)
#endif
#endif

#if INTERRUT_EXTERNAL_ON_CHANGE==ENABLE

#define RB_ENABLE() (INTCONbits.RBIE=1)
#define RB_DISABLE() (INTCONbits.RBIE=0)
#define RB_CLEAR_FLAG()(INTCONbits.RBIF=0)

#define RB_HIGH_PRIORITY() (INTCON2bits.RBIP=1)
#define RB_LOW_PRIORITY() (INTCON2bits.RBIP=0)

#endif 


/////////////
typedef enum{

    Rising_edge,
    Falling_edge
}Edge_t;

typedef enum{

    Int0,
            Int1,
            Int2
}Int_t;

typedef struct 
{   void (*EXT) (void);
    pin_config mypin;
    uint8 edge;
    uint8 source;
    uint8 priority;
}INTX_T;

typedef struct 
{
 void (*EXT_HIGH) (void);
  void (*EXT_LOW) (void);

    pin_config mypin;
    uint8 priority;
}RBX_T;
//////////////////////////////////
Std_ReturnType INTERRUPT_INTX_INIT(INTX_T * my_int);
Std_ReturnType INTERRUPT_INTX_DEINIT(INTX_T * my_int);
Std_ReturnType INTERRUPT_RBX_INIT(RBX_T * my_int);
Std_ReturnType INTERRUPT_RBX_DEINIT(RBX_T * my_int);
#endif	/* EXTERNAL_INTERRUPT_H */

