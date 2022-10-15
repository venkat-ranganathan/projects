# Hello 🤖

<p>&nbsp;</p>

## Hi, I'm Venkat and I'm an Electrical Engineering major at Binghamton University graduating in May, 2024. I enjoy hiking, camping, and going on road trips with my dog. 🚶‍♂️🏕️🚙🐕

<p>&nbsp;</p>
---
<p>&nbsp;</p>

### I setup a network-wide adblocker, 10/14/2022:

![IMG_3908 - Copy](https://user-images.githubusercontent.com/96662693/195987388-c60aebf4-d2e1-43dd-9e1b-ccd38cb2e28f.jpg)

I got a Raspberry Pi 4B and used it to set up an ad blocker on my local network. The advantage of this is that it's not device-dependent, meaning I don't need to have an ad blocker setup on individual devices because this Raspberry Pi acts as the primary DNS server for my router (the Raspberry Pi automatically uses Google/Cloudflare {or whatever DNS service you prefer} as the next DNS server after the AdBlock filter list is applied; a DNS server tells your computer where to go when you type in a website like google.com into your web browser). This works for devices that don't have adblockers available, like my Google Speaker which I use to play music for my dog when I go to class. It also doesn't interfere with other ad blockers that are used locally on individual devices.

The idea is as follows: normally you need to set up an ad blocker on each of your individual devices (phone, computer, etc.) to block ads on those devices. By using this Raspberry Pi as my primary DNS server on my router, all data that goes into and out of the router first checks the filter list on my Raspberry Pi for any websites identified as ad networks or tracking links, if the link coming into or out of the router matches one of those links, it tells the router to block the connection. 

Will this slow down my internet connection? No, it won't slow down the internet at all because the filter list is just a text file of website addresses to block, there's no other data or instructions there. The router checks if the website attempting to connect is on the list, if it is, it blocks the connection. That's it.

<img width="960" alt="Screenshot_20221014_105709 - Copy" src="https://user-images.githubusercontent.com/96662693/195965951-204c7d7a-0ee2-46ae-9b3b-4d6c517938f8.png">

Setup was relatively simple:

- There's a Raspberry Pi app that formats and installs the Raspberry Pi OS onto your microSD card
- Then you plug the microSD card into the Raspberry Pi, turn it on and connect it to a monitor, keyboard, and mouse; then connect it to your Wi-Fi/ethernet
- You run: "sudo apt-get update" & "sudo apt-get upgrade -y" to update the OS
- Then install the Pi-hole adblocker using the installer from the Pi-hole website
- In the installer, you choose your static IP address for the Raspberry Pi
- You then set that IP address as your DNS address on your router (I also use a secondary DNS server as a backup on my router, in case the Raspberry Pi ever goes down)
- After that, you can disconnect the monitor, keyboard, and mouse because you can now connect to the Raspberry Pi through SSH since it's on your network
- With SSH I can update the OS & adblocker from my laptop using bash (I use MobaXterm to SSH into my Raspberry Pi)

<img width="960" alt="Screenshot_20221014_105612 - Copy" src="https://user-images.githubusercontent.com/96662693/195965968-0c2da8ca-1fdc-424e-8695-ae25028eaf5f.png">

With the device setup, I can just go to the IP address and and look at the dashboard to see what's being blocked, the uptime/memory usage/temperature of the Raspberry Pi, add adblock filters, adjust settings, etc.

I also drilled some holes on the top of the Raspberry Pi case because it otherwise had no airflow. I installed a small heatsink on the CPU and a fan over it to keep the device cool.

![IMG_3904 - Copy](https://user-images.githubusercontent.com/96662693/195964714-78ff049a-ce09-425e-ab78-3e61d114b47a.jpg)

<p>&nbsp;</p>
---
<p>&nbsp;</p>

### My VSCode setup, 09/04/2022:

This isn't super-important, so I set it off to the side

I figured out how to setup my VSCode debug environment for C using GDB. I'm stoked I can step through my code _and be able to see the values of my variables as the code is being executed, see what's changing in the register, AND see what stacks are being called_. Prior to setting up my debug environment, I was using a standard compile & run combination with a GCC compiler, and I used GDB through a bash terminal to debug my code on the school server. My current setup is _much_ nicer 🙂
<p>&nbsp;</p>
<img width="960" alt="my_vs_code_setup" src="https://user-images.githubusercontent.com/96662693/188341444-268b0cdd-fa57-4db5-b0ee-930dd6af753f.png">
