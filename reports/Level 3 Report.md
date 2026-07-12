# 2WD Differential Drive Mobile Robot

## Engineering Report

# Level 3 – PWM Motor Control & Modular Motion Controller

---

## Document Information

| Item | Details |
|------|----------|
| Project | 2WD Differential Drive Mobile Robot |
| Level | 3 |
| Version | v1.1.0 |
| Author | Chaitanya Belekar |
| Platform | Arduino UNO + ESP32 + L298N |
| Status | Completed |
| Date | July 2026 |

---

# 1. Introduction

After successfully establishing Bluetooth teleoperation in Level 2, the next objective was to improve the robot's motion control by introducing Pulse Width Modulation (PWM). Until this stage, the motors operated only at full speed using the ENA and ENB jumpers on the L298N motor driver.

This level focused on replacing the hardware enable jumpers with software-controlled PWM outputs from the Arduino UNO. In addition, the motor control logic was redesigned into a reusable software module, creating a clean abstraction layer for all future robot motion commands.

The completed implementation provides a scalable foundation for future features such as obstacle avoidance, autonomous navigation, ROS 2 integration, and closed-loop speed control.

---

# 2. Objectives

- Replace hardware enable jumpers with Arduino-controlled PWM outputs.
- Validate PWM-based motor speed control.
- Implement software-controlled motor enable functionality.
- Design a reusable motor control API.
- Improve software maintainability through modular programming.
- Prepare the robot for future autonomous behaviors.

---

# 3. Hardware Components

| Component | Specification | Quantity |
|-----------|---------------|---------:|
| Arduino UNO | ATmega328P | 1 |
| ESP32 Dev Board | ESP32-WROOM-32 | 1 |
| L298N Motor Driver | Dual H-Bridge Driver | 1 |
| BO Gear Motors | Dual Shaft DC Gear Motors | 2 |
| Robot Chassis | Acrylic 2WD Platform | 1 |
| Li-ion Battery | 7.4V Supply | 1 |

---

# 4. Software Tools

- Arduino IDE
- ESP32 Arduino Core
- Git
- GitHub

---

# 5. System Architecture

```
              Phone

                 │
           Bluetooth Classic

                 │
              ESP32 Module

                 │
              UART Serial

                 │
            Arduino UNO

                 │
          PWM + Direction Control

                 │
            L298N Driver

                 │
             DC Motors
```

---

# 6. PWM Speed Control

In previous levels, the ENA and ENB enable pins of the L298N motor driver were permanently enabled using onboard jumpers. This configuration forced both motors to operate at maximum speed whenever a direction command was applied.

During this level, the enable jumpers were removed and connected directly to Arduino PWM-capable output pins.

| Arduino Pin | L298N Pin |
|-------------|-----------|
| D9 | ENA |
| D6 | ENB |

Motor speed was then controlled using the Arduino `analogWrite()` function, allowing variable duty cycles between 0 and 255.

Example:

```cpp
analogWrite(ENA, 180);
analogWrite(ENB, 180);
```

This enables precise software control over motor speed without requiring any hardware modifications.

---

# 7. Motion Control API

To improve software organization, all low-level motor operations were encapsulated into reusable functions.

Implemented functions:

```cpp
initializeMotors();

forward(speed);

backward(speed);

left(speed);

right(speed);

stopRobot();
```

This abstraction hides the hardware implementation details from higher-level robot logic, allowing future modules to control the robot using simple motion commands.

---

# 8. Testing Procedure

The following validation tests were performed.

### Test 1 – PWM Enable Verification

Objective:

Verify that the Arduino can successfully enable both motor channels without the L298N jumpers.

Result:

PASS

---

### Test 2 – Variable Speed Validation

Objective:

Verify that motor speed changes with different PWM duty cycles.

PWM values tested:

- 255
- 220
- 200
- 180
- 160
- 140
- 120
- 100
- 80
- 60
- 40
- 20
- 0

Result:

PASS

The robot demonstrated successful speed variation across the tested PWM range.

---

### Test 3 – Motion Function Validation

The following reusable functions were tested individually.

| Function | Result |
|----------|--------|
| forward() | PASS |
| backward() | PASS |
| left() | PASS |
| right() | PASS |
| stopRobot() | PASS |

---

# 9. Debugging and Challenges

## Issue

Initially, the motors failed to respond after removing the ENA and ENB jumpers.

### Initial Assumption

The L298N module did not support software-controlled enable pins.

### Root Cause

The Arduino PWM wires were connected to the incorrect header row on the L298N module. As a result, the enable pins were not receiving the PWM signal.

### Solution

The PWM connections were moved to the correct ENA and ENB header pins.

### Result

The motors immediately responded to PWM commands, confirming that software-controlled speed regulation was fully functional.

---

# 10. Engineering Improvements

Compared to Level 2, the robot software now provides:

- Variable motor speed
- Software-controlled enable signals
- Modular software architecture
- Cleaner motion control interface
- Reusable movement functions
- Improved maintainability
- Reduced code duplication

---

# 11. Industrial Relevance

PWM-based motor control is a standard technique used in mobile robotics for regulating motor speed and improving motion quality. Encapsulating low-level hardware operations into reusable software modules follows common embedded systems and robotics software engineering practices.

This modular architecture simplifies future integration with Bluetooth communication, sensor processing, autonomous navigation, and ROS 2 control nodes.

---

# 12. Future Work

The next development stages include:

- Servo motor integration
- Ultrasonic distance measurement
- Environment scanning
- Obstacle avoidance
- ESP32 standalone motor control
- ROS 2 hardware interface
- Differential drive odometry
- SLAM
- Autonomous navigation

---

# 13. Conclusion

Level 3 successfully transitioned the robot from fixed-speed operation to software-controlled PWM motor control while introducing a reusable motion control interface. The implementation validated Arduino-based speed regulation using the L298N enable pins and established a modular software architecture suitable for future robotics development.

This milestone provides the motion control foundation upon which all subsequent sensing, autonomy, and ROS-based capabilities will be developed.
