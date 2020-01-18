#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

const int leftForward = 2;

const int leftBackward = 3;

const int rightForward = 4;

const int rightBackward = 5;


void setup() {

 BT.begin(9600);

 Serial.begin(9600);

    pinMode(leftForward , OUTPUT);

  pinMode(leftBackward , OUTPUT);

  pinMode(rightForward , OUTPUT);

  pinMode(rightBackward , OUTPUT);
}

 

void loop() {

  while (BT.available()){  

  delay(10); 

  char c = BT.read(); 

  readvoice += c; 

  } 

  if (readvoice.length() > 0) {

    Serial.println(readvoice);

  

  if(readvoice == "FF")//forward

  {

moveForward();

    delay(100);

    }
  

  else if(readvoice == "BB")//backward

  {

moveBackward();

    delay(100);

  }



  else if (readvoice == "RR")//right

  {

turnRight();

    delay (100);

  

  }



 else if ( readvoice == "LL")//left

 {

turnLeft();

   delay (100);

 }



 else if (readvoice == "SS")//stop

 {
robotStop();

   delay (100);

 }

readvoice="";}} //Reset the variable



void robotStop(){
  
    digitalWrite(leftForward , LOW);

    digitalWrite(leftBackward , LOW);

    digitalWrite(rightForward , LOW);

    digitalWrite(rightBackward , LOW);
}

void moveForward()

{

    digitalWrite(leftForward , HIGH);

    digitalWrite(leftBackward , LOW);

    digitalWrite(rightForward , HIGH);

    digitalWrite(rightBackward , LOW);

  }

  void moveBackward()

{

  digitalWrite(leftForward , LOW);

    digitalWrite(leftBackward , HIGH);

    digitalWrite(rightForward , LOW);

    digitalWrite(rightBackward , HIGH);

}

void turnRight() 

{

    digitalWrite(leftForward , HIGH);

    digitalWrite(leftBackward , LOW);

    digitalWrite(rightForward , LOW);

    digitalWrite(rightBackward , LOW);



}

void turnLeft()

{

    digitalWrite(leftForward , LOW);

    digitalWrite(leftBackward , LOW);

    digitalWrite(rightForward , HIGH);

    digitalWrite(rightBackward , LOW);



}
