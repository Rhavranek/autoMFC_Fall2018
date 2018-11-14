#include <Wire.h>

//Global variables

//global variables for internal function timers
unsigned long timer;
unsigned long internalnormalruntimer=0;

int msgholder = 0;  //Brett check why this variable is global
String temp_message = "";
String temp_message_part="";

String CheckValcoValveString = "";
String CheckMFC1String = "";
String CheckMFC2String = ""; 


bool IdleMode = false; //bool variable for setting arduino to idle

void setup() {
  Serial.begin(115200); //Partical board and USB computer
  Serial1.begin(9600);  //Valco
  Serial2.begin(9600);  //MFC1
  Serial3.begin(9600);  //MSF2
  
  while(Serial1.available()) {  //Cleaning out anything that might be sitting around in the serial
  char c = Serial1.read();
  }
  while(Serial2.available()) {
  char c = Serial1.read();
  }
  while(Serial3.available()) {
  char c = Serial1.read();
  }
    
}

//--------------------------------------------------------------------------------------------------------------------
//------------------------------------ Loop --------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
void loop () {
  timer = millis(); // store time since arduino has been turned on, in milliseconds, to the variable timer
  
  if (timer >= 4294955000)  // make sure every 50 days we don't have a time reset that messes with us. 
  {
    delay(13000);
    Serial.println("50 Day delay");
  }
  
  get_data_from_serial();
  
  if(!IdleMode){ // inverse logic for if statement. within this if statement, place all active commands to disable functions w/o turning off arduino
      CheckValcoValve();
      CheckMFC1();
      CheckMFC2();
   }

  Serial.print("ArduinoMainTimer=");Serial.print(timer);Serial.print(",InternalTimerInmsec="); Serial.println( millis()-internalnormalruntimer);
  Serial.println();
 // Wait a second before taking the next set of readings  //my not need
  delay(1000);

}

//--------------------------------------------------------------------------------------------------------------------
//------------------------------------End Loop------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
