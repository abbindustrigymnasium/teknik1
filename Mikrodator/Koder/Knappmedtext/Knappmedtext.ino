#define InputPin 13

bool ButtonState;

void setup() {
  Serial.begin(9600);

  pinMode(InputPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  }


void loop() {
  ButtonState = digitalRead(InputPin);
  digitalWrite(LED_BUILTIN,ButtonState);
  if (ButtonState==0){
  Serial.println("Du har inte tryckt in knappen");
  }
  else {
 Serial.println("Möcket Bra, Du har tryckt in knappen");
    }
  delay(200);
}
