---
title: "7: Serial Communication"
excerpt: "Implement a 2-Arduino game called Red Light, Green Light!"
toc: true
order: 7
header:
  teaser: /assets/images/RedLightGreenLight.png
---

<p align="center">
  <img width="350" height="350" src="/assets/images/RedLightGreenLight.png">
</p>

## About this Project

In this project, you will be implementing a 2-Arduino game called Red Light, Green Light. In this game you are a carduino playing against a randomly generated stoplight: You must move at a green light, and stop at a red light; should you run over a red signal, or stay put at a green signal, you lose. If you get it right, you’ll gain a point and move to the next intersection.

### [Lecture Slides](https://docs.google.com/presentation/d/1KOP_cQTVDBC-wFoAtvGqAs5BjWDAtQg0LjFRPGkvvV4/edit?usp=share_link)

### <ins>Prerequisites</ins>

- [4: Microcontrollers](/projects/4-microcontrollers)
- [5: Digital, Analog, and PWM](/projects/5-digital-analog-pwm)

### <ins>Skills Learned</ins>

- Pull-up/pull-down resistor
- Serial protocol: UART (Universal Asynchronous Receiver Transmitter)

## Parts List

| Part                      | Quantity | Unit Cost | Example Vendor                                                                                                                                                                |
| ------------------------- | -------- | --------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Arduino Nano              | 1        | $4.00     | [Amazon](https://www.amazon.com/KOOKYE-Arduino-Nano-ATmega328P-Micro-controller/dp/B019SXNBQY/ref=sr_1_8?s=electronics&ie=UTF8&qid=1468042975&sr=1-8&keywords=arduino%20nano) |
| Mini USB Cable            | 1        | $1.80     | [Mouser](https://www.mouser.com/ProductDetail/Qualtek/3021003-03/?qs=sGAEpiMZZMsnDbBzJh6VGJdPZmg6V0p2)                                                                        |
| Breadboard                | 1        | $1.50     | [Amazon](https://www.amazon.com/DEYUE-breadboard-Set-Prototype-Board/dp/B07LFD4LT6/ref=sr_1_3?dchild=1&keywords=breadboard&qid=1588123957&s=electronics&sr=1-3)               |
| Green LED                 | 1        | $0.12     | [Digikey](https://www.digikey.com/product-detail/en/lite-on-inc/LTL-4233/160-1130-ND/217580)                                                                                  |
| Red LED                   | 1        | $0.14     | [DigiKey](https://www.digikey.com/product-detail/en/kingbright/WP7113ID/754-1264-ND/1747663)                                                                                  |
| White LED                 | 1        | $0.17     | [DigiKey](https://www.digikey.com/product-detail/en/cree-inc/C543A-WMN-CCCKK141/C543A-WMN-CCCKK141-ND/9959490)                                                                |
| HC-05 Bluetooth Module    | 1        | $10.39    | [Amazon](https://www.amazon.com/HiLetgo-Bluetooth-Transceiver-Integrated-Communication/dp/B071YJG8DR)                                                                         |
| Push Button               | 1        | $0.23     | [DigiKey](https://www.digikey.com/product-detail/en/schurter-inc/1301.9302/486-3458-ND/7602712)                                                                               |
| 10k Ohm Resistor          | 1        | $0.10     | [DigiKey](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-10K/10KQBK-ND/338)                                                                                      |
| 100 nF (0.1 uf) Capacitor | 1        | $0.49     | [Digikey](https://www.digikey.com/en/products/detail/kemet/C320C104J5R5TA7301/3726105)                                                                                        |
| 200 Ohm Resistor          | 6        | $0.10     | [DigiKey](https://www.digikey.com/product-detail/en/yageo/CFR-25JB-52-200R/200QBK-ND/712)                                                                                     |
| Speaker                   | 1        | $0.90     | [Digikey](https://www.digikey.com/en/products/detail/PSR-29F08S02-JQ/458-1128-ND/2071444)                                                                                     |
| Potentiometer             | 1        | $0.95     | [Adafruit](https://www.adafruit.com/product/1831)                                                                                                                             |

**<ins>Total estimated cost:</ins>** $TODO per team of 2

_<ins>If reusing Arduino/MiniUSB/Breadboard:</ins>_ $TODO per team of 2

## Project Specification

One microcontroller (representing the stoplight) will flash one of the two red/green LEDs and the other microcontroller (representing the Car and its gas/brake pedals) will have two tactile switches (fancy word for buttons). Press the gas at green lights and the brake at red lights in order to score points and move to the next intersection. Get it wrong and you lose!

The goal of this project is to teach you how to use Serial communication and give you your first experience with communication protocols before we move on to more sophisticated and complex protocols.

### <ins>Reference Material</ins>

This lab requires reading documentation and datasheets. Here are some resources that you will reference throughout the project.

1. [Lecture 7 Slides](https://docs.google.com/presentation/d/1LQoQPmcH95rTSIBplJn-w9iuIVvoQFx8bOY2leiMXvk/edit?usp=sharing)
2. [Arduino Nano DataSheet](https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf)
3. [Arduino Nano Pinout](http://ops.ieeebruins.com/images/1/16/NanoPinout.png)
4. [Arduino Serial Library](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
5. [Arduino `random()` Function](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)
6. [Processing Language Reference](https://processing.org/reference)
7. [HC05 Connection Tutorial](https://components101.com/wireless/hc-05-bluetooth-module)

## Checkpoint 1: Getting UART Working

This is a group project! Team up with a partner!

1. **Wire up your MCU to your HC-05 so we can get them talking using the [Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/) library**. To read and write between hardware devices, use the Serial library’s read and write functions. Also, make sure that you are first checking that there is available serial data before reading from Serial. To print text to your Processing screen on your computer use the print or println functions as we have done before. Remember that data transmitted by one MCU is data received by the HC-05. Connect the Tx of one device to the Rx of the other device and vice versa. Make sure you also connect GND pins on both devices to each other so they share a common ground.

   > **NOTE**: DO NOT CONNECT THE TX RX PINS WHEN UPLOADING A SKETCH TO YOUR ARDUINO. Disconnect these pins when uploading code and reconnect them after the code is done uploading.

2. **Write two sketches, one for the Arduino, and one for Processing**:

   2. The Arduino sketch should accomplish the following:

      1. Check for the hardware button press, if it was pressed then set the point value to zero.

         1. This is done so we don’t have to reset the Arduino module if we want to replay (and thus don’t have to reconnect over bluetooth)

      2. Randomly generate a color for the stoplight intersection 2. Can be done using characters such as ‘r’ or ‘g’ to signify ‘red’ and ‘green’ respectively

         3. Can also be done using integers such as ‘1’ or ‘0’.

      3. Light the appropriate LED using the randomly generated item from before

         4. I.E. if the char was ‘r’ light the <span style="text-decoration:underline;">red</span> LED

      4. Read from the Serial buffer if there is data available

         5. Make sure to implement a <span style="text-decoration:underline;">wait to read</span> which can be done with:

            1. While `Serial.available == 0 {}`

               1. Do nothing loop (just waits until there is data)

            2. Some type of software identifier

         6. Use `Serial.read()` to log the data from bluetooth

      5. Identify whether or not the move sent over bluetooth was the correct move. This portion must meet the following requirements:

         7. IF CORRECT:

            3. One point must be added to the scoreboard

            4. A “happy tone” must be played from the buzzer for half a second

               2. Choose some arbitrary high pitch

               3. You’ll likely want to include pitches.h

            5. Have the white LED flash once per the number of points

               4. If 10 points there should be 10 flashes

         8. IF INCORRECT:

            6. Points must go back to 0

            7. The Red LED must turn on for 5 seconds

               5. While it is on a “mad tone” must be played from the buzzer for an equal amount of time

      6. The number of points should be printed back across serial communications to the host device

         9. Use `Serial.println()`

   3. The Processing Sketch should accomplish the following:

      7. Have two digital buttons

         10. One for GO

             8. Must be green

         11. One for STOP

             9. Must be red

         12. Buttons must be functional and send data across bluetooth to HC05 for MCU processing

      8. Display the point count at the bottom of the screen

      9. The majority of this code will be given to you, with comments describing the general UI functionality. It is not a requirement of this game for you to make a beautiful UI, but it is a requirement for it to be functional. Feel free to alter the looks however you like once the functionality is working

## Checkpoint 2: Wiring Up Hardware

**Creating the green and red lights:** You will need to hook up 2 different output LEDs to your Stoplight Arduino. Remember, LEDs can burn out if more than 20mA of current passes through them, and usually you want to limit current to &lt;=5mA to save energy and to prevent the LED from being too bright. Make sure to include a current-limiting resistor in series with your LEDs. The digital pins output ~5V when you write HIGH.

**Points reset:** Your RC-carduino will have 1 push button input that represents the points reset. If the button is pressed the number of points should return to their default state of zero.

NOTE: Button Debouncing.

When you press or release a button, it will “bounce” several times before reaching its final state, which means several button presses will be registered.

<p id="gdcalert1" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image1.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert2">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image1.png "image_tooltip")

One way to avoid this is to put a capacitor in series with the button, so that the button release will not register until after the capacitor is fully discharged over time. If the capacitor’s value has been appropriately chosen, this will be after the button has finished bouncing, such that only one press will be registered. Below is the basic circuit for button debouncing:

<p id="gdcalert2" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image2.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert3">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image2.png "image_tooltip")

Vout is the voltage read by the microcontroller input pin, and Vdd is +5V. Use a 10k resistor and a 100nF capacitor for your debouncing circuit, so that you achieve an RC time constant of 1ms (time constant = resistance \* capacitance).

NOTE: This debouncing circuit also includes a pull-down resistor, so that Vout is HIGH when the button is pressed, and LOW otherwise. Also, the RC constant can be a complicated topic, but for now it is sufficient to understand that it is the product of resistance and capacitance, and corresponds to the amount of time the circuit debounces.

1. Draw the full schematic (on paper). After you get checked off, continue onto..

2. Write a sketch and build the circuit to light up each LED on one Arduino while its corresponding button on the other is pressed down. When a button is released, the LED should turn off.

**Buzzer Scoreboard:** Wire a buzzer to a PWM pin on your MCU. When we add a current limiting resistor in series to this buzzer the sound outputted by the speaker should decrease, as the power delivered to the buzzer decreases. We know buzzers can get annoying at times, so because of this you must implement a series potentiometer into your circuit to variably alter the output volume of your speaker.

<p id="gdcalert3" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image3.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert4">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image3.png "image_tooltip")

### Game Requirements

- Two different colored LEDs (used for stoplight)
- One white LED (used for points identification on RC-carduino side)
- The Stoplights flashes one of the LEDs; the color chosen should be as random as possible (check the reference materials above for more information);
- On Processing IDE (Player Module), the player should press the button that matches the LED the Controller flashed (i.e. Gas for Green Light, Brake for Red Light)
- The Stoplight should wait until a button is pressed in Processing (Player Module). The player must press the correct button.
- If the player presses the correct button, the white LED must blink the number of points allotted and a point must be added to the player’s score. The buzzer scoreboard should play a high pitched tune briefly. A new round must begin.
- Should the player lose (by pressing the incorrect button), the red LED should turn on for 5 seconds, the buzzer scoreboard must play a low tone for the duration of those 5 seconds then start a new game (remember to reset score).
- Processing IDE should print the player’s score at the end of every round (intersection). When the play loses, the serial monitor should show this with the reset score after the game starts again.

### Project Completion

Implement the Red Light, Green Light game, adhering to the above requirements

### Bonus Content

Want to implement your own iteration of this game? Don’t be shy! Use any materials you have at home to add to the game functionality! Or, if you don’t want to alter hardware, don’t be afraid to change up the Processing UI for your RC control interface.

### Helpful Tips

Connecting HC-05 to macOS

1. Turn bluetooth on, then go to bluetooth settings by spotlight searching ‘bluetooth’
2. Once the HC-05 is powered, you should see it on the list of available devices
   1. Common names are ‘HC-05’ & ‘General’

<p id="gdcalert4" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image4.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert5">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image4.png "image_tooltip")

3. Click ‘connect’, then ‘Options’ to enter the passcode, which is 1234 by default. (If 1234 doesn’t work, try 0000)

<p id="gdcalert5" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image5.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert6">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image5.png "image_tooltip")

<p id="gdcalert6" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image6.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert7">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image6.png "image_tooltip")

<p id="gdcalert7" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image7.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert8">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image7.png "image_tooltip")

Now you should be connected to the chip, the red LED on your HC-05 should be blinking. (If not, see [Troubleshooting/HC-05 Not Blinking](https://docs.google.com/document/d/1ncoJFaq7yTiuA7EJlKSRkx3F_6DGJ4xsIjtOcOVwxmE/edit#heading=h.seupp3qyd6v5))

Now we’ll locate where the bluetooth port is (you’ll need it later)

4. Open up Terminal.
5. Type in the command `ls /dev/tty* | grep HC` and press enter to locate your bluetooth port. Note it down for future reference.

If this outputs nothing, check that your HC-05 is powered on and blinking.

Now you’re good to go!

Connecting HC-05 to Windows

1. Navigate to Bluetooth Settings on your PC, go to ‘Add Device’ and add the HC-05 Module
2. If it asks for a password use ‘1234’ as this is the default password for the module
3. After it is connected, open up Device Manager on your PC. You can type in ‘Device Manager’ on the Windows Taskbar Search to find it.
4. Once here, click on Ports and you should see the HC-05 listed as ‘Standard Serial over Bluetooth Link (COMx)’

<p id="gdcalert8" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image8.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert9">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

![alt_text](images/image8.png "image_tooltip")

There may be two ports listed, but only one will work with Processing. We will test later which one, but make note of both of the COM numbers listed. Additionally, if you have anything else connected to your computer, such as your Arduino, you may see it under Ports, this is okay!
