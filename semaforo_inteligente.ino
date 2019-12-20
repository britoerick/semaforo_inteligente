#include <Ultrasonic.h>
#define ledVd_1 2           //led verde1
#define ledAm_1 3           //led amarelo1
#define ledVm_1 4           //led vermelho1
#define ledVd_2 11          //led verde2
#define ledAm_2 12          //led amarelo2
#define ledVm_2 13          //led vermelho2

Ultrasonic sensor_1(6,7);   //sensor ultrassônico1
Ultrasonic sensor_2(8,9);   //sensor ultrassônico2

long distSensor_1;          //distância sensor ultrassônico1
long distSensor_2;          //distância sensor ultrassônico2
int timeSensor;             //variável auxiliar tempo sensor1
int ultimoSensor;           //variável auxiliar para salvar último sensor que ativou sinal verde
int resetTimeSensor_1 = 0;  //variável para resetar time do sensor1
int resetTimeSensor_2 = 0;  //variável para resetar time do sensor2
int distancia = 5;          //variável para definir a distância que o sensor será acionado
int tempo = 20;             //variável para definir o tempo que o sinal ficará aberto após ser acionado, 1 = 200milisegundos

void setup() {
  pinMode(ledVd_1, OUTPUT);
  pinMode(ledAm_1, OUTPUT);
  pinMode(ledVm_1, OUTPUT);
  pinMode(ledVd_2, OUTPUT);
  pinMode(ledAm_2, OUTPUT);
  pinMode(ledVm_2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  distSensor_1 = sensor_1.Ranging(CM);
  distSensor_2 = sensor_2.Ranging(CM);

  digitalWrite(ledVm_1, HIGH);
  digitalWrite(ledVm_2, HIGH);

  /* teste sensor e acender todas os leds
  delay(1000);

  digitalWrite(ledVd_1, HIGH);
  digitalWrite(ledAm_1, HIGH);
  digitalWrite(ledVm_1, HIGH);
  digitalWrite(ledVd_2, HIGH);
  digitalWrite(ledAm_2, HIGH);
  digitalWrite(ledVm_2, HIGH);

  Serial.print("sensor1 ");
  Serial.println(distSensor_1);
  Serial.print("sensor2 ");
  Serial.println(distSensor_2);

  */

  Serial.print("sensor1 ");
  Serial.println(distSensor_1);
  Serial.print("sensor2 ");
  Serial.println(distSensor_2);

  if(distSensor_1 <= distancia && distSensor_2 > distancia && ultimoSensor != 1){
    ultimoSensor = 1;
    timeSensor = 0;

    while(timeSensor < tempo){
      digitalWrite(ledVm_1, LOW);
      delay(200);
      digitalWrite(ledVd_1, HIGH);
      distSensor_1 = sensor_1.Ranging(CM);
      timeSensor = timeSensor + 1;
        Serial.print("sensor1 ");
        Serial.println(distSensor_1);
        Serial.println(timeSensor);
    }
      delay(1500);
      digitalWrite(ledVd_1, LOW);
      digitalWrite(ledAm_1, HIGH);
      delay(1000);
      digitalWrite(ledAm_1, LOW);
  }

  
  if(distSensor_1 > distancia && distSensor_2 <= distancia && ultimoSensor != 2){
    ultimoSensor = 2;
    timeSensor = 0;
    
    while(timeSensor < tempo){
      digitalWrite(ledVm_2, LOW);
      delay(200);
      digitalWrite(ledVd_2, HIGH);
      distSensor_2 = sensor_2.Ranging(CM);
      timeSensor = timeSensor + 1;
        Serial.print("sensor1 ");
        Serial.println(distSensor_1);
        Serial.println(timeSensor);
    }
      delay(1500);
      digitalWrite(ledVd_2, LOW);
      digitalWrite(ledAm_2, HIGH);
      delay(1000);
      digitalWrite(ledAm_2, LOW);

  }

  if(distSensor_1 <= distancia && distSensor_2 <= distancia){

    switch(ultimoSensor){
      case 1:
        ultimoSensor = 2;
        timeSensor = 0;
        while(timeSensor < tempo){
          digitalWrite(ledVm_2, LOW);
          delay(200);
          digitalWrite(ledVd_2, HIGH);
          distSensor_2 = sensor_2.Ranging(CM);
          timeSensor = timeSensor + 1;
          Serial.print("sensor1 ");
          Serial.println(distSensor_1);
          Serial.println(timeSensor);
        }
          delay(1500);
          digitalWrite(ledVd_2, LOW);
          digitalWrite(ledAm_2, HIGH);
          delay(1000);
          digitalWrite(ledAm_2, LOW);
      break;
      
      case 2:
        ultimoSensor = 1;
        timeSensor = 0;
        
        while(timeSensor < tempo){
          digitalWrite(ledVm_1, LOW);
          delay(200);
          digitalWrite(ledVd_1, HIGH);
          distSensor_1 = sensor_1.Ranging(CM);
          timeSensor = timeSensor + 1;
          Serial.print("sensor1 ");
          Serial.println(distSensor_1);
          Serial.println(timeSensor);
        }
          delay(1500);
          digitalWrite(ledVd_1, LOW);
          digitalWrite(ledAm_1, HIGH);
          delay(1000);
          digitalWrite(ledAm_1, LOW);
      break;

      case 0:
        ultimoSensor = 1;
        timeSensor = 0;
        
        while(timeSensor < tempo){
          digitalWrite(ledVm_1, LOW);
          delay(200);
          digitalWrite(ledVd_1, HIGH);
          distSensor_1 = sensor_1.Ranging(CM);
          timeSensor = timeSensor + 1;
          Serial.print("switch caseeeeeeeee ");
          Serial.println(distSensor_1);
          Serial.println(timeSensor);
        }
          delay(1500);
          digitalWrite(ledVd_1, LOW);
          digitalWrite(ledAm_1, HIGH);
          delay(1000);
          digitalWrite(ledAm_1, LOW);
      break;
                
    }    
  }

  if(timeSensor != 0 && timeSensor <= 200 && ultimoSensor == 1){
    Serial.print("teste");
    Serial.println(resetTimeSensor_1);
    resetTimeSensor_1 = resetTimeSensor_1 + 1;
  }
  if(timeSensor != 0 && timeSensor <= 200 && ultimoSensor == 2){
    Serial.print("teste");
    Serial.println(resetTimeSensor_2);
    resetTimeSensor_2 = resetTimeSensor_2 + 1;
  }  

  if(resetTimeSensor_1 == 200){
    Serial.print("reset timesensor ");
    Serial.println(timeSensor);
    resetTimeSensor_1 = 0;
    ultimoSensor = 0;
  }
  if(resetTimeSensor_2 == 200){
    Serial.print("reset timesensor ");
    Serial.println(timeSensor);
    resetTimeSensor_2 = 0;
    ultimoSensor = 0;
  }
  
}
