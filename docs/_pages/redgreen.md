---
title: "Redlight Greenlight Project"
permalink: /redlight-greenlight/
---

<p align="center">
  <img width="350" height="350" src="../assets/images/RedLightGreenLight.png">
</p>

### [Lecture Slides](https://docs.google.com/presentation/d/1LQoQPmcH95rTSIBplJn-w9iuIVvoQFx8bOY2leiMXvk/edit?usp=sharing)

### **Prerequisites**
* Intro to Arduino

### **Skills Learned**
* Pull up/ pull down resistor
* Serial protocol: UART (Universal Asynchronouse Receiver Transmitter)

### **Parts List**

## **Project Specification**
In this lab, you will be implementing a 2-Arduino game called Red Light, Green Light. In this game you are a carduino playing against stoplights: You must move at a green light, and stop at a red light; should you run over a red signal, or stay put at a green signal, you lose. If you get it right, you’ll gain a point and move to the next intersection.

One microcontroller will flash one of the two color LEDs and the other microcontroller will have two tactile switches (fancy word for buttons) that each correspond to one LED.

The goal of this project is to teach you how to use Serial communication and give you your first experience with communication protocols before we move on to more sophisticated and complex protocols.

### **Reference Material**
This lab requires reading documentation and datasheets. Here are some resources that you will need to look at throughout the project.

1. [Lecture 7 Slides](https://docs.google.com/presentation/d/1LQoQPmcH95rTSIBplJn-w9iuIVvoQFx8bOY2leiMXvk/edit?usp=sharing)
2. [Arduino Nano DataSheet](https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf)
3. [Arduino Nano Pinout](http://ops.ieeebruins.com/images/1/16/NanoPinout.png)
4. [Arduino Serial Library](https://www.arduino.cc/reference/en/language/functions/communication/serial/)


### **Parts Required**

| Part                                  | Quantity | Unit Cost | Example Vendor |
| ------------------------------------- | -------- | -------------- | --------------
| Arduino Nano | 2 | $4.00 | [Amazon](https://www.amazon.com/KOOKYE-Arduino-Nano-ATmega328P-Micro-controller/dp/B019SXNBQY/ref=sr_1_8?s=electronics&ie=UTF8&qid=1468042975&sr=1-8&keywords=arduino%20nano) |
| Mini USB Cable | 1 | $1.80 | [Mouser](https://www.mouser.com/ProductDetail/Qualtek/3021003-03/?qs=sGAEpiMZZMsnDbBzJh6VGJdPZmg6V0p2) |
| Breadboard | 2 | $1.50 | [Amazon](https://www.amazon.com/DEYUE-breadboard-Set-Prototype-Board/dp/B07LFD4LT6/ref=sr_1_3?dchild=1&keywords=breadboard&qid=1588123957&s=electronics&sr=1-3) |
| Green LED | 1 | $0.12 | [Digikey](https://www.digikey.com/product-detail/en/lite-on-inc/LTL-4233/160-1130-ND/217580) |
| Red LED | 1 | $0.14 | [DigiKey](https://www.digikey.com/product-detail/en/kingbright/WP7113ID/754-1264-ND/1747663) |
| White LED | 1  | $0.17 | [DigiKey](https://www.digikey.com/product-detail/en/cree-inc/C543A-WMN-CCCKK141/C543A-WMN-CCCKK141-ND/9959490) |
| 200Ohm Resistor | 3 | $0.10 | [DigiKey](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-200R/200QBK-ND/712) |
| Push Button | 2 | $0.23 | [DigiKey](https://www.digikey.com/product-detail/en/schurter-inc/1301.9302/486-3458-ND/7602712) |
| 10kOhm Resistor | 2 | $0.10 | [DigiKey](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-10K/10KQBK-ND/338) |
| 100nF(0.1uf) Capacitor | 2 | $0.45 | [DigiKey](https://www.digikey.com/product-detail/en/kemet/C320C104J5R5TA7301/399-9867-1-ND/3726105) |

## **Checkpoint 1: Getting your MCUs(Arduinos) talking to each other via UART**

1. **Wire up your MCUs so that we can get them talking using the [Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/) library**. To read and write between hardware devices, use the Serial library’s read and write functions. Also, make sure that you are first checking that there is available serial data before reading from Serial. To print text to the screen of your computer use the print or println functions as we have done before. Remember that data transmitted by one MCU is data received by the other. Connect the Tx of one device to the Rx of the other device and vice versa. Make sure you also connect GND pins on both devices to each other so they share a common ground.

    > **NOTE**: DO NOT CONNECT THE TX RX PINS WHEN UPLOADING A SKETCH TO YOUR ARDUINO. Disconnect these pins when uploading code and reconnect them after the code is done uploading.
    
2. **Write two sketches, one for each Arduino.** One sketch(transmitter) should send two different characters continuously in a loop with a small delay between sending each character. The other sketch(receiving) should turn on the onboard led (pin 13) when one of the characters is received and turn off the onboard led when the other character is received. Make sure to set the same baud rate for both sketches. Use 2 computers to observe the data going over more easily.

## **Checkpoint 2: Wiring Up the rest of the Hardware**

**Arduino Device 1: Creating the green and red lights:**
You will need to hook up 2 different output LEDs (choose between red, yellow and/or green)** to your Stoplight Arduino. Remember, LEDs can burn out if more than 20mA of current passes through them, and usually you want to limit current to <=5mA to save energy and to prevent the LED from being too bright. Make sure to include a current-limiting resistor in series with your LEDs. The digital pins output ~5V when you write HIGH.

**Arduino Device 2: Pressing on the gas or break using buttons**
Your Carduino will have 2 push button inputs, one representing the gas pedal and one representing your brake. If the Green Light is flashed, you’ll press on the gas button. When the Red Light is flashed, you’ll press on the brake. Grab these buttons from the OPS parts drawers. Use this pinout to help you in selecting pins for your Arduino.

> **NOTE: Button Debouncing**
When you press or release a button, it will “bounce” several times before reaching its final state, which means several button presses will be registered. One way to avoid this is to put a capacitor in series with the button, so that the button release will not register until after the capacitor is fully discharged over time. If the capacitor’s value has been appropriately chosen, this will be after the button has finished bouncing, such that only one press will be registered. Below is the basic circuit for button debouncing:

<p align="center">
<img width="350" height="350" src="../assets/images/button_config.png">
</p>

Vout is the voltage read by the microcontroller input pin, and Vdd is +5V. Use a 10k resistor and a 100nF capacitor for your debouncing circuit, so that you achieve an RC time constant of 1ms (time constant = resistance * capacitance).

> **NOTE:** This debouncing circuit also includes a pull-down resistor, so that Vout is HIGH when the button is pressed, and LOW otherwise. Also, the RC constant can be a complicated topic, but for now it is sufficient to understand that it is the product of resistance and capacitance, and corresponds to the amount of time the circuit debounces.

1. Draw the full schematic (on paper). After you get checked off, continue onto..
2. Write a sketch and build the circuit to light up each LED on one Arduino while its corresponding button on the other is pressed down. When a button is released, the LED should turn off.

## **Checkpoint 3: Implementing the game Redlight, Greenlight**

The final objective of this lab is to write a complete implementation of the Red Light Green Light game. The expectations for this game are as follows:

### Game Requirements
- Two differently colored LEDs (Stoplight side; the game controller)
- One white LED (Carduino side; the player)
- The Stoplights (Game Controller) flashes one of the LEDs; the color chosen should be as random as possible (check the Appendix for help on this);
- On the Carduino (Player Module), the player should press the button that matches the LED the Controller flashed (i.e. Gas for Green Light, Brake for Red Light)
- The Stoplight (Game Controller) should wait until a button is pressed on the Carduino (Player Module). The player must press the correct button.
- If the player presses the correct button, the white LED must blink and a point must be added to the player’s score. A new round must begin.
- Should the player lose (by pressing the incorrect button), the white LED on the Car (Player Module) should turn on for 5 seconds, then start a new game (remember to reset score).
- The serial monitor should print the player’s score at the end of every round (intersection). When the play loses, the serial monitor should show this with the reset score after the game starts again.

> **NOTE:** In checkpoint 2, you might have just checked if the input button pin was HIGH to test if it was pressed. However, if you happen to press down on a button and release it right away, your Arduino will register multiple button presses since the loop() function runs multiple iterations while you are pressing down on the button, no matter how quickly you release the button. A solution to this could be to keep track of the previous and current state of the button and only want to register a button press  when it goes from LOW to HIGH, rather than just checking if the pin is HIGH.

**Project Completion:** Implement the Red Light, Green Light game, adhering to the above requirements.

## **Bonus Pizzaz**
This part of the project, while strongly encouraged, is *optional*. If you have more pressing work to complete, you’re done! Feel free to skip this part.

This is your chance to show us your game design skills by implementing whatever game elements you’d like in order to improve the Red Light, Green Light game. Here are a few ideas for features that can be implemented:
- 4 second time limit to successfully press the correct button
- Scaling difficulty by gradually decreasing the time limit after successfully completing a round
- Play a short jingle through your speaker upon success/failure of a round
- Implement turn signals and a potentiometer steering wheel. Ex: if a right turn signal is displayed, turn your potentiometer steering wheel all the way to the right, and press gas.
- Be creative!

## **Appendix: Troubleshooting/Helpful Tips**

### **Generating a random number**
In setup(): randomSeed(analogRead(0));
To get a random number: randNum = random(300); // random number from 0 to 299

This will allow you to get a truly random number sequence because we are randomizing the seed of the random number generator. The seed being used is the reading of an analog pin that is not currently being used, which is essentially just constantly fluctuating noise.

### **Timing**
millis(): returns the number of milliseconds that passed since program started

### **Help! My button is registering multiple button presses.**
It is important to note that if you hold down the button for too long (i.e. for multiple iterations of the loop() code), then it will read HIGH for every iteration of the loop. Thus, when checking if a button has been pressed, it is not ideal to simply check of the pin is HIGH; you should only register a button press if the pin has changed from previously being LOW to now being HIGH. Try implementing software debouncing!

### **How do I begin the implementing the Red Light, Green Light game?**
Don’t jump right into programming the game. Rather, think about the general structure of the game first and write some pseudocode to nail down the logical flow of the program. Then, begin implementing sections of the program in discrete blocks based on your pseudocode.

## Check off Questions

1. What are some advantages of parallel over serial, and why do we use serial?
- Parallel can send more data at a time than serial
- Parallel takes up more space and is more complex with more wires added so we opt to use high speed serial.
2. What is baud rate? What does Serial.begin(9600) mean?
- Rate at which information is transferred in a communication channel. It means a serial port is capable of sending a max of 9600 bits per second.
3. What will happen if the baud rate is not the same for both Arduinos?
- You might read gibberish values.
4. Why is a pull-down resistor needed?
- This ensures that when the button is not pressed, that a specific state is read by the MCU
5. Why do we use a debouncing circuit?
- To make sure multiple button presses are not registered; to make sure the button is correctly registered as pressed when you press it
6. What voltage would a pull up resistor be connected to and what is the other end of the resistor connected to.
- 5V and MCU pin
7. What is the voltage the pull down resistor is connected to and what is the other end of the resistor connected to.
- GND and MCU pin
8. Why does the MCU pin still read V even if there is a resistor?
- The resistor value is so small compared to the input impedance of the Nano so there would essentially be no voltage drop.
9. Why can’t we just connect 5V directly to the MCU and the button connected to the MCU and GND?
- You will short 5V and GND if you press the button :(
10. For a time constant of 1 ms, we had you use a 10k ohm resistor and a 100 nF capacitor. Why can’t we just use a 1 ohm resistor and a 1 mF capacitor instead if RC is the same?
- Using Ohm’s law, if we are supplying a fixed voltage Vin  and lower the resistance from 10k ohms to 1 ohm, we are pulling a ton more current from the Arduino, far more than the 40 mA limit. The Arduino will fry.


