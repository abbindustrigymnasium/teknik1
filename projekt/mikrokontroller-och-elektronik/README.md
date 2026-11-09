# Projekt: Mikrokontroller och elektronik

## Syfte

Nu får din hållare elektronik. Du lär dig programmera mikrodatorn ESP8266 (NodeMCU) i Arduino IDE, koppla komponenter på kopplingsdäck och läsa av en givare. Det är grunden för I hetaste laget och senare för robotbilen i Driverbot.

## Koppling till kursen

**Det här bedöms, i vanliga ord:**

- Hur du löser tekniska problem och felsöker tills koppling och kod fungerar.
- Hur du använder tekniska begrepp, till exempel digital ingång, I2C och pinne och signal.
- Hur väl du kommenterar och dokumenterar din kod.

**Centralt innehåll:** problemlösning med programmering, skapande och strukturering av programkod, strategier för att lösa tekniska problem.

**Kapitel som förbereder:** [6 Mikrodatorn och programmering](../../kapitel/06-mikrodatorn.md) och delar av [1 Från idé till återvinning](../../kapitel/01-teknikutvecklingsprocessen.md).

## Vad du ska göra

- **Labb 1:** installera Arduino IDE och ESP8266-kortet och få lysdioden att blinka.
- **Labb 2:** installera ett bibliotek och mät temperatur och luftfuktighet med AM2320-givaren via I2C.
- **Labb 3:** koppla in en tryckknapp till en digital ingång och låt programmet reagera på den.
- Efter varje labb: få det att fungera, förstå koden, ändra något och kommentera din kod.
- **Labb 4–7** (display, avståndssensor, servo, motorstyrning) gör du i och inför I hetaste laget när du behöver dem.

## Krav och leverabler

Momentet är formativt, vilket betyder att det i första hand ska hjälpa dig att lära. Du ska ha fungerande och kommenterad kod för labbarna.

## Arbetsgång

| Lektion | Innehåll |
|---------|----------|
| 1 | Labb 1: installera Arduino IDE, lägg till ESP8266-kortet (NodeMCU 1.0) och ladda ned Blink så att lysdioden blinkar. |
| 2 | Labb 2: installera AM2320-biblioteket, koppla givaren via I2C och visa temperatur och luftfuktighet i Serial Monitor. |
| 3 | Labb 3: koppla en tryckknapp till digital ingång och skriv ut olika meddelanden. Kommentera koden. Klar? Börja på labb 4 (display). |

## Bedömning

Momentet bedöms formativt och tillsammans med projekten. Läraren tittar på hur du felsöker och får kopplingar och kod att fungera, hur du använder begreppen och hur väl du kommenterar och dokumenterar din kod.

## Material

- [Labbarna i mappen Mikrodator](../../Mikrodator/)
- [Kodexempel](../../Mikrodator/Koder/)
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [Drivrutin för CP210x till Windows](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers), finns också i [mappen Mikrodator](../../Mikrodator/)
- Kursens samlade material: [MATERIAL.md](../../MATERIAL.md)

## Tips

- Dra ur USB-kabeln innan du kopplar om.
- Testa programmet utan givaren först, så att du vet att kortet fungerar.
- Lägg en sak i taget och testa efter varje steg.
- Får du inga värden från givaren: kontrollera SDA och SCL, spänningsmatningen och att I2C-pinnarna i koden stämmer med kopplingen.
- Skriv kommentarer som förklarar varför, inte bara vad.
- Använder du `analogWrite()` med värden upp till 1023? Läs rutan om PWM i [kapitel 6](../../kapitel/06-mikrodatorn.md).
