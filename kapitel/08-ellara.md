# Kapitel 8: Ellära

> **I det här kapitlet lär du dig**
> - vad spänning, ström och resistans är
> - hur du använder Ohms lag och räknar med SI-prefix
> - hur du räknar på serie- och parallellkopplingar
> - hur du använder Kirchhoffs lagar och räknar effekt och energi
> - hur du bedömer om ett svar är rimligt

Du har redan kopplat givare, knappar och motorer. Hittills har du följt instruktioner och hoppats att det ska fungera. Nu får du teorin bakom, så att du kan förstå varför en motor går långsamt, varför en ledning blir varm och varför lysdioden behöver ett motstånd.

## Spänning, ström och resistans

Tänk på vatten i två kärl på olika höjd, förbundna med en slang.

- **Spänning**, U, är skillnaden i höjd, alltså det som driver flödet. Enheten är volt (V). Ett AA-batteri ger 1,5 V, en USB-port 5 V och ett vägguttag 230 V.
- **Ström**, I, är flödet av laddning genom ledningen. Enheten är ampere (A).
- **Resistans**, R, är hur trång slangen är. Enheten är ohm (Ω).

Ström går bara om **kretsen är sluten**, det vill säga att det finns en hel väg från pluspolen till minuspolen. Strömriktningen räknas från plus till minus, trots att elektronerna i metaller rör sig åt motsatt håll. Det beror på att man bestämde riktningen innan man kände till elektronerna.

**Likström** (DC) går alltid åt samma håll och kommer från batterier och USB. **Växelström** (AC) byter riktning hela tiden och finns i vägguttaget. Elektronik drivs nästan alltid av likspänning, och därför behövs nätadaptrar.

Vägguttagets 230 V är farligt. Du ska aldrig arbeta med eller öppna nätspänningsapparater i det här momentet. Elinstallationer får bara göras av behörig personal.

**SI-prefix** gör stora och små tal lätta att skriva.

| Prefix | Betyder | Exempel |
|--------|---------|---------|
| k (kilo) | 1 000 | 4,7 kΩ = 4 700 Ω |
| m (milli) | 0,001 | 25 mA = 0,025 A |
| µ (mikro) | 0,000 001 | 10 µF = 0,000 010 F |

## Ohms lag

**Ohms lag** beskriver hur de tre storheterna hänger ihop:

> U = R · I

Vill du ha strömmen skriver du I = U / R, och vill du ha resistansen R = U / I.

**Genomräknat exempel.** Vad blir strömmen genom en resistor på 470 Ω som ansluts till 12 V?

I = 12 / 470 ≈ 0,02553 A = **25,5 mA**.

## Serie- och parallellkoppling

I en **seriekoppling** går samma ström genom alla delar, och resistanserna adderas: R_tot = R1 + R2 + R3.

**Kirchhoffs spänningslag** säger att spänningarna runt en sluten krets tar ut varandra. I praktiken betyder det att delspänningarna summeras till källans spänning.

**Exempel.** Tre resistorer på 100 Ω, 220 Ω och 330 Ω seriekopplas till 13 V.

- R_tot = 100 + 220 + 330 = 650 Ω
- I = 13 / 650 = 0,02 A = 20 mA
- U1 = 100 · 0,02 = 2,0 V, U2 = 220 · 0,02 = 4,4 V, U3 = 330 · 0,02 = 6,6 V
- Kontroll: 2,0 + 4,4 + 6,6 = 13,0 V. Det stämmer.

I en **parallellkoppling** ligger samma spänning över alla grenar. **Kirchhoffs strömlag** säger att strömmen in i en punkt är lika stor som strömmen ut. Ersättningsresistansen fås ur

> 1 / R_p = 1 / R1 + 1 / R2 + ...

För två resistorer kan du använda R_p = (R1 · R2) / (R1 + R2).

**Exempel.** 100 Ω och 150 Ω parallellkopplas till 12 V.

- R_p = (100 · 150) / (100 + 150) = 15 000 / 250 = 60 Ω
- I1 = 12 / 100 = 0,12 A, I2 = 12 / 150 = 0,08 A
- Total ström: 0,12 + 0,08 = 0,20 A, och 12 / 60 = 0,20 A. Det stämmer.

Ersättningsresistansen är alltid mindre än den minsta resistansen i parallellkopplingen. Får du ett större värde har du räknat fel.

## Blandade kretsar

**Exempel.** En resistor på 47 Ω ligger i serie med parallellkopplingen ovan (100 Ω och 150 Ω). Kretsen ansluts till 12 V.

1. Parallelldelen: R_p = 60 Ω.
2. Totalt: R_tot = 47 + 60 = 107 Ω.
3. Total ström: I = 12 / 107 ≈ 0,1121 A = 112,1 mA.
4. Spänning över 47 Ω: 47 · 0,1121 ≈ 5,27 V.
5. Spänning över parallelldelen: 60 · 0,1121 ≈ 6,73 V. Kontroll: 5,27 + 6,73 = 12,00 V.
6. Grenströmmar: 6,73 / 100 ≈ 67,3 mA och 6,73 / 150 ≈ 44,9 mA. Summa: 112,2 mA, vilket stämmer inom avrundningen.

## Effekt och energi

**Effekt**, P, är hur mycket energi som omvandlas per tidsenhet, och mäts i watt (W). I likspänningskretsar gäller:

> P = U · I

**Energi**, W, är effekt gånger tid: W = P · t. I hemmet räknas energi ofta i kilowattimmar (kWh).

**Exempel.** I den blandade kretsen ovan är effekten P = 12 · 0,1121 ≈ **1,35 W**. En värmefläkt på 500 W som går i 3 timmar förbrukar 0,5 · 3 = **1,5 kWh**.

## Ledningsresistans

Även ledningar har resistans. Den beräknas med R = ρ · l / A, där ρ är resistiviteten, l längden och A tvärsnittsarean. För koppar är ρ cirka 0,0175 Ω·mm²/m.

**Exempel.** En kopparkabel är 10 m lång (20 m fram och tillbaka) med arean 0,5 mm². R = 0,0175 · 20 / 0,5 = **0,7 Ω**. Vid 2 A faller 0,7 · 2 = **1,4 V** i ledningen. Det förklarar varför en motor kan gå sämre med långa tunna ledningar.

## Rätt motstånd till en lysdiod

**Exempel.** En lysdiod ansluts till 3,3 V. Den har framspänningen 2,0 V och ska få ungefär 10 mA.

- Spänning över resistorn: 3,3 − 2,0 = 1,3 V.
- R = 1,3 / 0,010 = **130 Ω**.
- Närmaste vanliga större värde är 150 Ω, vilket ger 1,3 / 150 ≈ **8,7 mA**.

Att välja det närmaste **större** standardvärdet är ett vanligt sätt att inte riskera för hög ström.

## Rimlighetsbedömning

Fråga dig alltid: är svaret rimligt? En mobilladdare drar inte hundratals ampere, och en parallellkoppling kan inte ha större resistans än sin minsta gren. Kontrollera med Kirchhoffs lagar. Mät också gärna med en multimeter och jämför med det du räknat fram: en voltmeter kopplas parallellt över det du mäter, och en amperemeter i serie.

## Begrepp

- **Spänning (U):** det som driver strömmen, mäts i volt.
- **Ström (I):** flöde av laddning, mäts i ampere.
- **Resistans (R):** motstånd mot strömmen, mäts i ohm.
- **Ohms lag:** U = R · I.
- **Kirchhoffs lagar:** samband för spänningar i en slinga och strömmar i en punkt.
- **Effekt (P):** energi per tidsenhet, mäts i watt.
- **Resistivitet:** materialets förmåga att motstå ström.
- **Rimlighetsbedömning:** kontroll av att ett resultat kan stämma.

## Testa dig själv

1. Varför går det ingen ström i en öppen krets?
2. Varför är strömmen lika stor överallt i en seriekoppling?
3. Varför är ersättningsresistansen alltid mindre än minsta grenen i en parallellkoppling?
4. Vad händer med strömmen om spänningen fördubblas men resistansen är konstant?
5. Vad är skillnaden mellan effekt och energi?
6. Hur kopplar du en voltmeter och en amperemeter?

## Koppling till projektet

Det här är innehållet i projektet [Ellära](../projekt/ellara/README.md), som avslutas med ett prov. Du använder det sedan i [Driverbot](../projekt/produktutveckling-driverbot/README.md) när du räknar på motorer och batterier.

## Läs mer

- [Kjell & Company: serie- och parallellkoppling](https://www.kjell.com/se/kunskap/hur-funkar-det/elelektronik/grundlaggande-ellara/seriekoppling-och-parallellkoppling)
- [Ledningsresistans](https://el.ltgee.se/docs/ledningsresistans/)
- [Videoserie om ellära](https://www.youtube.com/watch?v=L4OkCzc4fbg&list=PLriWw5UoiIWuMPddMrLR0fmsnKzvtzaJu)
- [Elsäkerhetsverket](https://www.elsakerhetsverket.se)

[← Föregående](07-it-system-och-matning.md) | [Innehåll](../README.md) | [Nästa →](09-konstruktion-och-robotbil.md)
