# 2WD Differential Drive Mobile Robot

# Engineering Report

## Level 5 – Ultrasonic Sensor Integration & Perception Foundation

---

## Document Information

| Item | Details |
|------|----------|
| Project | 2WD Differential Drive Mobile Robot |
| Level | 5 |
| Author | Chaitanya Belekar |
| Platform | Arduino UNO |
| Sensor | HC-SR04 Ultrasonic Sensor |
| Status | Completed |
| Date | July 2026 |

---

# 1. Introduction

Level 5 introduced environmental perception into the robot through the integration of the HC-SR04 ultrasonic distance sensor. Previous development stages focused on robot actuation through DC motors and a servo motor. This level enables the robot to detect nearby objects by measuring the distance between the sensor and surrounding obstacles.

A reusable UltrasonicController software module was developed to provide reliable distance measurements and simplify future integration with autonomous navigation algorithms.

---

# 2. Objectives

- Integrate the HC-SR04 ultrasonic sensor.
- Understand ultrasonic time-of-flight measurement.
- Measure object distance accurately.
- Reduce measurement noise using software filtering.
- Design a reusable UltrasonicController API.
- Prepare the robot for autonomous obstacle avoidance.

---

# 3. Hardware Components

| Component | Specification |
|-----------|---------------|
| Arduino UNO | ATmega328P |
| HC-SR04 | Ultrasonic Distance Sensor |
| Jumper Wires | Male-Female |
| USB Power | 5 V |

---

# 4. Wiring Configuration

| HC-SR04 | Arduino UNO |
|----------|-------------|
| VCC | 5V |
| GND | GND |
| TRIG | D11 |
| ECHO | D12 |

---

# 5. Working Principle

The HC-SR04 measures distance using the Time-of-Flight (ToF) principle.

1. Arduino generates a 10 µs trigger pulse.
2. The sensor emits an ultrasonic burst at approximately 40 kHz.
3. The sound wave reflects from an object.
4. The reflected wave returns to the sensor.
5. The Echo pin remains HIGH during the round-trip travel time.
6. Arduino calculates distance from the measured duration.

The distance is calculated using:

```
Distance = (Time × 0.0343) / 2
```

where 0.0343 cm/µs represents the speed of sound in air.

---

# 6. Software Architecture

The ultrasonic subsystem was implemented as a reusable controller.

Implemented API:

```cpp
initializeUltrasonic();

getDistance();

getFilteredDistance();

isObstacleDetected();

isWithinRange();
```

This modular design separates low-level sensor communication from higher-level robot behavior.

---

# 7. Experiments Performed

## Experiment 1 – Basic Distance Measurement

### Objective

Validate raw distance measurements.

### Result

PASS

The sensor successfully measured the distance to nearby objects with expected accuracy.

---

## Experiment 2 – Filtered Measurements

### Objective

Reduce sensor noise using software averaging.

### Method

Five consecutive measurements were averaged while invalid readings were discarded.

### Result

PASS

Measurement stability improved significantly.

---

## Experiment 3 – UltrasonicController Validation

### Objective

Validate the reusable software interface.

| Function | Result |
|----------|--------|
| initializeUltrasonic() | PASS |
| getDistance() | PASS |
| getFilteredDistance() | PASS |
| isObstacleDetected() | PASS |
| isWithinRange() | PASS |

---

# 8. Engineering Improvements

Compared with the initial prototype:

- Modular controller architecture
- Filtered distance measurements
- Invalid echo handling
- Single measurement reused throughout each control cycle
- Improved software readability and maintainability

---

# 9. Industrial Relevance

Ultrasonic ranging is widely used in:

- Autonomous Mobile Robots (AMRs)
- Automated Guided Vehicles (AGVs)
- Industrial safety systems
- Collision avoidance systems
- Warehouse automation
- Service robots

The modular controller developed in this project follows software engineering practices used in embedded robotics applications.

---

# 10. Challenges Encountered

During development, a configuration mismatch between software pin assignments and hardware wiring resulted in repeated "No Valid Echo" messages.

After correcting the TRIG and ECHO pin definitions, the system operated as expected. This highlighted the importance of maintaining consistency between software configuration and physical wiring during embedded system development.

---

# 11. Future Work

The HC-SR04 will be mounted on the SG90 servo motor to enable directional scanning.

Upcoming capabilities include:

- Left-Center-Right scanning
- Environment perception
- Obstacle avoidance
- Autonomous navigation
- ROS 2 sensor integration

---

# 12. Conclusion

Level 5 successfully introduced distance sensing into the robot through the integration of the HC-SR04 ultrasonic sensor. A reusable UltrasonicController module was developed to provide stable distance measurements and configurable obstacle detection. This level establishes the perception foundation required for autonomous robot behavior in the upcoming development stages.
