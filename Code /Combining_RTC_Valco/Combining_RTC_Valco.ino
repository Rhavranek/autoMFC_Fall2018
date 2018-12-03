/*
 * A lot of this code comes from the RTC example code
 * Some of this code also comes from a code Brett/Sierra wrote to control the valco valve 
 */

#include <SPI.h> //SPI library for RTC
#include <SparkFunDS3234RTC.h> //RTC library 
#define PRINT_USA_DATE //I'm an American chump, and I want my dates to look normal 
#define DS13074_CS_PIN 53 //  RTC Chip-select pin - This is the SS pin on the MEGA, would be pin 10 on an uno 
#define INTERRUPT_PIN 2 //  RTC SQW/interrupt pin (optional)

void setup() {
  Serial.begin(9600); // use serial monitor to view outputs
  Serial1.begin(9600); // Valcovalve baud rate 
  Serial1.println("HM"); // serial1 moves the valco Move actuator to position 1 
  
#ifdef INTERRUPT_PIN //
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
#endif

rtc.begin(DS13074_CS_PIN); // initailizes the library 
rtc.update(); //Update time/date values, so we can set alarms 
rtc.enableAlarmInterrupt(); //configures SQW pin as an interupt 
rtc.setAlarm1(rtc.minute() + 1); //My hope is that this makes alarm 1 go off once a minute, it might go off every second. 
 
}

void loop() {
  rtc.update();  

#ifdef INTERRUPT_PIN
  // Interrupt pin is active-low, if it's low, an alarm is triggered
  if (!digitalRead(INTERRUPT_PIN))
  {
#endif

 if (rtc.alarm1()
  { 
      Serial1.println("CW4"); // moves the actuator in a clockwise motion to position 4 
      Serial.println("The valco should have moved");
  Serial1.println("CW6"); // move the acutuator to position 6 in a clockwise motion 

}
