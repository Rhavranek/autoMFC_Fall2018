
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////MFC 1//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
void CheckMFC1(void){
  String msg = String("");  //get
  String temp = String("");
  if(Serial2.available() > 0)
  {
    while(Serial2.available() > 0)
    {
      msg += char(Serial2.read());
      delay(10); 
     }
    Serial.print("FromMFC1,");
    Serial.println(msg);
    CheckMFC1String = msg;
  }
}
void MFC1ChangeFlow(double NewFlowRate){
  // Need code to change flow rate
  Serial2.println("hi do stuff for me");
  Serial.println("I told the MFC1 to do stuff");
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////MFC 2//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
void CheckMFC2(void){
  String msg = String("");  //get
  String temp = String("");
  if(Serial3.available() > 0)
  {
    while(Serial3.available() > 0)
    {
      msg += char(Serial3.read());
      delay(10); 
     }
    Serial.print("FromMFC2,");
    Serial.println(msg);
    CheckMFC2String = msg;
  }
}

void MFC2ChangeFlow(double NewFlowRate){
  // Need code to change flow rate
  Serial3.println("hi do stuff for me");
  Serial.println("I told the MFC2 to do stuff");
}
