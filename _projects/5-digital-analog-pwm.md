---
title: "5: Digital, Analog, and PWM"
excerpt: "Play your favorite tunes with your very own iPoduino!"
toc: true
order: 5
header:
  teaser: /assets/images/iPoduino.png
---

<p align="center">
  <img src="/assets/images/iPoduino.png" width="350" />
</p>

## About this Project

In this project, you will be making an iPod Arduino Music Player. It will contain 3 subsystems: a speaker that plays programmable music of your choice, a potentiometer interface that allows users to select 1 of 3 songs, and a display (which you design!) that indicates which song will play.

### [Lecture Slides](https://docs.google.com/presentation/d/1TzHN9ttHChtWZEGykyobTMMqQm1kncnTiPPNr_60DTw/edit?usp=share_link)

### <ins>Prerequisites</ins>

- [Intro to Arduino: Potentiometer Blink](/potentiometer-blink)

### <ins>Skills Learned</ins>

- Digital/Analog signals
- Pulse Width Modulation (PWM)
- Intermediate Arduino programming
- Using library files

## Parts List

| Part                          | Quantity | Estimated Cost | Example Vendor                                                                                                                                                                |
| ----------------------------- | -------- | -------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Arduino Nano                  | 1        | $4.00          | [Amazon](https://www.amazon.com/KOOKYE-Arduino-Nano-ATmega328P-Micro-controller/dp/B019SXNBQY/ref=sr_1_8?s=electronics&ie=UTF8&qid=1468042975&sr=1-8&keywords=arduino%20nano) |
| Mini USB Cable                | 1        | $1.80          | [Mouser](https://www.mouser.com/ProductDetail/Qualtek/3021003-03/?qs=sGAEpiMZZMsnDbBzJh6VGJdPZmg6V0p2)                                                                        |
| Breadboard                    | 1        | $1.50          | [Amazon](https://www.amazon.com/DEYUE-breadboard-Set-Prototype-Board/dp/B07LFD4LT6/ref=sr_1_3?dchild=1&keywords=breadboard&qid=1588123957&s=electronics&sr=1-3)               |
| Speaker                       | 1        | $0.85          | [Digikey](https://www.digikey.com/product-detail/en/PSR-29F08S02-JQ/458-1128-ND/2071444/?itemSeq=293168811)                                                                   |
| Potentiometer                 | 1        | $1.00          | [Adafruit](https://www.adafruit.com/product/562)                                                                                                                              |
| 82 Ohm Resistor (for Speaker) | 2        | $0.03          | [Digikey](https://www.digikey.com/product-detail/en/stackpole-electronics-inc/CF14JT82R0/CF14JT82R0CT-ND/1830325)                                                             |

In addition to the listed parts, you'll also want to order assorted LEDs and resistors so that members can implement their own display designs.

> <ins>**Note:**</ins> The listed speakers do <ins>NOT</ins> come pre-soldered. You will need access to a soldering station to solder the two leads yourself.

**<ins>Total estimated cost:</ins>** $9.21 per member + assorted parts for display
_<ins>If reusing Arduino/MiniUSB/Breadboard:</ins>_ $1.91 per member + assorted parts for display

## Project Specification

In order build our own iPoduino and program a song of our choice on it, we will develop it subsystem by subsystem. But first, we will build a quick demo to demonstrate the magic of PWM!

### <ins>Checkpoint 1: Manually Create PWM</ins>

Before we start creating our iPod, let’s test your understanding of PWM.

**A quick recap:** our Arduino Nano is not capable of producing true analog signals. Rather, it is only capable of producing digital outputs (either HIGH or LOW, nothing in between). However, by rapidly alternating between HIGH and LOW for a particular proportion of time (duty cycle), we can simulate an analog voltage!

<p align="center">
  <img src="/assets/images/ipoduino-1.png" width="500" />
</p>

As seen in the above figure, a duty cycle of 50% means that the signal is HIGH half the time and LOW half the time. This equations to an analog voltage value that is 50% of HIGH. By varying the duty cycle, we can also vary the resulting analog output. This is in fact what happens every time we call the `analogWrite(int x)` function: the integer parameter `x` gets mapped to a duty cycle!

**Now onto the assignment:**
You will need to control the brightness of an LED by generating a 1 kHz PWM square wave (_1 kHz corresponds to one wave every 1000 microseconds_). Think about what parameters you can change that will correspond to a change in the LED’s brightness.

You’ll be restricted to using only two functions in your loop():

- digitalWrite(pin#)
- delayMicroseconds(#us)

**<ins>To get checked off:</ins>** create 3 different Arduino sketches, with each one clearly corresponding to a different brightness level.

### <ins>Checkpoint 2: Sound Check</ins>

It's time to build our iPoduino! The schematic is shown below for convenience. Note that the display interface that tells the user which song will play is not shown (since you'll design it yourself!).

<p align="center">
  <img src="/assets/images/ipoduino-2.png" width="700" />
</p>

For the first part of the project, you will be programming your own song to play through a speaker. To do this, there are a few helpful Arduino functions:

- **tone(pin, frequency):** generates a 50% duty cycle PWM square wave at specified frequency.
- **noTone(pin):** stops PWM wave generated by tone()

However, we’ve simplified the use of the two functions above for you by writing the following helper function, play():

<p align="center">
  <img src="/assets/images/ipoduino-3.png" width="500" />
</p>

Copy this code into the top of your program, putting your speaker output pin in the indicated field. This function takes a note frequency and its duration as input, and sends a PWM signal to the output pin aliased as SPEAKER.

Please also download one of the following files and place it in the same folder as your Arduino iPod sketch:

- <a href="/assets/code/pitches.h" download>pitches.h</a> - includes all notes
- <a href="/assets/code/basicpitches.h" download>basicpitches.h</a> - includes only one octave for simplicity’s sake

In your main Arduino iPod sketch, write `#include “pitches.h”` at the top of your program. These files include note frequencies (in Hz) represented by their common note name (e.g. 262Hz can now be called as NOTE_C4, with 4 indicating the octave number).

Now, you will be able to play notes in the following format:

- `play(NOTE_C4, 4)` —> play middle C for 4 note durations
- an n-beat rest can be programmed using `delay(NOTE_DUR*n)`
- By making repeated calls to play(), we can play songs through our speaker!

**<ins>To get checked off:</ins>** write a song (minimum 10 notes) and play it through your speaker. The song should play on start-up and when the reset button in the center of the Arduino is pressed. We encourage you to get creative and show us something cool! E-mail us at outreach@ieeebruins.com! :)

For some inspiration: <a href="/assets/code/Despacito.h" download>Despacito.h</a>. Copy and paste into your code and call Despacito() to see it go!

### <ins>Checkpoint 3: Interface</ins>

For the next portion of the project, you will be implementing a potentiometer interface. Depending on what voltage is read from the potentiometer when the reset button is pressed, you will need to be able to switch between at least 3 songs. This means you’ll have to program more songs! Pseudocode for this portion is pictured below:

<p align="center">
  <img src="/assets/images/ipoduino-4.png" width="500" />
</p>

It might be helpful to create a separate function for each programmed song, to make your code more organized. Additionally, think about this: if a song is only being played when the reset button is pressed, where in our Arduino code should the songs be played?

**<ins>To get checked off:</ins>** be able to play 3 different songs by turning the Potentiometer dial and pressing the reset button.

### <ins>Checkpoint 4: Display</ins>

Alright, at this point you've accomplished quite a bit! You've programmed at least 3 songs, and can switch between them by turning your potentiometer dial and pressing the on-board reset button. However, which potentiometer settings correspond to which songs is a bit of a guessing game, since we don't have real-time feedback until the button is already pressed.

Much like a real iPod has a visual display indicating which song we are selecting, we'll add a display to our iPoduino! Once your iPoduino is done playing music, it should indicate which song will play next when the reset button is pressed again. When your iPoduino _is_ playing music, it need not display anything. It’s up to you to implement this, as there are multiple ways of going about this. For example, we could represent different songs with different colors, different brightnesses, etc.

**<ins>To get checked off and complete your iPoduino:</ins>** demo your fully functional Arduino iPod with the display system you designed.

### Further Understanding

Think about each of our 3 subsystems: sound, interface, and display. Which of these utilizes Analog/Digital inputs and outputs? Which of these utilizes PWM signals?

## Member Examples

Some past OPS members have made some pretty dope iPoduinos! Turns out there are a ton of music nerds in engineering. Check out some standout projects below:

<p align="center">
  <iframe width="560" height="315" src="https://www.youtube.com/embed/jFWt276UH0s" frameborder="0" allow="accelerometer; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
  <br/>
  <iframe width="560" height="315" src="https://www.youtube.com/embed/GxeAPmE0bw4" frameborder="0" allow="accelerometer; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</p>

Send us yours for a chance to be featured too :-)

## Checkoff Questions

Here are some questions you can use to test understanding of the concepts involved in Checkpoint \#1 (manually creating PWM):

1. How did you ensure that your PWM signal has a frequency of 1 KHz?

- 1 KHz corresponds to a period of 1000 microseconds, so the amount of time that the LED is on AND off should add up to 1000 microseconds.

2. Why does our frequency need to be so high? Why can’t we just use the regular delay() function instead of delayMicroseconds()?

- The frequency needs to be high enough so that our eyes can perceive the blinking as a brightness. If we used delay() instead, we would get different blinking rates but not different brightnesses.
