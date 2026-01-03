#include<LPC21XX.h>
#include"types.h"
#include"delay.h"
#include"lcd.h"
#include"keypad.h"
#include"rtc.h"
#include"defines.h"
#include"lcd_defines.h"
#include"keypaddefines.h"
#include"rtc_defines.h"
#include"project_functions.h"

// Main function
int main()
{
// Initialize RTC
initRTC();
// Initialize the LCD
initLCD();
// Initialize keypad
keypadinit();
// Set the initial time (hours, minutes, seconds)
SetRTCTimeInfo(22,30,00);
SetRTCDateInfo(02,02,2026);
SetRTCDay(5);
strLCD("welcome.."); //welcome simple message to start
delay_s(1);
cmdLCD(CLEAR_LCD);
while(1)
{
   show_main_display();                    // always display current time/date on LCD
	
	if(((IOPIN0>>SW1)&1)==1)                 // If SW1 pressed ? open menu
	{
		while(((IOPIN0>>SW1)&1)==1);           // wait for release to debounce
		menu_handler();                        // open menu
	}
	
// Check if any medicine matches the time
check_medicine_alert();
}
}
