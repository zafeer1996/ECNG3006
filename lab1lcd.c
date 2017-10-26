#include <p18f452.h>
#include "xlcd2.h"
#include <delays.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000


void DelayFor18TCY (void)
{
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
}

void DelayPORXLCD (void)
{
    Delay1KTCYx(15);
    return;
}

void DelayXLCD (void)
{
    Delay1KTCYx(5);
    return;
}

void init_XLCD (void)
{
    OpenXLCD (FOUR_BIT & LINES_5X7);
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
}
unsigned char counter;
void main (void)
{
    
    init_XLCD();
 
   
    /*Changes*/
    while( BusyXLCD() );
    SetDDRamAddr(0x43);
    putrsXLCD( "Hello world!");
    while(1)
    {}
       
}