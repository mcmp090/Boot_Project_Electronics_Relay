// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
char c;
void setup() {
  Wire.begin(9);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  switch (c){
    case '1':
    digitalWrite(5,HIGH);
    break;
    case '2':
    digitalWrite(5,LOW);
    break;
    case '3':
    digitalWrite(6,HIGH);
    break;
    case '4':
    digitalWrite(6,LOW);
    break;
    case '5':
    digitalWrite(7,HIGH);
    break;
    case '6':
    digitalWrite(7,LOW);
    break;
    case '7':
    digitalWrite(8,HIGH);
    break;
    case '8':
    digitalWrite(8,LOW);
    break;
    case '9':
    digitalWrite(9,HIGH);
    break;
    case 'A':
    digitalWrite(9,LOW);
    break;
    case 'B':
    digitalWrite(10,HIGH);
    break;
    case 'C':
    digitalWrite(10,LOW);
    break;
    case 'D':
    digitalWrite(11,HIGH);
    break;
    case 'E':
    digitalWrite(11,LOW);
    break;
    case 'F':
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(5,LOW);
    break;
    default:
    break;
  }

}
