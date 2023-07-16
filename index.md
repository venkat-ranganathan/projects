<a href="https://github.com/venkat-ranganathan/projects" target="_blank">GitHub</a>

<!--- <a href="https://leetcode.com/venka_/" target="_blank">LeetCode</a> --->


# 🤖 🚀 🌎 🇺🇸 {#TOP}

## Here are some projects I've completed as an Electrical Engineering student:

<p>&nbsp;</p>
---
<p>&nbsp;</p>

#### Table of Contents:

- [Metal Detection System using Colpitts Oscillator & FPGA](#MetalDetector)
- [Synthesizing a Guitar Signal w/ MATLAB - Signals & Systems](#Synthesizing)
- [Analog-to-Digital Converter](#Analog-to-Digital-Converter)
- [Minesweeper](#Minesweeper)
- [Pololu 3pi IR reflectance sensor repair](#Pololu-3pi-IR-reflectance-sensor-repair)
- [FPGA Calculator](#FPGA-Calculator)

## Metal Detection System using Colpitts Oscillator & FPGA {#MetalDetector}

Junior Design final project: create metal detection system using off-the-shelf parts. Team consists of two Electrical Engineers (Venkat Ranganathan (myself), Muhaned Abdelmoniem) and three Computer Engineers (Kyle Duran, Christopher Shortt, Arvind Balajee). 

Electrical Engineers: 
System consists of three circuits, each having a Colpitts oscillator, high-pass filter, half-wave rectifier, low-pass filter, and voltage
divider. Each circuit connected to magnetic coil that detects presence of metal using
principles of electromagnetic induction and Lenz’s law. Output signal from each coil fed to
analog-to-digital converters of FPGA board. 

Computer Engineers:
Design implemented using embedded MicroBlaze soft processor on FPGA. Microprocessor system uses GPIO peripherals for inputs/outputs.
Main loop running at 1ms period using alarm timer custom IP enabled controlled timing of
FSMs (finite state machines) and increased accuracy of peak values in Peak Finder IP, since code allows for
multiple periods to run through the IP before clearing its value. Major FSM used in design is 
Metal Detect Debounce. LED strength meter logic implemented into function using bit shifting
to turn on correct amount of LEDs based on how close or far metal is from coil. Register
value comparisons and Seven Segment logic was done in main loop, displayed number
of times metal was detected in each region.

Team result:
System correctly detected 15/15 conductive objects in various combinations of position and distance from magnetic coils during demonstration.





<iframe width="560" height="315" src="https://www.youtube.com/embed/-WaQUf2m0IE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/NohT7cfAe3E" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/sM72W-lKSLk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

[Back to Top](#TOP)

---
<p>&nbsp;</p>

## Synthesizing a Guitar Signal w/ MATLAB {#Synthesizing}

[Back to Top](#TOP)

---
<p>&nbsp;</p>

## Analog-to-Digital Converter {#Analog-to-Digital-Converter}

Used LM741CN op-amps as comparators to convert an analog voltage signal ranging from 0 to 7 volts (including decimal
values in between) into an equivalent digital, discrete signal (positive and negative whole numbers) output through
LEDs. With a 7V reference voltage, the LEDs are connected to the op-amp from top-to-bottom, 7V to 1V (any decimal value
between 0V and less than 1V will not turn on the last LED), the last op amp will use a 1V reference voltage, the second
last, 2V, etc., up to the top-most op amp using a 7V reference voltage--all integer values because we’re converting
real-world, continuous signals into digital, discrete signals that can be read by a digital device, such as an Arduino (
due to time constraints, and because I worked on this project alone, I chose seven LEDs as being representative of a
3-bit
output [000 would be no LEDs on, 001 1 LED, 010 2 LEDs, 011 3 LEDs, 100 4 LEDs, 101 5 LEDs, 110 6 LEDs, 111 7 LEDs]).
Designed and verified circuit in LTSpice, then built physical circuit. Added additional strobe light effect by swapping
DC input voltage with function generator using triangle wave with frequency and phase adjustment (professor helped with
this last part)

In the YouTube videos, I mistakenly said that each op-amp represents a 0.5V drop, instead of a 1V drop. It was finals
time and my brain was fried 🧠⚡

<iframe width="560" height="315" src="https://www.youtube.com/embed/-QS3QFqIXqw" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/ZHAc84ZIXrE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/rmEVREj6PuM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

[Back to Top](#TOP)

---
<p>&nbsp;</p>

## Minesweeper {#Minesweeper}

Programmed Pololu 3pi Robot to navigate a 36x48” black-lined grid and find user defined number of
1x1” white “mines”. Directly programmed hardware. Defined motors as output, light sensors as input,
buttons as input, LCD display as output, and piezo (speaker) as output. Created functions to self-correct
movement to stay on grid by using current state of light sensors and adjusting left/right motor power
using PWM; 360-spin when mine found, play music when mine found, separately handle three/four-way
intersections and corners. Worked with teammate. Used AVR-GCC to compile C code

<iframe width="560" height="315" src="https://www.youtube.com/embed/QYsK_otjukI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/BOo6CoiAndg" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/aQm8Qw_Mvac" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

[Back to Top](#TOP)

---
<p>&nbsp;</p>

## Pololu 3pi IR reflectance sensor repair {#Pololu-3pi-IR-reflectance-sensor-repair}

I broke off one the 3pi's IR reflectance sensors by repeatedly crashing it into a concrete wall (by accident) at high
speeds while learning how to adjust the left/right motor speeds. Since the five IR reflectance sensors are connected in
series, when one doesn't work, all of them stop working.

Since the sensor broke off cleanly, I first tried to match up the orientation of the sensor to the sensor contact points
on the 3pi and super glued it back on, but that didn't work.

I cleaned off as much of the super glue I could using acetone (nail polish remover) and a qtip/tweezer, then I used a
soldering iron with a fine tip, heated up the contact points of the sensor and added a drop of solder to restore the
metal-to-metal contact between the sensor and the board. This got the IR relfectance sensors working normally again

<iframe width="350" height="621" src="https://www.youtube.com/embed/oCuWAioy6bY" title="How I fixed an IR reflectance sensor that I broke" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

[Back to Top](#TOP)

---
<p>&nbsp;</p>

## FPGA Calculator {#FPGA-Calculator}

Used logic gates, adders, and multiplexers to design and implement a calculator that can add, subtract,
multiply, and divide using toggle switches on the BASYS 3 Artix-7 and output results on the seven-segment display.
Programmed in Verilog. Synthesized and implemented in Vivado.

[Back to Top](#TOP)
