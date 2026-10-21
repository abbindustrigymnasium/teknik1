# Teknik 1

Välkommen till kursen **Teknik nivå 1** (TEKI1000X, 100 poäng) på Hitachigymnasiet! Här hittar du allt material för kursen: presentationer, instruktioner, laborationer, CAD-filer och kodexempel.

Börja med kursintroduktionen: [Teknik 1 - Kursintroduktion.pptx](Teknik%201%20-%20Kursintroduktion.pptx)

## Kursöversikt

Kursen består av sju moment som bygger på varandra – från skiss och ritning, via CAD och 3D-utskrift, till mikrodatorer, elektronik och till sist en egen robotbil.

| # | Moment | Material |
|---|--------|----------|
| 1 | Ritteknik | [Ritteknik och Inventor/](Ritteknik%20och%20Inventor/) |
| 2 | CAD med Autodesk Inventor (inkl. examinerande uppgift *Hållare*) | [Ritteknik och Inventor/](Ritteknik%20och%20Inventor/), [Hållare/](H%C3%A5llare/) |
| 3 | 3D-utskrift med Bambu Lab | Se länkar nedan |
| 4 | Mikrodator – ESP8266 och Arduino IDE (7 laborationer) | [Mikrodator/](Mikrodator/) |
| 5 | Projekt: I hetaste laget (temperaturmätare) | [I hetaste laget/](I%20hetaste%20laget/) |
| 6 | Ellära + prov | [Ellära/](Ell%C3%A4ra/) |
| 7 | Driverbot – robotbil | [Driverbot/](Driverbot/) |

Kursens centrala innehåll och betygskriterier finns i [kurskriterie.md](kurskriterie.md).

---

## 1. Ritteknik

Vi lär oss skissa och rita tekniska ritningar för hand: vyer, projektioner och måttsättning.

- [Ritteknik presentation.pptx](Ritteknik%20och%20Inventor/Ritteknik%20presentation.pptx)
- [Träning, vyer och måttsättning.docx](Ritteknik%20och%20Inventor/Tr%C3%A4ning%2C%20vyer%20och%20m%C3%A5tts%C3%A4ttning.docx)
- [Orthographic-Projection-Sheet-1.pdf](Ritteknik%20och%20Inventor/Orthographic-Projection-Sheet-1.pdf)
- [Klosshäfte inskannat.pdf](Ritteknik%20och%20Inventor/Klossh%C3%A4fte%20inskannat.pdf)

## 2. CAD med Autodesk Inventor

Från ritning till 3D-modell. Vi modellerar detaljer i Inventor och gör ritningar från modellerna.

- [Introduktion Inventor CAD.pdf](Ritteknik%20och%20Inventor/Introduktion%20Inventor%20CAD.pdf) ([.docx](Ritteknik%20och%20Inventor/Introduktion%20Inventor%20CAD.docx))
- [Inventor intro.mp4](Ritteknik%20och%20Inventor/Inventor%20intro.mp4) – videogenomgång
- Gratis studentlicens: [Autodesk Education](https://www.autodesk.com/education/edu-software/overview)

### Examinerande uppgift: Hållare

Konstruera en hållare för ESP8266-kortet som sedan 3D-skrivs ut.

- [Hållare esp mm.docx](H%C3%A5llare/H%C3%A5llare%20esp%20mm.docx) – uppgiftsbeskrivning
- [Baskort.ipt](H%C3%A5llare/Baskort.ipt) – modell av baskortet att konstruera runt
- [Videogenomgång (YouTube)](https://www.youtube.com/watch?v=BizTnf3CqtA)

## 3. 3D-utskrift med Bambu Lab

Vi skriver ut våra konstruktioner på skolans Bambu Lab-skrivare.

- [Bambu Studio](https://bambulab.com/en/download/studio) – slicerprogrammet
- [Bambu Lab Wiki](https://wiki.bambulab.com/en/home) – guider och felsökning

## 4. Mikrodator – ESP8266 och Arduino IDE

Sju laborationer där vi programmerar ESP8266 (NodeMCU) i Arduino IDE och kopplar in sensorer, displayer och motorer.

1. [Installation av Arduino IDE och komma igång med ESP8266](Mikrodator/1%20Installation%20av%20Arduino%20IDE%20och%20komma%20ig%C3%A5ng%20med%20ESP8266-VW19117.docx)
2. [Lägga till bibliotek i Arduino IDE och mäta temperatur med AM2320](Mikrodator/2%20L%C3%A4gga%20till%20bibliotek%20%20i%20Arduino%20IDE%20och%20m%C3%A4ta%20temperatur%20med%20AM2320.docx)
3. [Koppla in trycknapp till digital ingång](Mikrodator/3%20Koppla%20in%20trycknapp%20till%20digital%20ing%C3%A5mg.docx)
4. [Skriva till en display](Mikrodator/4%20Skriva%20till%20en%20Display.docx)
5. [Avståndssensor VL53L0X](Mikrodator/5%20Avst%C3%A5ndsensor%20VLX53L0X.docx)
6. [Servo](Mikrodator/6%20Servo.docx)
7. [Motorstyrning](Mikrodator/7%20Motorstyrning.docx)

Kodexempel till laborationerna finns i [Mikrodator/Koder/](Mikrodator/Koder/).

**Programvara och drivrutiner**

- [Arduino IDE](https://www.arduino.cc/en/software)
- Board manager-URL för ESP8266: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
- USB-drivrutin CP210x (Windows): [CP210x_Universal_Windows_Driver.zip](Mikrodator/CP210x_Universal_Windows_Driver.zip) eller från [Silicon Labs](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers)

**Bibliotek och referenser**

- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [AM2320 (temperatur/luftfuktighet)](https://github.com/hibikiledo/AM2320)
- [VL53L0X (avståndssensor)](https://github.com/pololu/vl53l0x-arduino)
- [Adafruit SSD1306 (OLED-display)](https://adafruit.github.io/Adafruit_SSD1306/html/class_adafruit___s_s_d1306.html) och [Adafruit GFX](http://adafruit.github.io/Adafruit-GFX-Library/html/class_adafruit___g_f_x.html)

## 5. Projekt: I hetaste laget

Ett projekt tillsammans med [Programmering 1](https://github.com/abbindustrigymnasium/programmering1) där vi bygger en uppkopplad temperaturmätare med ESP8266 och AM2320.

- [I hetaste laget.pptx](I%20hetaste%20laget/I%20hetaste%20laget.pptx)
- [Mäta temperatur med AM2320.docx](I%20hetaste%20laget/M%C3%A4ta%20temperatur%20med%20AM2320.docx)

## 6. Ellära

Ström, spänning, resistans, Ohms lag, serie- och parallellkoppling. Momentet avslutas med ett prov.

- [Ellärakompendium VT26.docx](Ell%C3%A4ra/Ell%C3%A4rakompendium%20VT26.docx)
- [Kjell & Company: Seriekoppling och parallellkoppling](https://www.kjell.com/se/kunskap/hur-funkar-det/elelektronik/grundlaggande-ellara/seriekoppling-och-parallellkoppling)
- [Ledningsresistans](https://el.ltgee.se/docs/ledningsresistans/)
- [Videoserie om ellära (YouTube)](https://www.youtube.com/watch?v=L4OkCzc4fbg&list=PLriWw5UoiIWuMPddMrLR0fmsnKzvtzaJu)

## 7. Driverbot – robotbil

Kursens slutprojekt: konstruera, skriv ut, bygg och programmera en egen robotbil.

- [Driverbot250s.pptx](Driverbot/Driverbot250s.pptx) – projektbeskrivning
- [Arbetsordning.docx](Driverbot/Arbetsordning.docx)
- [1. Motorhållare instruktion.mp4](Driverbot/1.%20Motorh%C3%A5llare%20instruktion.mp4)

CAD-filer för standardkomponenter:

- [TT motor.STEP](Driverbot/TT%20motor.STEP)
- [Micro servo 9g-SG90.stp](Driverbot/Micro%20servo%209g-SG90.stp)
- [Lego axle.STEP](Driverbot/Lego%20axle.STEP)
- [11M Beam.ipt](Driverbot/11M%20Beam.ipt)
- [Nummerplåt.stp](Driverbot/Nummerpl%C3%A5t.stp)

---

## Extra: Film

- [Teknikhistoria 250s.docx](Film/Teknikhistoria%20250s.docx) – se även [UR Play: Automatiseringens tidevarv](https://urplay.se/serie/196527-automatiseringens-tidevarv)
- [Reklamfilm på ditt spel.docx](Film/Reklamfilm%20p%C3%A5%20ditt%20spel.docx)

## Länkar

- [Skolverket – ämnet Teknik](https://www.skolverket.se/undervisning/gymnasieskolan/laroplan-program-och-amnen-i-gymnasieskolan/gymnasieprogrammen/amne?code=TEK)
- [Programmering 1](https://github.com/abbindustrigymnasium/programmering1)
