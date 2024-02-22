---
permalink: /led-circuit/
title: "Getting Started: Simple LED Circuit"
excerpt: "Get your hands wet with the LED circuit"
last_modified_at: 2020-06-29T01:52:00-02:40
toc: true
---

<p align="center">
  <img src="/assets/images/led-circuit.png" width="350" />
</p>

## About this Project

For this project you will be tasked with constructing a circuit that delivers power to an LED, making it light up. When you have completed it you must show it to an officer and they will ask you some questions about it.

### [Lecture Slides](https://docs.google.com/presentation/d/1Ffw38JwpkiysFZLtaTBewk9dKj35dEf5Dzmhv943o0c/edit?usp=sharing)

### <ins>Prerequisites</ins>
* N/A

### <ins>Skills Learned</ins>

* Voltage, Current, Resistance in a Circuit
* Using Ohm's Law
* Converting a Schematic to a Circuit
* Using Data Sheets

## Parts List

* Microcontroller Board
* Breadboard
* Jumper Wires
* 9V Battery
* Battery Snap-on Connector
* Resistor (you must calculate the resistance)
* LED

<p align="center">
  <img src="/assets/images/led1.png" width="350" />
</p>

## Project Specification
### Schematic

Use the following schematic for reference when constructing your circuit. Be aware that the orientation of the LED is important when entering it into your circuit on your breadboard. For the LEDs in your kits the cathode(-) should have a shorter lead and flat edge, whereas the anode(+) has a longer lead and rounded base.

<p align="center">
  <img src="/assets/images/led2.png" width="350" />
</p>

### <ins>Checkpoint 1: Choose Your Resistor</ins>

In order to determine the resistance needed for your circuit you must first determine the LED’s **forward voltage** and **forward current**. Please refer to the following datasheets depending on what color LED you use. Please use the value under ‘Typ’ as this is the typical value for the component. You then must apply Ohm’s Law to determine the proper resistance to create the forward voltage.

* White LED: [datasheet](https://cdn-shop.adafruit.com/product-files/754/P754B_datasheet_FD-5TW-1.pdf
)
* Green LED: [datasheet](https://www.mouser.com/datasheet/2/216/WP793GD-52917.pdf
)
* Blue LED: [datasheet](https://www.mouser.com/datasheet/2/216/WP154A4SUREQBFZGC-1173568.pdf
)
* Yellow LED: [datasheet](https://www.arduino.cc/documents/datasheets/LEDY-L-7113YT.pdf
)
* Red LED: [datasheet](http://www.us.kingbright.com/images/catalog/SPEC/WP7113ID.pdf
)

### <ins>Setting up your Power Source</ins>
**NOTE**: <em>Please read through this section and the common mistakes section completely before starting to avoid harming your Arduino.</em>

<p align="center">
  <img src="/assets/images/led3.png" width="350" />
</p>

1. Connect your battery to the snap-on adapter, then plug it into your Arduino. The onboard LEDs should light up to indicate your Arduino is powered. (You can also power your Arduino by connecting it to your PC via USB if your battery dies)
2. When powered, your Arduino has a built-in 3.3V and 5V power source, for this we project we will just use the 3.3V source.
3. Orientate your Arduino so that the power port is the top edge, on the left edge you should see a set of Power pins, connect a wire to the 3.3V pin and a different wire to one of the Ground (GND) pins.
4. Connect the 3.3V wire to one of the holes on your breadboards positive (+) rail. Connect the ground wire to one of the holes on the negative (-) rail.
5. Now you can build your circuit on the breadboard. Treat the positive rail as the positive end of the battery and ground as the negative end of the battery. **Make sure there is always a resistor in your circuit, otherwise your power source will be short circuited causing problems/breaking your Arduino.**

### Helpful Tips/Common Mistakes
* The rows on the breadboard are shorted, don’t connect both leads from a component into the same row.
* Construct your LED circuit before plugging in your battery.
* If your calculated resistance is a value you don’t have it’s safer to round up instead of rounding down.
* If you are unsure about your circuit, ask an officer before plugging it in
* Double check your LED is oriented the correct way.
* Unlike the LED, the resistor doesn’t have a specific orientation.
* Always make sure there is a resistor in your circuit to avoid breaking your Arduino/LED
