[GitHub - Venkat Ranganathan](https://github.com/venkat-ranganathan/projects)

# 🤖 🚀 🌎 🇺🇸

## Here are some projects I've completed as an Electrical Engineering student:

<p>&nbsp;</p>
---
<p>&nbsp;</p>

### Network-wide adblocker, 10/14/2022:

I got a Raspberry Pi 4B and used it to setup an adblocker on my network. 

<img width="960" alt="Screenshot_20221014_105709 - Copy" src="https://user-images.githubusercontent.com/96662693/195965951-204c7d7a-0ee2-46ae-9b3b-4d6c517938f8.png">

Setup was relatively simple:

- There's a Raspberry Pi app that formats and installs the Raspberry Pi OS onto your microSD card
- Then you plug the microSD card into the Raspberry Pi, turn it on and connect it to a monitor, keyboard, and mouse; then connect it to your Wi-Fi/ethernet
- You run: "sudo apt-get update & sudo apt-get upgrade -y" to update the OS
- Then install the Pi-hole adblocker using the installer from the Pi-hole website
- In the installer, you choose your static IP address for the Raspberry Pi
- You then set that IP address as your DNS address on your router (I also use a secondary DNS server as a backup on my router, in case the Raspberry Pi ever goes down)
- After that, you can disconnect the monitor, keyboard, and mouse because you can now connect to the Raspberry Pi through SSH since it's on your network
- With SSH I can update the OS & adblocker from my laptop using bash (I use MobaXterm to SSH into my Raspberry Pi)

<img width="960" alt="Screenshot_20221014_105612 - Copy" src="https://user-images.githubusercontent.com/96662693/195965968-0c2da8ca-1fdc-424e-8695-ae25028eaf5f.png">

With the device setup, I can just go to the IP address and and look at the dashboard to see what's being blocked, the uptime/memory usage/temperature of the Raspberry Pi, add adblock filters, adjust settings, etc.

I also drilled some holes on the top of the Raspberry Pi case because it otherwise had no airflow. I installed a small heatsink on the CPU and a fan over it to keep the device cool.

![IMG_3904 - Copy](https://user-images.githubusercontent.com/96662693/195964714-78ff049a-ce09-425e-ab78-3e61d114b47a.jpg)



## Minesweeper

Programmed Pololu 3pi Robot to navigate a 36x48” black-lined grid and find user defined number of
1x1” white “mines”. Directly programmed hardware. Defined motors as output, light sensors as input,
buttons as input, LCD display as output, and piezo (speaker) as output. Created functions to self-correct
movement to stay on grid by using current state of light sensors and adjusting left/right motor power
using PWM; 360-spin when mine found, play music when mine found, separately handle three/four-way
intersections and corners. Worked with teammate. Used AVR-GCC to compile C code

<iframe width="560" height="315" src="https://www.youtube.com/embed/QYsK_otjukI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/BOo6CoiAndg" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/aQm8Qw_Mvac" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


<p>&nbsp;</p>
---
<p>&nbsp;</p>

## Analog-to-Digital Converter

Used LM741CN op-amps as comparators to convert an analog voltage signal ranging from 0 to 7 volts (including decimal values in between) into an equivalent digital, discrete signal (positive and negative whole numbers) output through LEDs. With a 7V reference voltage, the LEDs are connected to the op-amp from top-to-bottom, 7V to 1V (any decimal value between 0V and less than 1V will not turn on the last LED), the last op amp will use a 1V reference voltage, the second last, 2V, etc., up to the top-most op amp using a 7V reference voltage--all integer values because we’re converting real-world, continuous signals into digital, discrete signals that can be read by a digital device, such as an Arduino (due to time constraints, and because I worked on this project alone, I chose seven LEDs as being representative of a 3-bit output [000 would be no LEDs on, 001 1 LED, 010 2 LEDs, 011 3 LEDs, 100 4 LEDs, 101 5 LEDs, 110 6 LEDs, 111 7 LEDs]). Designed and verified circuit in LTSpice, then built physical circuit. Added additional strobe light effect by swapping DC input voltage with function generator using triangle wave with frequency and phase adjustment (professor helped with this last part)

In the YouTube videos, I mistakenly said that each op-amp represents a 0.5V drop, instead of a 1V drop. It was finals time and my brain was fried 🧠⚡

<iframe width="560" height="315" src="https://www.youtube.com/embed/-QS3QFqIXqw" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/ZHAc84ZIXrE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/rmEVREj6PuM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


<p>&nbsp;</p>
---
<p>&nbsp;</p>

## Pololu 3pi IR reflectance sensor repair

I broke off one the 3pi's IR reflectance sensors by repeatedly crashing it into a concrete wall (by accident) at high speeds while learning how to adjust the left/right motor speeds. Since the five IR reflectance sensors are connected in series, when one doesn't work, all of them stop working.

Since the sensor broke off cleanly, I first tried to match up the orientation of the sensor to the sensor contact points on the 3pi and super glued it back on, but that didn't work.

I cleaned off as much of the super glue I could using acetone (nail polish remover) and a qtip/tweezer, then I used a soldering iron with a fine tip, heated up the contact points of the sensor and added a drop of solder to restore the metal-to-metal contact between the sensor and the board. This got the IR relfectance sensors working normally again

<iframe width="350" height="621" src="https://www.youtube.com/embed/oCuWAioy6bY" title="How I fixed an IR reflectance sensor that I broke" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


<p>&nbsp;</p>
---
<p>&nbsp;</p>

## FPGA Calculator

Used logic gates, adders, and multiplexers to design and implement a calculator that can add, subtract,
multiply, and divide using toggle switches on the BASYS 3 Artix-7 and output results on the seven-segment display. Programmed in Verilog. Synthesized and implemented in Vivado.

