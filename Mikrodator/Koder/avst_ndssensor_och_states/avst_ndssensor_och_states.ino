#include <Wire.h> //I2C tvåtrådskommunikationen
#include <VL53L0X.h> //Hämtar bibliotek till avståndssensor VL53L0X
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

 

#define InputPin 13 //definierar IO13 som InputPin, kopplad till pinne D7

 

bool ButtonState; //definierar tryckknappen som bool, bool har bara två tillstånd, 1-0, true-false, på-av
int SensorDistance; //Talar om att variabeln SensorDistance är en textremsa

 

typedef enum States {
  Init,
  Stopp,
  Fram,
  Back,
};

 

States State = Init; //börjare i case init //använd ctrl + t för att snygga till kod

 

VL53L0X sensor; //skapar en instans av klassen

 

Adafruit_SSD1306 display(128, 64, &Wire, -1, 400000UL, 100000UL); //Adafruit är en klass, display är en stycken av den klassen, med följande egenskaper
//och-tecknet före Wire är en pekare

 


void setup() { //körs en gång i början av programmet
  Serial.begin(9600); //Kommunikation med serial monitor
  Wire.begin(14, 12); //IO-nummer 14 motsvarar pinne D5 kopplas till SDA=Serial data, IO-nummer 12 motsvarar pinne D6 kopplas till SCL=Serial clock
  delay(2000); //Väntar 2 sekunder
  display.begin(SSD1306_SWITCHCAPVCC, 0X3C); //0x3C är adressen
  delay(3000);//väntar given tid
  display.clearDisplay(); //tar bort gammalt skräp
  display.setTextColor(WHITE);//displayen är på/tänd
  display.setCursor(0, 8);
  delay(1000);

 


  sensor.setTimeout(500); // väntar 500 millisekunder
  if (!sensor.init()) // !=inte , alternativa skrivsätt, sensor.init()==false sens.int!=true
  {
    Serial.println("Failed to detect and initialize sensor!"); //skriver linje, print line
    while (1) {}
  }
  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();

 

}

 

void loop() { //upprepar händelsen

 

  ButtonState = digitalRead(InputPin); //läser av signalen, noll eller ett, på input pin
  switch (State) { //switch byter mellan olika case, kan inte köra flera samtidigt
    case Init: //startläge, väntar på knapptryck för att starta
      display.clearDisplay(); //rensar
      display.setCursor(0, 8);
      display.println("Tryck for att starta");
      display.display(); //visar det som finns i minnet
      if (ButtonState) { //Vid knapptryck, hoppa vidare till Stopp
        State = Stopp;
      }
      break; //avslutar case init

 

    case Stopp: //Stannar motorn
      display.clearDisplay(); //rensar
      display.display(); //visar
      getDistance(); //hämtar avstånd
      displayDistance("Stopp"); //Visar avstånd
      delay(500); //väntar en halv sekund
      if (SensorDistance > 320 and SensorDistance < 2000) { //Om värdet är mellan 320 och 2000 gå till fram
        State = Fram;
      }
      if (SensorDistance < 280) { //om värdet är mindre än 280 gå till back
        State = Back;
      }

 


      
//Här ska det in något som gör att programmet går tillbaka till init vid knapptryck, utan att komma till Stopp.
//Antingen med hjälp av toggle som ger 0->1 och 1->0, eller en räknare som vid udda ger init och jämna ger stopp. 

 

 


      break;

 

    case Fram: //kör motorn framåt
      display.clearDisplay();
      display.display();
      getDistance(); //hämtar avstånd
      displayDistance("Kor framat"); //Visar avstånd

 

      delay(500);
      if (!(SensorDistance > 320)) { //om avståndet inte är större än 320, går tillbaka till stopp
        State = Stopp;
      }
      break;

 

    case Back: //backar motorn
      display.clearDisplay();
      display.display();
      getDistance(); //hämtar avstånd
      displayDistance("Backar"); //anropar funktionen och skickar med värdet backar

 

      delay(500);
      if (!(SensorDistance < 280)) { //om avståndet inte är mindre än 280, går tillbaka till stopp
        State = Stopp;
      }
      break;

 

  }
}
void getDistance() { //skapar funktionen getDistance som läser av Avstånd samt skickar tillbaka ett värde
  SensorDistance = (sensor.readRangeContinuousMillimeters()) ; //Hämta avståndsvärdet från givaren
  Serial.print("Distance: ");//Skriver ut i serial monitor-fönstret
  Serial.println(SensorDistance); //tillsammans med värdet från givaren
}

 

void displayDistance(String StateStr) { //en funktion som skriver ut avståndet på displayen, tar emot strängen som är skickad
  display.clearDisplay(); //rensar display
  display.print("Avstand: "); //Skriver ut texten
  display.println(SensorDistance); //skriver ut avsåndet i mm
  display.println(StateStr);  //Skriver ut medskickad sträng
  display.setCursor(0, 8); //Var den börjar skriva ut
  display.display (); //visar
}
