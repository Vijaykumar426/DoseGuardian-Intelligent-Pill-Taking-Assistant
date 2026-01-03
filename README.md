# 💊 DoseGuardian – Intelligent Pill-Taking Assistant

## 📖 Overview
DoseGuardian is an ARM LPC2148 based intelligent medication reminder system designed to assist users in taking prescribed medicines on time. The system continuously monitors real-time clock (RTC) data and provides alerts when scheduled medicine times are reached.It provides timely alerts via LCD and buzzer, allows user input through a keypad, and detects missed doses using switches and LED indication.

---

## 🎯 Objectives
- Display real-time date and time using RTC on LCD  
- Allow users to edit RTC settings using a keypad  
- Enable configuration of medicine schedules  
- Generate alerts when medicine time matches current time  

---

## 🧠 System Features
- ⏰ Real-time medicine reminder  
- ⌨️ User-configurable schedules via keypad  
- 🔔 Audio alert using buzzer  
- 📟 Visual indication on LCD  
- 🔴 Missed dose indication using LED  

---

## 🧩 Hardware Components
- 🧠 LPC2148 ARM7 Microcontroller  
- 📟 16×2 LCD  
- ⌨️ 4×4 Matrix Keypad  
- ⏱️ RTC (Internal)  
- 🔔 Buzzer  
- 🔘 Push Buttons (Switches)  
- 💡 LEDs  
- 🔌 USB-UART Converter / DB-9 Cable  

---

## 💻 Software & Tools
- 🧾 Embedded C  
- 🛠️ Keil µVision  
- 🔥 Flash Magic  

---

## ⚙️ Working Principle
1. User sets the medicine schedule using the keypad.  
2. The microcontroller continuously monitors the RTC time.  
3. When the current time matches the stored medicine time:
   - LCD displays a reminder message  
   - Buzzer is activated  
4. User confirms medicine intake using a switch.  
5. If acknowledgment is not given within a defined time, a red LED indicates a missed dose.

---

## 📌 Pin Configuration – LPC2148

### 📟 LCD (16×2) Interface *(8-bit Mode)*

| LCD Signal | LPC2148 Pin | Description |
|-----------|-------------|-------------|
| D0 | P0.0 | Data Line |
| D1 | P0.1 | Data Line |
| D2 | P0.2 | Data Line |
| D3 | P0.3 | Data Line |
| D4 | P0.4 | Data Line |
| D5 | P0.5 | Data Line |
| D6 | P0.6 | Data Line |
| D7 | P0.7 | Data Line |
| RS | P0.8 | Register Select |
| RW | P0.9 | Read / Write Control |
| EN | P0.10 | Enable Signal |

---

### ⌨️ 4×4 Matrix Keypad Interface

#### 🔹 Rows (Inputs)

| Keypad Row | LPC2148 Pin |
|-----------|-------------|
| Row 0 | P1.16 |
| Row 1 | P1.17 |
| Row 2 | P1.18 |
| Row 3 | P1.19 |

#### 🔹 Columns (Outputs)

| Keypad Column | LPC2148 Pin |
|--------------|-------------|
| Column 0 | P1.20 |
| Column 1 | P1.21 |
| Column 2 | P1.22 |
| Column 3 | P1.23 |

---

### 🔘 Switches

| Switch | LPC2148 Pin | Function |
|------|-------------|----------|
| Switch 1 | P0.16 | Menu / Schedule Entry |
| Switch 2 | P0.17 | Medicine Acknowledgment |

---
### 🔔 Buzzer

| Device | LPC2148 Pin | Function |
|------|-------------|----------|
| Buzzer | P1.25 | Audio Alert |

---
### 💡 LED Indicators

| LED | LPC2148 Pin | Indication |
|----|-------------|------------|
| Red LED | P1.26 | Missed Dose |

---

### ⏱️ RTC

| Module | Type | Purpose |
|------|------|---------|
| RTC | Internal RTC | Real-time date and time tracking |

---

## Working Style
🟢 Initial System Setup (Project First View)
<img width="1294" height="876" alt="Screenshot 2026-01-03 093231" src="https://github.com/user-attachments/assets/f969b20b-f83e-4d33-b972-3c8c2389fe29" />

This figure shows the initial stage of the project, including the LPC2148 microcontroller interfaced with a 16×2 LCD, keypad, RTC, buzzer, LED, and control switches. At this stage, the system powers up and displays the current time and date on the LCD, confirming proper hardware initialization and peripheral connectivity.

📋 User Menu Display (Mode Selection)
<img width="1214" height="854" alt="Screenshot 2026-01-03 144952" src="https://github.com/user-attachments/assets/8ec5bf79-f47f-42d0-9945-750826014864" />

This stage displays the main menu on the LCD, allowing the user to select different operating modes using the keypad. Options include editing RTC settings, setting medicine reminder time, and exiting the menu. This interface provides easy and user-friendly navigation for system configuration.

🔘 Switch Indications
SW1 – Menu / Edit Switch.
Used to enter menu mode.
Used to edit settings, such as:RTC time and date ,Medicine time slots.
Used to navigate through options.
➡️ Purpose: Menu selection & editing.

SW2 – Medicine Taken Confirmation Switch
Pressed after taking the medicine.
Confirms that the medicine is taken on time.
Stops:Buzzer alarm and LED indication.
Displays message on LCD:
“MEDICINE TAKEN”.
➡️ Purpose: Medicine intake confirmation

⏰ RTC Time & Date Configuration
<img width="1244" height="875" alt="Screenshot 2026-01-03 153034" src="https://github.com/user-attachments/assets/e25214cc-0a2b-4368-83a9-0b67458ea434" />

This screen allows the user to configure the RTC parameters such as hours, minutes, seconds, date, month, year, and day using the keypad. The selected values are displayed on the LCD, enabling accurate time and date setup for reliable medicine reminder operation.

⌨️ Medicine Time Slot Selection
<img width="1213" height="860" alt="Screenshot 2026-01-03 153438" src="https://github.com/user-attachments/assets/1d15ed6b-a28e-4e72-9058-4bf8d309a7d2" />

This screen allows the user to select a medicine time slot using the keypad. The system supports multiple slots to schedule medicines at different times of the day.

✅ Medicine Time Acknowledgement
<img width="1217" height="858" alt="Screenshot 2026-01-03 145506" src="https://github.com/user-attachments/assets/7a8695d4-ca60-4224-b5a6-4dfb33c454a0" />

This screen confirms that the medicine reminder time has been successfully saved. The LCD displays a confirmation message after the user enters the required time using the keypad, ensuring the reminder is stored correctly for future alerts.

⏰ Medicine Reminder Alert
<img width="1227" height="856" alt="Screenshot 2026-01-03 151432" src="https://github.com/user-attachments/assets/fd6d1762-48a0-4c48-861a-7a7f53a0fb80" />

This screen appears at the scheduled medicine time. The LCD clearly instructs the user to take the medicine, while the buzzer and  audio and visual alerts to grab attention.
🔔 What Happens Here
LCD displays “TAKE MEDICINE – MEDICINE 1”
Buzzer sounds as an alert
User must confirm after taking the medicine

✅ Medicine Taken Confirmation
<img width="1208" height="863" alt="Screenshot 2026-01-03 151023" src="https://github.com/user-attachments/assets/b9832d42-596f-4083-bf05-e4114b346b5c" />

When ever medicine is taken SW2 is pressed for confirmation.This screen appears when the user confirms that the medicine has been taken. The LCD displays a clear confirmation message, and the alert (buzzer/LED) is turned off, ensuring the system records the dose as completed.

💊 Medicine Time Slot & Alert Status
<img width="1222" height="868" alt="Screenshot 2026-01-03 151536" src="https://github.com/user-attachments/assets/538165f9-0a41-473e-9704-bd0a2c4f0202" />

This screen indicates the medicine reminder status. When the scheduled medicine time is missed, and SW2 is not pressed the system displays a warning message on the LCD and activates the buzzer and LED. This ensures the user is immediately alerted and helps prevent missed doses.

---
📁 Project Folder Structure
├── Project_main.c.c/Project_functions.c/Project_functions.h → Main application file
├── lcd.c / lcd.h → LCD driver
├── lcd_defines.h → LCD commands & macros
├── keypad.c / keypad.h → Keypad driver
├── keypad_defines.h → Key mappings
├── rtc.c / rtc.h → RTC driver
├── rtc_defines.h → RTC registers & macros
├── MD_CLK_SET.c → Time/Date/Day arrow mode logic
├── MD_CLK_SET_2.c → Medicine scheduling logic
├── delay_header.h → Delay prototypes
├── def_delay.c → Delay implementation
├── defines.h → Global macros & pin definitions
├── types.h → Custom data types
└── README.md → Project documentation

---

⚙️ Functional Overview
The system initializes LCD, RTC, keypad, buzzer, LED, and switches
User can:
Edit RTC time, date, and day
Configure medicine reminder time
RTC continuously monitors the current time
When medicine time matches:
Buzzer turns ON
LED turns ON
Alert message is displayed on LCD
User confirms medicine intake using SW2
Alert stops after confirmation

---

🔄 System Working Flow
Power ON / Reset the system
Configure GPIO directions
Initialize LCD and display startup message
Initialize RTC
Initialize keypad and switches
User enters menu using SW1
User sets RTC and medicine time
System continuously checks RTC time
On time match:
Buzzer and LED are activated
Alert message is displayed
User presses SW2 after taking medicine
Alert stops and system returns to monitoring mode

---

## ✅Conclusion

This project presents a smart and reliable Medicine Reminder System using an ARM (LPC2124) microcontroller. 
It effectively uses RTC for accurate time tracking, a keypad for user input, and switches for editing settings and confirming medicine intake.
The system provides clear alerts through an LCD display, buzzer, and LED, helping users avoid missed medication doses.

This implementation demonstrates practical embedded system design, real-time scheduling, and human-friendly interaction.
It is especially useful for elderly patients and individuals who require timely medication reminders.

---

## 🚀 Applications
- Medication management for elderly patients  
- Long-term treatment adherence systems  
- Smart healthcare embedded solutions  

---

## 🔮 Future Enhancements
- 📱 GSM / IoT based notifications  
- 🧠 Mobile app integration  
- 🔋 Battery backup support  
- 📊 Data logging of medicine intake  

---
✨  “Good engineering is not just about building systems, but about improving lives.”
---

## 👨‍💻 Author
**Jarpla Vijay Kumar**  
🎓 ECE Graduate | Embedded Systems Trainee  
💡 Skills: C, C++, ARM, Embedded Linux, Communication Protocols
