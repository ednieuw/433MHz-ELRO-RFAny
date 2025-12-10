/*
  Example for receiving:   https://github.com/sui77/rc-switch/
  If you want to visualize a telegram copy the raw data and paste it into http://test.sui.li/oszi/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() 
{
 delay(250);
Serial.begin(115200);
delay(250);
Serial.println("Send-ELROV03");
Serial.println("Turns at the start OFF Then On and again OFF all four ELRO devices");
Serial.println("First 5 DIP switches ON ON ON ON ON");
Serial.println("Then turns ON for 5 seconds and OFF ELRO devices A, B, C and D in a loop");

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

}
