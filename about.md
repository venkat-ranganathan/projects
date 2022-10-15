# Hello 🤖

<p>&nbsp;</p>

## Hi, I'm Venkat and I'm an Electrical Engineering major at Binghamton University graduating in May, 2024. I enjoy hiking, camping, and going on road trips with my dog. 🚶‍♂️🏕️🚙🐕

<p>&nbsp;</p>
---
<p>&nbsp;</p>

### I set up a network-wide adblocker, 10/14/2022:

I got a Raspberry Pi 4B and used it to setup an adblocker on my network. 

Setup was relatively simple:

- There's a Raspberry Pi app that formats and installs the Raspberry Pi OS on your microSD card
- Then you plug the microSD card into the Raspberry Pi, turn it on and connect it to a monitor, keyboard, and mouse; then connect it to your Wi-Fi/ethernet
- You run: "sudo apt-get update & sudo apt-get upgrade -y" to update the OS
- Then install the Pi-hole adblocker using the installer from the Pi-hole website
- In the installer, you choose your static IP address for the Raspberry Pi
- You then set that IP address as your DNS address on your router (I also use a secondary DNS server as a backup on my router, in case the Raspberry Pi ever goes down)
- After that you can disconnect the monitor, keyboard, and mouse because you can now connect to the Raspberry Pi through SSH since it's on your network
- With SSH I can update the OS & adblocker from my computer using bash (I use MobaXterm to SSH into my Raspberry Pi)

With the device setup, I can just go to the IP address and and look at the dashboard to see what's being blocked, the uptime/memory usage/temperature of the Raspberry Pi, add adblock filters, adjust settings, etc.

<img width="1919" alt="Screenshot_20221014_100538" src="https://user-images.githubusercontent.com/96662693/195964606-0b19cd92-b63c-4598-90b2-200ce7bfb9a6.png">

I also drilled some holes on the top of the case because it otherwise had no airflow. I installed a small heatsink on the CPU and a fan over it to keep the device cool.

![IMG_3904 - Copy](https://user-images.githubusercontent.com/96662693/195964714-78ff049a-ce09-425e-ab78-3e61d114b47a.jpg)


<p>&nbsp;</p>
---
<p>&nbsp;</p>

### My VSCode setup, 09/04/2022:

This isn't super-important, so I set it off to the side

I figured out how to setup my VSCode debug environment for C using GDB. I'm stoked I can step through my code _and be able to see the values of my variables as the code is being executed, see what's changing in the register, AND see what stacks are being called_. Prior to setting up my debug environment, I was using a standard compile & run combination with a GCC compiler, and I used GDB through a bash terminal to debug my code on the school server. My current setup is _much_ nicer 🙂
<p>&nbsp;</p>
<img width="960" alt="my_vs_code_setup" src="https://user-images.githubusercontent.com/96662693/188341444-268b0cdd-fa57-4db5-b0ee-930dd6af753f.png">
