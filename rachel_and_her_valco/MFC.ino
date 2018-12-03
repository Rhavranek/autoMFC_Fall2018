////////////////////////////////////// Calc CRC Function  /////////////////////////////////////////////////////////
int CalcCRC (byte cmnd[]) {
int crc = 0xffff; //initialize crc to hex value of 0 //I think I can use int, but a good place to fix this code would be to change this to long int
int i;
int j; //indexes for the loops

// This loops through and converts the first bit, i, and the second bit, j, to hex
for (i= 0;i < sizeof(cmnd); i++) {
  crc = crc ^(int(cmnd[i])*0x0100);
  /* the ASCII value is times by 0x0100 first then XORED to the current crc value
  - XORED is check if its exactly the same in the same order*/

  for(j=0; j<=8;j++){
    if((crc&0x8000)==0x8000){
              crc=((crc<<1)^0x1021)&0xffff;
              }
          else{
              crc=(crc<<1)&0xffff;
              }
  } //end of j loop
} // end of i loop

if ((crc & 0xff00) == 0x0d00)
      crc += 0x0100;
    if ((crc & 0x00ff) == 0x000d)
      crc += 0x0001;
    if ((crc & 0xff00) == 0x0000)
      crc += 0x0100;
    if ((crc & 0x00ff) == 0x0000)
      crc += 0x0001;
    return crc;
/* These are byte values so the high byte and the low byte of the crc must be
checked and incremented if the bytes are either 0x00 0r 0x0d
*/
} // end of void loop


///////////////////////////// Create MFC message  ///////////////////////////////////////
String AddCRC ( ){
  //String cmnd = "!Setr10.00"; 
  // bring in a the stringe command "Sinv2.000"
  //String cmnd = "";
  byte b_cmnd [20]; // initialiaze b_cmnd with plenty of room
  cmnd.getBytes(b_cmnd, 20) ; // convert to a byte array

  // calculate crc
  int crc = CalcCRC(b_cmnd);
  byte b_crc; // create a byte array to put the CRC into
  b_crc = (byte)crc; // convert it to a byte array

/*Seb's code:
    b_cmd[cmd_i] = b_crc[0]; cmd_i++; // the last bit of cmd should be the highbyte of the crc, then move on
    b_cmd[cmd_i] = b_crc[1]; cmd_i++; // the last bit of cmd should be the lowbyte of the crc,then move on
    b_cmd[cmd_i] = 0x0d; cmd_i++; // the last bit of cmd should be a return, then move on

my shot at the same chunk: */
  memcpy(b_cmnd, b_crc, sizeof(b_cmnd)); //add crc to command byte array
  memcpy(b_cmnd, 0x0d, sizeof(b_cmnd)); // add return

  /* Seb's code
      // loop through to print all
      Console.WriteLine(cmd);
      for (int i = 0; i < cmd_i; i++) {
        Console.Write("0x{0:x2} = ", b_cmd[i]);
        Console.WriteLine((char) b_cmd[i]);
        // Serial1.print(b_cmd[i]);
        */
char msg = (char(b_cmnd));
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////MFC 1//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
/*
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
*/

void MFC1setpoint (void){
  String msg = String("");  //get
  if(Serial2.available() > 0)
  {
    while(Serial2.available() > 0)
      Serial2.print (AddCRC(cmnd));
      Serial.print ("MFC1 setpoint is")
      Serial.println (msg) 
  }
}

void MFC1ChangeFlow(double NewFlowRate){
  Serial2.print (AddCRC(cmnd));
  Serial.println("I told the MFC1 to do stuff");
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////MFC 2//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/*
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
*/

void MFC2setpoint (void){
  String msg = String("");  //get
  if(Serial2.available() > 0)
  {
    while(Serial3.available() > 0)
      Serial3.print (AddCRC(cmnd));
      Serial.print ("MFC1 setpoint is")
      Serial.println (msg) 
  }
}

void MFC2ChangeFlow(double NewFlowRate){
  Serial3.print (AddCRC(cmnd));
  Serial.println("I told the MFC1 to do stuff");
}



