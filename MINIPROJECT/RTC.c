#include <LPC21xx.H>
#include "rtc_defines.h"
#include "types.h"
#include "lcd.h"
#include "lcd_defines.h"
//#define CPU_LPC2148
u8 WEEK[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
void initRTC(void)
{
	// Disable and reset the RTC
	CCR = 1<<1;
	#ifndef CPU_LPC2148
	// Set prescaler integer and fractional parts
	PREINT=PREINT_VAL;
	PREFRAC=PREFRAC_VAL;
  // Enable the RTC
	CCR=1<<0;
	#else
	// Enable the RTC & select the clock source
	CCR=(1<<0)|(1<<4);
	#endif
}
/*
Set the RTC time
Hour to set (0 23)
Minute to set (0 59)
Second to set (0 59)
*/
void SetRTCTimeInfo(u32 hour, u32 minute, u32 second)
{
	HOUR = hour;
	MIN = minute;
	SEC = second;
}


/*
Set the RTC date
day of month to set (1 31)
month to set (1 12)
year to set (four digits)
*/
void SetRTCDateInfo(u32 date, u32 month, u32 year)
{
	DOM = date;
	MONTH = month;
	YEAR = year;	
}

/*
Set the day of the week in RTC
Day of Week to set (0=Sunday, ..., 6=Saturday)
*/
void SetRTCDay(u32 day)
{
	DOW = day;
}

/*
Get the current RTC time
hour Pointer to store the current hour
minute Pointer to store the current minute
second Pointer to store the current second
*/
void GetRTCTimeInfo(u32 *hour, u32 *minute, u32 *second)
{
	*hour = HOUR;
	*minute = MIN;
	*second = SEC;
}

/*
Get the current RTC date
day Pointer to store the current date (1 31)
month Pointer to store the current month (1 12)
year Pointer to store the current year (four digits)
*/
void GetRTCDateInfo(u32 *date, u32 *month, u32 *year)
{
	*date = DOM;
	*month = MONTH;
	*year = YEAR;
}

/*
Get the current day of the week
dow Pointer to store Day of Week (0=Sunday, ..., 6=Saturday)
*/
void GetRTCDay(u32 *day)
{
	*day = DOW; 
}


/*
Display the RTC time on LCD
hour value (0 23)
minute value (0 59)
second value (0 59) seperated by ':'
*/

void DisplayRTCTime(u32 hour, u32 minute, u32 second)
{
		cmdLCD(GOTO_LINE1_POS0);
		charLCD((hour/10)+48);
		charLCD((hour%10)+48);
		charLCD(':');
		charLCD((minute/10)+48);
		charLCD((minute%10)+48);
		charLCD(':');
		charLCD((second/10)+48);
		charLCD((second%10)+48);
}


/*
Display the RTC date on LCD
Day of month (1 31)
Month (1 12)
Year (four digits) and seperated by '/'
*/
void DisplayRTCDate(u32 date, u32 month, u32 year)
{
		cmdLCD(GOTO_LINE2_POS0);
		charLCD((date/10)+48);
		charLCD((date%10)+48);
		charLCD('/');
		charLCD((month/10)+48);
		charLCD((month%10)+48);
		charLCD('/');
		intLCD(year);
}


/*
Display the current day of the week on LCD
dow (Day of Week) (0=Sunday, ..., 6=Saturday)
*/
void DisplayRTCDay(u32 dow)
{
	cmdLCD(0x8A);
	strLCD(WEEK[dow]);  
}
