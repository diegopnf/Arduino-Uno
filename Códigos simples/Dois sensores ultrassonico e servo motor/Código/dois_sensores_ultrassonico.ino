#include <Ultrasonic.h>
#include <Servo.h>

#define PinoTrigger 4 
#define PinoEcho1 5 
#define PinoTrigger2 6
#define PinoEcho2 7
#define ServoPino 8
int distancia1;
int distancia2;

Ultrasonic ultrasonic(4,5); 
Ultrasonic ultrasonic2(6,7);
Servo servomotor; 

void setup() {
  servomotor.attach(ServoPino);
  servomotor.write(0); 
  Serial.begin(9600); 
}

void loop()
{  
  leituraUltrassonica();
  cancelaAutomatica(); 
  leituraSerial(); 
}

void leituraUltrassonica(){
  digitalWrite(PinoTrigger, HIGH); 
  delayMicroseconds(10);
  digitalWrite(PinoTrigger, LOW);
  pulseIn(PinoEcho1, HIGH); 
  pulseIn(PinoEcho2, HIGH); 
  distancia1=ultrasonic.Ranging(CM); 
  distancia2=ultrasonic2.Ranging(CM); 
}

void cancelaAutomatica(){
  if(distancia1<=20){ 
    servomotor.write(45);
  }
  else if(distancia2<=20){ 
    servomotor.write(0);
  }
}

void leituraSerial(){
  Serial.println("LEITURA 1"); 
  Serial.println(distancia1);
  Serial.println("LEITRURA 2"); 
  Serial.println(distancia2);  
}
