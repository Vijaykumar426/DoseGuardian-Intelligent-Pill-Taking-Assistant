/*
 * File Name   : lcd.c
 * Description : LCD driver file for 16x2 LCD interfacing with LPC21xx
 *               Supports command, character, string, integer, float
 *               display and custom character generation.
 */

#include<LPC21XX.h>          // LPC21xx register definitions
#include"delay.h"            // Delay functions (ms and us)
#include"types.h"            // Custom data type definitions
#include"bytedefines.h"      // Byte-level macro definitions
#include"lcd.h"              // LCD function declarations

/* LCD pin configuration macros */
#define LCD_data 0           // LCD data lines starting from P0.0
#define RS 8                 // Register Select pin (P0.8)
#define RW 9                 // Read/Write pin (P0.9)
#define EN 10                // Enable pin (P0.10)

/*
 * Function Name : initLCD
 * Description   : Initializes the 16x2 LCD in 8-bit mode
 *                 and configures display parameters.
 */
void initLCD(void)
{
	IODIR0|=0XFF<<LCD_data|(1<<RS)|(1<<RW)|(1<<EN); // Configure LCD pins as output
	delay_ms(20);                                 // LCD power-on delay
	cmdLCD(0x30);                                 // Function set
	delay_ms(8);
	cmdLCD(0x30);
	delay_ms(1);
	cmdLCD(0x30);
	delay_ms(1);
	cmdLCD(0x38);                                 // 8-bit mode, 2 lines
	cmdLCD(0x10);                                 // Cursor move
	cmdLCD(0x01);                                 // Clear display
	cmdLCD(0x06);                                 // Entry mode set
	cmdLCD(0x0C);                                 // Display ON, cursor OFF
}

/*
 * Function Name : dispLCD
 * Description   : Sends either command or data byte to LCD.
*/
void dispLCD(u8 val)
{
	IOCLR0=1<<RW;                                 // Select write operation
	WRITEBYTE(IOPIN0,LCD_data,val);               // Write byte to LCD data pins
	IOSET0=1<<EN;                                 // Enable high
	delay_us(2);                                  // Enable pulse width
	IOCLR0=1<<EN;                                 // Enable low
	delay_ms(2);                                  // Command execution delay
}

/*
 * Function Name : cmdLCD
 * Description   : Sends command to LCD.
 */
void cmdLCD(u8 cmd)
{
	IOCLR0=1<<RS;                                 // Select command register
	dispLCD(cmd);                                 // Send command
}

/*
 * Function Name : charLCD
 * Description   : Displays a single character on LCD.
 */
void charLCD(s8 data)
{
	IOSET0=1<<RS;                                 // Select data register
	dispLCD(data);                               // Send character
}

/*
 * Function Name : strLCD
 * Description   : Displays a string on LCD.
 */
void strLCD(u8 *ptr)
{
	while(*ptr!='\0')                            // Loop until null character
	{
		charLCD(*ptr);                            // Display each character
		ptr++;
	}
}

/*
 * Function Name : intLCD
 * Description   : Displays a signed integer value on LCD.
 */
void intLCD(s32 num)
{
	s8 a[10],i=0;                                // Buffer to store digits
	if(num==0)
	{
		charLCD(0+48);                           // Display '0'
	}
	else
	{
		if(num<0)
		{
			charLCD('-');                        // Display negative sign
			num=-num;
		}
		while(num)
		{
			a[i++]=num%10+48;                    // Convert digit to ASCII
			num/=10;
		}
		--i;
		for(;i>=0;i--)
		{
			charLCD(a[i]);                      // Display digits in correct order
		}
	}
}

/*
 * Function Name : floatLCD
 * Description   : Displays floating point value up to 3 decimal places.
*/
void floatLCD(f32 num)
{
	u32 n;
	s32 i;
	if(num<0)
	{
		charLCD('-');                            // Display negative sign
		num=-num;
	}
	n=num;                                      // Extract integer part
	intLCD(n);                                  // Display integer part
	charLCD('.');                               // Display decimal point
	for(i=0;i<3;i++)
	{
		num=(num-n)*10;                         // Extract fractional digits
		n=num;
		charLCD(n+48);                          // Display fractional digit
	}
}

/*
 * Function Name : writetoCGRAM
 * Description   : Writes custom character pattern to LCD CGRAM.
 */
void writetoCGRAM(void)
{
	s8 i,a[]={0x17,0x14,0x14,0x1f,0x05,0x05,0x1D,0x00}; // Custom character pattern
	cmdLCD(0x60);                                     // Set CGRAM address
	for(i=0;i<8;i++)
	{
		charLCD(a[i]);                                // Write pattern data
	}
}

