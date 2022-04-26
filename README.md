# INO_Arduino-boot-counter

A small project that counts and stores the number of times that the arduino booted up.

## Table of contents

- [Table of contents](#table-of-contents)
- [Detailled description](#detailled-description)
- [Components and supplies](#components-and-supplies)
- [Breadboard view](#breadboard-view)
- [Schematic view](#schematic-view)

## Detailled description

I started working on this since I wanted to use the I2C method for displaying something on the 7-segment display.
I also wanted to test how to store data into the arduino nano (using E²PROM), even after it has been turned off.

When powered on, the arduino gets from memory the number of times the system has turned on, then displays it and rewrites the old value with the new incremented value. Then, it plays a neat sound ;)

If you want to start from 0, simply press the "reset button" added into the circuit: that will set the number to default.

## Components and supplies

- 4-Pin button
- 5V Active buzzer
- 10K Resistor
- Adafruit 0.56" 4-Digit 7-Segment Display w/I2C Backpack
- Arduino Nano
- Breadboard
- Jumper wires

## Breadboard view

![image](https://user-images.githubusercontent.com/56207146/165314665-9cd131b1-2862-4487-8667-d78e67cd936c.png)

## Schematic view

![image](https://user-images.githubusercontent.com/56207146/165314725-b492cc9c-42a6-45ab-9d12-a57647bf8cd3.png)
