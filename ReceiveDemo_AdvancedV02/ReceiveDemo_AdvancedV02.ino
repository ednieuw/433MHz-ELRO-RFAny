/*
  Example for receiving
  https://github.com/sui77/rc-switch/
  If you want to visualize a telegram copy the raw data and paste it into http://test.sui.li/oszi/
*/

#include <RCSwitch.h>
#define CONCATLINES   // if you do not want to see all identical transimitted lines uncomment this #define
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200); 
Serial.println("ReceiveDemo_Advanced V02");  
Serial.println("Print the received strings on the 433 MHz receiver"); 
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) 
  {
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    Serial.print(":");
    mySwitch.resetAvailable();
  }
}
