#include "EUSART.h"
static void (* tx_call) (void)=NULL;
static void (* rx_call) (void)=NULL;


void baud_rate_calc(eusart_t * eusart);
void tx_mode_init(eusart_t * eusart);
void rx_mode_init(eusart_t * eusart);

Std_ReturnType eusart_init(eusart_t * eusart)
{
RCSTAbits.SPEN=EUSART_DISABLE;
TRISCbits.RC6=1;
TRISCbits.RC7=1;
baud_rate_calc(eusart);
tx_mode_init(eusart);
rx_mode_init(eusart);


RCSTAbits.SPEN=EUSART_ENABLE;

}

 Std_ReturnType eusart_tx_write_byte_blocking_with_enable(uint8 val)
 {    while(!TXSTAbits.TRMT);
        TXREG=val;        
        TX_INTERRUPT_ENABLE();

 

 }
 
 Std_ReturnType eusart_tx_write_byte_blocking_without_enable(uint8 val)
 {      while(!TXSTAbits.TRMT);
     TXREG=val;

 }
 
 Std_ReturnType eusart_tx_write_string_blocking(eusart_t * eusart,uint8 val[],uint16 size_)
 {      for(int i=0;i<size_;i++)
     if(eusart->tx_config.tx_inter==1)
     { eusart_tx_write_byte_blocking_with_enable (val[i]);}
     else { eusart_tx_write_byte_blocking_without_enable (val[i]);}



  
 }
  
  
Std_ReturnType eusart_rx_read_byte_blocking(uint8 *val)
   {
       Std_ReturnType ret = E_NOT_OK;
    while(!PIR1bits.RCIF);
    
    *val = RCREG;
    return ret;
   
   }


void baud_rate_calc(eusart_t * eusart)
{
    float temp=0;
    switch (eusart->choose_baudrate_equ)
    {case _8BIT_Asynchronous_low : 
        TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
           TXSTAbits.BRGH=EUSART_LOW_SPEED;
           BAUDCONbits.BRG16=EUSART_8BIT;
           temp=((_XTAL_FREQ/(float)eusart->baudrate )/64)-1;
            break;
    
    case _8BIT_Asynchronous_high : 
        TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
           TXSTAbits.BRGH=EUSART_HIGH_SPEED;
           BAUDCONbits.BRG16=EUSART_8BIT;
                       temp=((_XTAL_FREQ/(float)eusart->baudrate )/16)-1;

            break;
    
    
    case _16BIT_Asynchronous_low : 
        
            TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
           TXSTAbits.BRGH=EUSART_LOW_SPEED;
           BAUDCONbits.BRG16=EUSART_16BIT;
                                  temp=((_XTAL_FREQ/(float)eusart->baudrate )/16)-1;

            break;
    
    
    case _16BIT_Asynchronous_high : 
        TXSTAbits.SYNC=EUSART_ASYNCHRONOUS_MODE;
           TXSTAbits.BRGH=EUSART_HIGH_SPEED;
           BAUDCONbits.BRG16=EUSART_16BIT;
     temp=((_XTAL_FREQ/(float)eusart->baudrate )/4)-1;

            break;
    
    
    case _8BIT_synchronous : 
        
            TXSTAbits.SYNC=EUSART_SYNCHRONOUS_MODE;
                       BAUDCONbits.BRG16=EUSART_8BIT;
     temp=((_XTAL_FREQ/(float)eusart->baudrate )/4)-1;

            break;
            
            
    case _16BIT_synchronous : 
        
            TXSTAbits.SYNC=EUSART_SYNCHRONOUS_MODE;
           BAUDCONbits.BRG16=EUSART_16BIT;
                temp=((_XTAL_FREQ/(float)eusart->baudrate )/4)-1;

            break;
    
    }
SPBRG=temp;

SPBRGH=((uint32)temp)>>8;
}

void tx_mode_init(eusart_t * eusart)
{
    if(eusart->tx_config.tx_enable==EUSART_ASYNCHRONOUS_TX_ENABLE)
    {
    TXSTAbits.TXEN=EUSART_ASYNCHRONOUS_TX_ENABLE;
    
       if(eusart->tx_config.tx_9_8_bit==EUSART_ASYNCHRONOUS_TX_9bit)
            {
                TXSTAbits.TX9=EUSART_ASYNCHRONOUS_TX_9bit;
            }
       else 
            {
                TXSTAbits.TX9=EUSART_ASYNCHRONOUS_TX_8bit;

            }
       
    
    
    if(eusart->tx_config.tx_inter==1)     
       {  

         #if  TX_INTERRUT ==ENABLE
          // 
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(eusart->tx_config.tx_priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
              TX_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
            TX_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        tx_call=eusart->tx_config.tx_inter_;
        TX_INTERRUPT_ENABLE();
        #endif
       
       }
       else{}
    
    }
    
    else 
    {
    
        TXSTAbits.TXEN=EUSART_ASYNCHRONOUS_TX_DISABLE;

    
    
    }

}
void rx_mode_init(eusart_t * eusart)
{
    if(eusart->rx_config.rx_enable==EUSART_ASYNCHRONOUS_RX_ENABLE)
    {
    RCSTAbits.CREN=EUSART_ASYNCHRONOUS_RX_ENABLE;
    
       if(eusart->rx_config.rx_9_8_bit==EUSART_ASYNCHRONOUS_RX_9bit)
            {
                 RCSTAbits.RX9=EUSART_ASYNCHRONOUS_RX_9bit;
            }
       else 
            {
                RCSTAbits.RX9=EUSART_ASYNCHRONOUS_RX_8bit;

            }
      if(eusart->rx_config.rx_inter==1)     
       {
          #if  RX_INTERRUT ==ENABLE
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(eusart->rx_config.rx_priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
              RX_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
            RX_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        rx_call=eusart->rx_config.rx_inter_;
         RX_INTERRUPT_ENABLE();
        
        #endif
       
       }
       else{}
    
    }
    
    else 
    {
    
        RCSTAbits.CREN=EUSART_ASYNCHRONOUS_RX_DISABLE;

    
    
    }

}
void rx_isr (void)
{
   
    if(rx_call)
    {rx_call();}

}

void tx_isr (void)
{
   TX_INTERRUPT_DISABLE();
    if(tx_call)
    {tx_call();}

}