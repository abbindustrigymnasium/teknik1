#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <AM2320.h>

//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define InputPin 13

Adafruit_SSD1306 display(128, 64, &Wire,-1,400000UL,100000UL);

bool ButtonState;
float SensorTemp;
float SensorHum;

AM2320 sensor;

void setup() {
  Serial.begin(9600);
  pinMode(InputPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.pins(14,12);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
    
 display.setTextColor(WHITE);
 display.setTextSize(2,3);
}


  
void loop() {
  
  ButtonState = digitalRead(InputPin);
  digitalWrite(LED_BUILTIN,ButtonState);
  
  if (ButtonState){
  
  display.clearDisplay();
  display.setTextSize(1,2);
  display.setCursor(30, 0);
  display.print("Humidity %");
  display.setTextSize(2,3);
  display.setCursor(30, 30);
  display.println(SensorHum);
  
  
 
    for(int16_t i=0; i<display.height()/2-2; i+=40) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i,
    display.height()/4, SSD1306_WHITE);
    display.display();
    delay(1);
    }
  }
  else {
    display.clearDisplay();
    display.setTextSize(1,2);
    display.setCursor(30, 0);
    display.print("Temperature C");
    display.setTextSize(2,3);
    display.setCursor(30, 30);
    display.println(SensorTemp);
 
  for(int16_t i=0; i<display.height()/2-2; i+=40) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i,
      display.height()/4, SSD1306_WHITE);
    display.display();
    delay(1);
    }
  getTempHum();
  delay(500);
}
}
void getTempHum(){
  if (sensor.measure()){
  SensorTemp = sensor.getTemperature();
  display.setTextSize(1,2);
  Serial.print("Temperature: ");
  Serial.println(SensorTemp);

  SensorHum = sensor.getHumidity();
  Serial.print("Humidity: ");
  Serial.println(SensorHum);
  }
  else {
  int errorCode = sensor.getErrorCode();
  switch (errorCode) {
    case 1: Serial.println("ERR: Sensor is offline"); break;
    case 2: Serial.println("ERR: CRC validation failed."); break;
      }
    }
  } 
