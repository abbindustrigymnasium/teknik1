const byte MotorSpeed = D1;  //5
const byte MotorDir = D3;   //0

int minspeed = 450;
int maxspeed = 1020;
int nospeed = 0;

void setup() {
    Serial.begin(9600);
 
    pinMode(MotorDir, OUTPUT);
    digitalWrite(MotorDir, HIGH);
   }

void loop() {
        digitalWrite(MotorDir,HIGH);
                
        analogWrite(MotorSpeed, nospeed);
        delay(2000);     
        analogWrite(MotorSpeed, minspeed);
        delay(5000);
        analogWrite(MotorSpeed, maxspeed);
        delay(5000);
        analogWrite(MotorSpeed, minspeed);
        delay(5000);
        analogWrite(MotorSpeed, nospeed);
        delay(2000);
        
        digitalWrite(MotorDir,LOW);
                
        analogWrite(MotorSpeed, nospeed);
        delay(2000);
        analogWrite(MotorSpeed, minspeed);
        delay(5000);
        analogWrite(MotorSpeed, maxspeed);
        delay(5000);
        analogWrite(MotorSpeed, minspeed);
        delay(5000);
        analogWrite(MotorSpeed, nospeed);
        delay(2000);
}
