# 2WD Differential Drive Mobile Robot

# Engineering Report

## Level 4 – Servo Motor Integration & Sensor Positioning System

---

## Document Information

| Item | Details |
|------|----------|
| Project | 2WD Differential Drive Mobile Robot |
| Level | 4 |
| Version | v1.2.0 |
| Author | Chaitanya Belekar |
| Platform | Arduino UNO |
| Servo Motor | SG90 Micro Servo |
| Status | Completed |
| Date | July 2026 |

---

# 1. Introduction

Following the successful implementation of PWM-based motor control in Level 3, the next objective was to introduce a position-controlled actuator into the robot. Unlike the DC drive motors, which provide continuous rotational motion, the SG90 servo motor enables accurate angular positioning.

The servo will serve as the rotating platform for the ultrasonic sensor in future development stages, allowing the robot to scan its surroundings before making navigation decisions.

This level focused on understanding servo operation, validating angular motion, implementing smooth scanning trajectories, and designing a reusable software interface for future sensor integration.

---

# 2. Objectives

- Understand the working principle of a servo motor.
- Integrate an SG90 servo with the Arduino UNO.
- Validate angular positioning at predefined angles.
- Generate smooth sweep trajectories.
- Design a reusable Servo Controller API.
- Prepare the robot for environment scanning.

---

# 3. Hardware Components

| Component | Specification | Quantity |
|-----------|---------------|---------:|
| Arduino UNO | ATmega328P | 1 |
| SG90 Servo Motor | 180° Micro Servo | 1 |
| USB Power Supply | 5 V | 1 |
| Jumper Wires | Male-Female | As Required |

---

# 4. Servo Wiring

| Servo Wire | Arduino Connection |
|------------|-------------------|
| Brown | GND |
| Red | 5V |
| Orange | D10 |

---

# 5. Software Tools

- Arduino IDE
- Servo Library (Built-in)
- Git
- GitHub

---

# 6. Working Principle

Unlike a conventional DC motor, a servo motor provides controlled angular positioning using an internal feedback mechanism.

An SG90 servo contains:

- DC Motor
- Reduction Gear Train
- Potentiometer
- Embedded Control Circuit

The Arduino generates a control pulse approximately every 20 ms. The pulse width corresponds to the desired shaft angle. The internal controller continuously compares the commanded position with the feedback from the potentiometer and drives the motor until the position error becomes negligible.

This makes the servo a closed-loop actuator.

---

# 7. System Architecture

```
Arduino UNO

      │

Servo Library

      │

PWM Control Signal

      │

SG90 Servo Motor

      │

Angular Position

      │

Future Ultrasonic Sensor Mount
```

---

# 8. Servo Controller API

To maintain software modularity, all servo operations were encapsulated into reusable functions.

Implemented interface:

```cpp
initializeServo();

moveTo(angle);

lookLeft();

lookCenter();

lookRight();

scanEnvironment();
```

This abstraction hides low-level servo control from higher-level navigation logic.

---

# 9. Experiments Performed

## Experiment 1 – Fixed Position Validation

### Objective

Verify servo movement to predefined angular positions.

Commands executed:

- 0°
- 90°
- 180°

### Result

PASS

The servo accurately positioned itself at all commanded angles.

---

## Experiment 2 – Continuous Sweep Motion

### Objective

Generate a smooth angular trajectory across the complete operating range.

Sweep:

```
0°

↓

180°

↓

0°
```

### Result

PASS

The servo demonstrated smooth, continuous motion without noticeable vibration or missed positions.

---

## Experiment 3 – Servo Controller Validation

Objective:

Validate all reusable Servo Controller functions.

| Function | Result |
|----------|--------|
| initializeServo() | PASS |
| moveTo() | PASS |
| lookLeft() | PASS |
| lookCenter() | PASS |
| lookRight() | PASS |
| scanEnvironment() | PASS |

---

# 10. Software Design

The servo control software was redesigned into a modular architecture.

Previous approach:

```cpp
servo.write(90);
```

Current approach:

```cpp
lookCenter();
```

Benefits include:

- Improved readability
- Reduced code duplication
- Easier maintenance
- Simplified future expansion

---

# 11. Engineering Improvements

Compared to previous levels, the robot now includes:

- Position-controlled actuator
- Smooth angular trajectory generation
- Reusable Servo Controller
- High-level movement abstraction
- Preparation for sensor scanning

---

# 12. Industrial Relevance

Servo motors are widely used throughout robotics and automation wherever accurate positioning is required.

Typical applications include:

- Sensor positioning systems
- Camera pan-tilt units
- Robotic grippers
- Inspection robots
- Pick-and-place manipulators
- Steering systems in autonomous vehicles

The modular controller developed in this project reflects common embedded software engineering practices used in industrial robotics.

---

# 13. Challenges Encountered

During implementation, careful pin allocation was required to avoid conflicts with the PWM pins already dedicated to the L298N motor driver.

The final configuration assigned:

| Function | Arduino Pin |
|----------|-------------|
| ENA | D6 |
| ENB | D9 |
| Servo Signal | D10 |

This arrangement allows independent operation of both the differential drive system and the servo motor.

---

# 14. Future Work

The servo controller developed in this level will be integrated with an HC-SR04 ultrasonic sensor to create a rotating sensor head.

Upcoming milestones include:

- Ultrasonic distance measurement
- Left-Center-Right environment scanning
- Obstacle detection
- Obstacle avoidance
- Autonomous navigation
- ROS 2 sensor integration

---

# 15. Conclusion

Level 4 successfully introduced precise position control into the robot through the integration of an SG90 servo motor. The servo was validated for fixed-angle positioning and smooth sweep motion, and a reusable Servo Controller API was developed to simplify future software development.

This level establishes the mechanical and software foundation required for environment perception using a rotating ultrasonic sensor, representing an important transition from purely teleoperated motion toward autonomous sensing capabilities.
