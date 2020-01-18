//pins manette
const int SW_pin=2;
const int X_pin=0;
const int Y_pin=1;
//pins button
int but_A=3;
int but_B=4;
int but_C=5;
int but_D=6;
void setup() {
//manette
pinMode(SW_pin,INPUT);
digitalWrite(SW_pin,HIGH);
Serial.begin(115200);
//button
pinMode(but_A,INPUT);
pinMode(but_B,INPUT);
pinMode(but_C,INPUT);
pinMode(but_D,INPUT);
}

void loop() {
//reglage des button  
int valA=digitalRead(but_A); 
int valB=digitalRead(but_B); 
int valC=digitalRead(but_C); 
int valD=digitalRead(but_D);
//button
if (valA==0){
  Serial.print("\n A");
  }
  
if (valB==0){
  Serial.print("\n B");
  }
  
if (valC==0){
  Serial.print("\n C");
  }
  
if (valD==){
  Serial.print("\n D");
  }
  delay(500);
//manette
int x=analogRead(X_pin);
int y=analogRead(Y_pin);
//up/down/right/left
if (x>=1000  &&y>=510 &&y<=530 ){
  Serial.print("\n up");
  }
if (x>=0 && x<=30 &&y>=510 &&y<=530 ){
  Serial.print("\n down");
  }
if (x>=510 &&x<=530 &&y>=1000 ){
  Serial.print("\n right");
  }
if (x>=510 &&x<=530 &&y>=0 && y<=30 ){
  Serial.print("\n left");
  }
//up-left/up-right/down-left/down-right
/*
if (x==1024 &&y==0 ){
  Serial.print("\n up-left");
  }
if (x==1024 &&y==1024 ){
  Serial.print("\n up-right");
  }
if (x==0 &&y==0 ){
  Serial.print("\n down-left");
  }
if (x==0 &&y==1024 ){
  Serial.print("\n down-right");
  }
  */
//center
if (x==512 &&y==512 ){
  Serial.print("\n center");
  }

if (SW_pin==1){
  Serial.print("\n center");
  }
  
}
