/*
 * File:   DMM_apps.c
 * Author: Marwan Khaled
 *
 * Created on April 7, 2024, 12:59 AM
 */
#include "app.h"
lcd_4 lcd={
.lcd_rs.my_direction=OUTPUT,
.lcd_rs.my_pin=pin1,
.lcd_rs.my_port=PORTd,
.lcd_rs.my_logic=LOW,

.lcd_e.my_direction=OUTPUT,
.lcd_e.my_pin=pin0,
.lcd_e.my_port=PORTd,
.lcd_e.my_logic=LOW,

.lcd_pins[0].my_direction=OUTPUT,
.lcd_pins[0].my_pin=pin0,
.lcd_pins[0].my_port=PORTc,
.lcd_pins[0].my_logic=LOW,

.lcd_pins[1].my_direction=OUTPUT,
.lcd_pins[1].my_pin=pin1,
.lcd_pins[1].my_port=PORTc,
.lcd_pins[1].my_logic=LOW,

.lcd_pins[2].my_direction=OUTPUT,
.lcd_pins[2].my_pin=pin2,
.lcd_pins[2].my_port=PORTc,
.lcd_pins[2].my_logic=LOW,

.lcd_pins[3].my_direction=OUTPUT,
.lcd_pins[3].my_pin=pin3,
.lcd_pins[3].my_port=PORTc,
.lcd_pins[3].my_logic=LOW,

};

adc_pin_t ADC_Pin=
 {
     .pin_name=channel_a0,
     .v_ref=DEF_VOLT,
     .pin_time=TAD_12,
     .pin_clock=FOSC_over_16,
     .res_format= RIGH_FORMAT, 
 };

void DC_Volt_Up_to_5_selection();
void DC_Volt_Up_to_50_selection();
void DC_Volt_Up_to_200_selection();

void AC_Volt_Up_to_5_selection();
void AC_Volt_Up_to_50_selection();
void AC_Volt_Up_to_200_selection();

void DC_Current_selection();
void AC_Current_selection();

void Resistance_Up_to_10k_selection();
void Resistance_Up_to_1M_selection();

void config_pins();
void Calculate_digits(float x,unsigned int *x2,unsigned int *x1,unsigned int *x0,unsigned int *x_1,unsigned int *x_2);

void Display_volt(lcd_4 *My_lcd,unsigned int x2,unsigned int x1,unsigned int x0,unsigned int x_1,unsigned int x_2);
void Display_Current(lcd_4 *My_lcd,unsigned int x2,unsigned int x1,unsigned int x0,unsigned int x_1,unsigned int x_2);
void Display_Resistance(lcd_4 *My_lcd,unsigned int x2,unsigned int x1,unsigned int x0,unsigned int x_1,unsigned int x_2);

uint16 ADC_Val;

int main(void)
  {   float  x ;
      unsigned int x2,x1,x0,x_1,x_2;
      lcd_4bit_initilization(&lcd);
      adc_init(&ADC_Pin);
      config_pins();

      while(1)
        {   
            if(PORTBbits.RB5==1) // dc volt up to 5 volt range
             {   
                 DC_Volt_Up_to_5_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 10051 / 51.0f)*(float)( 450.0f / 20000);
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_volt(&lcd,x2,x1,x0,x_1,x_2);
             }

            if(PORTBbits.RB4==1) // dc volt up to 50 volt range
             {   DC_Volt_Up_to_50_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 10051 / 51.0f)*(float)( 1350.0f / 20000.0f);
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_volt(&lcd,x2,x1,x0,x_1,x_2);
             }
            
            
            if(PORTBbits.RB3==1) // dc volt up to 200 volt range
             {  DC_Volt_Up_to_200_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 10051 / 51.0f)*(float)( 5050.0f / 20000.0f);
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_volt(&lcd,x2,x1,x0,x_1,x_2);
             }
             
            
            if(PORTBbits.RB2==1) // Ac volt  up to 5 volt range
             {   AC_Volt_Up_to_5_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 10051 / 51.0f)*(float)( 450.0f / 20000.0f)*( 22700.0f/22000 );
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_volt(&lcd,x2,x1,x0,x_1,x_2);
             }
             
            if(PORTBbits.RB1==1) // Ac volt  up to 50 volt range
             {   AC_Volt_Up_to_50_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 10051 / 51.0f)*(float)( 1350.0f / 20000.0f)*( 22700.0f/22000 );
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_volt(&lcd,x2,x1,x0,x_1,x_2);
             }
             
            if(PORTBbits.RB0==1) // Ac volt  up to 200 volt range
             {   AC_Volt_Up_to_200_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 10051 / 51.0f)*(float)( 5050.0f / 20000.0f)*( 22700.0f/22000 );
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_volt(&lcd,x2,x1,x0,x_1,x_2);
  
             }
             
            if(PORTDbits.RD7==1) // Dc Current  
             {   DC_Current_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 2.0f/10)*(float)( 100350.0f/100000.0f);
                 x=x*1000.0f;
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_Current(&lcd,x2,x1,x0,x_1,x_2);
             }
             
            if(PORTDbits.RD6==1) // Ac Current  
             {   AC_Current_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=x*(float)( 2.0f/10)*(float)( 22700.0f/22000.0f);
                 x=x*1000.0f;
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_Current(&lcd,x2,x1,x0,x_1,x_2);
             }
             
            if(PORTDbits.RD5==1) // R 10K 
             { 
                 Resistance_Up_to_10k_selection();
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=(float)(1350.0f * x) / (float)( 5.0f-x );
                 x=x/1000.0f;
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_Resistance(&lcd,x2,x1,x0,x_1,x_2);
             }
             
             
            if(PORTDbits.RD4==1) // R 1M
             {   Resistance_Up_to_1M_selection();          
                 adc_start_conv(&ADC_Pin);
                 adc_get_result(&ADC_Pin,&ADC_Val);
                 x=(float)(ADC_Val*5)/1023;
                 x=(float)(1500350.0f * x) / (float)( 5.0f-x );
                 x=x/1000.0f;
                 Calculate_digits(x,&x2,&x1,&x0,&x_1,&x_2);
                 Display_Resistance(&lcd,x2,x1,x0,x_1,x_2);
             }
        
        }
     
    return 0;  
    

 }

void Display_volt(lcd_4 *My_lcd,unsigned int x2,unsigned int x1,unsigned int x0,unsigned int x_1,unsigned int x_2)
 {
      lcd_4bit_sned_character_at_pos(My_lcd,1,1,x2+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,2,x1+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,3,x0+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,4,'.');
     lcd_4bit_sned_character_at_pos(My_lcd,1,5,x_1+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,6,x_2+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,7,'V');
     lcd_4bit_sned_character_at_pos(My_lcd,1,8,' ');
     lcd_4bit_sned_character_at_pos(My_lcd,1,9,' ');
     lcd_4bit_sned_character_at_pos(My_lcd,1,10,' ');

 }


void Display_Current(lcd_4 *My_lcd,unsigned int x2,unsigned int x1,unsigned int x0,unsigned int x_1,unsigned int x_2)
 {
     lcd_4bit_sned_character_at_pos(My_lcd,1,1,x2+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,2,x1+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,3,x0+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,4,'.');
     lcd_4bit_sned_character_at_pos(My_lcd,1,5,x_1+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,6,x_2+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,7,'m');
     lcd_4bit_sned_character_at_pos(My_lcd,1,8,'A');
     lcd_4bit_sned_character_at_pos(My_lcd,1,9,' ');
     lcd_4bit_sned_character_at_pos(My_lcd,1,10,' ');
 }

void Display_Resistance(lcd_4 *My_lcd,unsigned int x2,unsigned int x1,unsigned int x0,unsigned int x_1,unsigned int x_2)
  {
     lcd_4bit_sned_character_at_pos(My_lcd,1,1,x2+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,2,x1+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,3,x0+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,4,'.');
     lcd_4bit_sned_character_at_pos(My_lcd,1,5,x_1+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,6,x_2+'0');
     lcd_4bit_sned_character_at_pos(My_lcd,1,7,'K');
     lcd_4bit_sned_character_at_pos(My_lcd,1,8,'o');
     lcd_4bit_sned_character_at_pos(My_lcd,1,9,'h');
     lcd_4bit_sned_character_at_pos(My_lcd,1,10,'m');

  
  }

void Calculate_digits(float x,unsigned int *x2,unsigned int *x1,unsigned int *x0,unsigned int *x_1,unsigned int *x_2)
{ 
(*x2)=x/100 ;       (*x1)=(x-(*x2)*100)/10 ;         (*x0)=(x-(*x2)*100-(*x1)*10) ; 
       *x_1=(x*100-(*x2)*10000-(*x1)*1000-(*x0)*100)/10;
       *x_2=(x*100-(*x2)*10000-(*x1)*1000-(*x0)*100-(*x_1)*10);

}

void config_pins()
{


TRISBbits.TRISB5 = 1;
TRISBbits.TRISB4 = 1;
TRISBbits.TRISB3 = 1;
TRISBbits.TRISB2 = 1;
TRISBbits.TRISB1 = 1;
TRISBbits.TRISB0 = 1;
TRISDbits.TRISD7 = 1;
TRISDbits.TRISD6 = 1;
TRISDbits.TRISD5 = 1;
TRISDbits.TRISD4 = 1;

TRISAbits.TRISA6 = 0;
TRISAbits.TRISA5 = 0;
TRISAbits.TRISA4 = 0;
TRISAbits.TRISA3 = 0;
TRISAbits.TRISA2 = 0;
TRISAbits.TRISA1 = 0;
}

void DC_Volt_Up_to_5_selection()
{
LATAbits.LATA4=0;
LATAbits.LATA3=0;
LATAbits.LATA2=1;
LATAbits.LATA1=0;
LATAbits.LATA5=0; 
}


void DC_Volt_Up_to_50_selection()
{
LATAbits.LATA4=0;
LATAbits.LATA3=0;
LATAbits.LATA2=0;
LATAbits.LATA1=1;
LATAbits.LATA5=0; 
}
void DC_Volt_Up_to_200_selection()
{
LATAbits.LATA4=0;
LATAbits.LATA3=0;
LATAbits.LATA2=0;
LATAbits.LATA1=0;
LATAbits.LATA5=0;
}
void AC_Volt_Up_to_5_selection()
{
LATAbits.LATA4=1;
LATAbits.LATA3=0;
LATAbits.LATA2=1;
LATAbits.LATA1=0;
LATAbits.LATA5=1;
LATAbits.LATA6=0;
}
void AC_Volt_Up_to_50_selection()
{
LATAbits.LATA4=1;
LATAbits.LATA3=0;
LATAbits.LATA2=0;
LATAbits.LATA1=1;
LATAbits.LATA5=1;
LATAbits.LATA6=0;
}
void AC_Volt_Up_to_200_selection()
{
LATAbits.LATA4=1;
LATAbits.LATA3=0;
LATAbits.LATA2=0;
LATAbits.LATA1=0;
LATAbits.LATA5=1;
LATAbits.LATA6=0;
}

void DC_Current_selection()
{
LATAbits.LATA4=0;
LATAbits.LATA3=1;
LATCbits.LATC2=0;
LATAbits.LATA5=0;
}
void AC_Current_selection()
{
LATAbits.LATA4=1;
LATAbits.LATA3=0;
LATAbits.LATA5=1; 
LATAbits.LATA6=1;
LATAbits.LATA5=1;
}
void Resistance_Up_to_10k_selection()
{
LATAbits.LATA4=1;
LATAbits.LATA3=1;
LATAbits.LATA5=1;
}
void Resistance_Up_to_1M_selection()
{
LATAbits.LATA4=1;
LATAbits.LATA3=1;
LATAbits.LATA5=0;
}