# co2ampel

[Projektseite beim Fablab Bruchsal](https://wiki.fablab-bruchsal.de/doku.php?id=allgemein:co2-ampel)

## Arduino IDE vorvbereiten


### ESP 8266 Boardmanager installieren

[Siehe Anleitung bei Heise](https://www.heise.de/ct/artikel/Arduino-IDE-installieren-und-fit-machen-fuer-ESP8266-und-ESP32-4130814.html)

Tools / Board / LOLIN(Wemos) D1 R2 & mini

### Bibliotheken installieren

Die Links bei den includes in der co2ampel.ino Datei klicken und die jeweiligen Bibliotheken installieren

## Module ausprobieren

Als nächster Schritt sollte jedes Modul getrennt angesprochen werden.

- [LCD Display](https://github.com/johnrickman/LiquidCrystal_I2C/blob/master/examples/HelloWorld/HelloWorld.pde)
- [SCD30 Sensor](https://github.com/sparkfun/SparkFun_SCD30_Arduino_Library/blob/master/examples/Example1_BasicReadings/Example1_BasicReadings.ino)
- [LED Leiste](https://github.com/adafruit/Adafruit_NeoPixel/blob/master/examples/strandtest/strandtest.ino)

## CO2 Werte auf LCD darstellen

- Sensor auslesen und Werte für CO2, Temperatur und Feuchtigkeit in Variable speichern
- Darstellen der Messwerte auf LCD

## CO2 Ampel

- Schwellwerte festlegen (grün, gelb, rot)
- LED Leiste in der jeweiligen Farbe leuchten lassen abhängig von CO2 Wert
- Optional: Anzahl akrive LEDs abhängig von CO2 Wert (Tipp: [Funktion map&(https://www.arduino.cc/reference/de/language/functions/math/map/) )

