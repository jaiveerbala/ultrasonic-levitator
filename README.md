# Acoustic Levitator

An Arduino-powered acoustic levitator that suspends small objects in midair using ultrasonic standing waves. Built in 7th grade.

## How it works

Two ultrasonic transmitters face each other at a specific distance. When driven at 40kHz (the resonant frequency of the transducers), they create a standing wave between them. The pressure nodes of that wave are strong enough to trap and suspend small lightweight objects like foam balls or pieces of paper without any physical contact.

The transmitters are desoldered from HC-SR04 ultrasonic sensor modules. The Arduino alone can't drive them with enough power to form a stable levitation node, so an L298N motor driver module is used to amplify the signal from 5V up to around 25V peak-to-peak. The Arduino generates the 40kHz square wave and the L298N does the amplification.

Getting it to work requires careful physical alignment and finding the right distance between the two transmitters. Once a stable configuration is found the geometry is fixed in place.

## Hardware

- Arduino Uno or Nano
- L298N dual H-bridge motor driver module
- 2x ultrasonic transmitters (desoldered from HC-SR04 modules)
- 12V DC power supply
- 3D printed enclosure (designed after alignment was confirmed)

## Wiring

| Arduino | L298N |
|---------|-------|
| A0      | IN1   |
| A1      | IN2   |
| GND     | GND   |

| L298N  | Component          |
|--------|--------------------|
| OUT1   | Transmitter 1 (+)  |
| OUT2   | Transmitter 1 (-)  |
| OUT3   | Transmitter 2 (+)  |
| OUT4   | Transmitter 2 (-)  |
| 12V    | 12V power supply   |

Both transmitters face each other. Power the L298N from a 12V supply, not the Arduino's 5V rail.

## Notes

The half-period delay in the code is set to 12 microseconds, producing approximately 40kHz. If levitation is weak or unstable, try adjusting this value by 1 or 2 microseconds in either direction to better match your specific transducers' resonant frequency. Alignment and distance between the transducers also significantly affect performance and may need tuning.
