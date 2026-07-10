# Engineering Report

# Level 2 – ESP32 Bluetooth Teleoperation and Distributed Embedded Control

---

| Document Information | |
|----------------------|-----------------------------------------|
| **Project** | 2WD Differential Drive Mobile Robot |
| **Level** | Level 2 – ESP32 Bluetooth Teleoperation |
| **Project Version** | v1.0.0 |
| **Document Version** | v1.0 |
| **Status** | Completed |
| **Development Platform** | Arduino UNO + ESP32 WROOM-32 |
| **Programming Language** | Arduino (C/C++) |
| **Communication Protocols** | Bluetooth Classic, UART |
| **Date** | July 2026 |

---

# Abstract

After successfully validating the differential drive hardware in Level 1, the next development objective was to introduce wireless teleoperation without altering the proven motor control subsystem.

Instead of replacing the Arduino UNO with an ESP32, a distributed embedded architecture was adopted. The ESP32 was dedicated to Bluetooth communication, while the Arduino UNO continued to manage all motor control functions. Communication between the two controllers was established using UART serial communication.

A simple single-character command protocol was developed to transmit robot motion commands from an Android device to the ESP32, then to the Arduino UNO, which executed the appropriate motor control routines.

This modular architecture improves scalability, simplifies debugging, and provides a clear migration path toward ROS 2 integration in future development stages.

---

# 1. Introduction

Modern robotic systems often divide responsibilities among multiple processing units. Rather than assigning communication, sensing, motor control, and navigation to a single microcontroller, many robots distribute these tasks across specialized controllers.

This approach offers several advantages:

- Improved software modularity
- Easier debugging
- Independent subsystem development
- Better scalability
- Simplified future upgrades

Level 2 introduces this philosophy by separating communication and motor control into two independent embedded systems connected through a serial interface.

---

# 2. Objectives

The objectives of Level 2 were:

- Integrate wireless Bluetooth communication using ESP32.
- Establish UART communication between ESP32 and Arduino UNO.
- Develop a lightweight command protocol for robot control.
- Maintain the validated motor control subsystem without modification.
- Verify end-to-end communication from smartphone to robot.
- Prepare the project architecture for future ROS 2 integration.

---

# 3. Background Theory

## 3.1 Bluetooth Classic

Bluetooth Classic (Serial Port Profile - SPP) provides a reliable wireless serial communication channel between two devices.

Unlike Bluetooth Low Energy (BLE), Bluetooth Classic behaves similarly to a traditional serial cable, making it ideal for command-based robot control.

Advantages include:

- Simple implementation
- Wide Android support
- Low latency
- Compatible with serial terminal applications

---

## 3.2 UART Communication

Universal Asynchronous Receiver Transmitter (UART) is one of the simplest communication protocols between embedded systems.

UART communication requires:

- Transmitter (TX)
- Receiver (RX)
- Common Ground (GND)

Data is transmitted sequentially without a shared clock.

For this project:

- ESP32 acts as UART Transmitter.
- Arduino UNO acts as UART Receiver.

Baud Rate:

```
9600 bps
```

---

## 3.3 Distributed Embedded Architecture

Instead of combining communication and motor control on one controller, the system was divided into two dedicated modules.

ESP32

Responsibilities:

- Bluetooth pairing
- Receiving user commands
- UART transmission

Arduino UNO

Responsibilities:

- UART reception
- Motion interpretation
- Motor control
- Differential drive implementation

This separation follows common embedded design principles where each processor performs a clearly defined task.

---

# 4. Hardware Components

| Component | Specification | Quantity |
|-----------|---------------|---------:|
| Arduino UNO | ATmega328P | 1 |
| ESP32 WROOM-32 Development Board | Dual Core | 1 |
| L298N Motor Driver | Dual H-Bridge | 1 |
| Android Smartphone | Bluetooth Controller | 1 |
| BO Gear Motors | 6–12V | 2 |
| Li-ion Battery Pack | 7.4V | 1 |

---

# 5. System Architecture

The communication architecture implemented during Level 2 is shown below.

```
           Android Phone
                  │
          Bluetooth Classic
                  │
          ESP32 WROOM-32
      (Communication Controller)
                  │
            UART Serial
                  │
            Arduino UNO
        (Motor Controller)
                  │
             L298N Driver
                  │
           Differential Drive Robot
```

This architecture provides a clean separation between communication and motion control.

---

# 6. Circuit Connections

## ESP32 to Arduino UNO

| ESP32 | Arduino UNO |
|--------|-------------|
| GPIO17 (TX2) | D10 (SoftwareSerial RX) |
| GND | GND |

Only one-way communication was required during this development stage.

Future levels may implement bidirectional communication by connecting:

ESP32 RX2 ← Arduino TX

---

# 7. Communication Protocol

A lightweight command protocol was implemented using single ASCII characters.

| Command | Robot Action |
|----------|--------------|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |

The ESP32 receives the character through Bluetooth and forwards it unchanged to the Arduino UNO.

This protocol minimizes communication overhead while remaining human-readable.

---

# 8. Software Architecture

The software was intentionally divided into two independent programs.

## ESP32 Firmware

Responsibilities:

- Initialize Bluetooth
- Wait for smartphone connection
- Receive Bluetooth commands
- Forward commands through UART

## Arduino Firmware

Responsibilities:

- Monitor SoftwareSerial
- Receive UART command
- Decode character
- Execute motion function
- Drive motors

This modular software architecture allows either controller to be upgraded independently.

---

# 9. Testing Methodology

Testing was conducted incrementally to isolate communication issues before full robot operation.

| Test | Objective | Status |
|------|-----------|--------|
| UART Transmission Test | ESP32 → Arduino | PASS |
| Serial Debugging | Character Verification | PASS |
| Bluetooth Pairing | Android → ESP32 | PASS |
| Command Forwarding | ESP32 → Arduino | PASS |
| Motion Execution | Arduino → Motors | PASS |
| End-to-End Robot Control | Smartphone → Robot | PASS |

---

# 10. Experimental Results

The complete communication chain operated successfully.

```
Phone

↓

Bluetooth

↓

ESP32

↓

UART

↓

Arduino

↓

Motor Driver

↓

Robot Motion
```

Each transmitted command resulted in the expected robot motion without noticeable communication delay.

Repeated testing confirmed reliable operation for all implemented commands.

---

# 11. Challenges and Debugging

Several practical issues were encountered during development.

## Issue 1 – Incorrect SoftwareSerial Logic

A programming mistake in the command parsing logic prevented proper command execution.

Resolution:

Corrected the variable usage and switch statement implementation.

Result:

Commands were interpreted correctly.

---

## Issue 2 – USB Communication Failure

The ESP32 intermittently disappeared from the Windows COM port list.

Root Cause:

Faulty USB cable.

Resolution:

Replaced the USB cable.

Result:

Stable serial communication restored.

---

## Issue 3 – Robot Not Moving

Observation:

Bluetooth communication appeared successful, but the motors remained stationary.

Root Cause:

Robot power switch was OFF.

Resolution:

Enabled battery power.

Result:

Normal operation resumed.

---

## Issue 4 – Software Validation

Before connecting the motors, UART communication was validated using serial monitors on both controllers.

This isolated communication problems before introducing motor hardware.

---

# 12. Engineering Decisions

| Decision | Reason |
|----------|--------|
| Use ESP32 for Bluetooth only | Separation of responsibilities |
| Keep Arduino as motor controller | Existing validated motor subsystem |
| Use UART | Reliable and simple communication |
| Single-character commands | Minimal communication overhead |
| SoftwareSerial on Arduino | Preserved hardware USB serial for debugging |

These decisions reduced development complexity and simplified troubleshooting.

---

# 13. Industrial Relevance

The architecture implemented in Level 2 resembles the distributed control philosophy used in industrial robotic systems.

Examples include:

- Communication controller ↔ Motor controller
- High-level processor ↔ Low-level actuator controller
- Navigation computer ↔ Embedded drive controller

This modular design allows future expansion without redesigning the existing motor control software.

---

# 14. Lessons Learned

Several important engineering lessons were obtained.

- Validate communication independently from hardware.
- Debug one subsystem at a time.
- Maintain modular software architecture.
- Use serial debugging extensively during embedded development.
- Hardware issues often appear as software faults.
- Reliable power distribution is essential for mobile robots.

---

# 15. Future Work

The successful completion of Level 2 enables future development including:

- PWM speed control
- Differential steering
- ESP32 standalone implementation
- Wheel encoder integration
- Closed-loop motor control
- ROS 2 teleoperation
- Gazebo simulation
- Odometry
- SLAM
- Autonomous navigation

---

# 16. Conclusion

Level 2 successfully transformed the mobile robot from a standalone embedded platform into a distributed robotic system capable of wireless teleoperation.

Bluetooth communication using the ESP32, combined with UART communication to the Arduino UNO, enabled reliable smartphone-based control while preserving the validated motor control subsystem developed during Level 1.

The modular architecture adopted during this stage establishes a scalable foundation for future development, including ROS 2 integration, autonomous navigation, and advanced robotics algorithms.

This milestone demonstrates the successful integration of embedded communication, modular software design, and differential drive control into a unified robotic platform.
