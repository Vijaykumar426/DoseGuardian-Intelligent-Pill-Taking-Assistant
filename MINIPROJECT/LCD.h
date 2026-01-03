/* File Name : lcd.h */

#include"types.h"          // user-defined data types

void initLCD(void);        // initialize LCD
void cmdLCD(u8);           // send command to LCD
void charLCD(s8);          // display character
void strLCD(u8*);          // display string
void intLCD(s32);          // display integer
void floatLCD(f32);        // display float value
void writetoCGRAM(void);   // write custom character
