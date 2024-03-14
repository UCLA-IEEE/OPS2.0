---
title: "4: Microcontrollers"
excerpt: "An introduction to Arduino with a fun and easy project."
toc: true
order: 4
header:
    teaser: /assets/images/arduino.jpg
---

<p align="center">
  <img src="/assets/images/arduino.jpg" width="350" />
</p>

## About this Project
In this project, you will be working with microcontrollers which is just a fancy word for a small programmable computer that can coordinate different input/output functions in your circuit. The different components that will be attached to the microcontroller include a potentiometer(input) used as a voltage divider and an LED(output) that will change blinking frequency as you turn the potentiometer knob. This project will fuse both your knowledge on circuits and coding to make a really cool project!

### [Lecture Slides](https://docs.google.com/presentation/d/1nyP0vQC_arV6IUXLa0IzkofAdlR-QKfLa5nKvuNIZzM/edit?usp=sharing)

### <ins>Prerequisites</ins>

* [Turning on an LED](/turn-on-led)

### <ins>Skills Learned</ins>

* Voltage Divider Circuit
* Potentiometer
* Choosing Arduino Pins
* Arduino Programming

## Parts List

| Part                                  | Quantity | Estimated Cost | Example Vendor |
| ------------------------------------- | -------- | -------------- | --------------
| Breadboard | 1 | $1.50 | [Amazon](https://www.amazon.com/DEYUE-breadboard-Set-Prototype-Board/dp/B07LFD4LT6/ref=sr_1_3?dchild=1&keywords=breadboard&qid=1588123957&s=electronics&sr=1-3) |
| Potentiometer | 1 | $0.95 | [Adafruit](https://www.adafruit.com/product/1831) |
| LED | 1 | $0.25 | [Digikey](https://www.digikey.com/product-detail/en/lite-on-inc/LTL-4233/160-1130-ND/217580) |
| 130 Ohm Resistor | 1 | $0.03 | [Digikey](https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CFM12JT130R/S130HCT-ND/2617554) |
| Arduino Nano | 1 | $4.00 | [Amazon](https://www.amazon.com/KOOKYE-Arduino-Nano-ATmega328P-Micro-controller/dp/B019SXNBQY/ref=sr_1_8?s=electronics&ie=UTF8&qid=1468042975&sr=1-8&keywords=arduino%20nano) |
| Mini USB Cable | 1 | $2.00 | [Mouser](https://www.mouser.com/ProductDetail/Qualtek/3021003-03/?qs=sGAEpiMZZMsnDbBzJh6VGJdPZmg6V0p2) |


**<ins>Total estimated cost:</ins>** $8.73 per member
*<ins>If reusing Breadboard/Arduino/MiniUSB:</ins>* $1.23 per member

## Background

### <ins>Voltage Dividers</ins>
* A voltage divider is a circuit that consists of 2 resistors R1 and R2, and an input voltage Vin.
* Vout is a measurement across the resistor closest to GND (R2)  and its value depends on the ratio of R1 and R2.
* Using Ohm’s Law (V=IR), we can determine the exact value of Vout
  * Equivalent Resistance Req = R1 + R2 (add when resistors are in series)
  * Vin = I * Req
    * We can rearrange the equation to get: I = Vin/Req = Vin/(R1 + R2)
  * Vout = V2 = I * R2
    * We can plug in I found previously into this equation since current through R1 has the same value as R2 to get: Vout = Vin * (R2/(R1+R2))
<p align="center">
  <img src="/assets/images/potentiometer-voltage-div.png" width="350" />
</p>
<p align="center">
  <img src="/assets/images/potentiometer-vout.png" width="350" />
</p>

### <ins>Potentiometers</ins>
* All potentiometers have a total resistance associated with it and in this project, we have a 10K Ohm one. A potentiometer splits this 10K resistance into 2 resistances R1 and R2, whose values depend on how much the knob of a potentiometer is turned. See figure 2.
* You can think of a potentiometer as a variable voltage divider because there are two resistances involved. By turning the potentiometer knob (wiper), the ratio of the 2 resistances in the potentiometer will change and thus Vout will also change.
* There are 3 terminals, and the outermost terminals (1 and 3 in the figure below) are connected to either GND or VCC. The middle terminal(T2) should be connected to an INPUT pin on the Arduino since we want to READ the voltage of the potentiometer at that pin with respect to GND. The voltage you would be reading if looking at Figure 2 is the Vout or the voltage across R2. This setup will create a voltage divider circuit, where you will be able to change R1 and R2 by turning the knob.
* NEVER CONNECT THE MIDDLE TERMINAL TO GND OR VCC
  * If you turn the knob all the way to the left so that R2 is 0 Ohms (no resistance) in the example below and then connect the output terminal to VCC, there will be a short from VCC to GND and your Arduino will fry/smoke/break which is NOT GOOD!
  * The same thing will happen if you turn the knob all the way to the right so that R1 has no resistance and connect the middle terminal to GND so that there is also a short from VCC to GND.
  * Always check this before doing anything else.

<p align="center">
  <img src="/assets/images/potentiometer-terminals.jpg" width="350" />
  <div align="center">Physical potentiometer and its 3 terminals</div>
</p>
<p align="center">
  <img src="/assets/images/potentiometer-representation.png" width="350" />
  <div align="center">Symbolic representation of a potentiometer as 2 variable resistances</div>
</p>

### <ins>The Arduino Nano’s Pins</ins>
* There are 3 types of programmable pins on the Arduino, but we will only focus on the first two types for this project. The pins can either read a voltage value or output a voltage.
  1. Digital INPUT/OUTPUT pins
    * These are labelled with the letter “D” on the Arduino Nano.
    * The digital pins will use a HIGH or LOW voltage to read/output. HIGH for the Arduino Nano equates to 5V and LOW is 0V. For the project, we want to have our LED turn completely ON/OFF instead of gradually dimming/becoming brighter, so we connect the LED to a digital OUTPUT pin.
    * Input: The pin will read either a HIGH(1) or LOW(0) voltage
    * Output: The pin will output either a HIGH(1) or LOW(0) voltage
  2. Analog INPUT pins
    * These pins are labelled with the prefix letter “A” on the Arduino Nano.
    * Analog input pins will map a voltage between 0V and 5V to a digital number from 0-1023.
    * Note(not necessary to know): There are 1024 total digital values that can be represented because the Arduino uses a 10 bit ADC(analog to digital converter), meaning there are 2^10 = 1024 values that 10 bits can represent.
    * In this project, we want to connect the middle pin of the potentiometer to an analog input pin since we want to change the LED’s blinking frequency AS we are turning the potentiometer knob and can do so using a range of input values.
  3. Digital PWM OUTPUT pins
    * To output an analog-like signal, PWM(pulse width modulation) pins are used. More on this in later projects. This is not used in this project.
  <p align="center">
    <img src="/assets/images/arduino-pins.png" width="600" />
  </p>

### <ins>The Arduino IDE</ins>
* The Arduino Integrated Development Environment (IDE) uses syntax that is very similar to C++
* The concepts that will be applicable when coding in the Arduino IDE are:
  * declaring and initializing variables
  * loops
  * arrays
  * strings
  * functions
  * libraries and #include statements
  * #define statements
* This environment allows one to provide logic and functionality to their circuit connected to the Arduino Nano. After writing a program in the IDE, the program can then be compiled and uploaded to the Arduino board from the IDE itself.

### <ins>The Arduino IDE Coding Structure</ins>
* The coding structure for a typical Arduino program:
  * #define <variableName> <pin#>
    * This allows one to refer to the variableName instead of the pin# so that it is easier to read and if the pin# changes, you would only need to change the pin# in the define statement rather than in the entire program.
  * setup()
    * Runs once
    * Define your pins to be an INPUT or OUTPUT pin
    * Set the serial baud rate and allow you to use Serial.print()
  * loop()
    * Runs forever, like a forever for loop
    * Read inputs from pins or output to a pin

### <ins>Typical Arduino Functions</ins>
* digitalWrite(pin #, HIGH/LOW)
  * outputs discrete voltage (HIGH/LOW)
* analogRead(pin #)
  * reads variable voltage (outputs a range from 0-1023)
* delay(milliseconds)
  * pauses for a specified time
* Serial.print(text)
  * prints out text to the serial window
* Serial.println(text)
  * same as above, but adds a new line afterward
* Note: Make sure you call Serial.begin(9600) in setup() or this won’t work!

## Project Specification Part 1 (Building the Schematic on your Breadboard)
There are two parts to the schematic below. On the left side, you can see the potentiometer symbol with the two OUTER terminals connected to GND and 5V(could also use Vin) and the middle terminal connected to an analog input pin (A4). MAKE SURE THE MIDDLE TERMINAL IS NOT CONNECTED TO EITHER 5

On the right side, you can see the LED circuit consisting of an LED and resistor in series (to limit the current going through the LED). The resistor R1 is connected to the digital pin D7 which you will program in the Arduino IDE to output 5V(turn on the LED) or 0V(turn off the LED).
<p align="center">
  <img src="/assets/images/potentiometer-circuit.png" width="600" />
</p>

## Project Specification Part 2 (Writing the Arduino Program)
* Using the coding structure mentioned before and the pseudocode below, program the LED to turn on/off for a certain amount of time based on the value from the potentiometer. Some useful functions include:
  * pinMode(<pinName>, <INPUT/OUTPUT>);
  * Serial.begin(9600);
  * Serial.print(“Some statement to print to the serial monitor on your laptop”);
  * digitalWrite(<pinName>, <HIGH/LOW>);
  * analogRead(<pinName>)
  * delay(<# of milliseconds>)
    * Note: there are 1000 milliseconds in 1 second

<p align="center">
  <img src="/assets/images/potentiometer-code.png" width="600" />
</p>

## Checkoff Questions
Here are some questions you can use to test understanding of the concepts involved in this project:

1. What is the difference between a digital and an analog signal?
  * Digital: either LOW or HIGH (OFF or ON, square wave);
  * Analog: Has a lot of possible values (0-255) making any transition smooth and continuous; emulated by PWM (they must answer this last part too)
2. When do the setup and loop functions run, and what do they do?
  * Setup function runs once when the Arduino turns on, then the loop function runs repeatedly every clock cycle, indefinitely
3. How does a voltage divider work?
  * When two resistors are in series with each other and connected to a voltage source, the voltage across each resistor is split in proportion to their resistance values.
