#include <Servo.h>

Servo servot;

const int AI_Pot = 0;
int PotValue = 0;

unsigned long previousMillis =0;
unsigned long currentMillis;
unsigned long diffMillis;

//long Time;
void setup () {
  Serial.begin(9600);
  servot.attach(D2, 544,2400);
 }

void loop() {
  PotValue = analogRead(AI_Pot);
  //Time =long(AI_Pot);
   // Map potentiometer value to betweeon 0 and 180 for servo position
  long ServoPos = map(PotValue, 0, 1023, 0, 180);
  // Move servo
  servot.write(ServoPos);
  //analogWrite(D2, PotValue);
  Serial.print (PotValue );
  Serial.print (" ");
  Serial.println(ServoPos);
  TimeLimit(1000);

}

boolean TimeLimit(int intervall){
  currentMillis = millis();
  diffMillis = currentMillis - previousMillis;
  if(diffMillis > intervall) {
    previousMillis = currentMillis;
    return true;
  }
  else return false;
}
  
