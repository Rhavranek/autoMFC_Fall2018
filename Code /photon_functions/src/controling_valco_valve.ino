/*
 * Project controling_valco_valve
 * Description:
 * Author:
 * Date:

General Valco notes:
Requires 9600 baud rate, 8 bit, 1 stop bit,
"HM" - moves to position 1
"CP" - current positions
"CW" - moves the actuator in the postive direction e.g. 4 ->5.
  You can just use this command to move it one position up
"CW nn" - moves actutor in a positive direction to position nn
"CC" - moves the actuator in a negative direction e.g. 5->4
"CC nn " where nn is a position number moves the actuator in a negative direction to position nn
*/



/*
 * Project controling_valco_valve
 * Description:
 * Author:
 * Date:

General Valco notes:
Requires 9600 baud rate, 8 bit, 1 stop bit,
"HM" - moves to position 1
"CP" - current positions
"CW" - moves the actuator in the postive direction e.g. 4 ->5.
  You can just use this command to move it one position up
"CC" - moves the actuator in a negative direction e.g. 5->4
"CC nn " where nn is a position number moves the actuator in a negative direction to position nn
*/

//Initialize all my varibales for the setup chunk
int nvalvestate = 0; //This initializes the nvalvestate variable
String valvename =""; //This initializes valvename string
int turnup (String command); //turnup will be an integer and we will feed it a string command
int turndown(String command); //turndown will be an integer and we will feed it a string command
int turnhm(String command); //same thing
int where(String command);
String msg =""; //initializes that msg will be a string - right now its empty

void setup() {
  Serial.begin(9600); //computer side
  Serial1.begin(9600); //valco side
  Particle.variable("valvesint", nvalvestate); //sets up the variable valvesint as a varible on OS
  Particle.variable("valvestate", msg); //sets up the variable valvestate as a variable on OS
  nvalvestate = 5; //feeds it an arbitrary vavlvestate to start
  Particle.function("turndown", turndown); //initializes the function in OS - doesn't turn the valco
  Particle.function("turnup", turnup); //initializes the function in OS
  Particle.function("turnhm", turnhm); // initializes the function in OS
}

void loop() {
  nvalvestate = 1;
  delay(10000);// loop() runs over and over again, as quickly as it can execute.
  nvalvestate = 2;
  delay(10000);
}


//Below I define a funciton to have the valco tell me where it is
int where(String command)
{
  if(command == "1") //what i enter into the ap
  {
    Serial1.println("CP"); //Scream at valco WHERE ARE YOU
    nvalvestate=listentovalco(); //Need to be a better listener
  }
  else return -1; //if I haven't screamed at the valcovalve, then just sty in this random -1 state
}

int turnup(String command)
{
  if(command == "1") //if I enter one then ..
  {
    Serial1.println("CW"); //SCREAM at the valcovalve to move up one position
    //HERE I'd like to have the valco then use where - so that I can see where it moved to.
  }
  else return -1;
}



int turndown(String command)
{
  if(command == "turndown")
  {
    Serial1.println("CC");
    msg="bye"; //this is a way for us to know the function worked
  }
  else return -1;
}




int turnhm (String command)
{
  if (command == "turnhm")
  {
    Serial1.println("HM");
    msg="hello"; //this is a way for us to know the function worked
  }
  else return -1;
}



String temp_message = ""; //initialize for the listen to valco function.

int listentovalco(void) { //function listentovalco
  while (Serial1.available()) {
    byte c = Serial1.read();
    if (c == 0) { //if there are no bytes, do nothing  // do nothing when 0 character encountered
    }
        else if (c >= 32 && c <= 126) { // regular ASCII range - else if = or if
      temp_message += (char) c; // build a temporary message message out of letters
    } else  if (c == 13) { // return character received - then print Whole line: temp-message
      Serial.print("Whole line: ");
      Serial.println(temp_message);
      msg=temp_message; //permanently store this, until the next time
      temp_message = ""; //clear temp message so its ready

    } else { //if serial1 is not available, then do nothing! cause you can't listen nerd.
    }
  }
}
