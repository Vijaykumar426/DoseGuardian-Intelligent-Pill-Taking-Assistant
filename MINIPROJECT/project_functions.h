/* File Name : main.h */

#include"types.h"                 // user-defined data types

void show_main_display(void);     // display main screen on LCD
void menu_handler(void);          // handle menu selection logic
void edit_rtc_info(void);         // edit RTC date and time
void edit_medicine_time(void);    // edit medicine schedule
void check_medicine_alert(void);  // check medicine time match
void trigger_alert(u8 index);     // activate alert for given index
u32 get_number_from_keypad(void); // read numeric input from keypad

/* ---------------------------
   Configuration defines
   --------------------------- */

#define SW1      16               // switch 1 connected to P0.16
#define SW2      17               // switch 2 connected to P0.17
#define BUZZER   25               // buzzer connected to P0.25
#define LED      26               // LED connected to P0.26
