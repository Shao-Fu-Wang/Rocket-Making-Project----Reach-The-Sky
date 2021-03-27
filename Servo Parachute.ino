#include <Servo.h> 
int servoPin = 3;  
Servo Servomotor; 
void setup() { 
   Servomotor.attach(servoPin); 
}
void loop(){   
   delay(10000); //rough estimated flying time 
   Servomotor.write(180);
}
