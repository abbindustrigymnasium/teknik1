# Projekt: Produktutveckling: Driverbot

## Syfte

Kursens slutprojekt är Driverbot: du konstruerar, 3D-skriver ut, bygger och programmerar en egen robotbil med ESP8266. Här använder du allt du lärt dig i kursen, CAD i Inventor, 3D-utskrift, elektronik och programmering. Du följer teknikutvecklingsprocessen från idé och modell till prototyp, test och färdig produkt.

## Koppling till kursen

**Det här bedöms, i vanliga ord:**

- Hur du driver processen och hur dina val påverkar resultatet.
- Hur du löser tekniska problem och värderar din lösning.
- Hur du använder tekniska begrepp, modeller och beräkningar.
- Hur väl du dokumenterar och redovisar din bil.

**Centralt innehåll:** teknikutvecklingsprocessen, arbete i projektform, problemlösning med programmering, modellering och prototyper, testning och utvärdering, kommunikation och dokumentation.

**Kapitel som förbereder:** [3 CAD och Inventor](../../kapitel/03-cad-och-inventor.md), [4 3D-utskrift](../../kapitel/04-3d-utskrift.md), [5 Material och hållbarhet](../../kapitel/05-material-och-hallbarhet.md), [6 Mikrodatorn och programmering](../../kapitel/06-mikrodatorn.md), [7 IT-system, mätning och kommunikation](../../kapitel/07-it-system-och-matning.md), [8 Ellära](../../kapitel/08-ellara.md), [9 Konstruktion av en robotbil](../../kapitel/09-konstruktion-och-robotbil.md), [10 Teknik, samhälle och normer](../../kapitel/10-teknik-samhalle-normer.md).

## Vad du ska göra

Följ arbetsordningen:

1. Axelkoppling mellan TT-motor och Lego-axel.
2. Nummerplåt.
3. Motorhållare (se film eller genomgång).
4. Bygg bilens grund och programmera den att köra fram och back.
5. Servohållare så att bilen kan svänga.
6. ESP-hållare: modifiera din gamla hållare.
7. Bygg klart bilen, styr den via internet och redovisa.

## Krav och leverabler

Projektet har nivåer:

| Nivå | Krav |
|------|------|
| E | Bilen är ihopsatt och kan köra fram och back av sig själv |
| C | Bilen kan också svänga och styras via internet |
| A | Bilen är kompakt, max 150 × 150 × 150 mm, med egen ESP-hållare och egna funktioner i koden |

Du lämnar in dokumentation med CAD-modeller, bilder på bygget och kommenterad kod, och du redovisar din bil.

## Arbetsgång

Projektet är 22 lektioner, här sammanslagna i faser.

| Lektion | Innehåll |
|---------|----------|
| 1 | Projektstart: genomgång av projektet, nivåerna och arbetsordningen. Gör en egen planering. |
| 2–3 | Konstruera axelkopplingen mellan TT-motor och Lego-axel i Inventor med de färdiga STEP-filerna. Skriv ut den och börja modellera nummerplåten. |
| 4–5 | Nummerplåten klar. Se filmen om motorhållaren, konstruera och skriv ut motorhållaren och testa passformen mot motor och axel. |
| 6–8 | Bygg bilens grund: motorer, axlar och balkar till ett chassi. Koppla motorn till ESP8266 via H-bryggan och testa motorstyrning (labb 7). Programmera bilen att köra fram och back av sig själv och logga det (E-nivå). Avstämning. |
| 9–11 | Konstruera en servohållare för SG90-servot, skriv ut och testa servot med kod (labb 6). Montera styrningen och koppla ihop drivning och styrning. |
| 12 | ESP-hållare: modifiera din gamla hållare så att ESP8266 och kopplingsdäck passar på bilen. Skriv ut. |
| 13–14 | Genomgång av styrning via internet (MQTT) med färdig kod. Koppla upp din bil, testa och felsök (C-nivå). Avstämning med läraren om var du ligger i arbetsordningen. |
| 15–17 | Bygg klart bilen. Siktar du på A: gör den kompakt, max 150 × 150 × 150 mm. Egna förbättringar av kod eller konstruktion. Testkör, justera och felsök. |
| 18–19 | Dokumentera projektet: CAD-modeller, bilder på bygget och kommenterad kod. Färdigställ bil och dokumentation, sista utskrifter och justeringar. |
| 20–22 | Förbered redovisningen. Redovisning av robotbilarna: visa och kör din bil och berätta om konstruktion och kod. Lämna in dokumentationen och utvärdera projektet. |

## Bedömning

Du bedöms på hur du driver processen, löser tekniska problem, använder tekniska begrepp och hur väl du dokumenterar och redovisar din bil.

## Material

- [Mappen Driverbot](../../Driverbot/), med projektbeskrivningen och CAD-filer
- [Arbetsordning](../../Driverbot/Arbetsordning.docx)
- [Film om motorhållaren](../../Driverbot/1.%20Motorh%C3%A5llare%20instruktion.mp4)
- CAD-filer: [TT-motor](../../Driverbot/TT%20motor.STEP), [servo SG90](../../Driverbot/Micro%20servo%209g-SG90.stp), [Lego-axel](../../Driverbot/Lego%20axle.STEP), [11M Beam](../../Driverbot/11M%20Beam.ipt), [nummerplåt](../../Driverbot/Nummerpl%C3%A5t.stp)
- [Labb 6 Servo](../../Mikrodator/6%20Servo.docx) och [Labb 7 Motorstyrning](../../Mikrodator/7%20Motorstyrning.docx)
- [Kodexempel](../../Mikrodator/Koder/)
- [Uppgiften Hållare](../../H%C3%A5llare/H%C3%A5llare%20esp%20mm.docx), som du utgår från när du gör ESP-hållaren

## Tips

- Gör en egen planering och följ upp den vid avstämningarna. Utskrifter tar längre tid än du tror.
- Testa delsystem för sig innan du sätter ihop dem, och lyft bilen när du provar motorn första gången.
- Kontrollera vilka pinnar som används av motordrivkortet innan du kopplar in servot.
- Lägg aldrig inloggningar till MQTT eller Wi-Fi i kod som du delar.
- Skriv ett testprotokoll innan du testar. Det gör dokumentationen mycket lättare.
- När du utvärderar projektet: ta gärna upp hållbarhet och vem bilen är tänkt för. Frågorna finns i [kapitel 5](../../kapitel/05-material-och-hallbarhet.md) och [kapitel 10](../../kapitel/10-teknik-samhalle-normer.md).
