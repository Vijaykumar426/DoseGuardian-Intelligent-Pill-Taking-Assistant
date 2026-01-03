/* File Name : rtc.h */

#ifndef RTC_H                  // check if RTC header is not defined
#define RTC_H                  // define RTC header macro

#include "types.h"             // user-defined data types

/* ---------------------------
   RTC Initialization
   --------------------------- */
void initRTC(void);            // initialize RTC module

/* ---------------------------
   RTC Set Functions
   --------------------------- */
void SetRTCTimeInfo(u32,u32,u32);  // set RTC time (hours, minutes, seconds)
void SetRTCDateInfo(u32,u32,u32);  // set RTC date (date, month, year)
void SetRTCDay(u32);               // set RTC day

/* ---------------------------
   RTC Get Functions
   --------------------------- */
void GetRTCTimeInfo(u32 *,u32 *,u32 *); // get RTC time values
void GetRTCDateInfo(u32 *,u32 *,u32 *); // get RTC date values
void GetRTCDay(u32 *);                  // get RTC day value

/* ---------------------------
   RTC Display Functions
   --------------------------- */
void DisplayRTCTime(u32,u32,u32); // display RTC time on LCD
void DisplayRTCDate(u32,u32,u32); // display RTC date on LCD
void DisplayRTCDay(u32);          // display RTC day on LCD

#endif                           // end of RTC header file
