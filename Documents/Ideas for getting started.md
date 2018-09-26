# This is where I'll keep my updates and documentation as I start my project

## My initial goals:
1. Identify some ideas for arduino code - I can't be inventing the wheel. What exists?
2. Identify what I already know, and what I want to be inside my code
3. Learn some C basics, so that I can understand existing codes

## 1. Ideas for my Mass Flow controller

Some forums seem to think using a PID loop is ideal,
Here is what a PID is: https://playground.arduino.cc/Code/PIDLibrary
see this basic example: https://playground.arduino.cc/Code/PIDLibaryBasicExample

This also gives examples of code for interfacing with different parts: https://playground.arduino.cc/Main/InterfacingWithHardware#envtop

This is an example of what I would like to do but in a slightly different system:
http://tommccarthyprojects.com/diy-mass-flow-controller-interface/

From Sierra instruments:
https://www.youtube.com/watch?v=ivSDSOQ_iqs

I need to figure how the Arduino and MFC talk to each other – what speed will they talk to each other at?

## 2. Details for the code I’d like to have right now:
(For testing – will want to change the magnitude of some variables for field testing)

Inside the loop:
Turn the input mass flow controller from 0 to 60 sccm.
Hold at 60 sccm for 30 min (30 min * 60 seconds * 1000 ms)
Turn the mass flow controller down to 0 scmm
Hold at 10 minutes (10 min * 60 seconds * 1000 ms)

Because I’m using c, I’ll need to define my variables like:
Double Setpoint, Input, Output

Setpoint = 60 (I’m not sure what my input will need to be – it will either be in sccm units (ideal for me) or it will be in a voltage translation
