#include "EEPROM.h"
Std_ReturnType EEPROM_write_data(uint16 add,uint8 data )

{   Std_ReturnType ret=E_OK;
uint8 inter_state=INTCONbits.GIE;
        EEADRH=(uint8)(add)>>8;
        EEADR=(uint8)(add);
        EEDATA=data;
        EECON1bits.EEPGD=0;
        EECON1bits.CFGS=0;
        EECON1bits.WREN=1;
        INTCONbits.GIE=0;
        EECON2=0x55;
        EECON2=0xAA;
        EECON1bits.WR=1;
        while(EECON1bits.WR)
        {}
        EECON1bits.WREN=0;
        INTCONbits.GIE=inter_state;


            return ret;
}
Std_ReturnType EEPROM_read_data(uint16 add,uint8 *data )

{   Std_ReturnType ret=E_OK;

    if(data==NULL )
    {
        ret=E_NOT_OK;
    }
    else {
               ret=E_OK;
        EEADRH=(uint8)(add)>>8;
        EEADR=(uint8)(add);
        EECON1bits.EEPGD=0;
        EECON1bits.CFGS=0;
        EECON1bits.RD=1;
     
        EECON1bits.WR=1;
        NOP();
        NOP();
        *data=EEDATA;


        }
    
        return ret;

}