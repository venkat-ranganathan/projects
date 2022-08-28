[Venkat Ranganathan](https://github.com/venkat-ranganathan/projects)

# 🤖 🚀 🌎 🇺🇸

Here are some projects I've completed as an Electrical Engineering student:

## Minesweeper

Programmed Pololu 3pi Robot to navigate a 36x48” black-lined grid and find user defined number of
1x1” white “mines”. Directly programmed hardware. Defined motors as output, light sensors as input,
buttons as input, LCD display as output, and piezo (speaker) as output. Created functions to self-correct
movement to stay on grid by using current state of light sensors and adjusting left/right motor power
using PWM; 360-spin when mine found, play music when mine found, separately handle three/four-way
intersections and corners. Worked with teammate. Used AVR-GCC to compile C code.

<iframe width="560" height="315" src="https://www.youtube.com/embed/QYsK_otjukI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/BOo6CoiAndg" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/aQm8Qw_Mvac" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


## Analog-to-Digital Converter

Used LM741CN op-amps as comparators to convert an analog voltage signal ranging from 0 to 7
volts into an equivalent digital (discrete) signal output through LEDs. Designed and verified circuit in
LTSpice, then built physical circuit. Added additional strobe light effect by swapping DC
input voltage with function generator using triangle wave

<iframe width="560" height="315" src="https://www.youtube.com/embed/-QS3QFqIXqw" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/ZHAc84ZIXrE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/rmEVREj6PuM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


## Pololu 3pi IR reflectance sensor repair

I broke off one the 3pi's IR reflectance sensors by repeatedly crashing it into a concrete wall (by accident) at high speeds while learning how to adjust the left/right motor speeds. Since the five IR reflectance sensors are connected in series, when one doesn't work, all of them stop working.

Since the sensor broke off cleanly, I first tried to match up the orientation of the sensor to the sensor contact points on the 3pi and super glued it back on, but that didn't work.

I cleaned off as much of the super glue I could using acetone (nail polish remover) and a qtip/tweezer, then I used a soldering iron with a fine tip, heated up the contact points of the sensor and added a drop of solder to restore the metal-to-metal contact between the sensor and the board. This got the IR relfectance sensors working normally again

<iframe width="350" height="621" src="https://www.youtube.com/embed/oCuWAioy6bY" title="How I fixed an IR reflectance sensor that I broke" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


## FPGA Calculator

Used logic gates, adders, and multiplexers to design and implement a calculator that can add, subtract,
multiply, and divide using toggle switches on the BASYS 3 Artix-7 and output results on the seven-segment display. Programmed in Verilog. Synthesized and implemented in Vivado.

