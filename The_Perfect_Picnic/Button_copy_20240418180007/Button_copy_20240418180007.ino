/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/
#include <Servo.h>
// constants won't change. They're used here to set pin numbers:
const int buttonPinS = 2;  // the number of swordgirl's pushbutton pin
const int buttonPinT = 5;  // the number of the Tree's pushbutton pin
const int servoPinS = 9;    // the number of swordgirl's servo pin
const int servoPinT = 13;   // the number of the Tree's servo pin

// variables will change:
int treeState = 0;  // variable for reading the pushbutton status

Servo myservoS;
Servo myservoT;

void setup() {
  pinMode(servoPinS, OUTPUT);
  pinMode(buttonPinS, INPUT);
  myservoS.attach(servoPinS);
  myservoT.attach(servoPinT);
  myservoS.write(0);
  myservoT.write(0);
}

void loop() {
  // read the state of the pushbutton value:
  int pinValueS = digitalRead(buttonPinS);
  int pinValueT = digitalRead(buttonPinT);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (pinValueS == HIGH) {
    myservoS.write(60);  // sets the servo position according to the scaled value 
    delay(500);

    myservoS.write(0);  // sets the servo position according to the scaled value 
    delay(500);

    myservoS.write(60);  // sets the servo position according to the scaled value 
    delay(500);

    myservoS.write(0);  // sets the servo position according to the scaled value 
    delay(500);

    myservoS.write(60);  // sets the servo position according to the scaled value 
    delay(500);

    myservoS.write(0);  // sets the servo position according to the scaled value 
    delay(500);

    myservoT.write(90);
    delay(2500);

    myservoT.write(0);
    delay(2000);                 
  }
  /*
  else{                 
    myservoS.write(0);  // sets the servo position according to the scaled value 
    delay(50); 
  }
  */
  if (pinValueT == HIGH) {
    if(treeState == 0){
      myservoT.write(0);
      treeState = 1;
      delay(1000);
    }
    else{
      myservoT.write(90);
      treeState = 0;
      delay(1000);
    }
      // sets the servo position according to the scaled value               
  }
}
