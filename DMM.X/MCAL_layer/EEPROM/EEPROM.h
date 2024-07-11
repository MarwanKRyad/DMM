/* 
 * File:   EEPROM.h
 * Author: ideapad GAMING
 *
 * Created on August 19, 2023, 6:15 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include <../proc/pic18f4620.h>
#include "../MCAL_std_types.h"
Std_ReturnType EEPROM_write_data(uint16 add,uint8 data );
Std_ReturnType EEPROM_read_data(uint16 add,uint8 *data );

#endif	/* EEPROM_H */

