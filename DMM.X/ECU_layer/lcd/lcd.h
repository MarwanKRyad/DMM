/* 
 * File:   lcd.h
 * Author: ideapad GAMING
 *
 * Created on August 15, 2023, 3:11 AM
 */

#ifndef LCD_H
#define	LCD_H
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#define LCD_CLEAR 0X1
#define LCD_RETURN_HOME 0X2
#define LCD_INCREMENT_ADDRESS 0X6
#define LCD_DECREMENT_ADDRESS 0X4
#define LCD_DISLPAY_OFF 0X8
#define LCD_DISLPAY_ON_UNDERLINE_CURSER_OFF_SIDE_OFF 0X0C
#define LCD_DISLPAY_ON_UNDERLINE_CURSER_OFF_SIDE_ON 0X0D
#define LCD_DISLPAY_ON_UNDERLINE_CURSER_ON_SIDE_OFF 0X0E
#define LCD_DISLPAY_ON_UNDERLINE_CURSER_ON_SIDE_ON 0X0F
#define LCD_DISLPAY_MOVE_CURSOR_RIGHT  0X14
#define LCD_DISLPAY_MOVE_CURSOR_LEFT  0X10
#define LCD_DISLPAY_MOVE_DISPLAY_RIGHT  0X1C
#define LCD_DISLPAY_MOVE_DISPLAY_LEFT  0X18
#define LCD_8BIT_2LINE  0X38
#define LCD_4BIT_2LINE  0X28
#define DDRAM_START 0X80 
#define CGRAM_START 0X40 


typedef struct
{
    pin_config lcd_rs;
    pin_config lcd_e;
    pin_config lcd_pins[4];


}lcd_4;

typedef struct
{
    pin_config lcd_rs;
    pin_config lcd_e;
    pin_config lcd_pins[8];


}lcd_8;

Std_ReturnType lcd_8bit_initilization(lcd_8 * my_lcd);
Std_ReturnType lcd_8bit_sned_command(lcd_8 * my_lcd,char command);
Std_ReturnType lcd_8bit_sned_character(lcd_8 * my_lcd,char character);
Std_ReturnType lcd_8bit_sned_character_at_pos(lcd_8 * my_lcd,char row,char column,char character);
Std_ReturnType lcd_8bit_sned_string(lcd_8 * my_lcd,char array[]);
Std_ReturnType lcd_8bit_sned_string_at_pos(lcd_8 * my_lcd,char row,char column,char array[]);
Std_ReturnType lcd_8bit_sned_custom_char(lcd_8 * my_lcd,char row,char column,char array[],char pos);


Std_ReturnType lcd_4bit_initilization(lcd_4 * my_lcd);
Std_ReturnType lcd_4bit_sned_command(lcd_4 * my_lcd,char command);
Std_ReturnType lcd_4bit_sned_character(lcd_4 * my_lcd,char character);
Std_ReturnType lcd_4bit_sned_character_at_pos(lcd_4 * my_lcd,char row,char column,char character);
Std_ReturnType lcd_4bit_sned_string(lcd_4 * my_lcd,char array[]);
Std_ReturnType lcd_4bit_sned_string_at_pos(lcd_4 * my_lcd,char row,char column,char array[]);
Std_ReturnType lcd_4bit_intialize(const lcd_4  *lcd);
Std_ReturnType lcd_4bit_sned_custom_char(lcd_4 * my_lcd,char row,char column,char array[],char pos);

void convert_char_to_string (unsigned char number,unsigned char array[]);
void convert_short_to_string (short int  number,char array[]);
void convert_int_to_string (int number,char array[]);

#endif	/* LCD_H */

