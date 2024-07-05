Venkat Ranganathan  
&nbsp;  
<a href="https://github.com/venkat-ranganathan/projects" target="_blank">GitHub</a>
&
<a href="https://linkedin.com/in/venkatesh-ranganathan" target="_blank">LinkedIn</a>
<!--- <a href="https://leetcode.com/venka_/" target="_blank">LeetCode</a> --->


# 🤖 🚀 🌎 🇺🇸 {#TOP}

## Here are some projects I've completed as an Electrical Engineering student:

<p>&nbsp;</p>

#### Table of Contents:

- [AI/ML Autonomous RC car operated using NVIDIA Jetson Orin Nano](#nano)
- [Texas Instruments Summer '23 intern, Industrial Networking EtherCAT Project: TI AM62x (microprocessor, RT-Linux), TI AM243x (microcontroller, RTOS)](#EtherCAT)
- [Metal Detection System using Colpitts Oscillator & FPGA](#MetalDetector)
- [Synthesizing a Guitar Signal w/ MATLAB - Signals & Systems](#Synthesizing)
- [Analog-to-Digital Converter](#Analog-to-Digital-Converter)
- [Minesweeper](#Minesweeper)
- [Pololu 3pi IR reflectance sensor repair](#Pololu-3pi-IR-reflectance-sensor-repair)
- [FPGA Calculator](#FPGA-Calculator)

<p>&nbsp;</p>

## AI/ML Autonomous RC car operated using NVIDIA Jetson Orin Nano {#nano}

**05/04/25**, Project Complete

ECD 407 completed our senior design project and accomplished our required and stretch goals of operating a modified RC car autonomously on a track with variable throttle, and the ability to detect and avoid objects.

I'll add more details once the semester ends:

Summary of my contribution:

•	Led team of four to implement object detection and object avoidance on autonomous RC car running Linux on NVIDIA Jetson Orin Nano.

•	Debugged Python errors to get functional RC car. Trained road following and object detection models.

•	Configured steering gain, steering bias, offset, min/max/cruise speed, turn/straight speed variability to maximize performance of car on track. Made local news.

•	Set up PyTorch, Torch2trt, torchvision, JetCam, JetRacer, Jetson-inference. Installed inertial measurement unit driver.

•	Configured Jupyter Lab Server to auto-launch on boot, assign itself IP address, and broadcast on local network.

•	Upgraded stability and speed of model training by installing NVMe drive and setting up 4GB swap partition to expand total available memory to 12GB from 8GB.

•	Evaluated power requirement to select battery pack to power NVIDIA device.

Project experience video for now:
<iframe width="560" height="315" src="https://www.youtube.com/embed/-anzSoZteY4?si=_LfH062httOYH4Ep" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

<p>&nbsp;</p>

Object detection using Jetson-inference with mobilenet-ssdv2 model:
<iframe width="560" height="315" src="https://www.youtube.com/embed/-Uvp3NqYuJg?si=L8dwYpDO8vhwOr6O" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

<p>&nbsp;</p>

**11/17/23**, New video shows car operating on track & ML GUI at the same time

<p>&nbsp;</p>

<iframe width="560" height="315" src="https://www.youtube.com/embed/9RpD5LQKWM8?si=Zm1AnutmOsDabtUR" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<p>&nbsp;</p>

**10/31/23**, Minor update: team improved the model to operate faster and with less wobbliness by increasing min/max speed and reducing steering gain. Changed track to add a chicane (s-shaped turn)

<p>&nbsp;</p>

<iframe width="560" height="315" src="https://youtube.com/embed/mJ2f-fdebcI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<p>&nbsp;</p>

**10/31/23**

<p>&nbsp;</p>

<iframe width="560" height="315" src="https://www.youtube.com/embed/Crt7o4zLEpg" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<p>&nbsp;</p>

Project is in-progress

Senior Design year-long project: Machine learning based autonomous RC car 

Team members (major): myself (EE), Justin Anderson (CoE), Jack Bonfiglio (CoE), Kyle Duran (CoE)

Tools used: Linux, Jupyter Notebook, PyTorch, Torch2RT, OpenCV

Current status: Have car operating autonomously around track. Stays on track, takes basic turns, has variable throttle for straights/turns. Using NVIDIA JetRacer GitHub. Camera connected via CSI to Jetson Nano. Camera is activated from PyTorch, images used to train inference model. LaTrax Rally RC car has IMU (inertial measurement unit) to capture position in space, velocity, & acceleration. RC car components controlled by Jetson Nano via GPIO

Next steps: implement object detection > object avoidance > lane keeping

<p>&nbsp;</p>

[Back to top](#TOP)

<p>&nbsp;</p>

## Texas Instruments Summer '23 intern, Industrial Networking EtherCAT Project: TI AM62x (microprocessor, RT-Linux), TI AM243x (microcontroller, RTOS) {#EtherCAT}

<iframe width="560" height="315" src="https://www.youtube.com/embed/iQLYndh6RPo" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<p>&nbsp;</p>

I spent my Summer as an Applications Engineer intern with Sitara Embedded Linux Applications at Texas Instruments in Dallas, TX.

My intern project demonstrates that a TI AM62x microprocessor running RT-Linux (<a href="https://www.yoctoproject.org/software-overview/" target="_blank">Yocto</a>) on its <a href="https://developer.arm.com/Processors/Cortex-A53" target="_blank"> ARM A53</a> cores can function as an <a href="https://en.wikipedia.org/wiki/EtherCAT" target="_blank">EtherCAT</a> MainDevice to control test LEDs on multiple TI AM243x microcontroller SubDevices running <a href="https://en.wikipedia.org/wiki/Real-time_operating_system" target="_blank">RTOS</a> on its <a href="https://developer.arm.com/Processors/Cortex-R5" target="_blank"> ARM R5F</a> cores simultaneously. In factory automation, the test LEDs can be replaced with motors, servos, robotic arms, etc.

<a href="https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1257180/faq-how-to-set-up-an-ethercat-system-with-am6xx-maindevice-and-am64-am243-subdevice-using-codesys-development-system" target="_blank">I wrote customer-facing Texas Instruments documentation</a> for the end-user to get an EtherCAT TI Main/SubDevice system set up and running and be able to manipulate test LEDs on multiple SubDevices simultaneously connected via standard Ethernet

Speaking broadly, I did the following to get my system up-and-running:

To setup the TI AM62x-EVM MainDevice:

- Loaded Yocto (Arago) RT-Linux onto AM62x-EVM
- Connected to AM62x via UART using screen
- Used Linux command-line tools (screen, dmesg, grep, ifconfig, ip link, ip addr, tcpdump, htop) to set up and debug the network connection to the AM62x from Linux & Windows
-   Connected remotely to AM62x from PowerShell on Windows PC using SSH
- Corporate environment blocked USB storage devices from connecting to corporate computers, to move files over Ethernet:
-   Set IP address of Ethernet port on AM62x to be on same subnet as the Ethernet port connected to Windows PC (ip link, ip addr add/del) (connected to Windows PC so AM62x can be detected by CODESYS software that is only available on Windows)
-   Used scp and set encryption to transfer CODESYS .deb files from computer to the AM62x Linux root directory (files needed to setup AM62x as an EtherCAT MainDevice)
-   Installed files on AM62x using opkg
-   Confirmed CODESYS MainDevice configuration ran on the AM62x

To setup TI AM64x/243x-EVM (GP, General purpose), TI AM243x-LP (HSFS, high-security field-securable), TI AM243x-EVM (HSFS):

- Built EtherCAT demo project using TI Code Composer Studio (IDE to program and debug real-time cores)
-   Modified build configuration
-   Debugged build errors
-   Filed JIRA ticket with debug information, steps to recreate, and solution (if known)
- Manually connected to and loaded application onto AM243x R5F core over JTAG
- Monitored AM243x terminal output over JTAG (XDS110)
- Flashed (via UART) modified configuration to automatically load built application onto AM243x R5F RT core after power cycle
- AM243x boards set to boot OSPI to load flashed instructions

To get system working:
- Built project on CODESYS Devolopment System. Detected SubDevices connected to MainDevice
- Located physical addresses of test LEDs on SubDevices, assigned to variables
- Built GUI to manually change state of LEDs on all boards, on the fly, simultaneously
- Debugged hardware, software issues: detected fault in boards, SDK documentation missing/incorrect, examples not building or running

To edit video:
- Got feedback from colleagues & fellow interns that it was difficult to know where to look
- Added arrow image to show device being changed
- Added zoomed in picture-in-picture to clearly see LED states changing

<p>&nbsp;</p>

[Back to top](#TOP)

<p>&nbsp;</p>

## Metal Detection System using Colpitts Oscillator & FPGA {#MetalDetector}

Junior Design final project: create metal detection system using off-the-shelf parts. Team consists of two Electrical Engineers (Muhaned Abdelmoniem, Venkat Ranganathan (myself)) and three Computer Engineers (Arvind Balajee, Kyle Duran, Christopher Shortt). 

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

<img width="831" alt="full_circuit" src="https://github.com/venkat-ranganathan/projects/assets/96662693/f62e131b-6265-4590-851f-3c9f9b82f0cf">

<img width="778" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/8a678fa8-4948-496b-8a3c-ca73987847bf">

<img width="780" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/f73a167b-4d93-4c2b-a12b-a34e08259ab2">

<img width="782" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/d3ef7f62-bca1-411a-9803-9216000314cd">

<img width="782" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/a414be13-b7d2-4cbb-b815-a8e063639cf4">

<iframe width="560" height="315" src="https://www.youtube.com/embed/-WaQUf2m0IE" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/NohT7cfAe3E" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/sM72W-lKSLk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<p>&nbsp;</p>

[Back to top](#TOP)

<p>&nbsp;</p>

## Synthesizing a Guitar Signal w/ MATLAB {#Synthesizing}

Signals & Systems final project. 

Team members: Venkat Ranganathan (myself) & Benjamin Telfer.

Imported 30 msec guitar note sample into MATLAB and generated synthesized guitar signal that was modified to replicate two additional notes by changing only the fundemental frequency, f0, of the signal.

Original signal extracted, listened to, and visualized using concepts of Fourier Series, its coefficients, and Fourier Transforms. Concept of Discrete Fourier Transform used to generate synthesized guitar signal from manually recorded FS coefficients. Concepts of stopband, transition band, and passband used to create FIR and IIR (recursive) filters to modify the sound profile of the synthesized signals. Transfer Function used to find poles and zeroes of plot, those values used to create peaks or nulls in signal to change its sound.

Result: Original guitar signal sounded best. Synthesized signal impressive given small amount of data points they were generated from. Ability to amplifiy or nullify desired and undeseried aspects of signal, respectively, shows promise for creating copies of original sound while using only a fraction of data.

Formulas set using LaTeX

<p>&nbsp;</p>

<img width="690" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/c0414d56-4c15-4f21-b801-b6ef39d81cb4">
<img width="690" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/958555c5-31d6-4118-9858-51126bf2a718">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/90f6bd52-2481-405f-8422-0494a7b2ca60">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/da7aecc5-c41f-4bdd-9298-03649104809c">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/1b34680d-cfc4-4a48-837e-3529e9ac8886">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/d5529aca-d08f-4f6b-895a-50a930811c3a">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/6dc7b934-ef1c-4fd7-8766-b443166bb0ca">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/e025ae1b-5a58-480f-b5b6-bad648cb62c2">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/56a98d67-a25f-4cd5-89f0-0ce40f5e81a4">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/59d6898a-fe39-4af6-b599-beae4b3330c6">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/29497d95-7402-4cf6-bcd8-aff3eac63440">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/d5732daf-deda-4e37-8e4e-2e19e0b00d39">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/8b0afda4-ce25-4de6-99b9-be333412e2a1">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/b4cf2876-c2bc-45c3-bbf4-0edb048ef269">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/73f4aae5-c85f-4a76-acdd-fd6620a4c7d3">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/daa3acbb-9fb6-4c80-9515-b691decf759f">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/4a187b1f-4d46-48ef-b61d-251d3d48b11d">
<img width="675" alt="image" src="https://github.com/venkat-ranganathan/projects/assets/96662693/6f02e405-d7a2-4e10-a507-91450754b236">

<p>&nbsp;</p>

[Back to top](#TOP)

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

<p>&nbsp;</p>

[Back to top](#TOP)

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

<p>&nbsp;</p>

[Back to top](#TOP)

<p>&nbsp;</p>

## Pololu 3pi IR reflectance sensor repair {#Pololu-3pi-IR-reflectance-sensor-repair}

I broke off one of the 3pi's IR reflectance sensors by repeatedly crashing it into a concrete wall at high
speeds by accident while learning how to adjust the left/right motor speeds. Since the five IR reflectance sensors are connected in
series, when one doesn't work, all of them stop working.

Since the sensor broke off cleanly, I first tried to match up the orientation of the sensor to the sensor contact points
on the 3pi and super glued it back on, but that didn't work.

I cleaned off as much of the super glue I could using acetone (nail polish remover) and a qtip/tweezer, then I used a
soldering iron with a fine tip, heated up the contact points of the sensor and added a drop of solder to restore the
metal-to-metal contact between the sensor and the board. This got the IR relfectance sensors working normally again

<iframe width="350" height="621" src="https://www.youtube.com/embed/oCuWAioy6bY" title="How I fixed an IR reflectance sensor that I broke" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<p>&nbsp;</p>

[Back to top](#TOP)

<p>&nbsp;</p>

## FPGA Calculator {#FPGA-Calculator}

Used logic gates, adders, and multiplexers to design and implement a calculator that can add, subtract,
multiply, and divide using toggle switches on the BASYS 3 Artix-7 and output results on the seven-segment display.
Programmed in Verilog. Synthesized and implemented in Vivado.

<p>&nbsp;</p>

[Back to top](#TOP)
