#include "interrupt_manager.h"
#include <../proc/pic18f4620.h>
uint8 volatile flag_4=1;
uint8 volatile flag_5=1;
uint8 volatile flag_6=1;
uint8 volatile flag_7=1;
//static volatile uint8 RX_Data;
extern volatile uint8 i2c_slave1_rec_data;

#if INTERRUPT_PRIORITY ==ENABLE
void __interrupt() interrupt_high() 
    
{   
    if((INTERRUPT_ENABLE==INTCONbits.INT0IE)&&(INTERRUPT_OCUURED==INTCONbits.INT0IF))
        {INT0_ISR();}
    else {}
    ///////////////////////////////////////////////
    if((PORTBbits.KBI0==1)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
            &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_4==1))
        {RB4_ISR();
         flag_4=0;
        }
    else {}
   if((PORTBbits.KBI0==0)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
           &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_4==0))
        {RB4_ISR2();
        flag_4=1;
        }
    /////////////////////////////////////////////////////////////
     if((PORTBbits.KBI1==1)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
             &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_5==1))
        {RB5_ISR();
         flag_5=0;
        }
    else {}
   if((PORTBbits.KBI1==0)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
           &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_5==0))
        {RB5_ISR2();
        flag_5=1;
        }
    else {}
    /////////////////////////////////////////////////////////////
      if((PORTBbits.KBI2==1)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
            &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_6==1))
        {RB6_ISR();
         flag_6=0;
        }
    else {}
   if((PORTBbits.KBI2==0)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
           &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_6==0))
        {RB6_ISR2();
        flag_6=1;
        }
    /////////////////////////////////////////////////////////////
     if((PORTBbits.KBI3==1)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
             &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_7==1))
        {RB7_ISR();
         flag_7=0;
        }
    else {}
   if((PORTBbits.KBI3==0)&&(INTERRUPT_ENABLE==INTCONbits.RBIE)
           &&(INTERRUPT_OCUURED==INTCONbits.RBIF)&&(flag_7==0))
        {RB7_ISR2();
        flag_7=1;
        }
    else {}
    /////////////////////////////////////////////////////////////
    if((INTERRUPT_ENABLE==PIE1bits.ADIE)&&(INTERRUPT_OCUURED==PIR1bits.ADIF))
        {adc_isr();}
    else{}
    
    
    
    
   
   
}

void __interrupt(low_priority) interrupt_low(void)
{   
    if((INTERRUPT_ENABLE==INTCON3bits.INT2E)&&(INTERRUPT_OCUURED==INTCON3bits.INT2F))
        {INT2_ISR();}
    else {}
    if((INTERRUPT_ENABLE==INTCON3bits.INT1E)&&(INTERRUPT_OCUURED==INTCON3bits.INT1F))
        {
        INT1_ISR();}
    else {}
}



#elif INTERRUPT_PRIORITY ==DISABLE
void __interrupt() interrupt_ALL() 

{
    if((INTERRUPT_ENABLE==INTCONbits.INT0IE)&&(INTERRUPT_OCUURED==INTCONbits.INT0IF))
        {INT0_ISR();}
    else {}
    if((INTERRUPT_ENABLE==INTCON3bits.INT1IE)&&(INTERRUPT_OCUURED==INTCON3bits.INT1IF))
        {INT1_ISR();}
    else {}
    if((INTERRUPT_ENABLE==INTCON3bits.INT2IE)&&(INTERRUPT_OCUURED==INTCON3bits.INT2IF))
        {INT2_ISR();}
    else {}
     if((INTERRUPT_ENABLE==INTCONbits.RBIE)&&(INTERRUPT_OCUURED==INTCONbits.RBIF))
        {RB4_ISR();}
    else {}
}
#endif