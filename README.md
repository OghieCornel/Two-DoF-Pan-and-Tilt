[README.md](https://github.com/user-attachments/files/25701428/README.md)
# Two Degree of Freedom (2-DOF) Pan and Tilt Robot Using Arduino Uno

## Overview

This project presents the design and implementation of a Two Degree of Freedom (2-DOF) Pan and Tilt robotic platform controlled using an Arduino Uno.

The system enables precise angular positioning along:

- Pan (Horizontal axis)
- Tilt (Vertical axis)

Movement is controlled via Serial Monitor input in the Arduino IDE. The Arduino processes coordinate commands and generates PWM signals to drive two servo motors accordingly.

This project demonstrates practical integration of:

- Embedded systems
- Servo motor control
- PWM signal generation
- Power regulation
- Mechanical system design
- Real-time input handling

---

## Project Aim

To design, implement, and evaluate a 2-DOF pan and tilt robotic system capable of accurate two-axis orientation control using an Arduino-based embedded platform.

---

## Objectives

- Develop a mechanical structure with two orthogonal rotational axes.
- Integrate two servo motors for independent pan and tilt control.
- Implement serial-based real-time control using Arduino Uno.
- Map Cartesian input values safely to servo angles.
  
<img width="324" height="331" alt="pan and tilt chassis" src="https://github.com/user-attachments/assets/8ef6fde6-06d5-46b0-9419-7823064f3c17" />


---

## System Architecture

<img width="305" height="188" alt="schematic diagram" src="https://github.com/user-attachments/assets/eb0f9cf9-d2a0-45d5-96fe-e34f11b0afbe" />



### Functional Flow

<img width="300" height="80" alt="Screenshot 2026-03-03 at 03 48 12" src="https://github.com/user-attachments/assets/818a93d6-3243-41e3-b310-356d9bc86754" />


---

## Hardware Components

| Component | Quantity | Function |
|------------|----------|----------|
| Arduino Uno (ATmega328P) | 1 | Central control unit |
| Servo Motors | 2 | Pan and tilt actuation |
| LM2596 Buck Converter | 1 | 12V to 5V regulation |
| 12V Power Supply | 1 | Primary power source |
| Pan-Tilt Platform | 1 | Mechanical chassis |
| Veroboard | 1 | Circuit assembly |
| Jumper Wires | Multiple | Electrical connections |
| Enclosure | 1 | Structural housing |

---

## Power Design

- 12V external power supply
- Stepped down to 5V using LM2596 buck converter
- Servo motors powered separately from Arduino to prevent brownouts


---

## How It Works

1. User enters coordinates in the Serial Monitor:
2. Arduino parses input values.
3. Values are constrained within safe range (-100 to 100).
4. Coordinates are mapped to servo angles (0°–180°).
5. PWM signals drive the servos.
6. Platform moves to commanded orientation.

---


### Response Time
- Approximately 0.3 – 0.5 seconds
- Depends on angular travel distance

