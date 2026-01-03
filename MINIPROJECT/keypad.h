/* File Name : keypad.h */

#include"types.h"                    // user-defined data types

void keypadinit(void);               // initialize keypad rows and columns
s32 colstatus(void);                 // check column status of keypad
s8 readkeyval(void);                 // read pressed key value
u32 get_number_from_keypad(void);    // read numeric input from keypad
