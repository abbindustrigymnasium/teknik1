#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

typedef enum DriveStates {
Init,
Stop,
Frwd,
Bkwd
};

DriveStates DState;

byte PotInput = 0;
int PotValue;
byte SwitchInput = 13;
boolean SwitchOn;
byte Speed;

const byte RightMotorSpeed = 5;  //14 
const byte RightMotorDir = 0;   //12 
const byte LeftMotorSpeed = 4;  //13 
const byte LeftMotorDir = 2;  //15 

Adafruit_SSD1306 display(128, 64, &Wire,-1,400000UL,100000UL);

void setup() {
  Serial.begin(9600);
  pinMode(SwitchInput, INPUT);

  Wire.pins(14,12);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.display();
    
  display.setTextColor(WHITE);
  display.setTextSize(2,3);
  
  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);

  analogWrite(RightMotorSpeed, 0);
  analogWrite(LeftMotorSpeed, 0);
  DState = Init;
  }

void loop() {
  PotValue = analogRead(PotInput);
  Speed =map(PotValue,0,1023,0,255);
  SwitchOn = digitalRead(SwitchInput);
  Serial.print(SwitchOn);
  Serial.println(DState);
  Serial.print("/t");
  Serial.println(Speed);
  

  switch (DState) {
    case Init:
      display.clearDisplay();
      display.display();
      display.setTextSize(1,2);
      display.setCursor(30, 0);
      display.print("Läge");
      display.setTextSize(2,3);
      display.setCursor(30, 30);
      display.println(DState); 
      /*display.setTextSize(2,3);
      display.setCursor(30, 60);
      display.println(PotValue);*/
      
      delay(5000);
      DState = Stop;
      break;
      
      case Stop:

      display.clearDisplay();
      display.display();
      display.setTextSize(1,2);
      display.setCursor(30, 0);
      display.print("Läge");
      display.setTextSize(2,3);
      display.setCursor(30, 30);
      display.println(DState);
     /*display.setTextSize(2,3);
      display.setCursor(30, 60);
      display.println(PotValue);*/
      
      delay(3000);
      if (!SwitchOn)
      {
        DState = Frwd;
      }
      else
      {
      DState = Bkwd;
      }
    break;
    
    case Frwd:
      display.clearDisplay();
      display.display();
      display.setTextSize(1,2);
      display.setCursor(30, 0);
      display.print("Läge");
      display.setTextSize(2,3);
      display.setCursor(30, 30);
      display.println(DState);
      /*display.setTextSize(2,3);
      display.setCursor(30, 60);
      display.println(PotValue);*/
      
      digitalWrite(RightMotorDir, HIGH);
      digitalWrite(LeftMotorDir, HIGH);
      analogWrite(RightMotorSpeed, Speed);
      analogWrite(LeftMotorSpeed, Speed);
      
      if (Speed < 10) DState = Stop;
    break;
    
    case Bkwd:
      display.clearDisplay();
      display.display();
      display.setTextSize(1,2);
      display.setCursor(30, 0);
      display.print("Läge");
      display.setTextSize(2,3);
      display.setCursor(30, 30);
      display.println(DState);
     /*display.setTextSize(2,3);
      display.setCursor(30, 60);
      display.println(PotValue);*/
      
      digitalWrite(RightMotorDir,LOW);
      digitalWrite(LeftMotorDir, LOW);
      analogWrite(RightMotorSpeed, Speed);
      analogWrite(LeftMotorSpeed, Speed);
      if (Speed < 10) DState = Stop; 
    break;  
  }
}
  
