/*
 * File:   segment.h
 * Author: ideapad GAMING
 *
 * Created on August 12, 2023, 10:17 PM
 */

#ifndef SEGMENT_H
#define	SEGMENT_H
#include "../../MCAL_layer/GPIO/hal_gpio.h"
typedef struct
{
    pin_config all_seg[4];

}seg_t;
Std_ReturnType seg_initalization(seg_t* my_seg);
Std_ReturnType seg_write_number(seg_t* my_seg,uint8 number);



#endif	/* SEGMENT_H */

