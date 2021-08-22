# Dual-load-clap-switch
This repo contains program code for a clap switch that can control two loads using single and double claps.

The components used include:
Arduino UNO R3
Lm 393 sound detection sensor module
Relays(2)
A 12v power supply circuit
BD 139 switching transistors

When a clap(basically any sound whose intensity crosses the set threshold)  is heard, 
the arduino enters a routine where it waits for a second clap to be picked up.
If no clap is picked up after a short time, it toggles the relay which is connected to the first load through the transistor.
But if a second clap is picked up, it immediately toggles the relay connected to the second load.
