void CheckValcoValve(void){
  String msg = String("");  //get
  String temp = String("");
  if(Serial1.available() > 0)
  {
    while(Serial1.available() > 0)
    {
      msg += char(Serial1.read());
      delay(10); 
     }
    Serial.print("FromValco,");
    Serial.println(msg);
    CheckValcoValveString = msg;
  }
}


void turnValveCounterClockwise(int Valveposition)
{
   Serial1.print("CC");
   Serial1.println(Valveposition);//moves the valve down one number
   Serial.print("To valco \"CC\"" );
   Serial.println(Valveposition);
}

void turnValveClockwise(int Valveposition)
{
   Serial1.println("CW");  // moves the valve up one 
   Serial.println("To valco \"CW\"");
}

//ect
