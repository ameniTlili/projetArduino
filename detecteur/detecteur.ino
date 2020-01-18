//Robot Detecteur d'obstacle 
int mot1pin1=2;
int mot1pin2=3;
int mot2pin1=4;
int mot2pin2=5;
int trig=6;
int echo=7;

void setup(){
  pinMode(mot1pin1,OUTPUT);
  pinMode(mot1pin2,OUTPUT);
  pinMode(mot2pin1,OUTPUT);
  pinMode(mot2pin2,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  digitalWrite(trig,LOW);
  long duree=pulseIn(echo,HIGH);
  int distance = duree/58.2 ; 
 Serial.println(distance); 
  if(distance < 7){
    tourneDroit();
    Serial.println("tourne");
  }
  marche();  
}

void tourneDroit(){
  digitalWrite(mot1pin1,LOW);
  digitalWrite(mot1pin2,HIGH);
  digitalWrite(mot2pin1,HIGH);
  digitalWrite(mot2pin2,LOW);
}
void marche(){
  digitalWrite(mot1pin1,LOW);
  digitalWrite(mot1pin2,HIGH);
  digitalWrite(mot2pin1,LOW);
  digitalWrite(mot2pin2,HIGH);
}

