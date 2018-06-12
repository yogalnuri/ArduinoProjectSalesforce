#include <SoftwareSerial.h>

/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
//#include <ESP8266WiFi.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int buttonPin = 2;     // the number of the pushbutton pin
const int metalSensor=3;

const int motorSwitch=9;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int debug_showDigital = 0; //Show digital result in serial output?
int debug_showAnalog = 1; //Show analog result in serial output?



void setup() {
  Serial.begin(9600);
  myservo.attach(motorSwitch);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT);
  pinMode(metalSensor,INPUT);
  int digitalValMetalSensor = digitalRead(metalSensor); //Read Digital pin and store result
  int analogValMetalSensor = analogRead(A0); //Read analog pin and store result 
  myservo.write(pos);
}

void loop() {

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  int digitalVal = digitalRead(metalSensor); //Read Digital pin and store result
  int analogVal = analogRead(A0); //Read analog pin and store result 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  
  if (buttonState == LOW) {
    digitalVal = digitalRead(metalSensor); //Read Digital pin and store result
    analogVal = analogRead(A0); //Read analog pin and store result 
    Serial.print("Lectura Digital-->");
    Serial.println(digitalVal);
    Serial.print("Lectura Analogica-->");
    Serial.println(analogVal);
    if (digitalVal != HIGH) { //Digital result = 1
      Serial.println("Sensor no Detecta");
      pos = pos + 15;
      // turn LED on:
      if(pos>180){
        pos=0;
      }
       myservo.write(pos);
      Serial.println(buttonState);
      Serial.println(pos);
      delay(500);
    } 
    Serial.println("Sensor no Detecta");
    
   
  }

}

