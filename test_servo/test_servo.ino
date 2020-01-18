#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo  
void setup() 
{ 
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
                                  
    myservo.write(0);              // tell servo to go to position in variable 'pos' 
  
}
