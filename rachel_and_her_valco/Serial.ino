
// function for splitting a string and returning the part nr index split by separator
String getStringPartByNr(String data, char separator, int index) {
    int stringData = 0;        //variable to count data part nr 
    String dataPart = "";      //variable to hole the return text

    for(int i = 0; i<data.length(); i++) {    //Walk through the text one letter at a time

        if(data[i]==separator) {
            //Count the number of times separator character appears in the text
            stringData++;

        }else if(stringData==index) {
            //get the text when separator is the right one
            dataPart.concat(data[i]);

        }else if(stringData>index) {
            //return text and stop if the next separator appears - to save CPU-time
            return dataPart;
            break;
        }
    }
    //return text if this is the last part
    return dataPart;
}

//-------------------------------Get data from computer and change arduino stuff-------------------------------
void get_data_from_serial(void){
  String msg = String("");  //get
  String temp = String("");
  if(Serial.available() > 0)
  {
    while(Serial.available() > 0)
    {
      msg += char(Serial.read());
      delay(10); 
     }
    Serial.print("$");
    Serial.println(msg);
  }
  
    if(msg == "OMG") {Serial.println("Hi mom");} //example of how to get an exact string and then do something
    if(msg == "IdleMode") {   //Turn on or off IdleMode
      IdleMode = true;
      // Add in any commands for initiating idle mode
     }
    if(msg == "IdleModeoff") {IdleMode = false;}
   // if(msg == "Valveoneopen") {SetValve(1, OPEN); SendValves();} //Do several thing


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////Valco//////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    if(getStringPartByNr(msg, ',', 0) == ("Valco")) // example of how to get part of a string and call a fuction if it is = to something
      {
         temp = (getStringPartByNr(msg, ',', 1));
         if(temp == "CW"){
          temp = (getStringPartByNr(msg, ',', 2));
          turnValveClockwise(temp.toInt());
          Serial.println("I moved Clockwise");
         }
         if(temp == "CC"){
          temp = (getStringPartByNr(msg, ',', 2));
          turnValveCounterClockwise(temp.toInt());
          Serial.println("I moved Counter Clockwise");
         }
           
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////MFC 1//////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       
       
      }
     if(getStringPartByNr(msg, ',', 0) == ("MFC1_Flow")) // example of how get a number from a string and call a function with it
      {
       temp = (getStringPartByNr(msg, ',', 1));
       msgholder=temp.toInt();
       MFC1ChangeFlow(msgholder);

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////MFC 2//////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////             
      }
      if(getStringPartByNr(msg, ',', 0) == ("MFC2_Flow")) // example of how get a number from a string and call a function with it
      {
       temp = (getStringPartByNr(msg, ',', 1));
       msgholder=temp.toInt();
       MFC2ChangeFlow(msgholder);
            
      }
      

    
//-------------------------------END getting data from computer and changing arduino stuff-------------------------------


} //end of get_data_from_serial()
