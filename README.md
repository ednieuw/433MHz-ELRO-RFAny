### ELRO switch AB440R with Arduino


<h1 class="auto-style1">Control ELRO AB440R switches with Arduino&nbsp; </h1>
<p class="auto-style1">
I have these ELRO AB440R switches (now Brennenstuhl Comfort RCS 1000 N)&nbsp; 
for more than 10 years but you need the ELRO AB440SC remote controller to switch 
them On and Off. <br />
In the remote control a 433 MHz transmitter is used to send the commands.<br />
<a href="https://lastminuteengineers.com/433mhz-rf-wireless-arduino-tutorial/">Lastminuteengineers</a> explains how 
this works.<br />
This is a compilation of my research to get the switches working with Arduino's.<br />
</p>
<p class="auto-style1">
<img alt="FS1000-XY-MK-5V" height="418" src="Pics\FS1000-XY-MK-5V.png" width="730" /></p>
<p class="auto-style1">
I used the FS1000 transmitter to send the data to the ELRO switch and XY-MK-5V 
receiver to display the transmitted data on a separate Arduino. They can be 
bought very cheap together</p>
<p class="auto-style1">
For the ELRO switches to be switched On and Off a specific pulse signal 
must be sent preceded with an unique switch number. <br />
In the ELRO remote control five switches can be set. They must be identical with 
the five dip switches in the switches. I had the 5 switches all all turned ON.
<br />
In the switch there are beside the five switches also switches A, B, C, D and E. 
These last five identify the switch.<br />
The signal send to a switch has as preamble the state of the first 5 switches 
switches<br />
For example: mySwitch.switch<strong>On</strong>("11111", "10000"), turns on 
switch A.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
mySwitch.switch<strong>Off</strong>("11111", "10000"), turns on switch A.</p>
<p class="auto-style1">
All kind of Arduino's can be used. The cheap 168P Nano is perfect but the in 
2023 released, ESP32 Nano also works fine. <br />
The transmitter works fine at 5V. For a large transmission range attach a 17.3 
cm (6.8 inch) wire to the transmitter and receiver. It is said a straight, not 
coiled, wire gives the best results.</p>
<p class="auto-style1">
<img alt="All parts" height="675" src="Pics\All-parts-IMG_0915(1).png" width="900" /></p>
<p class="auto-style1">
Make to following connections.</p>
<p class="auto-style1">
On transmitter: Connect GND to GND and VCC to 5V or VIN. Middle pin to D10</p>
<p class="auto-style1">
On receiver:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Connect GND to GND and VCC to 5V or VIN. One of the two middle pins, 
both are identical, to D2.<br />
<br />
Antennas exactly&nbsp; 17.3 cm long, (6.8 inch).</p>
<p class="auto-style1">
Place the switches in the power supply and not in a stack on each other in one power supply 
(-:.<br />
<br />
If you power up the Arduino you can hear and see the switches switching.</p>
<p class="auto-style1">
<table class="auto-style2">
	<tr>
		<td style="width: 218px">
		<img alt="AB440R front" height="900" src="Pics\remote-AB440R.png" width="299" /></td>
		<td style="width: 295px">
		<img alt="AB440R" height="900" src="Pics\remote-AB440R-back.png" width="287" /></td>
		<td style="width: 452px">
		<img alt="switch AB440SC" height="900" src="Pics\Switch-AB440SC.png" width="475" /></td>
	</tr>
	<tr>
		<td style="width: 218px">&nbsp;</td>
		<td style="width: 295px">&nbsp;</td>
		<td style="width: 452px">&nbsp;</td>
	</tr>
</table>
<br />
&nbsp;Arduino code for sending to switches</p>
<pre>/*
  Example for receiving:   https://github.com/sui77/rc-switch/
  If you want to visualize a telegram copy the raw data and paste it into http://test.sui.li/oszi/
*/

#include &lt;RCSwitch.h&gt;

RCSwitch mySwitch = RCSwitch();

void setup() 
{
 delay(250);
Serial.begin(115200);
delay(250);
Serial.println("Send-ELROV03");
Serial.println("Turns at the start OFF Then On and again OFF all four ELRO devices");
Serial.println("First 5 DIP switches ON ON ON ON ON");
Serial.println("The turns ON for 5 seconds and OFF ELRO devices A, B and D in a loop");

  mySwitch.enableTransmit(10);  // Transmitter is connected to Arduino Pin #10  
//   mySwitch.setPulseLength(320);  // Optional set pulse length.
 Serial.println("All Switches OFF");
 mySwitch.switchOff("11111", "10000");
 mySwitch.switchOff("11111", "01000");
 mySwitch.switchOff("11111", "00100");
 mySwitch.switchOff("11111", "00010");
 delay(100); 
  Serial.println("All Switches ON");
 mySwitch.switchOn("11111", "10000");
 mySwitch.switchOn("11111", "01000");
 mySwitch.switchOn("11111", "00100");
 mySwitch.switchOn("11111", "00010");
 delay(100); 
 Serial.println("All Switches OFF");
 mySwitch.switchOff("11111", "10000");
 mySwitch.switchOff("11111", "01000");
 mySwitch.switchOff("11111", "00100");
 mySwitch.switchOff("11111", "00010");
 delay(100); 
 
}

void loop() 
{
int d =5000;
  // Switch on:
  // The first parameter represents the setting of the first 5 DIP switches. 
  // In this example it's ON-ON-OFF-OFF-ON.
  // 
  // The second parameter represents the setting of the last 5 DIP switches. 
  // In this example the last 5 DIP switches are OFF-ON-OFF-ON-OFF.  
  delay(d);
  mySwitch.switchOn("11111", "10000");  Serial.println("Switch A ON");
  delay(d); 
  mySwitch.switchOff("11111","10000");  Serial.println("Switch A OFF");
  delay(d); 
  mySwitch.switchOn("11111", "01000");  Serial.println("Switch B ON");
  delay(d); 
  mySwitch.switchOff("11111","01000");  Serial.println("Switch B OFF");
  delay(d); 
  mySwitch.switchOn("11111", "00010");  Serial.println("Switch D ON");
  delay(d); 
  mySwitch.switchOff("11111","00010");  Serial.println("Switch D OFF");

}</pre>
<pre>static const char* bin2tristate(const char* bin);
static char * dec2binWzerofill(unsigned long Dec, unsigned int bitLength);

void output(unsigned long decimal, unsigned int length, unsigned int delay, unsigned int* raw, unsigned int protocol) {

  const char* b = dec2binWzerofill(decimal, length);
  Serial.print("Decimal: ");
  Serial.print(decimal);
  Serial.print(" (");
  Serial.print( length );
  Serial.print("Bit) Binary: ");
  Serial.print( b );
  Serial.print(" Tri-State: ");
  Serial.print( bin2tristate( b) );
  Serial.print(" PulseLength: ");
  Serial.print(delay);
  Serial.print(" microseconds");
  Serial.print(" Protocol: ");
  Serial.println(protocol);
  
  Serial.print("Raw data: ");
  for (unsigned int i=0; i&lt;= length*2; i++) {
    Serial.print(raw[i]);
    Serial.print(",");
  }
  Serial.println();
  Serial.println();
}

static const char* bin2tristate(const char* bin) {
  static char returnValue[50];
  int pos = 0;
  int pos2 = 0;
  while (bin[pos]!='\0' &amp;&amp; bin[pos+1]!='\0') {
    if (bin[pos]=='0' &amp;&amp; bin[pos+1]=='0') {
      returnValue[pos2] = '0';
    } else if (bin[pos]=='1' &amp;&amp; bin[pos+1]=='1') {
      returnValue[pos2] = '1';
    } else if (bin[pos]=='0' &amp;&amp; bin[pos+1]=='1') {
      returnValue[pos2] = 'F';
    } else {
      return "not applicable";
    }
    pos = pos+2;
    pos2++;
  }
  returnValue[pos2] = '\0';
  return returnValue;
}

static char * dec2binWzerofill(unsigned long Dec, unsigned int bitLength) {
  static char bin[64]; 
  unsigned int i=0;

  while (Dec &gt; 0) {
    bin[32+i++] = ((Dec &amp; 1) &gt; 0) ? '1' : '0';
    Dec = Dec &gt;&gt; 1;
  }

  for (unsigned int j = 0; j&lt; bitLength; j++) {
    if (j &gt;= bitLength - i) {
      bin[j] = bin[ 31 + i - (j - (bitLength - i)) ];
    } else {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';
  
  return bin;
}</pre>
<pre>&nbsp;</pre>
<p class="auto-style1">Arduino code for receiving</p>
<pre>/*
  Example for receiving
  https://github.com/sui77/rc-switch/
  If you want to visualize a telegram copy the raw data and paste it into http://test.sui.li/oszi/
*/

#include &lt;RCSwitch.h&gt;
#define CONCATLINES   // if you do not want to see all identical transimitted lines uncomment this #define
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200); 
Serial.println("ReceiveDemo_Advanced V02");  
Serial.println("Print the received strings on the 433 MHz receiver"); 
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 =&gt; that is pin #2
}

void loop() {
  if (mySwitch.available()) 
  {
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    Serial.print(":");
    mySwitch.resetAvailable();
  }
}</pre>
<p class="auto-style1">&nbsp;</p>
<p class="auto-style1"><a href="433MHz-ELRO.zip">All codes and libraries in a 
Zip</a><br />
<br />
<a href="gebruikershandleidingELRO.pdf">Manual AB440R</a><br />
</p>
<p class="auto-style1">References:</p>
<p class="auto-style1">
<a href="https://www.instructables.com/Using-433MHz-Remote-Controlled-Switches-on-Arduino/">
Using 433MHz Remote Controlled Switches on Arduino : 10 Steps - Instructables</a></p>
<p class="auto-style1">
<a href="https://lastminuteengineers.com/433mhz-rf-wireless-arduino-tutorial/">
Insight Into How 433MHz RF Tx-Rx Modules Work &amp; Interface with Arduino (lastminuteengineers.com)</a></p>
<p class="auto-style1">
&lt;-- <a href="https://ednieuw.home.xs4all.nl/Woordklok/index.html">Home</a>&nbsp; <br />
</p>
<p class="auto-style1">Ed Nieuwenhuys oct 2023</p>





# 433MHz-ELRO-RFAny
Turn On and OFF ELRO 433 MHz power switches
![IMG_0908(1)](https://github.com/user-attachments/assets/63ded69b-1b4d-4139-9313-db73f3cb6cf5)
![IMG_0907(1)](https://github.com/user-attachments/assets/958f9e2c-e265-4f4e-affa-f8b45fe02dc1)
![IMG_0906(1)](https://github.com/user-attachments/assets/593b8663-b4ad-4309-95d6-691f43790f28)
