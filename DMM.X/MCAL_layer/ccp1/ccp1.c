#include "ccp1.h"
static void (* ccp1_call) (void)=NULL;
static void (* ccp2_call) (void)=NULL;
static void ccp_select_timer_(ccp_t * my_ccp)
{
    if(CCP1_CCP2_TIMER1==my_ccp->ccp_choose_timer)
    {
        T3CONbits.T3CCP1=0;
        T3CONbits.T3CCP2=0;

    
    }
    else if (CCP1_TIMER1_CCP2_TIMER3==my_ccp->ccp_choose_timer)

    {
    
    T3CONbits.T3CCP1=1;
        T3CONbits.T3CCP2=0;
    
    
    }
    else if (CCP1_CCP2_TIMER3==my_ccp->ccp_choose_timer)

    {
    
        T3CONbits.T3CCP1=1;
        T3CONbits.T3CCP2=1;
    
    
    }
}
/*if(my_ccp->ccp_number==1)
{

}
else if(my_ccp->ccp_number==2)
{

}*/

Std_ReturnType ccp_init(ccp_t * my_ccp)
{  Std_ReturnType ret=E_NOT_OK;

if(my_ccp->ccp_number==1)
{
ccp1_choose_mode(my_ccp->ccp_detailed_mode);

}
else if(my_ccp->ccp_number==2)
{
ccp2_choose_mode(my_ccp->ccp_detailed_mode);

}
   
 /////////////////////////////////////////////

if(my_ccp->ccp_number==1)
{
             #if  CCP1_INTERRUT ==ENABLE
  ret= CCP1_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_ccp->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
              CCP1_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
            CCP1_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        ccp1_call=my_ccp->ccp_inter;
        ret=  CCP1_INTERRUPT_ENABLE();
        
        #endif
}
else if(my_ccp->ccp_number==2)
{

    
       #if  CCP2_INTERRUT ==ENABLE
        ret= CCP2_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_ccp->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
              CCP2_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
            CCP2_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        ccp2_call=my_ccp->ccp_inter;
        ret=  CCP2_INTERRUPT_ENABLE();
        
          #endif  
    
}

    
        
    
        
 //////////////////////////////////
ret=gio_pin_init(&(my_ccp->my_pin));

if(my_ccp->ccp_mode_==ccp_pwm_mode__)
{
  //  uint32 temp=(my_ccp1->postscaler_value) * (my_ccp1->prescaler_value)* (my_ccp1->pwm_freq_)*4 ;
    PR2=(uint8)(( _XTAL_FREQ /( my_ccp->postscaler_value * 4.0 * my_ccp->prescaler_value * my_ccp->pwm_freq_ ))-1);
}


else if(my_ccp->ccp_mode_==ccp_capture_mode__)    
{
ccp_select_timer_(my_ccp);
}    


else if(my_ccp->ccp_mode_==ccp_compare_mode__)    
{
ccp_select_timer_(my_ccp);

} 


ret=E_OK;

   return ret;
}

Std_ReturnType ccp_is_capture_done (ccp_t * my_ccp,uint8* stat_)
{
Std_ReturnType ret=E_NOT_OK;
if(NULL==my_ccp || NULL== stat_)
{
ret=E_NOT_OK;
}
else{
    
    if(my_ccp->ccp_number==1)
{

         if(PIR1bits.CCP1IF==1)
    {
        *stat_=1;
          ret= CCP1_INTERRUPT_CLEAR_FLAG();
    }
    else {
    
        *stat_=0;
    }
        
}
else if(my_ccp->ccp_number==2)
{

     if(PIR2bits.CCP2IF==1)
    {
        *stat_=1;
          ret= CCP2_INTERRUPT_CLEAR_FLAG();
    }
    else {
    
        *stat_=0;
    }
    
}
    
    
   
    ret=E_OK;

}      
return ret;

}
  
Std_ReturnType ccp_capture_read_value(ccp_t * my_ccp,uint16* valu)
{
    reg_8_16 my_reg;
Std_ReturnType ret=E_NOT_OK;
if(NULL==my_ccp || NULL== valu)
{
ret=E_NOT_OK;
}
else{
    if(my_ccp->ccp_number==1)
{
my_reg.stcut_low=CCPR1L;
    my_reg.stcut_high=CCPR1H;
}
else if(my_ccp->ccp_number==2)
{
my_reg.stcut_low=CCPR2L;
    my_reg.stcut_high=CCPR2H;
}
    
    *valu=my_reg.stcut_all;
    ret=E_OK;

}      
return ret;

}



    
Std_ReturnType ccp_is_compare_done (ccp_t * my_ccp,uint8* stat_)
{
Std_ReturnType ret=E_NOT_OK;
if(NULL==my_ccp || NULL== stat_)
{
ret=E_NOT_OK;
}
else{
    
    if(my_ccp->ccp_number==1)
{

         if(PIR1bits.CCP1IF==1)
    {
        *stat_=1;
          ret= CCP1_INTERRUPT_CLEAR_FLAG();
    }
    else {
    
        *stat_=0;
    }
        
}
else if(my_ccp->ccp_number==2)
{

     if(PIR2bits.CCP2IF==1)
    {
        *stat_=1;
          ret= CCP2_INTERRUPT_CLEAR_FLAG();
    }
    else {
    
        *stat_=0;
    }
    
}
    
    
   
    ret=E_OK;

}      
return ret;

}
  








Std_ReturnType ccp_compare_write_value(ccp_t * my_ccp,uint16 valu)


{
    reg_8_16 my_reg;
Std_ReturnType ret=E_NOT_OK;
if(NULL==my_ccp || NULL== valu)
{
ret=E_NOT_OK;
}
else{
       my_reg.stcut_all=valu;

    if(my_ccp->ccp_number==1)
{
  CCPR1L =my_reg.stcut_low;
    CCPR1H=my_reg.stcut_high;
    ret=E_OK;
}
else if(my_ccp->ccp_number==2)
{
  CCPR2L =my_reg.stcut_low;
    CCPR2H=my_reg.stcut_high;
    ret=E_OK;
}
  

}      
return ret;

}



Std_ReturnType ccp_pwm_choose_duty_cycle (ccp_t * my_ccp,uint8 duty)
{  Std_ReturnType ret=E_OK;

    uint16 temp;
    
    temp=(PR2+1)*(duty/100.0)*4;
    if(my_ccp->ccp_number==1)
{
CCP1CONbits.CCP1M=temp&0x0003;
    CCPR1L=temp>>2;
}
else if(my_ccp->ccp_number==2)
{
CCP2CONbits.CCP2M=temp&0x0003;
    CCPR2L=temp>>2;
}
    
return ret;

}
  
Std_ReturnType ccp_pwm_start(ccp_t * my_ccp)
{
Std_ReturnType ret=E_OK;
    if(my_ccp->ccp_number==1)
{
ccp1_choose_mode(ccp_pwm_mode);

}
else if(my_ccp->ccp_number==2)
{
ccp2_choose_mode(ccp_pwm_mode);
;
}
return ret;
}
Std_ReturnType ccp_pwm_stop(ccp_t * my_ccp)
{
Std_ReturnType ret=E_OK;
    if(my_ccp->ccp_number==1)
{
ccp1_choose_mode(ccp_off_mode);

}
else if(my_ccp->ccp_number==2)
{
ccp2_choose_mode(ccp_off_mode);

}
return ret;
}

void ccp1_isr (void)
{
    CCP1_INTERRUPT_CLEAR_FLAG();
 
    if(ccp1_call)
    {ccp1_call();}

}

void ccp2_isr (void)
{
    CCP2_INTERRUPT_CLEAR_FLAG();
 
    if(ccp2_call)
    {ccp2_call();}

}
