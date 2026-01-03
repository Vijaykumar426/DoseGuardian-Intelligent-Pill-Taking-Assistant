/* File Name : delay.c */

#include"types.h"              // user-defined data types

/* ---------------------------
   Function Name : delay_s
   --------------------------- */
void delay_s(u32 tdly)          // function to generate delay in seconds
{
	tdly*=12000000;               // convert seconds into clock cycles
	while(tdly--);                // loop until delay count becomes zero
}

/* ---------------------------
   Function Name : delay_ms
   --------------------------- */
void delay_ms(u32 tdly)         // function to generate delay in milliseconds
{
	tdly*=12000;                 // convert milliseconds into clock cycles
	while(tdly--);               // loop until delay count becomes zero
}

/* ---------------------------
   Function Name : delay_us
   --------------------------- */
void delay_us(u32 tdly)         // function to generate delay in microseconds
{
	tdly*=12;                    // convert microseconds into clock cycles
	while(tdly--);               // loop until delay count becomes zero
}

