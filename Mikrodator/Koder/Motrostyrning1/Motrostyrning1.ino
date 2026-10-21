const byte RightMotorSpeed = 5;  //14 
const byte RightMotorDir = 0;   //12 
const byte LeftMotorSpeed = 4;  //13 
const byte LeftMotorDir = 2;  //15 

int minspeed = 450;
int maxspeed = 1020;
int nospeed = 0;

void setup() {
    Serial.begin(9600);
 
    pinMode(RightMotorDir, OUTPUT);
    pinMode(LeftMotorDir, OUTPUT);

    digitalWrite(RightMotorDir, HIGH);
    digitalWrite(LeftMotorDir, HIGH);
}

void loop() {
  
        digitalWrite(RightMotorDir,HIGH);
        digitalWrite(LeftMotorDir,HIGH);
        
        analogWrite(RightMotorSpeed, nospeed);
        analogWrite(LeftMotorSpeed , nospeed);
        delay(2000);
        
        analogWrite(RightMotorSpeed, minspeed);
        analogWrite(LeftMotorSpeed , minspeed);
        delay(5000);
        
        analogWrite(RightMotorSpeed, maxspeed);
        analogWrite(LeftMotorSpeed , maxspeed);
        delay(5000);
        
        analogWrite(RightMotorSpeed, minspeed);
        analogWrite(LeftMotorSpeed , minspeed);
        delay(5000);
        
        analogWrite(RightMotorSpeed, nospeed);
        analogWrite(LeftMotorSpeed , nospeed);
        delay(2000);
        
        digitalWrite(RightMotorDir,LOW);
        digitalWrite(LeftMotorDir,LOW);
        
        analogWrite(RightMotorSpeed, nospeed);
        analogWrite(LeftMotorSpeed , nospeed);
        delay(2000);
        
        analogWrite(RightMotorSpeed, minspeed);
        analogWrite(LeftMotorSpeed , minspeed);
        delay(5000);
        
        analogWrite(RightMotorSpeed, maxspeed);
        analogWrite(LeftMotorSpeed , maxspeed);
        delay(5000);
        
        analogWrite(RightMotorSpeed, minspeed);
        analogWrite(LeftMotorSpeed , minspeed);
        delay(5000);
        
        analogWrite(RightMotorSpeed, nospeed);
        analogWrite(LeftMotorSpeed , nospeed);
        delay(2000);
}
