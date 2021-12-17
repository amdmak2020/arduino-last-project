#include <Servo.h>

Servo myservo;
int echo = 12;
int trig = 13;
int led = 8;
int LDR = A0;
int LDR_sensor = 0;

void setup() {
  myservo.attach(9);
  pinMode(led, OUTPUT);
  
  pinMode(LDR, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop(){
  long duration, distance;
  LDR_sensor = analogRead(LDR);
  int pos = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  for (pos=0;pos<90;pos++){
    myservo.write(pos);
    delay(15);
  }
  for (pos=90;pos>0;pos -=1){
    myservo.write(pos);
    delay(15);
  }
  if ((distance < 100) && (LDR_sensor<300)){
    digitalWrite(led, HIGH);
  }
}
