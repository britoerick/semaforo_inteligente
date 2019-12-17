#include <Ultrasonic.h>
#define pinVerde 2
#define pinAmarelo 3
#define pinVermelho 4

  Ultrasonic ultrassom(8,7);
  long distancia;
  int amarelo;
 
 void setup() {
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  Serial.begin(9600);
 
 }
 
 void loop(){
   distancia = ultrassom.Ranging(CM);
   delay(100);
   
   if(distancia < 10){

    while(distancia < 10){
      Serial.println(distancia);
      digitalWrite(pinVermelho, LOW);
      delay(100);
      digitalWrite(pinVerde, HIGH);
      distancia = ultrassom.Ranging(CM);
    }
    digitalWrite(pinVerde, HIGH);
    delay(1500);
    digitalWrite(pinVerde, LOW);
    amarelo = 1;
   } else {
    
    if(amarelo == 1){
      digitalWrite(pinVermelho, LOW);
      digitalWrite(pinAmarelo, HIGH);
      delay(1000);
      digitalWrite(pinAmarelo, LOW);
    }
    amarelo = 0;
            
    Serial.println(distancia);
    digitalWrite(pinVermelho, HIGH);
   }
 }
