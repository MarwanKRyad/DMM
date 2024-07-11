#include "i2c.h"
static void (* i2c_call) (void)=NULL;

 Std_ReturnType i2c_init(i2c_t * my_i2c)
 {
     TRISCbits.RC3=1;
     TRISCbits.RC4=1;
     SSPCON1bits.SSPM=my_i2c->i2c_full_mode;
     if(my_i2c->i2c_mode==I2C_MASTER_MODE)
     {
      if(my_i2c->i2c_full_mode==I2C_MASTER_MODE_WITH_CLOCK)
     {  SSPADD = (uint8)(((_XTAL_FREQ / 4.0) / my_i2c->clock_rate) - 1);}
     
     }
     else if(my_i2c->i2c_mode==I2C_SLAVE_MODE)
     {
     SSPCON2bits.GCEN=my_i2c->general_call;
     SSPCON1bits.CKP=1;
     SSPADD=my_i2c->i2c_address;
     SSPCON2bits.SEN=1;
     }
     SSPSTATbits.SMP=my_i2c->i2c_slew_rate_enable;
     SSPSTATbits.CKE=my_i2c->i2c_smbus_enable;
     MSSP_MODULE_ENABLE_CFG();
     /////////////////////////////////////////////
 #if  I2C_INTERRUT ==ENABLE
  I2C_INTERRUPT_CLEAR_FLAG();
         #if INTERRUPT_PRIORITY==ENABLE
         INTERRUPT_ENABLE_PRIORITY();
         if(my_i2c->i2c_priority==High_Priority)
         {
             INTERRUPT_ENABLE_GLOBAL_HIGH_INTERRUPT();
             I2C_INTERRUPT_HIGH_PRIORITY();
         
         }
         else
         {
             INTERRUPT_ENABLE_GLOBAL_LOW_INTERRUPT();
           I2C_INTERRUPT_LOW_PRIORITY();
         }
        #elif INTERRUPT_PRIORITY==DISABLE
        INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
        INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        i2c_call=my_i2c->i2c_inter_;
         I2C_INTERRUPT_ENABLE();
        
#endif
 //////////////////////////////////
     

 }
  Std_ReturnType i2c_send_start(i2c_t * my_i2c)
 {Std_ReturnType ret=E_NOT_OK;
    PIE1bits.SSPIE=0;
     SSPCON2bits.SEN=1;
    while(SSPCON2bits.SEN==1)
    {}
     PIR1bits.SSPIF=0;
     PIE1bits.SSPIE=1;
     if(SSPSTATbits.S==I2C_START_BIT_DET)
     {
         ret=E_OK;
     }
     else if(SSPSTATbits.S==I2C_START_BIT_NOT_DET)
     {ret=E_NOT_OK;
     }
     return ret;

 }
  Std_ReturnType i2c_send_repeated_start(i2c_t * my_i2c)
 {Std_ReturnType ret=E_NOT_OK;
    PIE1bits.SSPIE=0;
     SSPCON2bits.RSEN=1;
    while(SSPCON2bits.RSEN==1)
    {}
     PIR1bits.SSPIF=0;
     PIE1bits.SSPIE=1;
   
     return ret;

 }
  Std_ReturnType i2c_send_stop(i2c_t * my_i2c)
  {Std_ReturnType ret=E_NOT_OK;
    PIE1bits.SSPIE=0;
     SSPCON2bits.PEN=1;
    while(SSPCON2bits.PEN==1)
    {}
     PIR1bits.SSPIF=0;
     PIE1bits.SSPIE=1;
     if(SSPSTATbits.P==I2C_STOP_BIT_DET)
     {
         ret=E_OK;
     }
     else if(SSPSTATbits.P==I2C_STOP_BIT_NOT_DET)
     {ret=E_NOT_OK;
     }
     return ret;

 }
  Std_ReturnType i2c_wrtie_byte(i2c_t * my_i2c , uint8 value,uint8 *ack)
  {
  SSPBUF=value;
      PIE1bits.SSPIE=0;

    while(PIR1bits.SSPIF==0);
    PIR1bits.SSPIF=0;
    PIE1bits.SSPIE=1;
    if(SSPCON2==Acknowledge_was_received_from_slave)
    {*ack=1;}
    else {*ack=0;}
    
  }
  Std_ReturnType i2c_read_byte(i2c_t * my_i2c , uint8* value,uint8 ack)
  {
  I2C_MASTER_RECEIVE_ENABLE_CFG();
  while(SSPSTATbits.BF==0);
  *value=SSPBUF;
  SSPCON2bits.ACKDT=ack;
  SSPCON2bits.ACKEN=1;
  
  
  
  }
void i2c_isr (void)
{
    I2C_INTERRUPT_CLEAR_FLAG();
    if(i2c_call)
    {i2c_call();}

}
  Std_ReturnType i2c_send_frame(i2c_t * my_i2c , uint8 address,uint8 value , uint8* wrtie_ack , uint8 read_ack)
  {
  
  

    i2c_send_start(my_i2c);
i2c_wrtie_byte(my_i2c,address,wrtie_ack);
i2c_wrtie_byte(my_i2c,value,read_ack);

  i2c_send_stop(my_i2c);
  
  }
