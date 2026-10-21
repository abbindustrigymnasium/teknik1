#include <Wire.h> //I2C tvåtrådskommunikationen
#include <VL53L0X.h> //Hämtar bibliotek till avståndssensor VL53L0X
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

VL53L0X sensor; //skapar en instans av klassen
Adafruit_SSD1306 display(128, 64, &Wire, -1, 400000UL, 100000UL); //Adafruit är en klass, display är en stycken av den klassen, med följande egenskaper
//och-tecknet före Wire är en pekare 

#define InputPin 13 //definierar IO13 som InputPin, kopplad till pinne D7

 

bool ButtonState; //definierar tryckknappen som bool, bool har bara två tillstånd, 1-0, true-false, på-av
int SensorDistance; //Talar om att variabeln SensorDistance är en textremsa
byte LastSpeed = 0; //Fösta hastigheten
byte MotorSpeed = 5; //
byte MotorDir = 0; //Digitalingång från motorns ingångar

typedef enum States {
  Init,
  Stopp,
  Fram,
  Back,
};

States State, LastState; //DE OLIKA LÄGENA  

//States State = Init; //börjare i case init //använd ctrl + t för att snygga till kod

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

  State = Init; // Läget är lika med init
  LastState = Init; // Det senaste läget är lika med init

  pinMode(MotorSpeed, OUTPUT);// är en digitalutgång
  pinMode(MotorDir, OUTPUT);// är en digitalutgång

  analogWrite(MotorSpeed, 0); //Motorn börjar med värdet 0 dvs av.

 


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
      Motor_1(0,1); //motorn (0 är den nya hastigheten en vill ha, 1 är hur snabb accelerationen ska bli(snabbare ju lägre värde)
      delay(500);//vänta 0,5s
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
      Motor_1(100, 10); //motorn (100 är den nya hastigheten en vill ha, 10 är hur snabb accelerationen ska bli(snabbare ju lägre värde)
      //delay(50);//vänta 0,05s

 

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
      Motor_1(100, 10);//motorn (100 är den nya hastigheten en vill ha, 10 är hur snabb accelerationen ska bli(snabbare ju lägre värde)
      //delay(50); //vänta 0,05s
 

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

void Motor_1(byte NewSpeed, long Step ) //(byte Newspeed) är den nya hastigheten en vill till, "long Step" är hur snabbt den accelerarar upp/ner 
{
  if (State != LastState)//om state inte är lika med laststate
  {
    NewSpeed = map(NewSpeed, 0, 100, 0, 255);// olika värden för hastighet "0,100" är lägsta och högsta värdet för den "current range" de två sista är de värderna en vill upp till
    LastState = State;//de är samma

    switch (State) { //byt kommando när state ges

      case Init:
        break;

      case Stopp:
        for (byte Speed = LastSpeed + 1 ; Speed <= NewSpeed; Speed -= 1)// går igenom kraver nedan och minskar värdet för lastspeed med 1
        {
          analogWrite(MotorSpeed, Speed);//sensorniometern läser av hastigheten
          delay(Step);// vänta ett steg, i detta case 1
        }
        break;

      case Fram:
        digitalWrite(MotorDir, HIGH);//Digitalingång dir b1 på (I nästa case blir detta omvänt vilket gör att motorn går åt andra hållet)
        for (short Speed = LastSpeed; Speed <= NewSpeed; Speed += 1)// går igenom kraver nedan och ökar värdet för lastspeed med 1
        {
          analogWrite(MotorSpeed, Speed);
          delay(Step);// vänta ett steg, i detta case 10
        }
        break;

      case Back:
        digitalWrite(MotorDir, LOW);//Digitalingång dir b1 av
        for (short Speed = LastSpeed; Speed <= NewSpeed; Speed += 1)// går igenom kraver nedan och ökar värdet för lastspeed med 1
        {
          analogWrite(MotorSpeed, Speed);
          delay(Step);// vänta ett steg, i detta case 10
        }
        break;
    }
    LastSpeed = NewSpeed; //Håller konstant hastighet om inget hinder kommer ivägen
  }
}
