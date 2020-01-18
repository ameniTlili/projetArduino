
#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;


int kef  = A0;
int midnine  = A1;
int gasrine  = A2;
int tunis  = A3;
int beja  = A4;
int tunisie  = A5;


int btnKef =2;
int btnMidnine =3;
int btnGasrine =4;
int btnTunis =5;
int btnBeja =6;

int trig=8;
int echo=7;
int cas;

void setup (){
  pinMode(kef,OUTPUT);
  pinMode(midnine,OUTPUT);
  pinMode(gasrine,OUTPUT);
  pinMode(tunis,OUTPUT);
  pinMode(beja,OUTPUT);
  pinMode(tunisie,OUTPUT);

  pinMode(btnKef,INPUT);
  pinMode(btnMidnine,INPUT);
  pinMode(btnGasrine,INPUT);
  pinMode(btnTunis,INPUT);
  pinMode(btnBeja,INPUT);
  
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  Serial.begin(9600);
  int cas=0;

  analogWrite(kef,0);
  analogWrite(midnine,0);
  analogWrite(gasrine,0);
  analogWrite(tunis,0);
  analogWrite(beja,0);
  analogWrite(tunisie,255);
  
  
  tmrpcm.speakerPin=9;
    if(!SD.begin(SD_ChipSelectPin))
    {
    Serial.println("SD fail");
    return;
     }
  tmrpcm.setVolume(6);
 
}
void loop(){

  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  int distance = duration/58.2;
  Serial.print("distance : ");
  Serial.println(distance);
  Serial.print("cas :");
  Serial.println(cas);
  Serial.print("btnKef :");
  Serial.println(digitalRead(btnKef));

  if(distance<6){
    if (cas != 1){
      analogWrite(kef,255);
      analogWrite(midnine,255);
      analogWrite(gasrine,255);
      analogWrite(tunis,255);
      analogWrite(beja,255);
      analogWrite(tunisie,255);
      tmrpcm.play("1.wav");
      cas=1;
    }
  }

  if((digitalRead(btnKef)) == 1){
    if (cas != 2){
      analogWrite(kef,255);
      analogWrite(midnine,0);
      analogWrite(gasrine,0);
      analogWrite(tunis,0);
      analogWrite(beja,0);
      analogWrite(tunisie,0);
     tmrpcm.play("kef.wav");
      cas=2;
    }

  }



}

