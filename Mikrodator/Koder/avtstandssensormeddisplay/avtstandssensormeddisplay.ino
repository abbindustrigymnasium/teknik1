#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

VL53L0X sensor;
//#define InputPin 13

Adafruit_SSD1306 display(128, 64, &Wire, -1, 400000UL, 100000UL);

//bool ButtonState;

void setup()
{
  Serial.begin(9600);
  Wire.begin(14, 12);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2, 3);

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    display.println("Failed to detect and initialize sensor!");
    display.display();
    delay(1);
    while (1) {}
  }

  sensor.startContinuous();
}

void loop()
{
  display.display();
  display.clearDisplay();
  display.setCursor(3,22);
  display.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) {
    display.print(" TIMEOUT");
  }
  delay(100);
  
}
