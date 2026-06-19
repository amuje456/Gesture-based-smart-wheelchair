# Smart Head Gesture Controlled Wheelchair

## Overview

The Smart Head Gesture Controlled Wheelchair is an assistive mobility system designed for physically challenged individuals and patients with limited hand movement. The system allows users to control wheelchair movement through simple head gestures, eliminating the need for traditional joystick or manual controls.

The project uses an MPU6050 sensor to detect head movements and Arduino microcontrollers to process and transmit commands wirelessly using NRF24L01 modules. Based on the detected gesture, the wheelchair moves in the desired direction.

---

## Features

- Head gesture-based wheelchair control
- Wireless communication using NRF24L01
- Forward, Backward, Left, Right and Stop movements
- Emergency stop mechanism for safety
- Low-cost and easy-to-build prototype
- Suitable for healthcare and rehabilitation applications

---

## Hardware Components

### Transmitter Unit
- Arduino Nano
- MPU6050 Accelerometer & Gyroscope Sensor
- NRF24L01 Wireless Transceiver Module
- 3.7V Battery

### Receiver Unit
- Arduino Uno
- NRF24L01 Wireless Transceiver Module
- L298N Motor Driver
- DC Motors
- 7.4V Battery

---

## System Architecture

```
Head Movement
      ↓
MPU6050 Sensor
      ↓
Arduino Nano
      ↓
NRF24L01 Transmitter
      ↓
Wireless Communication
      ↓
NRF24L01 Receiver
      ↓
Arduino Uno
      ↓
L298N Motor Driver
      ↓
DC Motors
      ↓
Wheelchair Movement
```

---

## Working Principle

1. The MPU6050 sensor detects the user's head tilt.
2. Arduino Nano processes the sensor readings.
3. A movement command is generated based on the detected gesture.
4. The command is transmitted wirelessly through NRF24L01.
5. Arduino Uno receives the command.
6. L298N motor driver controls the DC motors.
7. The wheelchair moves accordingly.

---

## Gesture Mapping

| Head Gesture | Action |
|-------------|---------|
| Forward Tilt | Move Forward |
| Backward Tilt | Move Backward |
| Left Tilt | Turn Left |
| Right Tilt | Turn Right |
| Neutral Position | Stop |
| Tilt > 30° | Emergency Stop |

---

## Safety Features

- Emergency stop for abnormal head tilt.
- Automatic stop in neutral position.
- Reliable wireless communication.
- Reduced risk of accidental movement.

---

## Applications

- Hospitals
- Rehabilitation Centers
- Elderly Care
- Home Healthcare
- Assistive Mobility Systems

---

## Future Enhancements

- Obstacle Detection using Ultrasonic Sensors
- Voice-Controlled Navigation
- Mobile App Integration
- IoT-Based Monitoring
- GPS Tracking
- AI-Based Gesture Recognition
- Autonomous Navigation

---

## Software Used

- Arduino IDE
- Embedded C/C++

---

## Project Team

- Add Team Member Names Here
- Add USNs Here

---

## Guide

- Add Guide Name Here

---

## License

This project is developed for academic and educational purposes.
