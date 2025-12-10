### ELRO switch AB440R with Arduino

# Control ELRO AB440R switches with Arduino

I have these ELRO AB440R switches (now Brennenstuhl Comfort RCS 1000 N)\
for more than 10 years but you need the ELRO AB440SC remote controller
to switch them On and Off.\
In the remote control a 433 MHz transmitter is used to send the
commands.\
[Lastminuteengineers](https://lastminuteengineers.com/433mhz-rf-wireless-arduino-tutorial/)
explains how this works.\
This is a compilation of my research to get the switches working with
Arduino's.

![FS1000-XY-MK-5V](Pics/FS1000-XY-MK-5V.png)

I used the FS1000 transmitter to send the data to the ELRO switch and
XY-MK-5V receiver to display the transmitted data on a separate Arduino.
They can be bought very cheap together

For the ELRO switches to be switched On and Off a specific pulse signal
must be sent preceded with an unique switch number.\
In the ELRO remote control five switches can be set. They must be
identical with the five dip switches in the switches. I had the 5
switches all all turned ON.\
In the switch there are beside the five switches also switches A, B, C,
D and E. These last five identify the switch.\
The signal send to a switch has as preamble the state of the first 5
switches\
switches\
For example: mySwitch.switch**On**("11111", "10000"), turns on switch
A.\
mySwitch.switch**Off**("11111", "10000"), turns on switch A.

All kind of Arduino's can be used. The cheap 168P Nano is perfect but
the in 2023 released, ESP32 Nano also works fine.\
The transmitter works fine at 5V. For a large transmission range attach
a 17.3 cm (6.8 inch) wire to the transmitter and receiver. It is said a
straight, not coiled, wire gives the best results.

![All parts](Pics/All-parts-IMG_0915(1).png)

Make to following connections.

On transmitter: Connect GND to GND and VCC to 5V or VIN. Middle pin to
D10

On receiver: Connect GND to GND and VCC to 5V or VIN. One of the two
middle pins, both are identical, to D2.

Antennas exactly 17.3 cm long, (6.8 inch).

Place the switches in the power supply and not in a stack on each other
in one power supply (-:.

If you power up the Arduino you can hear and see the switches switching.

  -------------------------------- ---------------------------------------- -----------------------------------
  ![AB440R                         ![AB440R](Pics/remote-AB440R-back.png)   ![switch
  front](Pics/remote-AB440R.png)                                            AB440SC](Pics/Switch-AB440SC.png)

  -------------------------------- ---------------------------------------- -----------------------------------

Arduino code for sending to switches

    <code omitted for brevity>

Arduino code for receiving

    <code omitted for brevity>

[All codes and libraries in a Zip](433MHz-ELRO.zip)

[Manual AB440R](gebruikershandleidingELRO.pdf)

References:

[Using 433MHz Remote Controlled Switches on Arduino : 10 Steps -
Instructables](https://www.instructables.com/Using-433MHz-Remote-Controlled-Switches-on-Arduino/)

[Insight Into How 433MHz RF Tx-Rx Modules Work & Interface with
Arduino](https://lastminuteengineers.com/433mhz-rf-wireless-arduino-tutorial/)

\<-- [Home](https://ednieuw.home.xs4all.nl/Woordklok/index.html)

Ed Nieuwenhuys oct 2023
