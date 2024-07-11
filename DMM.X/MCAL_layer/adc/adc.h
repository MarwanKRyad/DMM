/* 
 * File:   adc.h
 * Author: ideapad GAMING
 *
 * Created on September 2, 2023, 7:51 AM
 */

#ifndef ADC_H
#define	ADC_H
#include <../proc/pic18f4620.h>

#include "../MCAL_std_types.h"
#include "../interrupt/internal_interrupt.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
//////////////////////////////////////////////////////////////////

#define ADC_POWER_ON() (ADCON0bits.ADON=1)
#define ADC_POWER_OFF() (ADCON0bits.ADON=0)

#define ADC_READ_CONVERSION_STATUS() (ADCON0bits.GO_nDONE)
#define ADC_START_CONVERSION()       (ADCON0bits.GO_nDONE=1)
#define DEF_VOLT 0
#define EXT_VOLT 1

#define ADC_DEF_V_REF() {ADCON1bits.VCFG1 = 0;\
                         ADCON1bits.VCFG0 = 0;\
                                        }
#define ADC_EXTERNAL_V_REF() {ADCON1bits.VCFG1 = 1;\
                              ADCON1bits.VCFG0 = 1;\
                             }

#define RIGH_FORMAT 1
#define LEFT_FORMAT 0

#define  ADC_Result_Format_RIGH() (ADCON2bits.ADFM=1)
#define  ADC_Result_Format_LEFT() (ADCON2bits.ADFM=0)

#define pin_time(Time_) (ADCON2bits.ACQT=Time_)
#define pin_clock(Clock_) (ADCON2bits.ADCS=Clock_)
#define pin_choose(choose_) (ADCON0bits.CHS=choose_)

////////////////////////////////////////////////////////////////
#define ADC_AN0_AND_BEFORE_ANALOG (0X0E)
#define ADC_AN1_AND_BEFORE_ANALOG (0X0D)
#define ADC_AN2_AND_BEFORE_ANALOG (0X0C)
#define ADC_AN3_AND_BEFORE_ANALOG (0X0B)
#define ADC_AN4_AND_BEFORE_ANALOG (0X0A)
#define ADC_AN5_AND_BEFORE_ANALOG (0X09)
#define ADC_AN6_AND_BEFORE_ANALOG (0X08)
#define ADC_AN7_AND_BEFORE_ANALOG (0X07)
#define ADC_AN8_AND_BEFORE_ANALOG (0X06)
#define ADC_AN9_AND_BEFORE_ANALOG (0X05)
#define ADC_AN10_AND_BEFORE_ANALOG 0X04)
#define ADC_AN11_AND_BEFORE_ANALOG (0X03)
#define ADC_ALL_ANALOG  (0X00)
#define ADC_ALL_DIGITAL  (0X0F)

#define ADC_CHOOSE_ANALOUG_PINS(ANALOG_PIN) (ADCON1bits.PCFG=ANALOG_PIN)




typedef enum 
{
    channel_a0,
    channel_a1,
    channel_a2,
    channel_a3,
    channel_a4,
    channel_a5,
    channel_a6,
    channel_a7,
    channel_a8,
    channel_a9,
    channel_a10,
    channel_a11,
    channel_a12


}analog_channel_t;
typedef enum 
      {
          TAD_0,
          TAD_2,
          TAD_4,
          TAD_6,
          TAD_8,
          TAD_12,
          TAD_16,
          TAD_20
      }adc_time_t;
 
typedef enum 
 {
      
 FOSC_over_2,
 FOSC_over_8,
 FOSC_over_32,
 FRC_ ,
 FOSC_over_4,
 FOSC_over_16,
 FOSC_over_64
      }adc_clock_t;
      typedef struct
      {
        #if  ADC_INTERRUT==ENABLE
          void (*ADC_INTER) (void);
          
          uint8 priority;
        #endif
          uint8 pin_name;
          uint8 v_ref;
          uint8 pin_time;
          uint8 pin_clock;
          uint8 res_format;
      
      
      
      }adc_pin_t;
      /////////////////////////////
Std_ReturnType adc_init(adc_pin_t * my_adc);
      
Std_ReturnType adc_deinit(adc_pin_t * my_adc);
Std_ReturnType adc_select_pin(adc_pin_t * my_adc ,uint8 my_pin);
Std_ReturnType adc_start_conv(adc_pin_t * my_adc );
Std_ReturnType adc_is_conv_end(adc_pin_t * my_adc ,uint8* my_ans);
Std_ReturnType adc_get_result(adc_pin_t * my_adc ,uint16 * myres);
Std_ReturnType adc_all_conv(adc_pin_t * my_adc ,uint8 my_pin,uint16 * myres);
Std_ReturnType adc_all_conv_inter(adc_pin_t * my_adc ,uint8 my_pin);





#endif	/* ADC_H */

        


