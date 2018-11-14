void setup() {
  Serial.begin(9600); //baud rate of the computer 
  Serial1.begin(9600); // baud rate of the valcovalve
  Serial1.println("HM"); //Moves the actuator to position 1. If the actuator is already in position 1, the command is ignored.
  Serial.println("it should have moved home"); 
  delay (6000);
}

void loop() {
  Serial.println("CW4"); //use serial println rather than serial.write because the VV speaks in characters not bits 
  Serial1.println("CW4");
  //to run clockwise 4 is the amount of positions 
  delay(18000); 
  // delay 5 seconds 
  Serial.println("CC2");
  Serial1.println("CC2");
  // to run clounter clockwise 4 positions 
  delay (18000);
  // delay 5 seconds 
  
}

/* 
next steps: 
1. have the valco valve tell me where it is currently 
2. Then rather than have it turn to where it is currently + 1 
  a. That was if I have a power outage it doesn't go home, or restart 
3. Have a secondary code so that in the console I can tell it to move when I want it to. 
4. Mine what is useful from this for for the mass flow controllers 
*/

