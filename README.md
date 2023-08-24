# CUERT
Cairo university Eco-Racing team task
**Cairo University Eco-Racing Team: Autonomous Car Control System**

**Project Overview:**
The Cairo University Eco-Racing team participates annually in the Shell Eco-Racing 2023 Marathon competition. The project focuses on developing an embedded control system for an autonomous vehicle powered by an internal combustion engine (ICE). The system comprises various components, including a DC motor for speed control, a stepper motor for wheel angle adjustment, a decision-maker unit, and a dashboard to display real-time vehicle data.

**Project Task:**
Your task is to implement a simplified version of this system, involving UART-PC communication. A virtual terminal on your PC will receive data frames and map their values to control the autonomous car's speed, direction, and wheel orientation. The communication frame format is: XXXAYYBE, where:
- XXX represents the motor speed (0 to 100).
- A indicates the direction of the motor (F for forward, B for backward).
- YY denotes the angle of the second motor controlling wheel orientation (0 to 45).
- B signifies the direction of the second motor (R for right, L for left).
- E indicates the end of the frame.

**Example Communication Frames:**
I. 076F18LE: Set speed to 76%, move forward, and tilt wheels left by 18 degrees.
II. 76F18RE: Violates the standard frame length.
III. F100R09E: Does not match the standard frame.
IV. 076F18R: Correct frame but missing 'E'.

**General Assumptions:**
1. For DC motor: ACW is forward movement, CW is backward movement.
2. For stepper motor: Each step corresponds to one degree.

**Required Implementation:**
- Input speed, direction, and orientation via PC/laptop keyboard in the communication frame format.
- Display speed percentage and wheel angle on an LCD screen.
- Display time in HH:MM:SS AM/PM format, starting from 00:00:00 AM.

This project showcases your coding skills in embedded C, emphasizing efficiency, cleanliness, and robustness. You'll demonstrate integration capabilities by harmonizing multiple system components into a cohesive design.
