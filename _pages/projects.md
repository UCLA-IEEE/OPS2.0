---
title: "OPS 2.0 Projects"
permalink: /projects/
collection: projects
toc: true
---

## Project 1: [Back to the Basics](/projects/1-back-to-the-basics)

{% assign project_1 = site.projects | where: "name", "1-back-to-the-basics.md" | first %}

| <img src="{{ project_1.header.teaser }}" width="100" /> | {{ project_1.excerpt }} |

## Project 2: [Debugging](/projects/2-debugging)

{% assign project_2 = site.projects | where: "name", "2-debugging.md" | first %}

| <img src="{{project_2.header.teaser}}" width="100" /> | {{project_2.excerpt}} |

## Project 3: [Integrated Circuits](/projects/3-integrated-circuits)

{% assign project_3 = site.projects | where: "name", "3-integrated-circuits.md" | first %}

| <img src="{{project_3.header.teaser}}" width="100" /> | {{project_3.excerpt}} |

## Pilot Program

**Projects 4-7** are ideal for an early-stage OPS program.
{: .notice--info}

### Project 4: [Microcontrollers](/projects/4-microcontrollers)

{% assign project_4 = site.projects | where: "name", "4-microcontrollers.md" | first %}

| <img src="{{project_4.header.teaser}}" width="100" /> | {{project_4.excerpt}} |

### Project 5: [Digital, Analog, and PWM](/projects/5-digital-analog-pwm)

{% assign project_5 = site.projects | where: "name", "5-digital-analog-pwm.md" | first %}

| <img src="{{project_5.header.teaser}}" width="100" /> | {{project_5.excerpt}} |

### Project 6: [Distance Sensor](/projects/6-distance-sensor)

{% assign project_6 = site.projects | where: "name", "6-distance-sensor.md" | first %}

| <img src="{{project_6.header.teaser}}" width="100" /> | {{project_6.excerpt}} |

### Project 7: [Serial Communication](/projects/7-serial-communication)

{% assign project_7 = site.projects | where: "name", "7-serial-communication.md" | first %}

| <img src="{{project_7.header.teaser}}" width="100" /> | {{project_7.excerpt}} |

End of Pilot Program list.
{: .notice--info}

## Project 8: [Communication Protocols](/projects/8-communication-protocols)

{% assign project_8 = site.projects | where: "name", "8-communication-protocols.md" | first %}

| <img src="{{project_8.header.teaser}}" width="100" /> | {{project_8.excerpt}} |

## Project 9: [PID and Motor Control](/projects/9-pid-and-motor-control)

{% assign project_9 = site.projects | where: "name", "9-pid-and-motor-control.md" | first %}

| <img src="{{project_9.header.teaser}}" width="100" /> | {{project_9.excerpt}} |
