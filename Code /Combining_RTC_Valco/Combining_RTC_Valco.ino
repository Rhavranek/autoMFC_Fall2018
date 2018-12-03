#include <SPI.h> //SPI library for RTC
#include <SparkFunDS3234RTC.h> //RTC library 
#define PRINT_USA_DATE //I'm an American chump, and I want my dates to look normal 
#define DS13074_CS_PIN 53 //  RTC Chip-select pin - This is the SS pin on the MEGA, would be pin 10 on an uno 
#define INTERRUPT_PIN 2 //  RTC SQW/interrupt pin (optional)

void setup() {
  Serial.begin(9600); // use serial monitor to view outputs
  Serial1.begin(9600); // Valcovalve baud rate 
 
#ifdef INTERRUPT_PIN //
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
#endif

rtc.begin(DS13074_CS_PIN); // initailizes the library 
rtc.update(); //Update time/date values, so we can set alarms 
rtc.enableAlarmInterrupt(); //configures SQW pin as an interupt 
rtc.setAlarm1(00, 5); //This alarm will go off when the seconds are 00 and the minute is 5 
//rtc.setAlarm1(rtc.minute() + 1) 
 
}

void loop() {
  rtc.update();  

#ifdef INTERRUPT_PIN
  // Interrupt pin is active-low, if it's low, an alarm is triggered
  if (!digitalRead(INTERRUPT_PIN))
  {
#endif

 if (rtc.alarm1())
    { 
        Serial1.println("CW4"); // moves the actuator in a clockwise motion to position 4 
        Serial.println("The valco should have moved to 4");
        delay (5000); // delay 5 seconds 
        Serial1.println("CC2"); // move the acutuator to position 6 in a clockwise motion 
        Serial.println("The valco should have moved to 2");
    }
 #ifdef INTERRUPT_PIN
  }
  #endif
}
