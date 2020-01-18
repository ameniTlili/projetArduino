#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //TX, RX respetively
String readvoice;
#include "pitches.h"  //add note library
//notes in the melody
int melody[]={NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);


}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);
     if(readvoice == "W")
  {

    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    delay(100);
  }
   if(readvoice == "w")
  {
    digitalWrite(9,LOW);
    digitalWrite (8,LOW);
    
    delay(100);
  }

  if(readvoice == "F")
  {
    digitalWrite(3,LOW);
    digitalWrite (4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    delay(100);
    }
  
if(readvoice == "V")
{
    for (int thisNote=0; thisNote <8; thisNote++){

      //to calculate the note duration, take one second. Divided by the note type
      int noteDuration = 1000 / noteDurations [thisNote];
      tone(7, melody [thisNote], noteDuration);

      //to distinguish the notes, set a minimum time between them
      //the note's duration +30% seems to work well
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      //stop the tone playing
      noTone(7);
}

}
  


  
  else if(readvoice == "B")
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6,LOW );
    delay(100);
  }

  else if (readvoice == "R")
  {
    digitalWrite (3,LOW);
    digitalWrite (4,LOW);
    digitalWrite (5,HIGH);
    digitalWrite (6,LOW);
    delay (100);
  
  }

 else if ( readvoice == "L")
 {
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, HIGH);
   delay (100);
 }

 else if (readvoice == "S")
 {
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   delay (100);
 }
readvoice="";}} //Reset the variable

