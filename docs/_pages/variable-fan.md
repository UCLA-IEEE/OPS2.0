---
permalink: /variable-fan/
title: "Arduino Variable Fan"
excerpt: "Build a Custom Fan"
last_modified_at: 2020-09-07T08:52:00-10:40
toc: true
---

<p align="center">
  <img src="../assets/images/fan.png" width="350" />
</p>

## About this Project

In this project you will be making a fan that has three different speed settings: Low, Medium, and High; as well as an off state. In the first part of the project you will control the speed via three buttons. For the second part of the project you will control the speed via a potentiometer that will act as a dial. The purpose of this project is to introduce PWM/ analogWrite() functions in the Arduino, this will be what changes the speed of the fan motor.

### [Lecture Slides](https://docs.google.com/presentation/d/1moI7U1xzFQstFh7E4rx5PRVGADOLG4JN7vBeHRrRPc8/edit?usp=sharing)

### <ins>Prerequisites</ins>

* Intro to Arduino

### <ins>Skills Learned</ins>

* Potentiometer
* Push buttons
* Voltage divider circuit
* analogWrite()

## Parts list

* Microcontroller Board (Arduino)
* Breadboard
* USB Cable
* Jumpter Wires
* Resistors (3)
* Push Buttons (3)
* Fan Motor
* Potentiometer

## Project Specification

### <ins>The Motor</ins>

* The motor has two leads attached to it (red and black)
    - Red lead should be connected to a power source
    - Black lead should be connected to ground
    - **Note**: no need for a resistor between the leads since the motor has high internal resistance
* Connect the red wire to a digital PWM pin
    - PWM pins on the Arduino are marked with tildes (`~`)
    - PWM pins allow you to use `analogWrite()`
* `analogWrite(<pin_name>, <val>)`
    - `<val>` must be in range [0, 255]
    - ex) `analogWrite(FAN, 105)`, where the FAN is the defined name for the PWM pin used (using `#define <pin_name>`)
* Experiment with different values of `<val>` in `analogWrite()`
    - Observe how teh `<val>` changes the behavior of the fan
    - Try to find three values to make the fan go at low, medium, and high speeds

### <ins>Checkpoint 1: Turn the Motor on with a Button</ins>

* Construct a program and a circuit that
    - turns **on** the motor when the button is **pressed**
    - turns **off** the motor when the button is **not** being pressed
* You only need to wire the motor onece throughout this project

1. Connect the power source (5V) and ground to appropriate places
2. Add buttons to your breadboard
    - Make sure the pinson each side are in the same row (node) on the board
3. Connect one end of the button to the power source
4. Connect the other end of the button to ground via a resistor
    - This resistor can be of any value > 100Ω, it's only used to prevent a short circuit
    - Use two diagnoal pins to connect to power and ground to prevent accidently shorting the button (see [Lecture Slides: Buttons](https://docs.google.com/presentation/d/13bLpWzn6QU92ZCCOJLvv7wSa92oNdqFwzb_4N0MIXZA/edit?usp=sharing))
5. Connect the node on the butotn with the resistor connected to it to an analog input pin. 
    - This will be used to detect when the button is pressed.
    - This analog pin will read
        + large voltage when the button is pressed
        + nothing (0) when the button isn't pressed

Now we need to program the microcontroller. Below is the how the loop portion will look: 

```
void loop() {
    // declare a speed
    // read in the value from the BUTTON pin (hint: use analogRead())

    //50 to account for noise
    if (x > 50) {
        /* 
        turn the FAN on by sending some voltage to the FAN pin 
        (hint: use analogWrite())
        */
    }
    else {
        /*
        turn the FAN off 
        (hint: analogWrite(FAN, 0) will turn off voltage at the FAN pin)
        */
    }
}
```

**Note**: if your BUTTON is always reading high values (fan is always on), make sure your button is inserted the correct way (use 2 diagonal pins)

### <ins>Checkpoint 2: Choosing the Fan Speed with Buttons</ins>

We will now extend our design from the previous checkpoint to include 3 buttons. The buttons will let the user choose from three different speeds. The two buttons you add will be wired similarly to how you set up the first button. You will have to `#define` all 3 buttons.

Modify the code you've already written for the previous checkpoint, to incorporate 3 buttons

Here's the pseudo-pseudocode: (Pseudocode describes the program in general, but the details will be filled in by you! Below is a bad example of pseudocode but it gives you a more detailed guideline ;))

```
define the button pins
in setup,
    declare appropriate pins as inputs or outputs
    declare 3 speeds (low, medium, high)
in the loop,
    read inputs from the buttons
    if button1 is pressed, turn the fan on to low speed
    else if button2 is pressed, turn the fan on to medium speed
    else if button3 is pressed, turn the fan on to high speed
    else, turn the fan off
```

**Note**: Don't worry about how the fan will behave if more than one button is pressed at once (unless you want to)

### <ins>Checkpoint 3: Using a Potentiometer to Change Motor Speed</ins>

Now replace the triple button setup with a potentiometer that will allow us to select different speeds. The wiring of the motor stays the same as before. Here's how you might want to do that:

1. Connect power source (5V) and ground (GND) to appropriate places
2. Insert the potentiometer into the circuit
    - **Note**: be careful not to short the pins of the potentiometer
    - See [Lecture Slides: Potentiometer](https://docs.google.com/presentation/d/1pO5jrERVdcT1o-FZ_Pr5I6MBcexDJQ8248tcjNygXOs/edit?usp=sharing) for more on the potentiometer
3. Print the values of the analog pin to see how it changes as you turn the potentiometer knob
    - If it doesn't change as expected, doulbe check how you inserted the potentiometer to the circuit
4. Use the potentiometer input values to change the speed of the fan!
    - There are multiple ways to do this, but here's one way:
        + Declare threshold 3 values that will determine the fan setting (ex) 300, 600, 1023)
        + Read in the potentiometer value 
        + Choose fan speeds by comparing the potentiometer input value to the threshold values
    - Here's another way (optional):
        + Read in the potentiometer value
        + Map the input value ([0, 1023]) to the output value ([0, 255]) using the Arduino `map()` function ([Doc](https://www.arduino.cc/reference/en/language/functions/math/map/))