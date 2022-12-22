# Hello 🤖

<p>&nbsp;</p>
{#TOP}
## Hi, I'm Venkat and I'm an Electrical Engineering major at Binghamton University graduating in May, 2024. I enjoy hiking, camping, and going on road trips with my dog. 🚶‍♂️🏕️🚙🐕 

<p>&nbsp;</p>
---
<p>&nbsp;</p>

#### Table of Contents

- [Cool 3D zero-pole plot I visualized in MATLAB for Signals & Systems, 10/29/2022](#3D_MATLAB)
- [I setup a network-wide Ad Blocker, 10/14/2022](#AdBlocker)
- [My VSCode setup, 09/04/2022](#VSCode)

### Cool 3D zero-pole plot I visualized in MATLAB for Signals & Systems, 10/29/2022: {#3D_MATLAB}

We're currently learning about calculating transfer functions, H(z), from a given (recursive/non-recursive) difference equation, y[n] = x[n], then converting the transfer function into its corresponding frequency response, H(Ω).

From the transfer function, H(z), we're plotting its zero-pole plot on the real/imaginary plane inside a unit circle and determining whether it's stable or not (based on whether the poles are inside the unit circle).

I was able to conceptualize all these steps and calculate them, but I had difficulty visualizing what the frequency response, H(Ω), would look like from the zero-pole plot, so I looked into using MATLAB to plot it...

After reading the MATLAB documentation (and a lot of trial and error) I got a 3D visualization of how the frequency response would look like for a given zero-pole plot!

I'm using MATLAB as a visual aid to help me conceptulaize how to go from a 2D zero-pole plot, to a 3D frequency response-zero-pole plot. My code isn't documented because I made this post shortly after I got it working, and I wanted to share it since it's cool.

Here's the frequency response vs the zero-pole plot I produced from my difference equation:

<img width="407" alt="hw_prob_2_d_2" src="https://user-images.githubusercontent.com/96662693/199073167-3872b687-1a78-4447-b6af-1a9ae311b605.png">

Here's the messy code I used to generate it:

<img width="514" alt="image" src="https://user-images.githubusercontent.com/96662693/199073364-d42eca3e-18d2-461a-996c-46ba66a653de.png">

Here's the more direct zero-pole, frequency response, and phase plots:

<img width="842" alt="hw_prob_2_d_1" src="https://user-images.githubusercontent.com/96662693/199073009-ed0dcbb6-c603-4a2b-b1c0-b8edaff82c3b.png">

and here's the code I used to generate it:

<img width="502" alt="image" src="https://user-images.githubusercontent.com/96662693/199073449-1ca42d6b-ffbe-45f9-94d5-eb1ffc58781d.png">

[Back to Top](#TOP)
<p>&nbsp;</p>
---
<p>&nbsp;</p>

### I setup a network-wide Ad Blocker, 10/14/2022: {#AdBlocker}

![IMG_3908 - Copy](https://user-images.githubusercontent.com/96662693/195987388-c60aebf4-d2e1-43dd-9e1b-ccd38cb2e28f.jpg)

I got a Raspberry Pi 4B and used it to set up an ad blocker on my local network. The advantage of this is that it's not device-dependent, meaning I don't need to have an ad blocker setup on individual devices because this Raspberry Pi acts as the primary DNS server for my router (the Raspberry Pi automatically uses Google/Cloudflare {or whatever DNS service you prefer} as the next DNS server after the AdBlock filter list is applied; a DNS server tells your computer where to go when you type in a website like google.com into your web browser). It also doesn't interfere with other ad blockers that are used locally on individual devices.

The idea is as follows: normally you need to set up an ad blocker on each of your individual devices (phone, computer, etc.) to block ads on those devices. By using this Raspberry Pi as my primary DNS server on my router, all data that goes into and out of the router first checks the filter list on my Raspberry Pi for any websites identified as ad networks or tracking links, if the link coming into or out of the router matches one of those links, it tells the router to block the connection. 

Will this slow down my internet connection? No, it won't slow down the internet at all because the filter list is just a text file of website addresses to block, there's no other data or instructions there. The router checks if the website attempting to connect is on the list, if it is, it blocks the connection. That's it. 

This will speed up loading websites if there are ads or trackers on the website that are on the filter list, because your computer now doesn't need to load those ads or trackers before you can see the website content!

**A network-wide ad blocker isn't perfect**--it doesn't block YouTube or Hulu ads on streaming devices because a filter list doesn't block elements in an application, which is what the ads on YouTube and Hulu are. The ad blocker you install on a web browser _does_ block and hide elements, so that's why you still want to use a local ad blocker on individual devices even if you set up a Raspberry Pi as a network-wide ad blocker.

**Who is this good for?** Everyone, but especially for people who don't know how to install a local ad blocker (like family members). You just set up this little device on their home network and leave it alone. Since you can SSH into the Raspberry Pi when you're on the same local network, you can update it from your computer without needing to connect a monitor, keyboard, and mouse to the Raspberry Pi. 

It won't block _everything_, but it blocks _a lot more_ than nothing, so it's a net-positive result.

<img width="960" alt="Screenshot_20221015_100317 - Copy" src="https://user-images.githubusercontent.com/96662693/195990856-c6d4d4ff-1567-4a70-9002-79926b7808d7.png">

Setup was relatively simple using this guide: https://www.tomshardware.com/how-to/set-up-pi-hole-raspberry-pi

- There's a Raspberry Pi app that formats and installs the Raspberry Pi OS onto your microSD card
- Then you plug the microSD card into the Raspberry Pi, turn it on and connect it to a monitor, keyboard, and mouse; then connect it to your Wi-Fi/ethernet
- You run: "sudo apt-get update" & "sudo apt-get upgrade -y" to update the OS
- Then install the Pi-hole adblocker using the installer from the Pi-hole website
- In the installer, you choose your static IP address for the Raspberry Pi
- You then set that IP address as your DNS address on your router (I also use Google/Cloudflare as a secondary DNS server on my router, in case the Raspberry Pi ever goes down)
- After that, you can disconnect the monitor, keyboard, and mouse because you can now connect to the Raspberry Pi through SSH since it's on your network
- With SSH I can update the OS & ad blocker from my laptop using bash (I use MobaXterm to SSH into my Raspberry Pi)

<img width="960" alt="Screenshot_20221018_115834 - Copy" src="https://user-images.githubusercontent.com/96662693/196483782-83965529-4485-48de-bd28-a8fb9799c667.png">

With the device setup, I can just go to the IP address and and look at the dashboard to see what's being blocked, the uptime/memory usage/temperature of the Raspberry Pi, add adblock filters, adjust settings, etc.

I also drilled some holes on the top of the Raspberry Pi case because it otherwise had no airflow. I installed a small heatsink on the CPU and a fan over it to keep the device cool.

![IMG_3904 - Copy](https://user-images.githubusercontent.com/96662693/195964714-78ff049a-ce09-425e-ab78-3e61d114b47a.jpg)

[Back to Top](#TOP)
<p>&nbsp;</p>
---
<p>&nbsp;</p>

### My VSCode setup, 09/04/2022: {#VSCode}

This isn't super-important, so I set it off to the side

I figured out how to setup my VSCode debug environment for C using GDB. I'm stoked I can step through my code _and be able to see the values of my variables as the code is being executed, see what's changing in the register, AND see what stacks are being called_. Prior to setting up my debug environment, I was using a standard compile & run combination with a GCC compiler, and I used GDB through a bash terminal to debug my code on the school server. My current setup is _much_ nicer 🙂
<p>&nbsp;</p>
<img width="960" alt="my_vs_code_setup" src="https://user-images.githubusercontent.com/96662693/188341444-268b0cdd-fa57-4db5-b0ee-930dd6af753f.png">

[Back to Top](#TOP)
