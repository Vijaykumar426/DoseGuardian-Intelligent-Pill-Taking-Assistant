#include <LPC21XX.h>         // MCU register definitions
#include "types.h"           // u8, u32 typedefs
#include "delay.h"           // delay_ms(), delay_s()
#include "lcd.h"             // initLCD(), cmdLCD(), strLCD(), charLCD()
#include "keypad.h"          // R0..R3, C0..C3 definitions
#include "rtc.h"             // RTC helper functions (initRTC, Get/Set functions)
#include "defines.h"         // project-specific defines (if any)
#include "lcd_defines.h"     // GOTO_LINEx_POSx, CLEAR_LCD constants
#include "keypaddefines.h"
#include "rtc_defines.h"
#include "project_functions.h"

/* ---------------------------
   // Medicine 1 time
   --------------------------- */

  u32 med1_hour = 0;            // medicine1 hour
  u32 med1_min  = 0;            // medicine1 minute
  u32 med1_active = 0;          // medicine1 active flag (0=off,1=on)


/* ---------------------------
   // Medicine 2 time
   --------------------------- */
  u32 med2_hour = 0;            // medicine2 hour
  u32 med2_min  = 0;            // medicine2 minute
  u32 med2_active = 0;          // medicine2 active flag


/* ---------------------------
   // Medicine 3 time
   --------------------------- */
   u32 med3_hour = 0;            // medicine3 hour
   u32 med3_min  = 0;            // medicine3 minute
   u32 med3_active = 0;          // medicine3 active flag

/* ---------------------------
   RTC variables to hold current time
   --------------------------- */
   u32 hour,min,sec,date,month,year,day;


/* ---------------------------
   show_main_display
   Fetch current RTC time/date and show on LCD
   --------------------------- */
	 
void show_main_display()
{
    GetRTCTimeInfo(&hour, &min, &sec);        // read current hour,min,sec from RTC
    DisplayRTCTime(hour, min, sec);           // display time on LCD using helper
    GetRTCDateInfo(&date, &month, &year);     // read current date, month, year
    DisplayRTCDate(date, month, year);        // display date on LCD
    GetRTCDay(&day);                          // read current weekday
    DisplayRTCDay(day);                       // display weekday on LCD
}

/* ---------------------------
   menu_handler
   Show menu and let user pick edit RTC or edit medicine times
   --------------------------- */

void menu_handler()
{
    u32 option;
    cmdLCD(CLEAR_LCD);
    delay_ms(1);
	  cmdLCD(GOTO_LINE1_POS0);
    strLCD("1.E.RTC");
    cmdLCD(GOTO_LINE2_POS0);
    strLCD("2.E.MED TIME");
	  cmdLCD(GOTO_LINE1_POS0+9);
	  strLCD("3.EXIT");
    delay_s(1);
	  cmdLCD(CLEAR_LCD);
	  cmdLCD(GOTO_LINE1_POS0);
	  strLCD("Enter option 1-3");
    option = get_number_from_keypad();   // Get keypad input
	  if(option>3)
		{
			strLCD("invalid options");
			delay_s(1);
		  cmdLCD(CLEAR_LCD);
			return;
		}
	  cmdLCD(GOTO_LINE2_POS0);
	  intLCD(option);
    if(option == 1) 
		{
		edit_rtc_info();
		}
    else if(option == 2)
		{			
		edit_medicine_time();
		}
		else if(option == 3)
		{
			cmdLCD(CLEAR_LCD);
			return;
		}
}

/* ---------------------------
   edit_rtc_info
   Let user edit hour/min/sec/day/date/month/year using keypad (two-digit input where needed)
   --------------------------- */

void edit_rtc_info()
{
    u32 new,opt;
    while(1)
    {
        cmdLCD(CLEAR_LCD);
			  cmdLCD(GOTO_LINE1_POS0);
        strLCD("1.H 2.M 3.S 4.D");
        cmdLCD(GOTO_LINE2_POS0);
        strLCD("5.Dt 6.M 7.Y 8.E");
			  delay_s(1);
			  cmdLCD(CLEAR_LCD);
			  cmdLCD(GOTO_LINE1_POS0);
			  strLCD("enter option");
			  cmdLCD(GOTO_LINE2_POS0);
			  opt = get_number_from_keypad();
			  cmdLCD(CLEAR_LCD);
				cmdLCD(GOTO_LINE1_POS0);
        if(opt==1)
				{
					  strLCD("Enter hour(0-23)");
            new =get_number_from_keypad();
					  if(new>23)
						{
							cmdLCD(CLEAR_LCD);
							strLCD("invalid entry");
							delay_s(1);
							cmdLCD(CLEAR_LCD);
							return;
						}
            SetRTCTimeInfo(new, min, sec);
        }
        else if(opt==2)
				{
					  strLCD("Enter Min(0-59)");
            new = get_number_from_keypad();
					  if(new>59)
						{
							cmdLCD(CLEAR_LCD);
							strLCD("invalid entry");
							delay_s(1);
							cmdLCD(CLEAR_LCD);
							return;
						}
            SetRTCTimeInfo(hour, new, sec);
        }
        else if(opt==3)
				{
					  strLCD("Enter Sec(0-59)");
            new = get_number_from_keypad();
					  if(new>59)
						{
							cmdLCD(CLEAR_LCD);
							strLCD("invalid entry");
							delay_s(1);
							cmdLCD(CLEAR_LCD);
							return;
						}
            SetRTCTimeInfo(hour, min, new);
        }
        else if(opt==4)
				{
					  strLCD("Enter day(0-6)");
            new =get_number_from_keypad();
					  if(new>6)
						{
							cmdLCD(CLEAR_LCD);
							strLCD("invalid entry");
							delay_s(1);
							cmdLCD(CLEAR_LCD);
							return;
						}
            SetRTCDay(new);
        }
        else if(opt==5)
				{  
					  strLCD("Enter Date(0-31)");
            new = get_number_from_keypad();
					  if(new>31)
						{
							cmdLCD(CLEAR_LCD);
							strLCD("invalid entry");
							delay_s(1);
							cmdLCD(CLEAR_LCD);
							return;
						}
            SetRTCDateInfo(new, month, year);
        }
        else if(opt==6)
				{
					  strLCD("Enter month(1-12)");
            new = get_number_from_keypad();
					  if(new>12)
						{
							cmdLCD(CLEAR_LCD);
							strLCD("invalid entry");
							delay_s(1);
							cmdLCD(CLEAR_LCD);
							return;
						}
            SetRTCDateInfo(date, new, year);
        }
        else if(opt==7)
				{
					  strLCD("Enter year(2025)");
            new = get_number_from_keypad();
					  if(new>2030)
						{
							cmdLCD(CLEAR_LCD);
							strLCD("invalid entry");
							delay_s(1);
							cmdLCD(CLEAR_LCD);
							return;
						}
            SetRTCDateInfo(date, month, new);
        }
        else if(opt==8)
				{
            return;   // Exit
        }
				cmdLCD(CLEAR_LCD);
				cmdLCD(GOTO_LINE1_POS0);
				strLCD("Data Updated");
				delay_s(1);
				cmdLCD(CLEAR_LCD);
				return;
    }
}


/* ---------------------------
   edit_medicine_time
   Let user choose slot 1-3 and enter hour & minute and activate slot
   --------------------------- */

void edit_medicine_time()
{
    u32 slot,m,h;
    cmdLCD(CLEAR_LCD);
    strLCD("Select Slot 1-3");
    cmdLCD(GOTO_LINE2_POS0);
    slot = get_number_from_keypad();   // reads 1,2,3
    intLCD(slot);
    if(slot<1 || slot>3)
		{
			  cmdLCD(CLEAR_LCD);
			  strLCD("invalid slot 1-3");
			  delay_s(1);
			  cmdLCD(CLEAR_LCD);
        return;
		}
    cmdLCD(CLEAR_LCD);
		cmdLCD(GOTO_LINE1_POS0);
    strLCD("Enter Hour(0-23)");
    h = get_number_from_keypad();  // input from keypad
		if(h>23)
		{
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid Hour");
		delay_s(1);
		cmdLCD(CLEAR_LCD);
		return;
		}
    cmdLCD(GOTO_LINE2_POS0);
		intLCD(h);
    cmdLCD(CLEAR_LCD);
		cmdLCD(GOTO_LINE1_POS0);
    strLCD("Enter Min(0-59)");
    m =get_number_from_keypad();  //input from keypad
		if(m>59)
		{
		cmdLCD(CLEAR_LCD);
		strLCD("Invalid Min");
		delay_s(1);
		cmdLCD(CLEAR_LCD);
		return;
		}
    cmdLCD(GOTO_LINE2_POS0);
		intLCD(m);
    // Store in normal variables
    if(slot==1)
		{
        med1_hour = h;
        med1_min  = m;
        med1_active = 1;
    }
    else if(slot==2)
		{
        med2_hour = h;
        med2_min  = m;
        med2_active = 1;
    }
    else if(slot==3){
        med3_hour = h;
        med3_min  = m;
        med3_active = 1;
    }

    cmdLCD(CLEAR_LCD);
		cmdLCD(GOTO_LINE1_POS0);
		strLCD("Medicine Time");
		cmdLCD(GOTO_LINE2_POS0);
    strLCD("Saved..");
    delay_s(1);
		cmdLCD(CLEAR_LCD);
		return;
}


/* ---------------------------
   check_medicine_alert
   Compare current hour/min/second with each active slot and call trigger_alert
   --------------------------- */

void check_medicine_alert()
{
    // Medicine 1
    if(med1_active==1 && hour==med1_hour && min==med1_min && sec==0)
    {
        trigger_alert(1);
    }

    // Medicine 2
    if(med2_active==1 && hour==med2_hour && min==med2_min && sec==0)
    {
        trigger_alert(2);
    }

    // Medicine 3
    if(med3_active==1 && hour==med3_hour && min==med3_min && sec==0)
    {
        trigger_alert(3);
    }
}


/* ---------------------------
   trigger_alert
   Sound buzzer blink LED and wait for SW2 press to acknowledge.
   index is slot number 1..3 to show on LCD optionally.
   --------------------------- */

void trigger_alert(u8 index)
{
    u32 timeout = 0;
    IODIR1|=(1<<LED)|(1<<BUZZER);
    cmdLCD(CLEAR_LCD);
    strLCD("TAKE MEDICINE");
    cmdLCD(GOTO_LINE2_POS0);

    if(index==1)
		{			
			strLCD("MEDICINE 1");
		}
    else if(index==2) 
		{
			strLCD("MEDICINE 2");
		}
    else if(index==3) 
		{
			strLCD("MEDICINE 3");
		}
    while(timeout < 10)
    {
        IOSET1 = (1<<BUZZER);
        delay_ms(300);
        IOCLR1 = (1<<BUZZER);
        delay_ms(300);

        if(((IOPIN0>>SW2)&1)==1)
        {
            while(((IOPIN0>>SW2)&1)==1);

            cmdLCD(CLEAR_LCD);
            strLCD("MEDICINE TAKEN!");
            delay_s(1);
					  cmdLCD(CLEAR_LCD);
            return;
        }

        timeout++;
    }

    IOSET1 = (1<<LED);
    cmdLCD(CLEAR_LCD);
    strLCD("MISSED DOSE!");
    delay_s(2);
		cmdLCD(CLEAR_LCD);
		IOCLR1 = (1<<LED);
		return;
}

/* ----------------------------
   To read multi digit input from keypad
   --------------------------- */

u32 get_number_from_keypad()
{
    u32 num = 0,cnt=0;
    u8 key;

    while(1)
    {
        key = readkeyval();   // read 1 key
      
        if(key >= '0' && key <= '9')  // if digit
        {							
					  cmdLCD(GOTO_LINE2_POS0+cnt);
					  charLCD(key); 
            num = num * 10 + (key - '0');  // append digit
					  cnt++;
					  
        }
				// Backspace '*'
        else if(key == '*')
        {
            if(cnt > 0)
            {
                num = num / 10;              // remove last digit
                cnt--;

                cmdLCD(0x10);                // cursor move LEFT
                charLCD(' ');                // erase character
                cmdLCD(0x10);                // cursor LEFT again
            }
				}
        else if(key == '#')   // # = finish input
        {
            return num;
        }
    }
}

