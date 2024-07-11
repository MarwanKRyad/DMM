#include "adc.h"
static void (* adc_call) (void)=NULL;
static Std_ReturnType adc_input_pin(uint8 my_pin)
{

    switch(my_pin)
    { case(channel_a0): SET_BITE(TRISA,_TRISA_RA0_POSN); break;
             case(channel_a1): SET_BITE(TRISA,_TRISA_RA1_POSN);break;
             case(channel_a2): SET_BITE(TRISA,_TRISA_RA2_POSN);break;
             case(channel_a3): SET_BITE(TRISA,_TRISA_RA3_POSN);break;
             case(channel_a4): SET_BITE(TRISA,_TRISA_RA5_POSN);break;
              
             case(channel_a5): SET_BITE(TRISE,_TRISE_RE0_POSN);break;
             case(channel_a6): SET_BITE(TRISE,_TRISE_RE1_POSN);break;
              case(channel_a7): SET_BITE(TRISE,_TRISE_RE2_POSN);break;
                            case(channel_a8): SET_BITE(TRISB,_TRISB_RB2_POSN);break;
                            case(channel_a9): SET_BITE(TRISB,_TRISB_RB3_POSN);break;
                            case(channel_a10): SET_BITE(TRISB,_TRISB_RB1_POSN);break;
                            case(channel_a11): SET_BITE(TRISB,_TRISB_RB4_POSN);break;
                            case(channel_a12): SET_BITE(TRISB,_TRISB_RB0_POSN);break;}



}


Std_ReturnType adc_init(adc_pin_t * my_adc)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_adc == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        
        
 adc_input_pin(my_adc->pin_name);      
 pin_time(my_adc->pin_time) ;
 pin_clock(my_adc->pin_clock) ;
 pin_choose(my_adc->pin_name);
 /////////////////////////////////////////////
 #if  ADC_INTERRUT==ENABLE
  ret=ADC_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_adc->priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
             ADC_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
           ADC_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        adc_call=my_adc->ADC_INTER;
        ret= ADC_INTERRUPT_ENABLE();
        
#endif
 //////////////////////////////////
 if(my_adc->res_format==RIGH_FORMAT)
 { ADC_Result_Format_RIGH();}
 else

 {ADC_Result_Format_LEFT();}
 //////////////////////////////////////
 if(my_adc->v_ref==DEF_VOLT)   
 {ADC_DEF_V_REF();}
 else 
 {
     ADC_EXTERNAL_V_REF();
 }
 ////////////////////////////////////
 ADC_POWER_ON();
        ret=E_OK;
    }
return ret;
}

Std_ReturnType adc_select_pin(adc_pin_t * my_adc ,uint8 my_pin)
{
   Std_ReturnType ret=E_NOT_OK;

    if( my_adc == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {    pin_choose(my_pin);

         adc_input_pin(my_pin);      

        ret=E_OK;
    }
return ret;
}
Std_ReturnType adc_start_conv(adc_pin_t * my_adc )
        {
   Std_ReturnType ret=E_NOT_OK;

    if( my_adc == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        ADC_START_CONVERSION();
        ret=E_OK;
    }
return ret;
}
Std_ReturnType adc_is_conv_end(adc_pin_t * my_adc ,uint8* my_ans)
        {
   Std_ReturnType ret=E_NOT_OK;

    if( my_adc == NULL || my_ans==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   if(ADC_READ_CONVERSION_STATUS()==0) {*my_ans=1;} 
    else
    {
        *my_ans=0;
    }
        
        ret=E_OK;
    }
return ret;
}
Std_ReturnType adc_get_result(adc_pin_t * my_adc ,uint16 * myres)
        {
   Std_ReturnType ret=E_NOT_OK;

    if( my_adc == NULL || myres==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   if(my_adc->res_format==RIGH_FORMAT)
        *myres=(ADRESH<<8)+ADRESL;
    else 
    {
    *myres=(((ADRESH<<8)+ADRESL)>>6);
    
    }
        ret=E_OK;
    }
return ret;
}
Std_ReturnType adc_all_conv(adc_pin_t * my_adc ,uint8 my_pin,uint16 * myres)
               {
   Std_ReturnType ret=E_NOT_OK;
   uint8 my_ans;
    if( my_adc == NULL || myres==NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   adc_select_pin(my_adc,my_pin);
        adc_start_conv(my_adc);
        do {
        adc_is_conv_end(my_adc,&my_ans);}
        while(my_ans==0);
        
        adc_get_result(my_adc,myres);
        ret=E_OK;
    }
return ret;
}
Std_ReturnType adc_deinit(adc_pin_t * my_adc)
                     {
   Std_ReturnType ret=E_NOT_OK;

    if( my_adc == NULL )
    {
        ret=E_NOT_OK;
    }
    else 
    {   
        ADC_POWER_OFF();
        ret=E_OK;
    }
return ret;
}


Std_ReturnType adc_all_conv_inter(adc_pin_t * my_adc ,uint8 my_pin)
             {
   Std_ReturnType ret=E_NOT_OK;
   uint8 my_ans;
    if( my_adc == NULL  )
    {
        ret=E_NOT_OK;
    }
    else 
    {   adc_select_pin(my_adc,my_pin);
        adc_start_conv(my_adc);
    
        ret=E_OK;
    }
return ret;


}
void adc_isr (void)
{
    ADC_INTERRUPT_CLEAR_FLAG();
    if(adc_call)
    {adc_call();}

}