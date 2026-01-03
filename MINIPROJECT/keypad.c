/* File Name : keypad.c */

#include<LPC21XX.h>            // LPC21xx microcontroller register definitions
#include"LUT.h"                // lookup table for keypad values
#include"keypaddefines.h"      // keypad row and column pin definitions
#include"types.h"              // user-defined data types
#include"lcd.h"                // LCD function declarations
#include"defines.h"            // common project definitions

/* ---------------------------
   Function Name : keypadinit
   --------------------------- */
void keypadinit(void)           // function to initialize keypad
{
	IODIR1|=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3)); // configure keypad rows as output
}

/* ---------------------------
   Function Name : colstatus
   --------------------------- */
int colstatus(void)              // function to check column status
{
	if(((IOPIN1>>C0)&0xf)==0xf)    // check if all column pins are high
	{  
		return 1;                    // return 1 if no key is pressed
	}
	else
	{
		return 0;                    // return 0 if any key is pressed
	}
}

/* ---------------------------
   Function Name : readkeyval
   --------------------------- */
char readkeyval(void)              // function to read pressed key value
{
	char rowval,colval;               // variables to store row and column index
	WRITENIBBLE(IOPIN1,16,0);         // clear row output bits before scanning
	while(colstatus());               // wait until a key is pressed

	IOCLR1=1<<R0;                     // activate row 0
	IOSET1=((1<<R1)|(1<<R2)|(1<<R3)); // deactivate other rows
	if(((IOPIN1>>C0)&0xf)!=0xf)       // check if key pressed in row 0
	{ 
		rowval=0;                       // store row index as 0
		goto colcheck;                  // jump to column detection
	}

	IOCLR1=1<<R1;                     // activate row 1
	IOSET1=((1<<R0)|(1<<R2)|(1<<R3)); // deactivate other rows
	if(((IOPIN1>>C0)&0xf)!=0xf)       // check if key pressed in row 1
	{
		rowval=1;                       // store row index as 1
		goto colcheck;                  // jump to column detection
	}
 
	IOCLR1=1<<R2;                     // activate row 2
	IOSET1=((1<<R0)|(1<<R1)|(1<<R3)); // deactivate other rows
	if(((IOPIN1>>C0)&0xf)!=0xf)       // check if key pressed in row 2
	{
		rowval=2;                       // store row index as 2
		goto colcheck;                  // jump to column detection
	}

	IOCLR1=1<<R3;                      // activate row 3
	IOSET1=((1<<R0)|(1<<R1)|(1<<R2));  // deactivate other rows
	if(((IOPIN1>>C0)&0xf)!=0xf)        // check if key pressed in row 3
	{
		rowval=3;                        // store row index as 3
	}

colcheck:                            // label for column detection
	if(((IOPIN1>>C0)&1)==0)            // check column 0
	{
		colval=0;                        // store column index as 0
	}
	else if(((IOPIN1>>C1)&1)==0)       // check column 1
	{
		colval=1;                        // store column index as 1
	}
	else if(((IOPIN1>>C2)&1)==0)       // check column 2
	{
		colval=2;                        // store column index as 2
	}
	else 
		colval=3;                        // store column index as 3

	while(((IOPIN1>>C0)&0xf)!=0xf);    // wait until key is released
	return (LUT[rowval][colval]);      // return key value using lookup table
}
