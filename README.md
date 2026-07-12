# 🤖 2WD Differential Drive Mobile Robot

> A complete robotics engineering project documenting the design, development, simulation, and ROS 2 integration of a differential drive mobile robot built from scratch using Arduino UNO and ESP32.

![Status](https://img.shields.io/badge/Status-Level%202%20Completed-success)
![Platform](https://img.shields.io/badge/Platform-Arduino%20UNO%20%7C%20ESP32-blue)
![Communication](https://img.shields.io/badge/Communication-UART%20%7C%20Bluetooth-orange)
![Future](https://img.shields.io/badge/ROS2-Coming%20Soon-informational)

---

# 📖 Project Overview

This repository documents the complete engineering journey of building a **2WD Differential Drive Mobile Robot**, starting from basic motor testing and gradually evolving into a fully autonomous ROS 2 mobile robot.

Unlike conventional Bluetooth robot projects, this project follows a **modular robotics architecture**, separating communication, motor control, simulation, localization, and navigation into independent development stages.

The objective is to understand every subsystem individually before integrating them into a complete autonomous mobile robot.

---

# 🎯 Objectives

- Design a modular differential drive robot
- Learn embedded systems from first principles
- Implement reliable UART communication between controllers
- Develop Bluetooth teleoperation using ESP32
- Build a scalable architecture suitable for ROS 2
- Integrate simulation, odometry, SLAM, and autonomous navigation

---

# 🏗️ System Architecture (Current)

```
             Android Phone
                    │
          Bluetooth Classic
                    │
             ESP32 WROOM-32
       (Communication Controller)
                    │
             UART (9600 baud)
                    │
             Arduino UNO
         (Motor Controller)
                    │
              L298N Driver
                    │
          Differential Drive Robot
```

---

# ⚙️ Hardware Components

| Component | Quantity |
|------------|---------:|
| Arduino UNO | 1 |
| ESP32 WROOM-32 Development Board | 1 |
| L298N Motor Driver | 1 |
| BO Dual Shaft DC Gear Motors | 2 |
| 2WD Robot Chassis | 1 |
| Caster Wheel | 1 |
| 18650 Li-ion Battery | 2 |
| Power Switch | 1 |
| Jumper Wires | As Required |

---

# 💻 Software & Tools

- Arduino IDE
- ESP32 Board Package
- Bluetooth Classic (SPP)
- UART Serial Communication
- Git
- GitHub

Future:

- ROS 2 Humble
- Gazebo
- RViz
- Ubuntu 22.04
- Docker

---

# 📂 Project Roadmap

| Level | Description | Status |
|--------|-------------|--------|
| Level 1 | Motor Driver Testing | ✅ Completed |
| Level 2 | ESP32 Bluetooth Teleoperation | ✅ Completed |
| Level 3 | PWM Speed Control | ✅ Completed |
| Level 4 | Servo Scanning | 🔜 Planned |
| Level 5 | Obstacle Avoidance | 🔜 Planned |
| Level 6 | ESP32 Standalone Robot | 🔜 Planned |
| Level 7 | ROS 2 Integration | 🔜 Planned |
| Level 8 | Robot Simulation | 🔜 Planned |
| Level 9 | Odometry | 🔜 Planned |
| Level 10 | SLAM | 🔜 Planned |
| Level 11 | Navigation | 🔜 Planned |

---

# ✅ Level 1 — Motor Driver Bring-up

## Objective

Verify the complete motor driver wiring and understand differential drive kinematics before introducing communication layers.

## Hardware Tested

- Arduino UNO
- L298N Motor Driver
- Two DC Gear Motors

## Implemented Functions

✔ Individual Left Motor Test

✔ Individual Right Motor Test

✔ Forward Motion

✔ Backward Motion

✔ Left Rotation

✔ Right Rotation

✔ Complete Motion Test

## Motor Logic

### Forward

Left Motor

IN1 LOW

IN2 HIGH

Right Motor

IN3 HIGH

IN4 LOW

### Backward

IN1 HIGH

IN2 LOW

IN3 LOW

IN4 HIGH

### Left

IN1 HIGH

IN2 LOW

IN3 HIGH

IN4 LOW

### Right

IN1 LOW

IN2 HIGH

IN3 LOW

IN4 HIGH

### Stop

All control pins LOW

---

# ✅ Level 2 — ESP32 Bluetooth Teleoperation

## Objective

Separate communication and motor control by introducing an ESP32 as a dedicated Bluetooth communication controller.

## Controller Architecture

ESP32

- Bluetooth Communication
- UART Transmission

Arduino UNO

- UART Reception
- Motor Logic
- Differential Drive Control

## Communication Protocol

| Command | Action |
|----------|---------|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |

---



## Communication Flow

```
Android Phone

        │

Bluetooth

        │

ESP32

        │

UART

        │

Arduino UNO

        │

Motor Driver

        │

Robot Motion
```

---

# 📡 UART Configuration

ESP32

```
GPIO17 (TX2) -----> Arduino D10 (RX)

GND -------------> Arduino GND
```

Baud Rate

```
9600
```

---

# 🎮 Bluetooth Control

The robot can be controlled wirelessly using an Android application over Bluetooth Classic.

Implemented Controls

- Forward
- Backward
- Left
- Right
- Stop

---

## ✅ Level 3 – PWM Motor Controller

### Objective

Introduce software-controlled motor speed using PWM while redesigning the motor control software into a reusable and modular interface.

### Features

- PWM Speed Control
- Configurable Speed Parameter
- Reusable Motor Control API
- Safe Motor Initialization
- Modular Software Design

### Implemented API

```cpp
initializeMotors();

forward(speed);

backward(speed);

left(speed);

right(speed);

stopRobot();
```

## Engineering Improvements

Replaced fixed-speed motor control with PWM-based control.
Removed hardware enable jumpers.
Arduino now controls ENA and ENB using PWM outputs.
Introduced reusable motion functions for future development.

## Result

The robot can now execute all differential drive motions at variable speeds, providing a scalable foundation for future features such as smooth acceleration, obstacle avoidance, and ROS 2 integration.

---

# 🧠 Engineering Concepts Learned

- Differential Drive Kinematics
- H-Bridge Motor Driver
- Digital Motor Control
- UART Communication
- HardwareSerial
- SoftwareSerial
- Bluetooth Classic
- Command-Based Communication Protocol
- Modular Embedded System Design
- Serial Debugging
- Embedded System Troubleshooting

---

# 📸 Project Gallery

Coming Soon

- Robot Images
- Wiring Diagram
- Hardware Setup
- Bluetooth Demonstration
- Motion Videos

---

# 🚀 Future Development

### Embedded Systems

- PWM Speed Control
- Smooth Differential Steering
- Wheel Encoder Integration
- Closed Loop Speed Control

### Robotics

- Robot Odometry
- IMU Integration
- ROS 2 Hardware Interface
- URDF Model

### Simulation

- Gazebo Simulation
- RViz Visualization
- Robot State Publisher
- Joint State Publisher

### Autonomy

- SLAM
- Localization
- Navigation2
- Autonomous Path Planning

---

# 📈 Current Progress

```
██████████░░░░░░░░░░░░░░░░░░░░░ 22%

✔ Hardware Bring-up

✔ Motor Driver Testing

✔ UART Communication

✔ Bluetooth Teleoperation

⬜ PWM Speed Control

⬜ ROS 2 Integration

⬜ Simulation

⬜ Odometry

⬜ SLAM

⬜ Navigation
```

---

# 📚 Learning Outcomes

This project demonstrates practical understanding of

- Embedded Systems
- Mobile Robotics
- Differential Drive Kinematics
- Microcontroller Communication
- Bluetooth Communication
- Serial Protocols
- System Integration
- Robotics Software Development

---

# ⭐ Repository Goal

This repository is intended to document the complete engineering lifecycle of a mobile robot—from hardware bring-up and embedded programming to ROS 2 integration, simulation, and autonomous navigation.

Each level builds upon the previous one, creating a scalable robotics platform rather than a standalone Bluetooth-controlled robot.
