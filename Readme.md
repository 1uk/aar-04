# AREXX AAR-04 Schulprojekt
Gruppenmitglieder: Henri Chilla, Lukas Kitsche. Gearbeitet wird mit dem Arduino Roboter AREXX AAR-04. Drei verschiedene Probleme sind zu bewältigen: Ultraschall, Infrarot und Bluetooth, siehe unten.

## IDE
Als IDE wurde die offizielle [Arduino IDE](http://arduino.cc/en/main/software "git") und für Hacker ;) ein [Makefile](https://github.com/sudar/Arduino-Makefile "git") benutzt.

## Probleme
### Ultraschall
**Problemstellung:** Ermittle die Distanz mithilfe von Ultraschall.
#### Erklärung
Der Trigger sendet ein Signal eine Microsekunde und Echo empfängt das Signal nach einer bestimmten Zeit, mit der dann die Distanz ermittelt wird. Die Distanz kann mithilfe der Schallgeschwindigkeit und der Zeit ermittelt werden. Distanz=Schallgeschwindigkeit*Zeit/2
#### Kabel
Trig -> MISO

Echo -> MOSI

### Infrarot
#### Kabel
rechts -> SV1,D4

### Bluetooth
