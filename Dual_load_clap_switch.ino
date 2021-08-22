//Below, the three pins used are declared
const int mic = A2;
const int relay2 = 12;
const int relay = 13;

//The variables used are also declared
int reading = 0;//this variable store the value measured at the mic pin

boolean relayOn = 0;//here, we have two boolean variables which are used to toggle the state of the relay pins
boolean relayOn2 = 0;
int iChecker;//this integer variable  is used to ensure that either the code
// for the single clap or the double clap runs but not both


void setup() {
  pinMode(mic, INPUT);     //the mic pin is stated to be an input pin
  pinMode(relay, OUTPUT);  //the first relay pin is stated to be an output pin
  pinMode(relay2, OUTPUT); //the second relay pin is stated to be an output pin
}


//the arduino runs this loop over and over again forever
void loop() {
  reading = analogRead(mic);//the arduino takes reading of the mic pin
                            //and stores it in the variable called "reading"

  if (reading > 100) {      //If the value it has read is above 100, this code runs
    
    iChecker = 0;
    delay(100);
    reading = 0;
    
    for (int i = 0; i < 1000; i++) {//this code keeps running and increases "i" each time it runs
                                    //when "i" gets to 999, it stops and moves forward
      reading = analogRead(mic);
      delay(1);
      if (reading > 100) {          //during the period of running the for loop, if 
                                    //it senses high sound value,if runs this and sees it as a second clap
        relayOn2 = !relayOn2;
        iChecker = 3;
        reading = 0;
        delay(100);
        break;
      }
    }

    do {
      if (iChecker != 3) {
        relayOn = !relayOn;
        delay(100);
        break;
      }
    } while (reading > 100);
  }

  if (relayOn == 1) {
    digitalWrite(relay, HIGH);
  }
  else {
    digitalWrite(relay, LOW);
  }

  if (relayOn2 == 1) {
    digitalWrite(relay2, HIGH);
  }
  else {
    digitalWrite(relay2, LOW);
  }
}
