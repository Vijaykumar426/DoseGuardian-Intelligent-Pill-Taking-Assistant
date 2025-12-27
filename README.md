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

### 📟 LCD (16×2) Interface *(4-bit Mode)*

| LCD Signal | LPC2148 Pin | Description |
|-----------|-------------|-------------|
| RS | P0.8 | Register Select |
| RW | P0.9 | Read / Write Control |
| EN | P0.10 | Enable Signal |
| D4 | P0.11 | Data Line |
| D5 | P0.12 | Data Line |
| D6 | P0.13 | Data Line |
| D7 | P0.14 | Data Line |

---

### ⌨️ 4×4 Matrix Keypad Interface

#### 🔹 Rows (Inputs)

| Keypad Row | LPC2148 Pin |
|-----------|-------------|
| Row A | P1.16 |
| Row B | P1.17 |
| Row C | P1.18 |
| Row D | P1.19 |

#### 🔹 Columns (Outputs)

| Keypad Column | LPC2148 Pin |
|--------------|-------------|
| Column 1 | P1.20 |
| Column 2 | P1.21 |
| Column 3 | P1.22 |
| Column 4 | P1.23 |

---

### 🔘 Switches

| Switch | LPC2148 Pin | Function |
|------|-------------|----------|
| Switch 1 | P0.15 | Menu / Schedule Entry |
| Switch 2 | P0.16 | Medicine Acknowledgment |

---

### 💡 LED Indicators

| LED | LPC2148 Pin | Indication |
|----|-------------|------------|
| Red LED | P0.17 | Missed Dose |
| Green LED | P0.18 | Status Indication |

---

### 🔔 Buzzer

| Device | LPC2148 Pin | Function |
|------|-------------|----------|
| Buzzer | P0.19 | Audio Alert |

---

### ⏱️ RTC

| Module | Type | Purpose |
|------|------|---------|
| RTC | Internal RTC | Real-time date and time tracking |

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

## 👨‍💻 Author
**Jarpla Vijay Kumar**  
🎓 ECE Graduate | Embedded Systems Trainee  
💡 Skills: C, C++, ARM, Embedded Linux, Communication Protocols
