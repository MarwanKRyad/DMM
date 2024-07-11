/* 
 * File:   MCAL_std_types.h
 * Author: ideapad GAMING
 *
 * Created on July 26, 2023, 2:29 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/* section :includes section */
#include "std_lib.h"
#include "compiler.h"
/* section :DATA types declarations  */
typedef unsigned char uint8 ;
typedef unsigned short uint16 ;
typedef unsigned long uint32 ;
typedef signed char sint8 ;
typedef signed short sint16 ;
typedef signed long sint32 ;
typedef uint8 Std_ReturnType ;

typedef enum
{

    LOW,
    HIGH

}logic_t;
typedef enum
{

    OUTPUT,
    INPUT

}direction_t;


typedef enum
{

    pin0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7
}pin_number;


typedef enum
{

    PORTa ,
    PORTb ,
    PORTc ,
    PORTd ,
    PORTe
}port_name_;


typedef struct 
{
char my_pin :3 ;       /* @ref pin_number */
char  my_port :3 ;     /* @ref port_name_ */
char my_direction :1 ; /* @ref direction_t */
char my_logic :1 ;     /* @ref logic_t */

}pin_config;

/*section : Macro declarations  */

#define STD_HIGH      0X1
#define STD_LOW       0X0
#define E_OK         (Std_ReturnType) 0x1 
#define E_NOT_OK         (Std_ReturnType) 0x0
/* section :Macro function  declarations  */
#define SET_BITE(reg,bit_pos)   (reg |=(1<<bit_pos))
#define CLEAR_BITE(reg,bit_pos)   (reg &=~(1<<bit_pos))
#define TOGGLE_BITE(reg,bit_pos)   (reg ^=(1<<bit_pos))
#define READ_BITE(reg,bit_pos)   ((reg >>bit_pos )&1) // 1010 (1)010 -> 0101 0101 & 0000 0001
#define PIN_MAX_NUBER 8

#define PORT_MAX_NUBER 5





#endif	/* MCAL_STD_TYPES_H */

